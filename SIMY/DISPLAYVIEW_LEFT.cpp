// DISPLAYVIEW_LEFT.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAYVIEW_LEFT.h"


// DISPLAYVIEW_LEFT

IMPLEMENT_DYNCREATE(DISPLAYVIEW_LEFT, CFormView)

DISPLAYVIEW_LEFT::DISPLAYVIEW_LEFT()
	: CFormView(IDD_DISPLAYVIEW_LEFT)
	, IDC_TEST(_T(""))
{

}

DISPLAYVIEW_LEFT::~DISPLAYVIEW_LEFT()
{
}

void DISPLAYVIEW_LEFT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_show_identity, SHOW_IDENTITY);
	DDX_Text(pDX, IDC_EDIT1, IDC_TEST);
	DDX_Control(pDX, IDC_TREE1, navigation);
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


void DISPLAYVIEW_LEFT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	CString identity;
	CString name;

	switch (app->nCheckId)
	{
	case IDC_RADIO1:
	{
		identity = "管理员";
		//name = app->AIM->return_currently_logged_in_administrator().return_nick_name();
		break;
	}
	case IDC_RADIO2:
	{
		identity = "教师";
		break;
	}
	case IDC_RADIO3:
	{
		identity = "学生";
		break;
	}
	default:
	{
		identity = "未知";
		break;
	}
	}

	SetDlgItemText(IDC_show_identity, identity);



	UpdateData(false);

}


void DISPLAYVIEW_LEFT::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	// TODO: 在此添加专用代码和/或调用基类

	CFormView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
