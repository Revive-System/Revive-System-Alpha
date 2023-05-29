enum RS_EInstigatorEvent
{
	INCAPACITATED,
	REVIVED
};

[BaseContainerProps(), SCR_BaseContainerCustomTitleEnum(RS_EInstigatorEvent, "m_InstigatorEventKey")]
class RS_InstigatorEventNotificationKeys
{	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(RS_EInstigatorEvent))]
	RS_EInstigatorEvent m_InstigatorEventKey;
	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(ENotification))]
	ENotification m_UnknownOnPlayerNotificationKey;
	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(ENotification))]
	ENotification m_UnknownOnPossessedNotificationKey;
	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(ENotification))]
	ENotification m_PlayerOnPlayerNotificationKey;
	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(ENotification))]
	ENotification m_PlayerOnPossessedNotificationKey;
	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(ENotification))]
	ENotification m_PossessedOnPlayerNotificationKey;
	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(ENotification))]
	ENotification m_PossessedOnPossessedNotificationKey;
	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(ENotification))]
	ENotification m_AIOnPlayerNotificationKey;
	
	[Attribute("0", UIWidgets.SearchComboBox, "", "", ParamEnumArray.FromEnum(ENotification))]
	ENotification m_AIOnPossessedNotificationKey;
};
