// CSelectView.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "CSelectView.h"


// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CFormView)

CSelectView::CSelectView()
	: CFormView(IDD_SelectView)
{

}

CSelectView::~CSelectView()
{
}

void CSelectView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSelectView, CFormView)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序
