//Headers
#include<windows.h>
#include "MyMath.h"

//Global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declaration
	WNDCLASSEX wndclass;	//wndclass object created
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("Prashant's1stWindow");
	//Code
	//Initialization of WNDCLASSEX
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbWndExtra = 0;
	wndclass.cbClsExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register above class
	RegisterClassEx(&wndclass);

	//Creat Window
	hwnd = CreateWindow(szAppName,
		TEXT("Prashant's First Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//Message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Code
	//Varible declaration
	HINSTANCE hDLL = NULL;		//dll is null
	typedef int(*MakeSquarefn)(int);
	MakeSquarefn pfn = NULL;
	int i=5,j=0;
	TCHAR str[255]; 

	switch (iMsg)
	{
		case WM_CREATE:
		hDLL = LoadLibrary(TEXT("MyMath.dll"));		//expcititly adding dll
		//here there error checking for if hdll=null
		pfn = (MakeSquarefn)GetProcAddress(hDLL, "MakeSquare");
		j = pfn(i);		//function calling by its address
		wsprintf(str, TEXT("Square of %d is:%d"), i, j);
		MessageBox(hwnd, str, TEXT("Press OK to Continue..."), MB_OK);
		break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		}
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}


