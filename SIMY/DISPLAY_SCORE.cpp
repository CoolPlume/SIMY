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

	score_list.InsertColumn(0, _T(""), LVCFMT_CENTER, 23);
	score_list.InsertColumn(1, _T("学号"), LVCFMT_CENTER, 150);
	score_list.InsertColumn(2, _T("姓名"), LVCFMT_CENTER, 70);
	score_list.InsertColumn(3, _T("性别"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(4, _T("语文"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(5, _T("数学"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(6, _T("外语"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(7, _T("政治"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(8, _T("历史"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(9, _T("地理"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(10, _T("物理"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(11, _T("化学"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(12, _T("生物"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(13, _T("信计"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(14, _T("通计"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(15, _T("总分"), LVCFMT_CENTER, 60);


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
