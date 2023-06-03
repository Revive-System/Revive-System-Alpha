modded class SCR_GameModeHealthSettings : ScriptComponent
{	
	[Attribute("1", desc: "Scenario header setting will overwrite these values.")];
	protected bool m_bAllowHeaderSettings;
	
	override void OnPostInit(IEntity owner)
	{
		SCR_MissionHeader header = SCR_MissionHeader.Cast(GetGame().GetMissionHeader());
		
		if (m_bAllowHeaderSettings && header)
		{
			m_fDOTScale = header.m_fBleedingRate;
			m_fRegenScale = header.m_fHealthAndBloodRegenerationRate;
		};
	};
};
