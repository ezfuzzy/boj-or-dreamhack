#include <windows.h>
#include <iostream>
using namespace std;

// 콜백 함수 선언
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam);

int main() {
    // 콘솔창에 출력
    cout << "Press any key or click the mouse to see the input...\n";

    // 키보드 및 마우스 후킹
    HHOOK hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
    HHOOK hMouseHook = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, NULL, 0);

    if (!hKeyboardHook || !hMouseHook) {
        std::cerr << "Failed to set hooks!" << '\n';
        return 1;
    }

    // 메시지 루프 실행
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // 후크 해제
    UnhookWindowsHookEx(hKeyboardHook);
    UnhookWindowsHookEx(hMouseHook);

    return 0;
}

// 키보드 후크 콜백 함수
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT *pKeyboard = (KBDLLHOOKSTRUCT*)lParam;
        switch (wParam) {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
                cout << "Key Pressed: " << pKeyboard->vkCode << '\n';
                break;
            case WM_KEYUP:
            case WM_SYSKEYUP:
                cout << "Key Released: " << pKeyboard->vkCode << '\n';
                break;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// 마우스 후크 콜백 함수
LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        MSLLHOOKSTRUCT *pMouse = (MSLLHOOKSTRUCT*)lParam;
        switch (wParam) {
            case WM_LBUTTONDOWN:
                cout << "Left Button Down at (" << pMouse->pt.x << ", " << pMouse->pt.y << ")\n";
                break;
            case WM_LBUTTONUP:
                cout << "Left Button Up at (" << pMouse->pt.x << ", " << pMouse->pt.y << ")\n";
                break;
            case WM_RBUTTONDOWN:
                cout << "Right Button Down at (" << pMouse->pt.x << ", " << pMouse->pt.y << ")\n";
                break;
            case WM_RBUTTONUP:
                cout << "Right Button Up at (" << pMouse->pt.x << ", " << pMouse->pt.y << ")\n";
                break;
            case WM_MOUSEMOVE:
                cout << "Mouse Move at (" << pMouse->pt.x << ", " << pMouse->pt.y << ")\n";
                break;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
