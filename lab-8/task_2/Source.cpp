// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

// Stored instance handle for use in Win32 API calls such as FindResource
HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindowEx explained:
    // WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        750, 750,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
void drawHome(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(149, 95, 32));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);

    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);

    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);

    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);

   



   

}
void drawTree1(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 450, 525, NULL);
    LineTo(hdc, 525, 450);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);

    MoveToEx(hdc, 475, 450, NULL);
    LineTo(hdc, 525, 400);
    LineTo(hdc, 575, 450);
    LineTo(hdc, 475, 450);

    MoveToEx(hdc, 500, 400, NULL);
    LineTo(hdc, 525, 375);
    LineTo(hdc, 550, 400);
    LineTo(hdc, 500, 400);
}
void drawTree2(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    MoveToEx(hdc, 50, 525, NULL);
    LineTo(hdc, 50, 475);
    LineTo(hdc, 100, 400);

    MoveToEx(hdc, 50, 475, NULL);
    LineTo(hdc, 50, 425);
    LineTo(hdc, 100, 350);

    MoveToEx(hdc, 50, 425, NULL);
    LineTo(hdc, 50, 375);
    LineTo(hdc, 75, 325);

    MoveToEx(hdc, 50, 425, NULL);
    LineTo(hdc, 50, 300);

    MoveToEx(hdc, 50, 475, NULL);
    LineTo(hdc, 0, 400);

    MoveToEx(hdc, 50, 425, NULL);
    LineTo(hdc, 0, 350);

    MoveToEx(hdc, 50, 375, NULL);
    LineTo(hdc, 25, 325);
}
void drawMiniHome(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(149, 95, 32));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 450, 250, NULL);
    LineTo(hdc, 450, 150);
    LineTo(hdc, 500, 100);
    LineTo(hdc, 650, 100);
    LineTo(hdc, 650, 250);

    MoveToEx(hdc, 615, 250, NULL);
    LineTo(hdc, 450, 250);


    MoveToEx(hdc, 550, 150, NULL);
    LineTo(hdc, 500, 100);

    MoveToEx(hdc, 550, 150, NULL);
    LineTo(hdc, 450, 150);

    MoveToEx(hdc, 550, 150, NULL);
    LineTo(hdc, 550, 250);

    MoveToEx(hdc, 550, 150, NULL);
    LineTo(hdc, 650, 150);

    MoveToEx(hdc, 650, 200, NULL);
    LineTo(hdc, 625, 215);
    LineTo(hdc, 625, 265);
    LineTo(hdc, 650, 250);

    MoveToEx(hdc, 650, 200, NULL);
    LineTo(hdc, 615, 200);
    LineTo(hdc, 615, 250);

    MoveToEx(hdc, 525, 175, NULL);
    LineTo(hdc, 475, 175);
    LineTo(hdc, 475, 225);
    LineTo(hdc, 525, 225);
    LineTo(hdc, 525, 175);

    MoveToEx(hdc, 500, 175, NULL);
    LineTo(hdc, 500, 225);
}
int x1,x2,y1,y2;
void drawKust1(HDC hdc) {
    x1 = 250, y1 = 100;
    x2 = 350, y2 = 200;
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 200, 0));
    SelectObject(hdc, hPen);


    do
    {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 12;
    } while (x1 < 500);
}
void drawKust2(HDC hdc){
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(79, 20, 45));
    SelectObject(hdc, hPen);
    x1 = 0, y1 = 250;
    x2 = 100, y2 = 250;
    do
    {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 -= 10;
    } while (x1 <= 100);



    x1 = 100;
    y1 = 50;
    do
    {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 += 10;
    } while (x1 <= 200);
}
void drawZabor(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(45, 21, 189));
    SelectObject(hdc, hPen);

    x1 = 150, y1 = 0;
    x2 = 150, y2 = 100;
    do
    {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 10;
        x2 += 10;
    } while (x1 <= 450);
}
void drawpattern(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(211, 21, 18));
    SelectObject(hdc, hPen);

    x1 = 150, y1 = 400;
    x2 = 200, y2 = 350;
    MoveToEx(hdc, 180, 525, NULL);
    LineTo(hdc, 365, 350);
    do
    {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x2 += 41;
        y1 += 41;
    } while (x2 < 335);
    x1 = 400, y1 = 475;
    x2 = 350, y2 = 525;
    do
    {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x2 -= 41;
        y1 -= 41;
    } while (x2 > 190);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    HPEN hPen;
    switch (message)
    {
    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        
        drawHome(hdc);
        drawMiniHome(hdc);
       
        
        drawKust1(hdc);
        drawKust2(hdc);
        drawZabor(hdc);
        drawpattern(hdc);
        //drawTree1(hdc);
        drawTree2(hdc);
        EndPaint(hWnd, &ps);
        break;


    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}


