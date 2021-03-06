// HelloDemo.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "FloatingLayout.h"
#include "MainWnd.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                     // 当前实例
WCHAR szTitle[MAX_LOADSTRING];       // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING]; // 主窗口类名

// 此代码模块中包含的函数的前向声明:
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    CPaintManagerUI::SetInstance(hInstance);                              // 实例句柄与渲染类关联
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); // 指定资源路径

    CMainWnd *pMainWnd = new CMainWnd();								// 生成对象
    pMainWnd->Create(NULL, NULL, UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);	// 创建窗口
    pMainWnd->CenterWindow();											// 居中
    pMainWnd->ShowModal();												// 显示

    delete pMainWnd; // 删除对象

    return 0;
}

// DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
