//FXTetris_withAI.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "resource.h"
#include "fx_application.h"
#include "fx_point.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此放置代码。
	FXApplication::inst()->init(L"FX Tetris", L"FX_TETRIS_WITH_AI");

	FXPoint a(1, 1);
	FXPoint b(2, 3);
	a += b;
	FXPoint c = a + b;

    return FXApplication::inst()->exec(hInstance, nCmdShow);
}

