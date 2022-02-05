// DISPLAY_SCORE.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_SCORE.h"
#include "DLG_ADD_STUDENT.h"
#include "DLG_STUDENT_INFORMATION.h"

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
	DDX_Control(pDX, IDC_EDIT1, find_content);
	DDX_Control(pDX, IDC_BUTTON1, btn_find);
}

BEGIN_MESSAGE_MAP(DISPLAY_SCORE, CFormView)
	ON_EN_SETFOCUS(IDC_EDIT1, &DISPLAY_SCORE::OnEnSetfocusEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &DISPLAY_SCORE::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &DISPLAY_SCORE::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &DISPLAY_SCORE::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &DISPLAY_SCORE::OnBnClickedButton2)
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
	score_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); //| LVS_EX_CHECKBOXES);

	//score_list.InsertColumn(0, TEXT(""), LVCFMT_CENTER, 23);
	score_list.InsertColumn(0, TEXT("学号"), LVCFMT_CENTER, 150);
	score_list.InsertColumn(1, TEXT("姓名"), LVCFMT_CENTER, 70);
	score_list.InsertColumn(2, TEXT("性别"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(3, TEXT("语文"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(4, TEXT("数学"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(5, TEXT("外语"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(6, TEXT("政治"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(7, TEXT("历史"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(8, TEXT("地理"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(9, TEXT("物理"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(10, TEXT("化学"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(11, TEXT("生物"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(12, TEXT("信计"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(13, TEXT("通计"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(14, TEXT("总分"), LVCFMT_CENTER, 60);


	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	const auto stu_list = app->SIM->return_student_list();
	int cnt = 0;
	for (const auto& i : stu_list)
	{
		score_list.InsertItem(cnt, TEXT("student"));
		const auto member = static_cast<CString>(i.return_username().c_str());
		score_list.SetItemText(cnt, 0, member);
		const auto name = static_cast<CString>(i.return_actual_name().c_str());
		score_list.SetItemText(cnt, 1, name);
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
		score_list.SetItemText(cnt, 2, gender);

		cnt++;
	}

	
	find_content.SetWindowTextW(TEXT("在此输入学号"));
}


void DISPLAY_SCORE::OnEnSetfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	find_content.SetWindowTextW(nullptr);
}


void DISPLAY_SCORE::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString target_num;
	GetDlgItemText(IDC_EDIT1, target_num);
	if (target_num.IsEmpty() || target_num == TEXT("在此输入学号"))
	{
		::MessageBox(nullptr, TEXT("请在左侧文本框中输入要查找的学号！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}

	//遍历
	int i = 0;
	const int line_count = score_list.GetItemCount();
	bool find_flag = false;
	for (; i < line_count; i++)
	{
		const CString num = score_list.GetItemText(i, 0);
		if (num == target_num)
		{
			//清空选择
			for (int j = 0; j < line_count; j++)
			{
				score_list.SetItemState(j, 0, -1);
			}
			//选择
			score_list.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
			score_list.SetFocus();
			score_list.EnsureVisible(i, true);
			find_flag = true;
		}
	}
	if (i == line_count && find_flag == false)
	{
		::MessageBox(nullptr, TEXT("查无此人！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
	}

}


void DISPLAY_SCORE::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	if (app->nCheckId == IDC_RADIO1)
	{
		switch (const auto select = ::MessageBox(nullptr, TEXT("删除后无法撤回，是否继续？"), TEXT("警告"), MB_ICONWARNING | MB_YESNOCANCEL | MB_TASKMODAL); select)
		{
		case IDCANCEL:
		{
			__fallthrough;
		}
		case IDNO:
		{
			return;
		}
		case IDYES:
		{
			if (auto pos = score_list.GetFirstSelectedItemPosition(); pos == nullptr)
			{
				::MessageBox(nullptr, TEXT("没有被选中的项！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			}
			else
			{
				while (pos)
				{
					const auto npos = score_list.GetNextSelectedItem(pos);
					CString name = score_list.GetItemText(npos, 0);
					app->SIM->delete_student(static_cast<std::string>(CW2A(name)));
					score_list.DeleteItem(npos);
					pos = score_list.GetFirstSelectedItemPosition();
				}
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
	else
	{
		::MessageBox(nullptr, TEXT("权限不足！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
	}
}


void DISPLAY_SCORE::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	if (app->nCheckId == IDC_RADIO1)
	{
		DLG_ADD_STUDENT dlg;
		dlg.DoModal();
	}
	else
	{
		::MessageBox(nullptr, TEXT("权限不足！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
	}
}


void DISPLAY_SCORE::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	if (const auto pos = score_list.GetFirstSelectedItemPosition(); pos == nullptr)
	{
		::MessageBox(nullptr, TEXT("没有被选中的项！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
	}
	else
	{
		DLG_STUDENT_INFORMATION dlg;
		dlg.DoModal();
	}

}
