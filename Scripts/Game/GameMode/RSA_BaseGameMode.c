modded class SCR_BaseGameMode : BaseGameMode
{
	protected ref ScriptInvoker Event_OnControllableIncapacitated = new ScriptInvoker();
	protected ref ScriptInvoker Event_OnControllableRevived = new ScriptInvoker();
	
	ScriptInvoker GetOnControllableIncapacitated()
	{
		return Event_OnControllableIncapacitated;
	};
	
	ScriptInvoker GetOnControllableRevived()
	{
		return Event_OnControllableRevived;
	};
	
	void OnControllableIncapacitated(IEntity entity, IEntity instigator)
	{
		Event_OnControllableIncapacitated.Invoke(entity, instigator);

		foreach (SCR_BaseGameModeComponent comp : m_aAdditionalGamemodeComponents)
		{
			comp.OnControllableIncapacitated(entity, instigator);	
		};
	};
	
	void OnControllableRevived(IEntity entity, IEntity instigator)
	{
		Event_OnControllableRevived.Invoke(entity, instigator);

		foreach (SCR_BaseGameModeComponent comp : m_aAdditionalGamemodeComponents)
		{
			comp.OnControllableRevived(entity, instigator);	
		};
	};
};
