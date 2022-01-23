// DISPLAY_RIGHT.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_RIGHT.h"


// DISPLAY_RIGHT

IMPLEMENT_DYNCREATE(DISPLAY_RIGHT, CFormView)

DISPLAY_RIGHT::DISPLAY_RIGHT()
	: CFormView(IDD_DISPLAY_RIGHT)
{

}

DISPLAY_RIGHT::~DISPLAY_RIGHT()
{
}

void DISPLAY_RIGHT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DISPLAY_RIGHT, CFormView)
END_MESSAGE_MAP()


// DISPLAY_RIGHT 诊断

#ifdef _DEBUG
void DISPLAY_RIGHT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAY_RIGHT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAY_RIGHT 消息处理程序
