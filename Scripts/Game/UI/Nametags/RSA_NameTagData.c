/*
modded class SCR_NameTagData : Managed
{
	protected Widget m_wOverlayIcon;
	
	void SCR_NameTagData(ResourceName layout, Widget rootWidget)
	{
		m_wOverlayIcon = m_NameTagWidget.FindAnyWidget("OverlayIcon");
	};
	
	// -- TO DO: Find a better place to do this
	override void UpdateTagPos()
	{
		super.UpdateTagPos();
		m_wOverlayIcon.SetVisible(m_CharController.IsUnconscious());
	};
};
*/