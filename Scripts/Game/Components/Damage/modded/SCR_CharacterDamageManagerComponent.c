modded class SCR_CharacterDamageManagerComponent
{
	protected HitZone m_HealthHitZone;
	protected float m_fCriticalHealth;
	protected bool m_bUnconsciousProtectionEnabled = false;
	
	void SetUnconscious(bool enabled)
	{
		// Makes it so that only players can be unconscious. there are issues when AI are unconscious
		ChimeraCharacter character = ChimeraCharacter.Cast(GetOwner());
		if (!EntityUtils.IsPlayer(character))
			return;
			
		// permitting uncon in a vehicle creates a physics nightmare for the ragdoll and vehicle rigidbody 
		if (character.IsInVehicle())
			return;
		
		CharacterControllerComponent controller = character.GetCharacterController();	
		if (controller.IsUnconscious() == enabled)
			return;
		
		if (enabled)
		{
			// If a player doesn't have a bleeding zone they can't be revived
			// => Always add a bleeding zone to the chest
			SCR_CharacterDamageManagerComponent charDamMan = SCR_CharacterDamageManagerComponent.Cast(character.GetDamageManager());
			charDamMan.AddParticularBleeding();
		}
		else
		{
			FullHeal();
		};
		
		controller.SetUnconscious(enabled);
	};
	
	bool IsUnconscious()
	{
		ChimeraCharacter character = ChimeraCharacter.Cast(GetOwner());
		CharacterControllerComponent controller = character.GetCharacterController();
		
		return controller.IsUnconscious();
	};
	
	protected void SetUnconsciousProtection(bool enable)
	{
		m_bUnconsciousProtectionEnabled = enable;
	};
	
	protected override void OnDamage(EDamageType type, float damage, HitZone pHitZone, IEntity instigator, inout vector hitTransform[3], float speed, int colliderID, int nodeID)
	{
		super.OnDamage(type, damage, pHitZone, instigator, hitTransform, speed, colliderID, nodeID);
		
		if (!m_HealthHitZone)
		{
			m_HealthHitZone = GetHitZoneByName("Health");
			m_fCriticalHealth = m_HealthHitZone.GetDamageStateThreshold(ECharacterHealthState.CRITICAL);
		};
				
		// Sets the player unconscious if health is Critical
		if (!IsUnconscious() && m_HealthHitZone.GetHealthScaled() <= m_fCriticalHealth)
		{
			SetUnconscious(true);
			// Make sure unit can't die while falling unconscious (Protection for 1 second)
			SetUnconsciousProtection(true);
			GetGame().GetCallqueue().CallLater(SetUnconsciousProtection, 1000, false, false);
		};
		
		// Unconscious protection handling
		if (IsUnconscious() && m_bUnconsciousProtectionEnabled)
		{
			m_HealthHitZone.SetHealthScaled(m_fCriticalHealth);
		};
	};
	
	//! Makes sure that the player actually stays unconscious if the healthstate change set them unconscious
	override bool ShouldBeUnconscious()
	{
		return IsUnconscious();
	};
};

