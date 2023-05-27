modded class SCR_GameModeHealthSettings : ScriptComponent
{	
	[Attribute(defvalue: "300", uiwidget: UIWidgets.EditBox, desc: "How long it takes in seconds for an unconscious unit to bleed out")]
	protected float m_fUnconsciousBleedoutDuration;

	float GetUnconsciousBleedoutDuration()
	{
		SCR_MissionHeader header = SCR_MissionHeader.Cast(GetGame().GetMissionHeader());
		
		if (!header)
			return m_fUnconsciousBleedoutDuration;
		
		return header.m_fUnconsciousBleedoutDuration;
	};
};
