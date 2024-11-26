#include <windows.h>
#include <memory>
#include <iostream>

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int main()
{
	constexpr int FRAMEBUFFER_WIDTH = 1280, FRAMEBUFFER_HEIGHT = 960;
	constexpr int canvasWidth = FRAMEBUFFER_WIDTH / 80, canvasHeight = FRAMEBUFFER_HEIGHT / 80;

	WNDCLASSEX wc = {
	sizeof(WNDCLASSEX),
	CS_CLASSDC,
	WndProc,
	0L,
	0L,
	GetModuleHandle(NULL),
	NULL,
	NULL,
	NULL,
	NULL,
	L"Game Engine",
	NULL
	};

	RegisterClassEx(&wc);

	RECT rc = { 0, 0, FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		L"Game Engine Window",
		WS_OVERLAPPEDWINDOW,
		100, // 윈도우 좌측 상단의 x 좌표
		100, // 윈도우 좌측 상단의 y 좌표
		rc.right - rc.left, // 윈도우 가로 방향 해상도
		rc.bottom - rc.top, // 윈도우 세로 방향 해상도
		NULL,
		NULL,
		wc.hInstance,
		NULL);

	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);


}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_SIZE:
		// Reset and resize swapchain
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;
	case WM_MOUSEMOVE:
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONUP:
		break;
	case WM_KEYDOWN:
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}

	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}