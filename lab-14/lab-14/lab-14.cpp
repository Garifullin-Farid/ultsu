// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

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
//ÃËÎÁÀËÜÍÛÅ ÏÅÐÅÌÅÍÍÛÅ
int image1_x = 50;
int image1_y = 50;
int type = 0;
int size = 0;
int size1 = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;


    switch (message)
    {
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            image1_x -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            image1_x += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            image1_y -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN:
            image1_y += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x20:
            type++;
            if (type > 4) type = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x51:
            size++;
            if (size >5) size = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x57:
            size1++;
            if (size1 >5) size1 = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        
        }
        
        break;
    case WM_LBUTTONDOWN:
        WORD xPos, yPos;

        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);

        image1_x = xPos;
        image1_y = yPos;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
   
    
        
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        
        int x, y, i, i1;
        x = 0;
        y = 0;
        i = 0;
        do
        {
            x = 0;
            i1 = 0;
            do
            {
                if (type == 0) Image0(hdc, image1_x + x, image1_y + y, RGB(255, 255, 0));
                if (type == 1) Image1(hdc, image1_x + x, image1_y + y, RGB(255, 255, 0));
                if (type == 2) Image2(hdc, image1_x + x, image1_y + y, RGB(0, 255, 0));
                if (type == 3) Image3(hdc, image1_x + x, image1_y + y, RGB(255, 0, 255));
                if (type == 4) Image4(hdc, image1_x + x, image1_y + y, RGB(0, 255, 255));
                x += 50;
                i1++;
            } while (i1 < size1);
            x = 0;
            if (type == 0) Image0(hdc, image1_x + x, image1_y + y, RGB(255, 255, 0));
            if (type == 1) Image1(hdc, image1_x + x, image1_y + y, RGB(255, 255, 0));
            if (type == 2) Image2(hdc, image1_x + x, image1_y + y, RGB(0, 255, 0));
            if (type == 3) Image3(hdc, image1_x + x, image1_y + y, RGB(255, 0, 255));
            if (type == 4) Image4(hdc, image1_x + x, image1_y + y, RGB(0, 255, 255));
            y += 70;
            i++;
        } while (i < size);
        
        
            
        
           
        
          
       
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