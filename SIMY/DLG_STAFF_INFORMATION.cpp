// DLG_STAFF_INFORMATION.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "afxdialogex.h"
#include "DLG_STAFF_INFORMATION.h"

#include "DISPLAY_STAFF.h"


// DLG_STAFF_INFORMATION 对话框

IMPLEMENT_DYNAMIC(DLG_STAFF_INFORMATION, CDialogEx)

DLG_STAFF_INFORMATION::DLG_STAFF_INFORMATION(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STAFF_INFORMATION, pParent)
{

}

DLG_STAFF_INFORMATION::~DLG_STAFF_INFORMATION()
{
}

void DLG_STAFF_INFORMATION::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, username);
	DDX_Control(pDX, IDC_COMBO1, gender);
	DDX_Control(pDX, IDC_EDIT4, nick_name);
	DDX_Control(pDX, IDC_EDIT3, actual_name);
	DDX_Control(pDX, IDC_EDIT2, password);
}


BEGIN_MESSAGE_MAP(DLG_STAFF_INFORMATION, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_STAFF_INFORMATION::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_STAFF_INFORMATION::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_STAFF_INFORMATION::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &DLG_STAFF_INFORMATION::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &DLG_STAFF_INFORMATION::OnBnClickedButton10)
END_MESSAGE_MAP()


// DLG_STAFF_INFORMATION 消息处理程序


BOOL DLG_STAFF_INFORMATION::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	gender.AddString(TEXT("女"));
	gender.AddString(TEXT("男"));
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	const auto dlg = dynamic_cast<DISPLAY_STAFF*>(app->child_window->GetPane(0, 1));
	auto pos = dlg->staff_list.GetFirstSelectedItemPosition();
	const auto npos = dlg->staff_list.GetNextSelectedItem(pos);
	const CString name = dlg->staff_list.GetItemText(npos, 0);
	tea = app->TIM->find_teacher(static_cast<std::string>(CW2A(name)));

	CString name_disp, password_disp, nick_name_disp, actual_name_disp;
	name_disp = tea->return_username().c_str();
	password_disp = tea->return_password().c_str();
	nick_name_disp = tea->return_nick_name().c_str();
	actual_name_disp = tea->return_actual_name().c_str();
	const int gender_num = tea->return_gender();

	username.SetWindowTextW(name_disp);
	password.SetWindowTextW(password_disp);
	nick_name.SetWindowTextW(nick_name_disp);
	actual_name.SetWindowTextW(actual_name_disp);
	gender.SetCurSel(gender_num);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DLG_STAFF_INFORMATION::OnBnClickedButton2()
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
		if (tea->return_username().c_str() == name)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		tea->change_username(static_cast<std::string>(CW2A(name)));

		const auto dlg = dynamic_cast<DISPLAY_STAFF*>(app->child_window->GetPane(0, 1));
		auto pos = dlg->staff_list.GetFirstSelectedItemPosition();
		const auto npos = dlg->staff_list.GetNextSelectedItem(pos);
		dlg->staff_list.SetItemText(npos, 0, name);

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STAFF_INFORMATION::OnBnClickedButton1()
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
		if (tea->return_password().c_str() == password)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		tea->change_password(static_cast<std::string>(CW2A(password)));

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STAFF_INFORMATION::OnBnClickedButton4()
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
		if (tea->return_actual_name().c_str() == actual_name)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		tea->change_actual_name(static_cast<std::string>(CW2A(actual_name)));

		const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
		const auto dlg = dynamic_cast<DISPLAY_STAFF*>(app->child_window->GetPane(0, 1));
		auto pos = dlg->staff_list.GetFirstSelectedItemPosition();
		const auto npos = dlg->staff_list.GetNextSelectedItem(pos);
		dlg->staff_list.SetItemText(npos, 1, actual_name);

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STAFF_INFORMATION::OnBnClickedButton9()
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
		if (tea->return_nick_name().c_str() == nick_name)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		tea->change_nick_name(static_cast<std::string>(CW2A(nick_name)));

		break;
	}
	default:
	{
		break;
	}
	}
}


void DLG_STAFF_INFORMATION::OnBnClickedButton10()
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

		if (tea->return_gender() == gender_number)
		{
			::MessageBox(nullptr, TEXT("无效的修改！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			return;
		}
		tea->change_gender(gender_number);

		const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
		const auto dlg = dynamic_cast<DISPLAY_STAFF*>(app->child_window->GetPane(0, 1));
		auto pos = dlg->staff_list.GetFirstSelectedItemPosition();
		const auto npos = dlg->staff_list.GetNextSelectedItem(pos);
		dlg->staff_list.SetItemText(npos, 2, gender_string);

		break;
	}
	default:
	{
		break;
	}
	}
}
