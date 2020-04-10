/////////////////////////////////////////////////////////////////////////////////////////////
//wave.h - handle-���� ������������ wave �� �������                                        //
//���������� SHUMSKIY� SOFT Studio 2004-2006                                               //
//��� ����� ��������!                                                                      //
//��� ��������������� ���������� ������������ ������:                                      //
//         PlayResource(����� ������������� �������);                                      //
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
 		//����� ������� � ��� ������������
 		bOk = sndPlaySound((LPCTSTR)::LockResource(hData),SND_MEMORY|SND_SYNC|SND_NODEFAULT);
 		FreeResource(hData);
	}
 	/*if(!bOk)
	{
 		AfxMessageBox("������! ���������� ��������� �������� ����.");
	}*/
}


inline static void PlayResource(UINT nIDS)
{
	PlayResource(MAKEINTRESOURCE(nIDS));
}
