modded class SCR_CharacterDamageManagerComponent
{
	override void OnDamageStateChanged(EDamageState state)
	{
		super.OnDamageStateChanged(state);
		
		if (state == ECharacterHealthState.CRITICAL)
		{
			// Makes it so that only players can be unconscious. there are issues when AI are unconscious
			ChimeraCharacter character = ChimeraCharacter.Cast(GetOwner());
			if (!EntityUtils.IsPlayer(character))
				return;
			
			// permitting uncon in a vehicle creates a physics nightmare for the ragdoll and vehicle rigidbody 
			if (character.IsInVehicle())
				return;
			
			CharacterControllerComponent controller = character.GetCharacterController();
			
			// Sets the player unconscious if health is Critical
			controller.SetUnconscious(true);
			
			// If a player doesn't have a bleeding zone they can't be revived
			SCR_CharacterDamageManagerComponent CharDamMan = SCR_CharacterDamageManagerComponent.Cast(character.GetDamageManager());
			CharDamMan.AddParticularBleeding();
			
			// Schedule a call to the kill player function after bleed out duration has passed (in miliseconds)
			GetGame().GetCallqueue().Remove(KillPlayer);
			GetGame().GetCallqueue().CallLater(KillPlayer, s_HealthSettings.GetUnconsciousBleedoutDuration() * 1000, false);
		}
		else
		{
			GetGame().GetCallqueue().Remove(KillPlayer); //Remove the KillPlayer function from the call queue
		};
	};
	
	private void KillPlayer()
	{
		ChimeraCharacter character = ChimeraCharacter.Cast(GetOwner());
		CharacterControllerComponent controller = character.GetCharacterController();
	
		if (controller.IsUnconscious())
		{
			controller.ForceDeath();	
		};
	};
	
	//! Makes sure that the player actually stays unconscious if the healthstate change set them unconscious
	override bool ShouldBeUnconscious()
	{
		ChimeraCharacter character = ChimeraCharacter.Cast(GetOwner());
		CharacterControllerComponent controller = character.GetCharacterController();
		
		return controller.IsUnconscious();
	};
};
