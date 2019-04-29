#pragma once

#include "stdafx.h"
#include "resource.h"

using namespace DuiLib;

class CFloatingDlg : public WindowImplBase
{
public:
  virtual LPCTSTR GetWindowClassName() const { return _T("FloatingDlgWnd"); }
  virtual CDuiString GetSkinFile() { return _T("floating_dlg.xml"); }
  virtual CDuiString GetSkinFolder() { return _T("skin"); }
  virtual UILIB_RESTYPE GetResourceType() const { return UILIB_ZIPRESOURCE; }
  virtual LPCTSTR GetResourceID() const { return MAKEINTRESOURCE(IDR_ZIPRES); }

  virtual void InitWindow();
  virtual void Notify(TNotifyUI &msg);

private:
  CButtonUI *m_pBtnHello;
};
