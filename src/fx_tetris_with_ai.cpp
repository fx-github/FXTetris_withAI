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

	fx::point a(1, 1);
	a.rotate_self(90);
	fx::point b(2, 0);
	b.rotate_self(-90);
	a += b;
	fx::point c = a + b;
	c.rotate_self(180);
	c.rotate(180);

    return FXApplication::inst()->exec(hInstance, nCmdShow);
}

