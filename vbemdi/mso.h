#ifndef _MSO_C7198337_B9A1_45A3_8A8E_45E04ADBAC14_
#define _MSO_C7198337_B9A1_45A3_8A8E_45E04ADBAC14_

// https://documentation.help/MS-Office-VB/ofproLanguageID.htm

//TypeName(MsoAppLanguageID.msoLanguageIDUI) = Long
//Application.LanguageSettings.LanguageID(MsoAppLanguageID.msoLanguageIDUI) returns long (VT_I4)
enum MsoAppLanguageID
{
	msoLanguageIDInstall   = 1, //Install language
	msoLanguageIDUI 	   = 2, //User interface language
	msoLanguageIDHelp = 3, //Help language
	msoLanguageIDExeMode = 4, //Execution mode language
	msoLanguageIDUIPrevious =5  //User interface language used prior to the current user interface language
};


#endif//_MSO_C7198337_B9A1_45A3_8A8E_45E04ADBAC14_
