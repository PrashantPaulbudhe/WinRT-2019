//Headers
#include<windows.h>

//DLL Main
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpvReserve)
{




	switch (dwReason)
	{
		//process specific initializations
	case 1:DLL_PROCESS_ATTACH;
		break;
		//thread speacific initialiazation
	case 2:DLL_THREAD_ATTACH;
		break;
		//thread specific un-intialization
	case 3:DLL_THREAD_DETACH;
		break;
		//proces sepcific un-initialization
	case 4:DLL_PROCESS_DETACH;
		break;
	}
	return(TRUE);
}
extern "C" __declspec(dllexport) int MakeSquare(int iNum)
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










