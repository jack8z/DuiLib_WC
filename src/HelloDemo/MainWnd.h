#pragma once

#include "stdafx.h"
#include "resource.h"

using namespace DuiLib;

class CMainWnd : public WindowImplBase
{
public:
  virtual LPCTSTR GetWindowClassName() const { return _T("MainFrameWnd"); }
  virtual CDuiString GetSkinFile() { return _T("main.xml"); }
  virtual CDuiString GetSkinFolder() { return _T("skin"); }
  virtual UILIB_RESOURCETYPE GetResourceType() const { return UILIB_ZIPRESOURCE; }
  virtual LPCTSTR GetResourceID() const { return MAKEINTRESOURCE(IDR_ZIPRES); }

  virtual void InitWindow();
  virtual void Notify(TNotifyUI &msg);

private:
  CButtonUI *m_pBtnHello;
};
