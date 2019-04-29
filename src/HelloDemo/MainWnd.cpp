#include "MainWnd.h"

#include <commdlg.h>
#include <fstream>
#include <sstream>

void CMainWnd::InitWindow()
{
    m_pBtnHello = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnHello")));
}

void CMainWnd::Notify(TNotifyUI &msg)
{
    if (msg.sType == _T("click"))
    {
        CDuiString name = msg.pSender->GetName();
        if (name.CompareNoCase(_T("btnHello")) == 0)
        {	// 点击按钮
            MessageBox(m_hWnd, _T("您好，DuiLib_WC!!!"), _T("温馨提示"), MB_OK);
        }
    }

    return WindowImplBase::Notify(msg);
}
