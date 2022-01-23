// DISPLAYVIEW_LEFT.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAYVIEW_LEFT.h"


// DISPLAYVIEW_LEFT

IMPLEMENT_DYNCREATE(DISPLAYVIEW_LEFT, CFormView)

DISPLAYVIEW_LEFT::DISPLAYVIEW_LEFT()
	: CFormView(IDD_DISPLAYVIEW_LEFT)
{

}

DISPLAYVIEW_LEFT::~DISPLAYVIEW_LEFT()
{
}

void DISPLAYVIEW_LEFT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_show_identity, SHOW_IDENTITY);
}

BEGIN_MESSAGE_MAP(DISPLAYVIEW_LEFT, CFormView)
END_MESSAGE_MAP()


// DISPLAYVIEW_LEFT 诊断

#ifdef _DEBUG
void DISPLAYVIEW_LEFT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAYVIEW_LEFT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAYVIEW_LEFT 消息处理程序
