//Progarm:To implement DLL by using Defination module
//headers
#include<windows.h>

//DLLMain
BOOL DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpvReserve)
{


	switch (dwReason)
	{
		//process specific initializaton
	case 1:DLL_PROCESS_ATTACH;
		break;
		//thread specific initialization
	case 2:DLL_THREAD_ATTACH;
		break;
		//thread specific un-initialization
	case 3:DLL_THREAD_DETACH;
		break;
		//process specific un-initialization
	case 4:DLL_PROCESS_DETACH;
		break;
	}
	return(TRUE);

}
extern "C" int MakeSquare(int iNum)
{
		return(iNum*iNum);	
}
extern "C" BOOL IsNumberNegative(int iNum)
{
	if (iNum < 0)
		return(TRUE);
	else
		return(FALSE);
}

