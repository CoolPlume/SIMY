// CLoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, login_username(_T(""))
	, login_password(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, login_username);
	DDX_Text(pDX, IDC_EDIT1, login_password);
	DDX_Control(pDX, IDC_EDIT1, IDC_login_password);
	DDX_Control(pDX, IDC_CHECK1, IDC_REMEMBER);
	DDX_Control(pDX, IDC_CHECK2, auto_login);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_EN_SETFOCUS(IDC_EDIT2, &CLoginDlg::OnEnSetfocusEdit2)
	ON_EN_SETFOCUS(IDC_EDIT1, &CLoginDlg::OnEnSetfocusEdit1)
	ON_NOTIFY(BCN_HOTITEMCHANGE, IDC_CHECK2, &CLoginDlg::OnBnHotItemChangeCheck2)
	ON_BN_CLICKED(IDC_CHECK2, &CLoginDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &CLoginDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//exit(0);
	CDialogEx::OnClose();
}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	exit(0);
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	SetWindowText(TEXT("用户登录"));

	login_username = TEXT("在此输入用户名");
	login_password = TEXT("在此输入密码");
	UpdateData(false);

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	if (!::PathFileExists(app->szIniPath))
	{
		//return;
	}
	else
	{
		//判断是否记住密码
			//得到config信息
		TCHAR remember_password_flag[MAX_PATH] = { 0 };
		::GetPrivateProfileStringW(TEXT("Login options"), TEXT("remember password"), nullptr, remember_password_flag, MAX_PATH, app->szIniPath);
		//nValue = ::GetPrivateProfileInt(TEXT("Service"), TEXT("Description"), 0, szIniPath);

			//转换成string
		const int iLen = WideCharToMultiByte(CP_ACP, 0, remember_password_flag, -1, nullptr, 0, nullptr, nullptr);
		const auto chRtn = new char[iLen * sizeof(char)];
		WideCharToMultiByte(CP_ACP, 0, remember_password_flag, -1, chRtn, iLen, nullptr, nullptr);
		const std::string str(chRtn);
			//判断
		if (str == "true")
		{
			//设置用户名
			TCHAR name[MAX_PATH] = { 0 };
			::GetPrivateProfileStringW(TEXT("Login options"), TEXT("name"), nullptr, name, MAX_PATH, app->szIniPath);
			login_username = name;
			//设置密码
			TCHAR password[MAX_PATH] = { 0 };
			::GetPrivateProfileStringW(TEXT("Login options"), TEXT("password"), nullptr, password, MAX_PATH, app->szIniPath);
			login_password = password;
			IDC_login_password.SetPasswordChar('*');
			//设置身份
			TCHAR identity[MAX_PATH] = { 0 };
			::GetPrivateProfileStringW(TEXT("Login options"), TEXT("identity"), nullptr, identity, MAX_PATH, app->szIniPath);
			const int iLen = WideCharToMultiByte(CP_ACP, 0, identity, -1, nullptr, 0, nullptr, nullptr);
			const auto chRtn = new char[iLen * sizeof(char)];
			WideCharToMultiByte(CP_ACP, 0, identity, -1, chRtn, iLen, nullptr, nullptr);
			const std::string str(chRtn);
			const int identity_int = std::stoi(str);
			CheckRadioButton(IDC_RADIO1, IDC_RADIO3, identity_int);
			//勾选记住密码
			IDC_REMEMBER.SetCheck(1);
			UpdateData(false);
		}


		//判断是否自动登录
			//得到config信息
		TCHAR auto_login_flag[MAX_PATH] = { 0 };
		::GetPrivateProfileStringW(TEXT("Login options"), TEXT("auto login"), nullptr, auto_login_flag, MAX_PATH, app->szIniPath);

			//转换成string
		const int iLen1 = WideCharToMultiByte(CP_ACP, 0, auto_login_flag, -1, nullptr, 0, nullptr, nullptr);
		const auto chRtn1 = new char[iLen * sizeof(char)];
		WideCharToMultiByte(CP_ACP, 0, auto_login_flag, -1, chRtn1, iLen1, nullptr, nullptr);
		const std::string str1(chRtn1);
		//判断
		if (str1 == "true")
		{
			auto_login.SetCheck(true);
			OnBnClickedButton1();
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);

	if (login_username.IsEmpty() || login_password.IsEmpty() || login_username == TEXT("在此输入用户名") || login_password == TEXT("在此输入密码"))
	{
		::MessageBox(nullptr, TEXT("请输入用户名或密码"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());

	const auto username = static_cast<std::string>(ATL::CW2AEX(login_username.GetString()));
	const auto password = static_cast<std::string>(ATL::CW2AEX(login_password.GetString()));

	app->nCheckId = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO3);
	if (app->nCheckId == 0)
	{
		::MessageBox(nullptr, TEXT("请选择身份"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}

	bool login_flag = false;
	switch (app->nCheckId)
	{
	case IDC_RADIO1:
	{
		login_flag = app->AIM->login_decision(username, password);
		break;
	}
	case IDC_RADIO2:
	{
		login_flag = app->TIM->login_decision(username, password);
		break;
	}
	case IDC_RADIO3:
	{
		login_flag = app->SIM->login_decision(username, password);
		break;
	}
	}

	if (login_flag == false)
	{
		::MessageBox(nullptr, TEXT("用户名或密码错误！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}
	else
	{
		::MessageBox(nullptr, TEXT("登录成功！"), TEXT("提示"), MB_ICONINFORMATION | MB_OK | MB_TASKMODAL);
	}


	//写入config
	CString remember_flag_out, name_out, password_out, identity_out, auto_login_out;
	switch (const UINT remember_flag = IDC_REMEMBER.GetCheck(); remember_flag)
	{
	case BST_CHECKED:
	{
		remember_flag_out = TEXT("true");
		identity_out = std::to_string(app->nCheckId).c_str();
		switch (app->nCheckId)
		{
		case IDC_RADIO1:
		{
			name_out = app->AIM->return_currently_logged_in_administrator().return_username().c_str();
			password_out = app->AIM->return_currently_logged_in_administrator().return_password().c_str();
			break;
		}
		case IDC_RADIO2:
		{
			name_out = app->TIM->return_currently_logged_in_teacher().return_username().c_str();
			password_out = app->TIM->return_currently_logged_in_teacher().return_password().c_str();
			break;
		}
		case IDC_RADIO3:
		{
			name_out = app->SIM->return_currently_logged_in_student().return_username().c_str();
			password_out = app->SIM->return_currently_logged_in_student().return_password().c_str();
			break;
		}
		default:
		{
			break;
		}
		}
			break;
	}
	case BST_UNCHECKED:
	{
		remember_flag_out = TEXT("false");
		break;
	}
	default:
	{
		break;
	}
	}

	switch (const UINT auto_login_flag = auto_login.GetCheck(); auto_login_flag)
	{
	case BST_CHECKED:
	{
		auto_login_out = TEXT("true");
		break;
	}
	case BST_UNCHECKED:
	{
		auto_login_out = TEXT("false");
		break;
	}
	default:
	{
		break;
	}
	}

	::WritePrivateProfileString(TEXT("Login options"), TEXT("remember password"), remember_flag_out,app->szIniPath);
	::WritePrivateProfileString(TEXT("Login options"), TEXT("auto login"), auto_login_out, app->szIniPath);
	if (!name_out.IsEmpty() && !password_out.IsEmpty() && !identity_out.IsEmpty())
	{
		::WritePrivateProfileString(TEXT("Login options"), TEXT("name"), name_out, app->szIniPath);
		::WritePrivateProfileString(TEXT("Login options"), TEXT("password"), password_out, app->szIniPath);
		::WritePrivateProfileString(TEXT("Login options"), TEXT("identity"), identity_out, app->szIniPath);

	}

	EndDialog(0);
}


void CLoginDlg::OnEnSetfocusEdit2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (login_username == TEXT("在此输入用户名"))
	{
		login_username.Empty();
		UpdateData(false);
	}
}


void CLoginDlg::OnEnSetfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	IDC_login_password.SetPasswordChar('*');
	UpdateData(true);
	if (login_password == TEXT("在此输入密码"))
	{
		login_password.Empty();
		UpdateData(false);
	}
}


void CLoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	OnBnClickedButton1();
	//CDialogEx::OnOK();
}


void CLoginDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	//！！！！！！！！！！！！！！     IMPORTANT     ！！！！！！！！！！！！！！
	//测试用后门 勿忘！！！！！！！！！！！

	CDialogEx::OnCancel();
	//exit(0);
}


void CLoginDlg::OnBnHotItemChangeCheck2(NMHDR* pNMHDR, LRESULT* pResult)
{
	// 此功能要求 Internet Explorer 6 或更高版本。
	// 符号 _WIN32_IE 必须是 >= 0x0600。
	LPNMBCHOTITEM pHotItem = reinterpret_cast<LPNMBCHOTITEM>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CLoginDlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	//同步 记住密码 选项状态
	if (const auto flag = auto_login.GetCheck(); flag == false)
	{
		
	}
	else
	{
		IDC_REMEMBER.SetCheck(true);
	}

}


void CLoginDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (const auto flag1 = IDC_REMEMBER.GetCheck(); static_cast<bool>(flag1) == false)
	{
		if (const auto flag2 = auto_login.GetCheck(); static_cast<bool>(flag2) == true)
		{
			auto_login.SetCheck(false);
		}
	}
}
