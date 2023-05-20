// Version 1.2
modded class SCR_CharacterDamageManagerComponent
{
	
//------------------------------------------------------------------------------------------------	
	
	override void OnDamageStateChanged(EDamageState state)
	{
	    super.OnDamageStateChanged(state);
		
		ChimeraCharacter character = ChimeraCharacter.Cast(GetOwner());
		if (!character)
			return;
		
		CharacterControllerComponent controller = character.GetCharacterController();
		if (!controller)
			return;
		
		// Skip handling if unit is already unconscious
		if (controller.IsUnconscious())
			return;
		
	    if(state == ECharacterHealthState.CRITICAL)
	    {
			// Makes it so that only players can be unconscious. there are issues when AI are unconscious
			if (!EntityUtils.IsPlayer(character))
				return;
			
			// permitting uncon in a vehicle creates a physics nightmare for the ragdoll and vehicle rigidbody 
			if (character.IsInVehicle())
				return;
			
			// Sets the player unconscious if health is Critical
	        controller.SetUnconscious(true);
			
			// If a player doesn't have a bleeding zone they can't be revived
			SCR_CharacterDamageManagerComponent CharDamMan = SCR_CharacterDamageManagerComponent.Cast(character.GetDamageManager());
			CharDamMan.AddParticularBleeding();
			
			// Turns on Invincibility
	        DamageManagerComponent damageManager = character.GetDamageManager();
	        damageManager.EnableDamageHandling(false);
			
			// Schedule a call to the kill player function after bleed out duration has passed (in miliseconds)
			GetGame().GetCallqueue().CallLater(KillPlayer, s_HealthSettings.GetUnconsciousBleedoutDuration() * 1000, false);
	    }
		else 
		{	
			GetGame().GetCallqueue().Remove(KillPlayer); //Remove the KillPlayer function from the call queue
		}
	}
	
//------------------------------------------------------------------------------------------------
		
	private void KillPlayer()
	{
		ChimeraCharacter character = ChimeraCharacter.Cast(GetOwner());
	    CharacterControllerComponent controller = character.GetCharacterController();
	
	    if (controller.IsUnconscious())
	    {
	        controller.ForceDeath();
	    }
		
		else 
		{	
			GetGame().GetCallqueue().Remove(KillPlayer); //Remove the KillPlayer function from the call queue
		}
	}
};

//------------------------------------------------------------------------------------------------

modded class SCR_CharacterDamageManagerComponent
{
	
	//! Makes sure that the player actually stays unconscious if the healthstate change set them unconscious
	override bool ShouldBeUnconscious()
	{
	    ChimeraCharacter character = ChimeraCharacter.Cast(GetOwner());
	    CharacterControllerComponent controller = character.GetCharacterController();
	    if(controller.IsUnconscious())
	        return true;
	    else
	        return false;
	}
};

//------------------------------------------------------------------------------------------------
// Override to stop AI from shooting unconscious players, no war crimes here.
modded class SCR_AICombatComponent
{		
	override bool ShouldAttackEndForTarget(BaseTarget enemyTarget, out bool shouldInvestigateFurther = false, out string context = string.Empty)
	{	
		bool shouldEnd = super.ShouldAttackEndForTarget(enemyTarget, shouldInvestigateFurther, context);
		if(!shouldEnd)
		{
			IEntity targetEntity = enemyTarget.GetTargetEntity();
			ChimeraCharacter targetCharacter = ChimeraCharacter.Cast(targetEntity);
			if (!targetCharacter)
			    return true;
			
			CharacterControllerComponent controller = targetCharacter.GetCharacterController();
			if (controller && controller.IsUnconscious())
			{
			    context = "Target entity is unconscious";
			    return true;
			}
		}
		return shouldEnd;
	}

};