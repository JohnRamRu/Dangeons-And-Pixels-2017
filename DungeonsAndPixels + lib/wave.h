/////////////////////////////////////////////////////////////////////////////////////////////
//wave.h - handle-файл проигрывания wave из ресурса                                        //
//Разработан SHUMSKIY® SOFT Studio 2004-2006                                               //
//Все права защищены!                                                                      //
//Для воспроизведения необходимо использовать строку:                                      //
//         PlayResource(здесь идентификатор ресурса);                                      //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "mmsystem.h"
#include "coredll.lib"


static void PlayResource(LPCTSTR lpszSound)
{
	HRSRC hRes; // resource handle to wave file
 	HGLOBAL hData;
	BOOL bOk = FALSE;
 	if((hRes=::FindResource(AfxGetResourceHandle(),lpszSound,_T("WAVE")))!=NULL&&(hData=::LoadResource(AfxGetResourceHandle(),hRes))!=NULL)
	{
 		//Поиск ресурса и его проигрывание
 		bOk = sndPlaySound((LPCTSTR)::LockResource(hData),SND_MEMORY|SND_SYNC|SND_NODEFAULT);
 		FreeResource(hData);
	}
 	/*if(!bOk)
	{
 		AfxMessageBox("Ошибка! Невозможно проиграть звуковой файл.");
	}*/
}


inline static void PlayResource(UINT nIDS)
{
	PlayResource(MAKEINTRESOURCE(nIDS));
}
