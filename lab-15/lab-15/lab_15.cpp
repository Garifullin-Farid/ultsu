

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include"images.h"

static TCHAR szWindowClass[] = _T("DesktopApp");


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
        500, 500,
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
//√ÀŒ¡¿À‹Õ€≈ œ≈–≈Ã≈ÕÕ€≈
int image1_x = 50;
int image1_y = 50;
int dx5 = rand() % 10;
int dy5 = rand() % 21 - 10;
struct Image
{
    int x;
    int y;
    int vx;
    int vy;
};

struct Image im1 = { 100,200,10,0};
struct Image im2 = { 400,200,-10,0 };
struct Image im3 = { 250,50, 0,10};
struct Image im4 = { 250,400, 0,-10 };
struct Image im5 = { 250,250, 0,0 };



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;


    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, 1, 500, 0);
        break;
    case WM_TIMER:
        im1.x += im1.vx;
        im1.y += im1.vy;
        im2.x += im2.vx;
        im2.y += im2.vy;
        im3.x += im3.vx;
        im3.y += im3.vy;
        im4.x += im4.vx;
        im4.y += im4.vy;
        

        im5.x += dx5;
        im5.y += dy5;

        InvalidateRect(hWnd, NULL, TRUE);
        break;
    
        
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        Image0(hdc, im1.x, im1.y, RGB(128, 0, 0));
        Image1(hdc, im2.x, im2.y, RGB(128, 128, 0));
        Image2(hdc, im3.x, im3.y, RGB(255, 128, 0));
        Image3(hdc, im4.x, im4.y, RGB(128, 255, 0));
        Image4(hdc, im5.x, im5.y, RGB(255, 128, 0));

      
        EndPaint(hWnd, &ps);
        break;
    

    case WM_DESTROY:
        PostQuitMessage(0);  
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;

    

    }
    
    return 0;
}