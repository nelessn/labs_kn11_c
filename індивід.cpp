#include <windows.h>#include <string.h>
HWND hwndButton1;
HWND hwndButton2;HWND hwndButton3;
HWND hwndButton4;HWND hwndButton5;
HWND hwndButton6;HWND hwndInfo;
HWND hwndColor;HBRUSH hBrush;
void RecommendPhone(HWND hwndInfo, int phoneType) {
    char recommendation[256] = "";
    switch (phoneType) {        case 1:
            strcat(recommendation, "We recommend iphone for good camera\r\n");            break;
        case 2:            strcat(recommendation, "We recommend samsung for long-term \r\n");
            break;        case 3:
            strcat(recommendation, "We recommend poko for cheapness\r\n");            break;
        case 4:            strcat(recommendation, "We recommend xiaomi for good picture\r\n");
            break;
    }
    char currentText[4096];    GetWindowText(hwndInfo, currentText, sizeof(currentText));
    strcat(currentText, recommendation);    SetWindowText(hwndInfo, currentText);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {    switch (msg) {
        case WM_CREATE:            hwndButton1 = CreateWindowEx(0, "BUTTON", "good camera",
                                         WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,                        20, 20, 100, 25, hwnd, (HMENU)1, NULL, NULL);
            hwndButton2 = CreateWindowEx(0, "BUTTON", "long-term",
                                         WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,                        20, 50, 100, 25, hwnd, (HMENU)2, NULL, NULL);
            hwndButton3 = CreateWindowEx(0, "BUTTON", "cheap",
                                         WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,                        20, 80, 100, 25, hwnd, (HMENU)3, NULL, NULL);
            hwndButton4 = CreateWindowEx(0, "BUTTON", "good pictures",
                                         WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,                        20, 110, 100, 25, hwnd, (HMENU)4, NULL, NULL);


            hwndInfo = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER,                         20, 200, 580, 250, hwnd, NULL, NULL, NULL);
            // Створення кнопок для машини
            CreateWindow("STATIC", "Choose ROM:", WS_VISIBLE | WS_CHILD,                         150, 20, 120, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("BUTTON", "256gb", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                         150, 50, 100, 20, hwnd, (HMENU)5, NULL, NULL);
            CreateWindow("BUTTON", "128gb", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,                         150, 80, 100, 20, hwnd, (HMENU)6, NULL, NULL);
            CreateWindow("BUTTON", "64gb", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                         150, 110, 100, 20, hwnd, (HMENU)7, NULL, NULL);
            CreateWindow("BUTTON", "32gb", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,                         150, 140, 100, 20, hwnd, (HMENU)8, NULL, NULL);
            // Створення кнопок для вибору коробки передач
            CreateWindow("STATIC", "Choose RAM:", WS_VISIBLE | WS_CHILD,                         280, 20, 160, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("BUTTON", "16gb", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         280, 50, 100, 25, hwnd, (HMENU)9, NULL, NULL);
            CreateWindow("BUTTON", "8gb", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,                         280, 80, 100, 25, hwnd, (HMENU)10, NULL, NULL);
            CreateWindow("BUTTON", "6gb", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,                     280, 110, 100, 25, hwnd, (HMENU)11, NULL, NULL);
            // Створення для кольору
            CreateWindow("STATIC", "Choose color:", WS_VISIBLE | WS_CHILD,
                         420, 20, 120, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("BUTTON", "Black", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,                         420, 50, 100, 25, hwnd, (HMENU)12, NULL, NULL);
            CreateWindow("BUTTON", "White", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         420, 80, 100, 25, hwnd, (HMENU)13, NULL, NULL);
            CreateWindow("BUTTON", "Red", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,                         420, 110, 100, 25, hwnd, (HMENU)14, NULL, NULL);
            CreateWindow("BUTTON", "Blue", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         420, 140, 100, 25, hwnd, (HMENU)15, NULL, NULL);
            // Створення відображення вибору
                       hwndInfo = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER,    20, 200, 580, 250, hwnd, NULL, NULL, NULL);

        case WM_CTLCOLORBTN: {            HDC hdc = (HDC)wParam;
            return (INT_PTR)hBrush;
        }
        case WM_ERASEBKGND: {
            HDC hdc = (HDC)wParam;            RECT rect;
            GetClientRect(hwnd, &rect);            FillRect(hdc, &rect, hBrush);
            return (LRESULT)1;        }
        case WM_COMMAND: {
            char buffer[256];
            switch (LOWORD(wParam)) {     case 1:
                    strcpy(buffer, "You chose good camera<3\r\n");
                    RecommendPhone(hwndInfo, 1);
                    break;                case 2:
                    strcpy(buffer, "You chose long-term<3\r\n");
                    RecommendPhone(hwndInfo, 2);
                    break;                case 3:
                    strcpy(buffer, "You chose cheapness\r\n");
                    RecommendPhone(hwndInfo, 3);
                    break;                case 4:
                    strcpy(buffer, "You chose good picture\r\n");
                    RecommendPhone(hwndInfo, 4);
                    break;                case 5:
                    strcpy(buffer, "You chose 256gb\r\n");
                    break;               case 6:
                    strcpy(buffer, "You chose 128gb\r\n");
                    break;                case 7:
                    strcpy(buffer, "You chose 64gb<3\r\n");
                    break;                case 8:
                    strcpy(buffer, "You chose 32gb\r\n");
                    break;                case 9:
                    strcpy(buffer, "You chose 16gb<3\r\n");
                    break;                case 10:
                    strcpy(buffer, "You chose 8gb<3\r\n");
                    break;                case 11:
                    strcpy(buffer, "You chose 6gb\r\n");
                    break;                case 12:
                    strcpy(buffer, "You chose black color<3\r\n");
                    break;                case 13:
                    strcpy(buffer, "You chose white color<3\r\n");
                    break;                case 14:
                    strcpy(buffer, "You chose red color<3\r\n");
                    break;                case 15:
                    strcpy(buffer, "You chose blue color<3\r\n");
                    break;                default:
                    strcpy(buffer, "");
                    break;
            }
            char currentText[4096];
            GetWindowText(hwndInfo, currentText, sizeof(currentText));            strcat(currentText, buffer);
            SetWindowText(hwndInfo, currentText);        }
            break;
        case WM_CLOSE:            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:            PostQuitMessage(0);
            break;
        default:            return DefWindowProc(hwnd, msg, wParam, lParam);
    }    return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;
    wc.cbSize = sizeof(WNDCLASSEX);    wc.style = 0;
    wc.lpfnWndProc = WndProc;    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);    wc.lpszMenuName = NULL;
    wc.lpszClassName = "WindowClass";    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);        return 0;
    }
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "Phone Selection System",
                          WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
    if (hwnd == NULL) {        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {        TranslateMessage(&Msg);
        DispatchMessage(&Msg);    }
    return Msg.wParam;}
