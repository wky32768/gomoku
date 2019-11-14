#include <bits/stdc++.h>
#include <windows.h>
#include <tchar.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "sxdakcsp"

HDC g_hdc=NULL,g_mdc=NULL;
HPEN g_hPen[7];
HBRUSH g_hBrush[7];
int g_iPenStyle[7]={PS_SOLID,PS_DASH,PS_DOT,PS_DASHDOT,PS_DASHDOTDOT,PS_NULL,PS_INSIDEFRAME};
int g_iBrushStyle[6]={HS_VERTICAL,HS_HORIZONTAL,HS_CROSS,HS_DIAGCROSS,HS_FDIAGONAL,HS_BDIAGONAL};
HBITMAP g_hBitmap=NULL;

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);
BOOL Game_Init(HWND hwnd);
void Game_Paint(HWND hwnd);
BOOL Game_CleanUp(HWND hwnd);

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam) {
	PAINTSTRUCT paintStruct;
	switch(message) {
		case WM_PAINT:
			g_hdc=BeginPaint(hwnd,&paintStruct);
			Game_Paint(hwnd);
			EndPaint(hwnd,&paintStruct);
			ValidateRect(hwnd,NULL);
			break;
		case WM_KEYDOWN:
			if(wParam==VK_ESCAPE) DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			Game_CleanUp(hwnd);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}


BOOL Game_Init(HWND hwnd) {
	g_hdc=GetDC(hwnd);
	
//	For(i,0,6) {//»­Ë¢ 
//		g_hPen[i]=CreatePen(g_iPenStyle[i],1,RGB(rand()%256,rand()%256,rand()%256));
//		if(i==6) g_hBrush[i]=CreateSolidBrush(RGB(rand()%256,rand()%256,rand()%256));
//		else g_hBrush[i]=CreateHatchBrush(g_iBrushStyle[i],RGB(rand()%256,rand()%256,rand()%256));	
//	}

	g_hBitmap=(HBITMAP)LoadImage(NULL,"sxd.bmp",IMAGE_BITMAP,800,600,LR_LOADFROMFILE);
	g_mdc=CreateCompatibleDC(g_hdc);

	Game_Paint(hwnd);
	ReleaseDC(hwnd,g_hdc); 
	return 1;
}

void Game_Paint(HWND hwnd) {
//	int y=0;
//	For(i,0,6) {
//		y=(i+1)*70;
//		SelectObject(g_hdc,g_hPen[i]);
//		MoveToEx(g_hdc,30,y,NULL);
//		LineTo(g_hdc,100,y);
//	}
//	int xx1=120,xx2=190;
//	For(i,0,6) {
//		SelectObject(g_hdc,g_hBrush[i]);
//		Rectangle(g_hdc,xx1,70,xx2,y);
//		xx1+=90,xx2+=90;
//	}

	HFONT hFont=CreateFont(30,0,0,0,0,0,0,0,GB2312_CHARSET,0,0,0,0,"ÉñÏÉµÏ");
	SelectObject(g_hdc,hFont);
	SetBkMode(g_hdc,TRANSPARENT);
	
	char tt[]="Gomoku By wky32768";
	SetTextColor(g_hdc,RGB(rand()%256,rand()%256,rand()%256));
	TextOut(g_hdc,30,150,tt,strlen(tt));


	char t[]="csp2019RP++";
	SetTextColor(g_hdc,RGB(rand()%256,rand()%256,rand()%256));
	TextOut(g_hdc,50,250,t,strlen(t));
	DeleteObject(hFont);
	
	SelectObject(g_mdc,g_hBitmap);
	BitBlt(g_hdc,0,0,WINDOW_WIDTH,WINDOW_HEIGHT,g_mdc,0,0,SRCCOPY);
	
}

BOOL Game_CleanUp(HWND hwnd) {
	For(i,0,6) {
		DeleteObject(g_hPen[i]);
		DeleteObject(g_hBrush[i]);	
	}
//	DeleteObject(g_hBitmap);
//	DeleteDC(g_mdc);
	
	return 1;
}





int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	srand((int)time(0));
	
	WNDCLASSEX wndClass;
	memset(&wndClass,0,sizeof wndClass);
	wndClass.cbSize=sizeof(WNDCLASSEX);
	wndClass.style=CS_HREDRAW|CS_VREDRAW;
	wndClass.lpfnWndProc=WndProc;
	wndClass.cbClsExtra=0;
	wndClass.cbWndExtra=0;
	wndClass.hInstance=hInstance;
	wndClass.hIcon=(HICON)::LoadImage(NULL,("icon.ico"),IMAGE_ICON,0,0,LR_DEFAULTSIZE|LR_LOADFROMFILE);
	wndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground=(HBRUSH)(WHITE_BRUSH);
	wndClass.lpszMenuName=NULL;
	wndClass.lpszClassName="sxdakking";
	
	if(!RegisterClassEx(&wndClass)) return -1;
	
	HWND hwnd=CreateWindowEx(WS_EX_CLIENTEDGE,"sxdakking",WINDOW_TITLE,
	WS_VISIBLE|WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,WINDOW_WIDTH,
	WINDOW_HEIGHT,NULL,NULL,hInstance,NULL);
	
	MoveWindow(hwnd,250,80,WINDOW_WIDTH,WINDOW_HEIGHT,1);
	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);
	
	MSG msg;
	while(msg.message!=WM_QUIT) {
		if(PeekMessage(&msg,0,0,0,PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);	
		}
	}
	
	UnregisterClass("sxdakking",wndClass.hInstance);
	
	return 0;
}
