// DISPLAY_SCORE.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_SCORE.h"


// DISPLAY_SCORE

IMPLEMENT_DYNCREATE(DISPLAY_SCORE, CFormView)

DISPLAY_SCORE::DISPLAY_SCORE()
	: CFormView(IDD_SCORE)
{

}

DISPLAY_SCORE::~DISPLAY_SCORE()
{
}

void DISPLAY_SCORE::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DISPLAY_SCORE, CFormView)
END_MESSAGE_MAP()


// DISPLAY_SCORE 诊断

#ifdef _DEBUG
void DISPLAY_SCORE::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAY_SCORE::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAY_SCORE 消息处理程序
