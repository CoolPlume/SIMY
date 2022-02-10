// DLG_CHANGE_SCORE.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "afxdialogex.h"
#include "DLG_CHANGE_SCORE.h"

#include "DISPLAY_SCORE.h"


// DLG_CHANGE_SCORE 对话框

IMPLEMENT_DYNAMIC(DLG_CHANGE_SCORE, CDialogEx)

DLG_CHANGE_SCORE::DLG_CHANGE_SCORE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHANGE_SCORE, pParent)
	, chinese(0)
	, mathematics(0)
	, foreign_language(0)
	, choise1(0)
	, choise2(0)
	, choise3(0)
	, choise4(0)
{

}

DLG_CHANGE_SCORE::~DLG_CHANGE_SCORE()
{
}

void DLG_CHANGE_SCORE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, chinese);
	DDX_Text(pDX, IDC_EDIT3, mathematics);
	DDX_Text(pDX, IDC_EDIT2, foreign_language);
	DDX_Text(pDX, IDC_EDIT4, choise1);
	DDX_Text(pDX, IDC_EDIT6, choise2);
	DDX_Text(pDX, IDC_EDIT7, choise3);
	DDX_Text(pDX, IDC_EDIT8, choise4);
}


BEGIN_MESSAGE_MAP(DLG_CHANGE_SCORE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_CHANGE_SCORE::OnBnClickedButton1)
END_MESSAGE_MAP()


// DLG_CHANGE_SCORE 消息处理程序


BOOL DLG_CHANGE_SCORE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	const auto dlg = dynamic_cast<DISPLAY_SCORE*>(app->child_window->GetPane(0, 1));
	auto pos = dlg->score_list.GetFirstSelectedItemPosition();
	const auto npos = dlg->score_list.GetNextSelectedItem(pos);
	const CString name = dlg->score_list.GetItemText(npos, 0);
	const student stu = *(app->SIM->find_student(static_cast<std::string>(CW2A(name))));
	now_stu = app->SIM->find_student(static_cast<std::string>(CW2A(name)));
	CString choise[3];
	int cnt = 0;
	const bool politics_flag = now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::politics));
	const bool history_flag = now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::history));
	const bool geography_flag = now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::geography));
	const bool physics_flag = now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::physics));
	const bool chemical_flag = now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::chemical));
	const bool biology_flag = now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::biology));
	const bool technology_flag = now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::information_technology));

	if (politics_flag)
		choise[cnt++] = TEXT("政治：");
	if (history_flag)
		choise[cnt++] = TEXT("历史：");
	if (geography_flag)
		choise[cnt++] = TEXT("地理：");
	if (physics_flag)
		choise[cnt++] = TEXT("物理：");
	if (chemical_flag)
		choise[cnt++] = TEXT("化学：");
	if (biology_flag)
		choise[cnt++] = TEXT("生物：");
	if (!technology_flag)
	{
		reinterpret_cast<CEdit*>(GetDlgItem(IDC_CHOISE4)->ShowWindow(false));
		reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT8)->ShowWindow(false));

	}
	else
	{
		choise[cnt++] = TEXT("信计：");
		SetDlgItemText(IDC_CHOISE4, TEXT("通计："));
	}
	SetDlgItemText(IDC_CHOISE1, choise[0]);
	SetDlgItemText(IDC_CHOISE2, choise[1]);
	SetDlgItemText(IDC_CHOISE3, choise[2]);

	if (cnt != 3)
	{
		::MessageBox(nullptr, TEXT("非法选科"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
		EndDialog(0);
		return true;
	}

	chinese = now_stu->CIM.return_course_results(static_cast<int>(course_Type::chinese));
	mathematics = now_stu->CIM.return_course_results(static_cast<int>(course_Type::mathematics));
	foreign_language = now_stu->CIM.return_course_results(static_cast<int>(course_Type::foreign_language));
	cnt = 0;
	if (politics_flag)
	{
		choise1 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::politics));
		cnt++;
	}
	if (history_flag)
	{
		switch (cnt++)
		{
		case 0:
		{
			choise1 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::history));
			break;
		}
		case 1:
		{
			choise2 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::history));
			break;
		}
		case 2:
		{
			choise3 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::history));
			break;
		}
		}
	}
	if (geography_flag)
	{
		switch (cnt++)
		{
		case 0:
		{
			choise1 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::geography));
			break;
		}
		case 1:
		{
			choise2 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::geography));
			break;
		}
		case 2:
		{
			choise3 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::geography));
			break;
		}
		}
	}
	if (physics_flag)
	{
		switch (cnt++)
		{
		case 0:
		{
			choise1 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::physics));
			break;
		}
		case 1:
		{
			choise2 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::physics));
			break;
		}
		case 2:
		{
			choise3 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::physics));
			break;
		}
		}
	}
	if (chemical_flag)
	{
		switch (cnt++)
		{
		case 0:
		{
			choise1 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::chemical));
			break;
		}
		case 1:
		{
			choise2 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::chemical));
			break;
		}
		case 2:
		{
			choise3 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::chemical));
			break;
		}
		}
	}
	if (biology_flag)
	{
		switch (cnt++)
		{
		case 0:
		{
			choise1 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::biology));
			break;
		}
		case 1:
		{
			choise2 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::biology));
			break;
		}
		case 2:
		{
			choise3 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::biology));
			break;
		}
		}
	}
	if (technology_flag)
	{
		choise3= now_stu->CIM.return_course_results(static_cast<int>(course_Type::information_technology));
		choise4 = now_stu->CIM.return_course_results(static_cast<int>(course_Type::common_technology));
	}

	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DLG_CHANGE_SCORE::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	OnBnClickedButton1();
	//CDialogEx::OnOK();
}


void DLG_CHANGE_SCORE::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (chinese > main_subject_full_score ||
		mathematics > main_subject_full_score ||
		foreign_language > main_subject_full_score ||
		choise1 > associate_subjects_full_score ||
		choise2 > associate_subjects_full_score)
	{
		::MessageBox(nullptr, TEXT("非法成绩！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
		return;
	}

	CString cho1, cho2, cho3, cho4;
	GetDlgItemText(IDC_CHOISE1, cho1);
	GetDlgItemText(IDC_CHOISE2, cho2);
	GetDlgItemText(IDC_CHOISE3, cho3);
	GetDlgItemText(IDC_CHOISE4, cho4);

	if (cho3 == TEXT("信计："))
	{
		if (choise3 > technical_subjects_full_score || choise4 > technical_subjects_full_score)
		{
			::MessageBox(nullptr, TEXT("非法成绩！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
			return;
		}
	}

	now_stu->CIM.change_course_results(static_cast<int>(course_Type::chinese), chinese);
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	const auto dlg = dynamic_cast<DISPLAY_SCORE*>(app->child_window->GetPane(0, 1));
	auto pos = dlg->score_list.GetFirstSelectedItemPosition();
	const auto npos = dlg->score_list.GetNextSelectedItem(pos);
	dlg->score_list.SetItemText(npos, 3, static_cast<CString>(std::to_string(chinese).c_str()));
	now_stu->CIM.change_course_results(static_cast<int>(course_Type::mathematics), mathematics);
	dlg->score_list.SetItemText(npos, 4, static_cast<CString>(std::to_string(mathematics).c_str()));
	now_stu->CIM.change_course_results(static_cast<int>(course_Type::foreign_language), foreign_language);
	dlg->score_list.SetItemText(npos, 5, static_cast<CString>(std::to_string(foreign_language).c_str()));

	if (cho1 == TEXT("政治："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::politics), choise1);
		dlg->score_list.SetItemText(npos, 6, static_cast<CString>(std::to_string(choise1).c_str()));
	}
	else if (cho1 == TEXT("历史："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::history), choise1);
		dlg->score_list.SetItemText(npos, 7, static_cast<CString>(std::to_string(choise1).c_str()));
	}
	else if (cho1 == TEXT("地理："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::geography), choise1);
		dlg->score_list.SetItemText(npos, 8, static_cast<CString>(std::to_string(choise1).c_str()));
	}
	else if (cho1 == TEXT("物理："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::physics), choise1);
		dlg->score_list.SetItemText(npos, 9, static_cast<CString>(std::to_string(choise1).c_str()));
	}
	else if (cho1 == TEXT("化学："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::chemical), choise1);
		dlg->score_list.SetItemText(npos, 10, static_cast<CString>(std::to_string(choise1).c_str()));
	}
	else if (cho1 == TEXT("生物："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::biology), choise1);
		dlg->score_list.SetItemText(npos, 11, static_cast<CString>(std::to_string(choise1).c_str()));
	}
	else if (cho1 == TEXT("信计："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::information_technology), choise1);
		dlg->score_list.SetItemText(npos, 12, static_cast<CString>(std::to_string(choise1).c_str()));
	}
	else if (cho1 == TEXT("通计："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::common_technology), choise1);
		dlg->score_list.SetItemText(npos, 13, static_cast<CString>(std::to_string(choise1).c_str()));
	}

	if (cho2 == TEXT("政治："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::politics), choise2);
		dlg->score_list.SetItemText(npos, 6, static_cast<CString>(std::to_string(choise2).c_str()));
	}
	else if (cho2 == TEXT("历史："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::history), choise2);
		dlg->score_list.SetItemText(npos, 7, static_cast<CString>(std::to_string(choise2).c_str()));
	}
	else if (cho2 == TEXT("地理："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::geography), choise2);
		dlg->score_list.SetItemText(npos, 8, static_cast<CString>(std::to_string(choise2).c_str()));
	}
	else if (cho2 == TEXT("物理："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::physics), choise2);
		dlg->score_list.SetItemText(npos, 9, static_cast<CString>(std::to_string(choise2).c_str()));
	}
	else if (cho2 == TEXT("化学："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::chemical), choise2);
		dlg->score_list.SetItemText(npos, 10, static_cast<CString>(std::to_string(choise2).c_str()));
	}
	else if (cho2 == TEXT("生物："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::biology), choise2);
		dlg->score_list.SetItemText(npos, 11, static_cast<CString>(std::to_string(choise2).c_str()));
	}
	else if (cho2 == TEXT("信计："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::information_technology), choise2);
		dlg->score_list.SetItemText(npos, 12, static_cast<CString>(std::to_string(choise2).c_str()));
	}
	else if (cho2 == TEXT("通计："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::common_technology), choise2);
		dlg->score_list.SetItemText(npos, 13, static_cast<CString>(std::to_string(choise2).c_str()));
	}

	if (cho3 == TEXT("政治："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::politics), choise3);
		dlg->score_list.SetItemText(npos, 6, static_cast<CString>(std::to_string(choise3).c_str()));
	}
	else if (cho3 == TEXT("历史："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::history), choise3);
		dlg->score_list.SetItemText(npos, 7, static_cast<CString>(std::to_string(choise3).c_str()));
	}
	else if (cho3 == TEXT("地理："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::geography), choise3);
		dlg->score_list.SetItemText(npos, 8, static_cast<CString>(std::to_string(choise3).c_str()));
	}
	else if (cho3 == TEXT("物理："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::physics), choise3);
		dlg->score_list.SetItemText(npos, 9, static_cast<CString>(std::to_string(choise3).c_str()));
	}
	else if (cho3 == TEXT("化学："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::chemical), choise3);
		dlg->score_list.SetItemText(npos, 10, static_cast<CString>(std::to_string(choise3).c_str()));
	}
	else if (cho3 == TEXT("生物："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::biology), choise3);
		dlg->score_list.SetItemText(npos, 11, static_cast<CString>(std::to_string(choise3).c_str()));
	}
	else if (cho3 == TEXT("信计："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::information_technology), choise3);
		dlg->score_list.SetItemText(npos, 12, static_cast<CString>(std::to_string(choise3).c_str()));
	}
	else if (cho3 == TEXT("通计："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::common_technology), choise3);
		dlg->score_list.SetItemText(npos, 13, static_cast<CString>(std::to_string(choise3).c_str()));
	}

	if (cho4 == TEXT("通计："))
	{
		now_stu->CIM.change_course_results(static_cast<int>(course_Type::common_technology), choise4);
		dlg->score_list.SetItemText(npos, 13, static_cast<CString>(std::to_string(choise4).c_str()));
	}

	dlg->score_list.SetItemText(npos, 14, static_cast<CString>(std::to_string(now_stu->CIM.return_total_score()).c_str()));

	EndDialog(0);
}
