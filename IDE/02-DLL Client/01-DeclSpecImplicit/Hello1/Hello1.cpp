//Headers
#include<windows.h>

#include "MyMath.h"


//Global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#pragma comment(lib,"MyMath.lib")

//WinMain 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declaration
	WNDCLASSEX wndclass;	//wndclass object created
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("Prashant's 1st Window");
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
	//Local variable declaration and initialization
	int iNum = 5, iSquareOfNum;
	TCHAR str[255];


	//Code
	switch (iMsg)
	{
	case WM_CREATE:
		iSquareOfNum = MakeSquare(iNum);
		wsprintf(str, TEXT("Square of %d is %d:"), iNum, iSquareOfNum);
		MessageBox(hwnd, str, TEXT("Press OK to continue.."), MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);


	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}





