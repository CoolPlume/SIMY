// DLG_STUDENT_INFORMATION.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "afxdialogex.h"
#include "DLG_STUDENT_INFORMATION.h"

#include "DISPLAY_SCORE.h"


// DLG_STUDENT_INFORMATION 对话框

IMPLEMENT_DYNAMIC(DLG_STUDENT_INFORMATION, CDialogEx)

DLG_STUDENT_INFORMATION::DLG_STUDENT_INFORMATION(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_INFORMATION, pParent)
{

}

DLG_STUDENT_INFORMATION::~DLG_STUDENT_INFORMATION()
{
}

void DLG_STUDENT_INFORMATION::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, username_change);
	DDX_Control(pDX, IDC_EDIT1, username);
	DDX_Control(pDX, IDC_EDIT2, password);
	DDX_Control(pDX, IDC_BUTTON1, password_change);
	DDX_Control(pDX, IDC_EDIT3, actual_name);
	DDX_Control(pDX, IDC_BUTTON4, actual_name_change);
	DDX_Control(pDX, IDC_EDIT4, nick_name);
	DDX_Control(pDX, IDC_BUTTON9, nick_name_change);
	DDX_Control(pDX, IDC_BUTTON10, gender_change);
	DDX_Control(pDX, IDC_COMBO1, gender);
	DDX_Control(pDX, IDC_BUTTON11, course_change);
	DDX_Control(pDX, IDC_CHECK3, politics);
	DDX_Control(pDX, IDC_CHECK6, history);
	DDX_Control(pDX, IDC_CHECK9, geography);
	DDX_Control(pDX, IDC_CHECK4, physics);
	DDX_Control(pDX, IDC_CHECK8, chemical);
	DDX_Control(pDX, IDC_CHECK5, biology);
	DDX_Control(pDX, IDC_CHECK7, technology);
}


BEGIN_MESSAGE_MAP(DLG_STUDENT_INFORMATION, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_STUDENT_INFORMATION::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_STUDENT_INFORMATION::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_STUDENT_INFORMATION::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &DLG_STUDENT_INFORMATION::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &DLG_STUDENT_INFORMATION::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &DLG_STUDENT_INFORMATION::OnBnClickedButton11)
END_MESSAGE_MAP()


// DLG_STUDENT_INFORMATION 消息处理程序


BOOL DLG_STUDENT_INFORMATION::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	gender.AddString(TEXT("女"));
	gender.AddString(TEXT("男"));
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());

	if (app->nCheckId == IDC_RADIO2)
	{
		password.SetPasswordChar('*');
		username.SetReadOnly(true);
		username_change.EnableWindow(false);
		password.SetReadOnly(true);
		password_change.EnableWindow(false);
		actual_name.SetReadOnly(true);
		actual_name_change.EnableWindow(false);
		gender.EnableWindow(false);
		gender_change.EnableWindow(false);
		nick_name.SetReadOnly(true);
		nick_name_change.EnableWindow(false);
		course_change.EnableWindow(false);
		politics.EnableWindow(false);
		history.EnableWindow(false);
		geography.EnableWindow(false);
		physics.EnableWindow(false);
		chemical.EnableWindow(false);
		biology.EnableWindow(false);
		technology.EnableWindow(false);
	}

	const auto dlg = dynamic_cast<DISPLAY_SCORE*>(app->child_window->GetPane(0, 1));
	auto pos = dlg->score_list.GetFirstSelectedItemPosition();
	const auto npos = dlg->score_list.GetNextSelectedItem(pos);
	const CString name = dlg->score_list.GetItemText(npos, 0);
	const student stu = *(app->SIM->find_student(static_cast<std::string>(CW2A(name))));
	now_stu = app->SIM->find_student(static_cast<std::string>(CW2A(name)));

	//不能写在一起 会乱码
	CString name_disp, password_disp, nick_name_disp, actual_name_disp;
	name_disp = stu.return_username().c_str();
	password_disp = stu.return_password().c_str();
	nick_name_disp = stu.return_nick_name().c_str();
	actual_name_disp = stu.return_actual_name().c_str();
	const int gender_num = stu.return_gender();

	username.SetWindowTextW(name_disp);
	password.SetWindowTextW(password_disp);
	nick_name.SetWindowTextW(nick_name_disp);
	actual_name.SetWindowTextW(actual_name_disp);
	gender.SetCurSel(gender_num);

	if (now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::politics)) == true)
	{
		politics.SetCheck(true);
	}
	if (now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::history)) == true)
	{
		history.SetCheck(true);
	}
	if (now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::geography)) == true)
	{
		geography.SetCheck(true);
	}
	if (now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::physics)) == true)
	{
		physics.SetCheck(true);
	}
	if (now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::chemical)) == true)
	{
		chemical.SetCheck(true);
	}
	if (now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::biology)) == true)
	{
		biology.SetCheck(true);
	}
	if (now_stu->CIM.return_the_selection_status(static_cast<int>(course_Type::information_technology)) == true)
	{
		technology.SetCheck(true);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DLG_STUDENT_INFORMATION::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());

	switch (const auto select = ::MessageBox(nullptr, TEXT("是否确定修改？"), TEXT("警告"), MB_ICONWARNING | MB_YESNOCANCEL | MB_TASKMODAL); select)
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
		CString name;
		GetDlgItemTextW(IDC_EDIT1, name);
		if (now_stu->return_username().c_str() == name)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		now_stu->change_username(static_cast<std::string>(CW2A(name)));

		const auto dlg = dynamic_cast<DISPLAY_SCORE*>(app->child_window->GetPane(0, 1));
		auto pos = dlg->score_list.GetFirstSelectedItemPosition();
		const auto npos = dlg->score_list.GetNextSelectedItem(pos);
		dlg->score_list.SetItemText(npos, 0, name);

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STUDENT_INFORMATION::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (const auto select = ::MessageBox(nullptr, TEXT("是否确定修改？"), TEXT("警告"), MB_ICONWARNING | MB_YESNOCANCEL | MB_TASKMODAL); select)
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
		CString password;
		GetDlgItemTextW(IDC_EDIT2, password);
		if (now_stu->return_password().c_str() == password)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		now_stu->change_password(static_cast<std::string>(CW2A(password)));

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STUDENT_INFORMATION::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (const auto select = ::MessageBox(nullptr, TEXT("是否确定修改？"), TEXT("警告"), MB_ICONWARNING | MB_YESNOCANCEL | MB_TASKMODAL); select)
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
		CString actual_name;
		GetDlgItemTextW(IDC_EDIT3, actual_name);
		if (now_stu->return_actual_name().c_str() == actual_name)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		now_stu->change_actual_name(static_cast<std::string>(CW2A(actual_name)));

		const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
		const auto dlg = dynamic_cast<DISPLAY_SCORE*>(app->child_window->GetPane(0, 1));
		auto pos = dlg->score_list.GetFirstSelectedItemPosition();
		const auto npos = dlg->score_list.GetNextSelectedItem(pos);
		dlg->score_list.SetItemText(npos, 1, actual_name);

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STUDENT_INFORMATION::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (const auto select = ::MessageBox(nullptr, TEXT("是否确定修改？"), TEXT("警告"), MB_ICONWARNING | MB_YESNOCANCEL | MB_TASKMODAL); select)
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
		CString nick_name;
		GetDlgItemTextW(IDC_EDIT4, nick_name);
		if (now_stu->return_nick_name().c_str() == nick_name)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		now_stu->change_nick_name(static_cast<std::string>(CW2A(nick_name)));

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STUDENT_INFORMATION::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (const auto select = ::MessageBox(nullptr, TEXT("是否确定修改？"), TEXT("警告"), MB_ICONWARNING | MB_YESNOCANCEL | MB_TASKMODAL); select)
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
		CString gender_string;
		const auto combobox_index = gender.GetCurSel();
		gender.GetLBText(combobox_index, gender_string);
		int gender_number = 0;
		if (gender_string == TEXT("男"))
		{
			gender_number = 1;
		}
		else if (gender_string == TEXT("女"))
		{
			gender_number = 0;
		}

		if (now_stu->return_gender() == gender_number)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		now_stu->change_gender(gender_number);

		const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
		const auto dlg = dynamic_cast<DISPLAY_SCORE*>(app->child_window->GetPane(0, 1));
		auto pos = dlg->score_list.GetFirstSelectedItemPosition();
		const auto npos = dlg->score_list.GetNextSelectedItem(pos);
		dlg->score_list.SetItemText(npos, 2, gender_string);

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STUDENT_INFORMATION::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (const auto select = ::MessageBox(nullptr, TEXT("是否确定修改？"), TEXT("警告"), MB_ICONWARNING | MB_YESNOCANCEL | MB_TASKMODAL); select)
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
		const bool politics_flag = politics.GetCheck();
		const bool history_flag = history.GetCheck();
		const bool geography_flag = geography.GetCheck();
		const bool physics_flag = physics.GetCheck();
		const bool chemical_flag = chemical.GetCheck();
		const bool biology_flag = biology.GetCheck();
		const bool technology_flag = technology.GetCheck();

		//统计科目数
		int cnt = 0;
		if (politics_flag)
			cnt++;
		if (history_flag)
			cnt++;
		if (geography_flag)
			cnt++;
		if (physics_flag)
			cnt++;
		if (chemical_flag)
			cnt++;
		if (biology_flag)
			cnt++;
		if (technology_flag)
			cnt++;
		if (cnt != 3)
		{
			::MessageBox(nullptr, TEXT("应当只选择三门课！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}

		const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
		app->SIM->revise_currently_logged_in_student()->CIM.change_the_selection_status(static_cast<int>(course_Type::politics), politics_flag);
		app->SIM->revise_currently_logged_in_student()->CIM.change_the_selection_status(static_cast<int>(course_Type::history), history_flag);
		app->SIM->revise_currently_logged_in_student()->CIM.change_the_selection_status(static_cast<int>(course_Type::geography),geography_flag);
		app->SIM->revise_currently_logged_in_student()->CIM.change_the_selection_status(static_cast<int>(course_Type::physics), physics_flag);
		app->SIM->revise_currently_logged_in_student()->CIM.change_the_selection_status(static_cast<int>(course_Type::chemical), chemical_flag);
		app->SIM->revise_currently_logged_in_student()->CIM.change_the_selection_status(static_cast<int>(course_Type::biology), biology_flag);
		app->SIM->revise_currently_logged_in_student()->CIM.change_the_selection_status(static_cast<int>(course_Type::technology), technology_flag);


		break;
	}
	default:
	{
		break;
	}
	}
}
