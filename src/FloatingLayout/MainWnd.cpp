#include "MainWnd.h"

#include <commdlg.h>
#include <fstream>
#include <sstream>

void CMainWnd::InitWindow()
{
    m_pBtnHello = static_cast<CButtonUI *>(m_PaintManager.FindControl(_T("btnHello")));
}

void CMainWnd::Notify(TNotifyUI &msg)
{
    if (msg.sType == _T("click"))
    {
        CDuiString name = msg.pSender->GetName();
        if (name.CompareNoCase(_T("btnView")) == 0)
        { // 点击按钮
            if (m_pFloatingDlg)
            {
                m_pFloatingDlg->ShowWindow(true);
            }
            else
            {
                m_pFloatingDlg = new CFloatingDlg();
                m_pFloatingDlg->Create(NULL, NULL, UI_WNDSTYLE_EX_FRAME, WS_EX_WINDOWEDGE | WS_EX_ACCEPTFILES);
                m_pFloatingDlg->CenterWindow();
                m_pFloatingDlg->ShowWindow(true); //设为非模态框，主窗口退出，悬浮窗自动销毁
            }
        }
        else if (name.CompareNoCase(_T("btnHide")) == 0)
        { // 点击按钮
            if (m_pFloatingDlg)
            {
                m_pFloatingDlg->ShowWindow(false);
            }
        }
    }

    return WindowImplBase::Notify(msg);
}

LRESULT CMainWnd::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    if (m_pFloatingDlg)
    {
        m_pFloatingDlg->ShowWindow(false);
        delete m_pFloatingDlg; // 删除对象
    }

    return WindowImplBase::OnClose(uMsg, wParam, lParam, bHandled);
}
