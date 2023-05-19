modded class SCR_MissionHeader : MissionHeader
{
	[Attribute(defvalue: "300", uiwidget: UIWidgets.EditBox, desc: "How long it takes in seconds for an unconscious unit to bleed out")]
	float m_fUnconsciousBleedoutDuration;
}