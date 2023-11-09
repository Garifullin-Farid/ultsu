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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    { 
    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        HPEN hPen;
        hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
        SelectObject(hdc, hPen);

        HBRUSH hBrush;
        hBrush = CreateSolidBrush(RGB(255, 128, 67));
        SelectObject(hdc, hBrush);
        RECT rect = { 50, 200, 300, 250 };
        FillRect(hdc, &rect, hBrush);

        MoveToEx(hdc, 100, 200, NULL);
        LineTo(hdc, 150, 150);
        LineTo(hdc, 250, 150);
        LineTo(hdc, 300, 200);

        hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
        SelectObject(hdc, hPen);

        hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 70, 230, 120, 275);

        hPen = CreatePen(PS_SOLID, 7, RGB(128, 0, 0));
        SelectObject(hdc, hPen);

        hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 255, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 225, 230, 275, 275);

        hPen = CreatePen(PS_SOLID, 4, RGB(0,0,0));
        SelectObject(hdc, hPen);

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc,400,200,500,300);

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 415, 125, 485, 200);

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 425, 75, 475, 125);

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 455, 97, 458, 100);

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 440, 97, 443, 100);

        hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 450, 100, NULL);
        LineTo(hdc, 435, 110);
        LineTo(hdc, 450, 105);

        MoveToEx(hdc, 485, 150, NULL);
        LineTo(hdc, 500, 200);

        MoveToEx(hdc, 415, 150, NULL);
        LineTo(hdc, 400, 100);

        hPen = CreatePen(PS_SOLID, 3, RGB(87, 34, 5));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 430, 80, NULL);
        LineTo(hdc, 430, 40);
        LineTo(hdc, 470, 40);
        LineTo(hdc, 470, 80);


        hBrush = CreateSolidBrush(RGB(76, 128, 67));
        SelectObject(hdc, hBrush);
        rect = { 350, 475, 500, 525 };
        FillRect(hdc, &rect, hBrush);

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 350, 500, 400, 550);

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 440, 490, 500, 550);

        hPen = CreatePen(PS_SOLID, 3, RGB(87, 34, 5));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 425, 475, NULL);
        LineTo(hdc, 425, 435);
        LineTo(hdc, 500, 435);
        LineTo(hdc, 500, 475);

        hPen = CreatePen(PS_SOLID, 3, RGB(87, 34, 5));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 370, 475, NULL);
        LineTo(hdc, 370, 450);
        LineTo(hdc, 375, 450);
        LineTo(hdc, 375, 475);

        hBrush = CreateSolidBrush(RGB(87, 34, 5));
        SelectObject(hdc, hBrush);
        rect = { 100, 500, 200, 550 };
        FillRect(hdc, &rect, hBrush);

        hBrush = CreateSolidBrush(RGB(87, 34, 5));
        SelectObject(hdc, hBrush);
        rect = { 90, 490, 210, 510 };
        FillRect(hdc, &rect, hBrush);

        hBrush = CreateSolidBrush(RGB(60, 34, 5));
        SelectObject(hdc, hBrush);
        rect = { 140, 450, 150, 490};
        FillRect(hdc, &rect, hBrush);

        hPen = CreatePen(PS_SOLID, 3, RGB(0, 240, 0));
        SelectObject(hdc, hPen);
        hBrush = CreateSolidBrush(RGB(0, 255, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 120, 400, 175, 460);











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