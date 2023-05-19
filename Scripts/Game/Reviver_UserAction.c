// v1.1
modded class SCR_BandageUserAction
{	
	//overrides the Bandage action 'CanBePerformedScript' so that it works on unconscious people more consistantly
	override bool CanBePerformedScript(IEntity user)
	{
		if (!super.CanBePerformedScript(user))
			return false;
		
		if (m_eHitZoneGroup == EHitZoneGroup.VIRTUAL)
			return false;
		
		ChimeraCharacter userCharacter = ChimeraCharacter.Cast(user);
		if (!userCharacter)
			return false;
			
		ChimeraCharacter ownerCharacter = ChimeraCharacter.Cast(GetOwner());
		if (!ownerCharacter)
			return false;
		
		SCR_CharacterDamageManagerComponent charDamMan = SCR_CharacterDamageManagerComponent.Cast(ownerCharacter.GetDamageManager());
		if (!charDamMan || charDamMan.GetGroupDamageOverTime(m_eHitZoneGroup, EDamageType.BLEEDING) == 0)
			return false;
		
		SCR_ConsumableItemComponent consumableComponent = GetConsumableComponent(userCharacter);
		if (!consumableComponent)
			return false;
		
		return consumableComponent.GetConsumableType() == EConsumableType.Bandage;
		
		if (charDamMan.GetIsUnconscious())
            return true;	
	}
};

//------------------------------------------------------------------------------------------------

//Overrides the PerformAction to heal the player, remove unconsciousness and remove invincibility.
//it also sets a timer to finish before players get revived.
modded class SCR_HealingUserAction	
{		
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
	{
		ChimeraCharacter userCharacter = ChimeraCharacter.Cast(pUserEntity);
		if (!userCharacter)
			return;		
		
		ChimeraCharacter targetCharacter = ChimeraCharacter.Cast(pOwnerEntity);
		if (!targetCharacter)
			return;
		
		SCR_CharacterControllerComponent userController = SCR_CharacterControllerComponent.Cast(userCharacter.GetCharacterController());
		if (!userController)
			return;
		
		IEntity item = userController.GetAttachedGadgetAtLeftHandSlot();
		if (!item)
			return;
		
		SCR_ConsumableItemComponent consumableComponent = GetConsumableComponent(userCharacter);
		if (!consumableComponent)
			return;
		
		SCR_ConsumableEffectHealthItems consumableEffect = SCR_ConsumableEffectHealthItems.Cast(consumableComponent.GetConsumableEffect());
		if (!consumableEffect)
			return;
			
		TAnimGraphCommand desiredCmd = consumableEffect.GetApplyToOtherAnimCmnd(pOwnerEntity);

		SCR_CharacterControllerComponent targetController = SCR_CharacterControllerComponent.Cast(targetCharacter.GetCharacterController());
		if (targetController && targetController.IsUnconscious())
			desiredCmd = consumableEffect.GetReviveAnimCmnd(pOwnerEntity);
	
		SCR_CharacterDamageManagerComponent targetDamageMan = SCR_CharacterDamageManagerComponent.Cast(targetCharacter.GetDamageManager());
		if (!targetDamageMan)
			return;

		consumableComponent.SetTargetCharacter(pOwnerEntity);
		consumableComponent.GetConsumableEffect().ActivateEffect(pOwnerEntity, pUserEntity, item, new SCR_ConsumableEffectAnimationParameters(desiredCmd, 1, 0.0, consumableEffect.GetApplyToOtherDuraction(), targetDamageMan.FindAssociatedBandagingBodyPart(m_eHitZoneGroup), 0.0, false));
		
		DamageManagerComponent damageManager = targetCharacter.GetDamageManager();
		damageManager.EnableDamageHandling(true);
		targetController.SetUnconscious(false);
		targetDamageMan.FullHeal();
		
		/*GetGame().GetCallqueue().CallLater(FinishRevive, 5000, false, pOwnerEntity);*/
		
	}
	
};	
	
	/*private void FinishRevive(IEntity pOwnerEntity)
    {
        ChimeraCharacter targetCharacter = ChimeraCharacter.Cast(pOwnerEntity);
        if (!targetCharacter)
            return;
        
        SCR_CharacterControllerComponent targetController = SCR_CharacterControllerComponent.Cast(targetCharacter.GetCharacterController());
        if (targetController)
            targetController.SetUnconscious(false);
		
		DamageManagerComponent damageManager = targetCharacter.GetDamageManager();
        damageManager.EnableDamageHandling(true);
		
		SCR_CharacterDamageManagerComponent targetDamageMan = SCR_CharacterDamageManagerComponent.Cast(targetCharacter.GetDamageManager());
		targetDamageMan.FullHeal();
		
	};
};