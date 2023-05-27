[BaseContainerProps()]
modded class SCR_ConsumableBandage : SCR_ConsumableEffectHealthItems
{
	// Make bandages revive if all bleedings are stopped
	override void ApplyEffect(notnull IEntity target, notnull IEntity user, IEntity item, SCR_ConsumableEffectAnimationParameters animParams)
	{
		super.ApplyEffect(target, user, item, animParams);
		
		ChimeraCharacter targetCharacter = ChimeraCharacter.Cast(target);
		if (!targetCharacter)
			return;
			
		SCR_CharacterControllerComponent targetController = SCR_CharacterControllerComponent.Cast(targetCharacter.GetCharacterController());
		if (!targetController)
			return;
		
		SCR_CharacterDamageManagerComponent targetDamageMan = SCR_CharacterDamageManagerComponent.Cast(targetCharacter.GetDamageManager());
		if (!targetDamageMan)
			return;
		
		// Unit gets revived if no bleeding wound is present
		if (targetController.IsUnconscious() && !targetDamageMan.IsDamagedOverTime(EDamageType.BLEEDING))
		{
			targetDamageMan.FullHeal();
			targetController.SetUnconscious(false);
		};
	};
};
