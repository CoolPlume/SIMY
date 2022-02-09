// DLG_SELECT_SUBJECT.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "afxdialogex.h"
#include "DLG_SELECT_SUBJECT.h"


// DLG_SELECT_SUBJECT 对话框

IMPLEMENT_DYNAMIC(DLG_SELECT_SUBJECT, CDialogEx)

DLG_SELECT_SUBJECT::DLG_SELECT_SUBJECT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECTIVE_SUBJECTS, pParent)
{

}

DLG_SELECT_SUBJECT::~DLG_SELECT_SUBJECT()
{
}

void DLG_SELECT_SUBJECT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, politics);
	DDX_Control(pDX, IDC_CHECK2, history);
	DDX_Control(pDX, IDC_CHECK10, geography);
	DDX_Control(pDX, IDC_CHECK11, physics);
	DDX_Control(pDX, IDC_CHECK12, chemical);
	DDX_Control(pDX, IDC_CHECK13, biology);
	DDX_Control(pDX, IDC_CHECK14, technology);
}


BEGIN_MESSAGE_MAP(DLG_SELECT_SUBJECT, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_SELECT_SUBJECT::OnBnClickedButton1)
END_MESSAGE_MAP()


// DLG_SELECT_SUBJECT 消息处理程序


BOOL DLG_SELECT_SUBJECT::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	const student now_stu = app->SIM->return_currently_logged_in_student();

	const bool politics_flag = now_stu.CIM.return_the_selection_status(static_cast<int>(course_Type::politics));
	const bool history_flag = now_stu.CIM.return_the_selection_status(static_cast<int>(course_Type::history));
	const bool geography_flag = now_stu.CIM.return_the_selection_status(static_cast<int>(course_Type::geography));
	const bool physics_flag = now_stu.CIM.return_the_selection_status(static_cast<int>(course_Type::physics));
	const bool chemical_flag = now_stu.CIM.return_the_selection_status(static_cast<int>(course_Type::chemical));
	const bool biology_flag = now_stu.CIM.return_the_selection_status(static_cast<int>(course_Type::biology));
	const bool technology_flag = now_stu.CIM.return_the_selection_status(static_cast<int>(course_Type::information_technology));

	int cnt = 0;
	if (politics_flag == true)
	{
		cnt++;
		politics.SetCheck(true);
		politics.EnableWindow(false);
	}
	if (history_flag == true)
	{
		cnt++;
		history.SetCheck(true);
		history.EnableWindow(false);
	}
	if (geography_flag == true)
	{
		cnt++;
		geography.SetCheck(true);
		geography.EnableWindow(false);
	}
	if (physics_flag == true)
	{
		cnt++;
		physics.SetCheck(true);
		physics.EnableWindow(false);
	}
	if (chemical_flag == true)
	{
		cnt++;
		chemical.SetCheck(true);
		chemical.EnableWindow(false);
	}
	if (biology_flag == true)
	{
		cnt++;
		biology.SetCheck(true);
		biology.EnableWindow(false);
	}
	if (technology_flag == true)
	{
		cnt++;
		technology.SetCheck(true);
		technology.EnableWindow(false);
	}

	if (cnt >= 3)
	{
		::MessageBox(nullptr, TEXT("您已完成了选科"), TEXT("提示"), MB_ICONINFORMATION | MB_OK | MB_TASKMODAL);
		EndDialog(0);
		return true;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DLG_SELECT_SUBJECT::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	const auto flag = ::MessageBox(nullptr, TEXT("确认提交？"), TEXT("警告"), MB_ICONWARNING | MB_YESNO | MB_TASKMODAL);
	if (flag == IDNO)
	{
		return;
	}
	else if (flag == IDYES)
	{
		const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
		auto* now_stu = app->SIM->revise_currently_logged_in_student();
		const bool politics_flag = politics.GetCheck();
		const bool history_flag = history.GetCheck();
		const bool geography_flag = geography.GetCheck();
		const bool physics_flag = physics.GetCheck();
		const bool chemical_flag = chemical.GetCheck();
		const bool biology_flag = biology.GetCheck();
		const bool technology_flag = technology.GetCheck();

		int cnt = 0;
		if (politics_flag == true)
		{
			cnt++;
		}
		if (history_flag == true)
		{
			cnt++;
		}
		if (geography_flag == true)
		{
			cnt++;
		}
		if (physics_flag == true)
		{
			cnt++;
		}
		if (chemical_flag == true)
		{
			cnt++;
		}
		if (biology_flag == true)
		{
			cnt++;
		}
		if (technology_flag == true)
		{
			cnt++;
		}

		if (cnt > 3)
		{
			::MessageBox(nullptr, TEXT("选择的数量过多！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}

		now_stu->CIM.change_the_selection_status(static_cast<int>(course_Type::politics), politics_flag);
		now_stu->CIM.change_the_selection_status(static_cast<int>(course_Type::history), history_flag);
		now_stu->CIM.change_the_selection_status(static_cast<int>(course_Type::geography), geography_flag);
		now_stu->CIM.change_the_selection_status(static_cast<int>(course_Type::physics), physics_flag);
		now_stu->CIM.change_the_selection_status(static_cast<int>(course_Type::chemical), chemical_flag);
		now_stu->CIM.change_the_selection_status(static_cast<int>(course_Type::biology), biology_flag);
		now_stu->CIM.change_the_selection_status(static_cast<int>(course_Type::technology), technology_flag);
		::MessageBox(nullptr, TEXT("完成！"), TEXT("提示"), MB_ICONINFORMATION | MB_OK | MB_TASKMODAL);
		EndDialog(0);
	}
}
