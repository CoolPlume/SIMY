// DISPLAY_STAFF.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_STAFF.h"


// DISPLAY_STAFF

IMPLEMENT_DYNCREATE(DISPLAY_STAFF, CFormView)

DISPLAY_STAFF::DISPLAY_STAFF()
	: CFormView(IDD_STAFF)
{

}

DISPLAY_STAFF::~DISPLAY_STAFF()
{
}

void DISPLAY_STAFF::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, staff_list);
}

BEGIN_MESSAGE_MAP(DISPLAY_STAFF, CFormView)
END_MESSAGE_MAP()


// DISPLAY_STAFF 诊断

#ifdef _DEBUG
void DISPLAY_STAFF::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAY_STAFF::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAY_STAFF 消息处理程序


void DISPLAY_STAFF::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	staff_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	staff_list.InsertColumn(0, TEXT("职工号"), LVCFMT_CENTER, 150);
	staff_list.InsertColumn(1, TEXT("姓名"), LVCFMT_CENTER, 75);
	staff_list.InsertColumn(2, TEXT("性别"), LVCFMT_CENTER, 50);

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	auto tea_list = app->TIM->return_teacher_list();
	int cnt = 0;
	for (auto& i : tea_list)
	{
		staff_list.InsertItem(cnt, TEXT("teacher"));
		const auto member = static_cast<CString>(i.return_username().c_str());
		staff_list.SetItemText(cnt, 0, member);
		const auto name = static_cast<CString>(i.return_actual_name().c_str());
		staff_list.SetItemText(cnt, 1, name);
		const auto gender_flag = i.return_gender();
		CString gender;
		if (gender_flag == 1)
		{
			gender = TEXT("男");
		}
		else
		{
			gender = TEXT("女");
		}
		staff_list.SetItemText(cnt, 2, gender);

		cnt++;
	}
}
