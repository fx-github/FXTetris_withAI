#ifndef __FX_APPLICATION_H__
#define __FX_APPLICATION_H__

#include <string>
#include <windows.h>

#define FX_IDM_RESET 101

class FXApplication
{
private:
	FXApplication()
	{
	}

	//
	//  ����: MyRegisterClass()
	//
	//  Ŀ��: ע�ᴰ���ࡣ
	//
	ATOM MyRegisterClass(HINSTANCE hInstance)
	{
		WNDCLASSEXW wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FXTETRISWITHAI));
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = m_szWindowClass.c_str();
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

		return RegisterClassExW(&wcex);
	}

	//
	//   ����: InitInstance(HINSTANCE, int)
	//
	//   Ŀ��: ����ʵ�����������������
	//
	//   ע��: 
	//
	//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
	//        ��������ʾ�����򴰿ڡ�
	//
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
	{
		m_hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

		HWND hWnd = CreateWindowW(m_szWindowClass.c_str(), m_szTitle.c_str(), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

		if (!hWnd)
		{
			return FALSE;
		}

		ShowWindow(hWnd, nCmdShow);
		UpdateWindow(hWnd);

		return TRUE;
	}

	//
	//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
	//
	//  Ŀ��:    ���������ڵ���Ϣ��
	//
	//  WM_COMMAND  - ����Ӧ�ó���˵�
	//  WM_PAINT    - ����������
	//  WM_DESTROY  - �����˳���Ϣ������
	//
	//
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_COMMAND:
		{
			int wmId = LOWORD(wParam);
			// �����˵�ѡ��: 
			switch (wmId)
			{
			case IDM_ABOUT:
				DialogBox(m_hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				break;
//             case IDM_EXIT:
//                 DestroyWindow(hWnd);
//                 break;
			case FX_IDM_RESET:
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
		break;
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			// TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
			EndPaint(hWnd, &ps);
		}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}

	// �����ڡ������Ϣ�������
	static INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		UNREFERENCED_PARAMETER(lParam);
		switch (message)
		{
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
			{
				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
			break;
		}
		return (INT_PTR)FALSE;
	}

public:
	void init(const std::wstring szTitle, const std::wstring szWindowClass)
	{
		m_szTitle = szTitle;
		m_szWindowClass = szWindowClass;
	}

	int exec(_In_ HINSTANCE hInstance, _In_ int nCmdShow)
	{
		MyRegisterClass(hInstance);

		if (!InitInstance(hInstance, nCmdShow))
		{
			return FALSE;
		}

		ACCEL accels[] = 
		{
			{ FCONTROL | FVIRTKEY, 'R', FX_IDM_RESET},
		};
		int accelsize = sizeof(accels) / sizeof(accels[0]);
		HACCEL hAccelTable = CreateAcceleratorTable(accels, accelsize);

		MSG msg;
		while (GetMessage(&msg, nullptr, 0, 0))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		return (int)msg.wParam;
	}

	static FXApplication * inst()
	{
		static FXApplication instance;
		return &instance;
	}

private:
	std::wstring m_szTitle;
	std::wstring m_szWindowClass;

	static HINSTANCE m_hInst;
};

HINSTANCE FXApplication::m_hInst = nullptr;

#endif // !__FX_APPLICATION_H__
