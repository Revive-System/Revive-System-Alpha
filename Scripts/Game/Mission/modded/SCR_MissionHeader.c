modded class SCR_MissionHeader : MissionHeader
{
	[Attribute(defvalue: "0.56", uiwidget: UIWidgets.EditBox, desc: "A global bleeding rate multiplier. The higher the value, the faster entities will bleed to death.")]
	float m_fBleedingRate;
	
	[Attribute(defvalue: "1", uiwidget: UIWidgets.EditBox, desc: "A global multiplier affecting how fast entities will recover health and blood levels. The higher the value, the faster the regeneration.")]
	float m_fHealthAndBloodRegenerationRate;
};
