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
	DDX_Control(pDX, IDC_LIST1, score_list);
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


void DISPLAY_SCORE::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	score_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);

	score_list.InsertColumn(0, _T("选择"), LVCFMT_CENTER, 45);
	score_list.InsertColumn(1, _T("学号"), LVCFMT_CENTER, 150);
	score_list.InsertColumn(2, _T("姓名"), LVCFMT_CENTER, 70);
	score_list.InsertColumn(3, _T("性别"), LVCFMT_CENTER, 50);

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	const auto stu_list = app->SIM->return_student_list();
	int cnt = 0;
	for (const auto& i : stu_list)
	{
		score_list.InsertItem(cnt, NULL);
		const auto member = static_cast<CString>(i.return_username().c_str());
		score_list.SetItemText(cnt, 1, member);
		const auto name = static_cast<CString>(i.return_actual_name().c_str());
		score_list.SetItemText(cnt, 2, name);
		const auto gender_flag = i.return_gender();
		CString gender;
		if(gender_flag==1)
		{
			gender = TEXT("男");
		}
		else
		{
			gender = TEXT("女");
		}
		score_list.SetItemText(cnt, 3, gender);

		cnt++;
	}

	

}
