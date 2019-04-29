#include "FloatingDlg.h"

#include <commdlg.h>
#include <fstream>
#include <sstream>

void CFloatingDlg::InitWindow()
{
    //加入WS_EX_LAYERED扩展属性
    LONG styleValue = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
    styleValue &= ~(WS_EX_APPWINDOW); //当窗口可见时将一个顶层窗口放置在任务栏上
    styleValue |= WS_EX_TOOLWINDOW;   //工具条窗口样式
    SetWindowLong(m_hWnd, GWL_EXSTYLE, styleValue);

    m_pBtnHello = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnHello")));

    ::SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); //窗口置顶
}

void CFloatingDlg::Notify(TNotifyUI &msg)
{
    if (msg.sType == _T("click"))
    {
        CDuiString name = msg.pSender->GetName();
        if (name.CompareNoCase(_T("btnView")) == 0)
        { // 点击按钮
            //MessageBox(m_hWnd, _T("您好，即将显示浮窗!!!"), _T("温馨提示"), MB_OK);
        }
        else if (name.CompareNoCase(_T("btnHide")) == 0)
        { // 点击按钮
            //MessageBox(m_hWnd, _T("您好，即将关闭浮窗!!!"), _T("温馨提示"), MB_OK);
        }
    }

    return WindowImplBase::Notify(msg);
}
