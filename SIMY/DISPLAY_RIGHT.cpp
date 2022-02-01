// DISPLAY_RIGHT.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_RIGHT.h"

#include "DISPLAYVIEW_LEFT.h"


// DISPLAY_RIGHT

IMPLEMENT_DYNCREATE(DISPLAY_RIGHT, CFormView)

DISPLAY_RIGHT::DISPLAY_RIGHT()
	: CFormView(IDD_DISPLAY_RIGHT)
{

}

DISPLAY_RIGHT::~DISPLAY_RIGHT()
{
}

void DISPLAY_RIGHT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON3, logout);
	DDX_Control(pDX, IDC_EDIT1, information_name);
	DDX_Control(pDX, IDC_EDIT2, information_password);
	DDX_Control(pDX, IDC_BUTTON1, information_password_hidden);
	DDX_Control(pDX, IDC_BUTTON2, information_password_change);
	DDX_Control(pDX, IDC_EDIT5, information_password_change_content);
	DDX_Control(pDX, IDC_EDIT3, nick_name);
	DDX_Control(pDX, IDC_EDIT4, nick_name_change_content);
	DDX_Control(pDX, IDC_BUTTON4, nick_name_change);
}

BEGIN_MESSAGE_MAP(DISPLAY_RIGHT, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &DISPLAY_RIGHT::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DISPLAY_RIGHT::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DISPLAY_RIGHT::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DISPLAY_RIGHT::OnBnClickedButton4)
END_MESSAGE_MAP()


// DISPLAY_RIGHT 诊断

#ifdef _DEBUG
void DISPLAY_RIGHT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAY_RIGHT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAY_RIGHT 消息处理程序


void DISPLAY_RIGHT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	auto* pWnd = dynamic_cast<CDialog*>(FromHandle(AfxGetMainWnd()->GetSafeHwnd()));
	//MessageBox(TEXT("aaa"));
	information_password.SetPasswordChar('*');
	logout.SetFocus();
}


void DISPLAY_RIGHT::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString caption;
	information_password_hidden.GetWindowTextW(caption);
	if (caption == TEXT("显示密码"))
	{
		information_password_hidden.SetWindowTextW(TEXT("隐藏密码"));
		information_password.SetPasswordChar(NULL);
	}
	else
	{
		information_password_hidden.SetWindowTextW(TEXT("显示密码"));
		information_password.SetPasswordChar('*');
	}
	//刷新状态
	information_password.SetFocus();
	information_password_hidden.SetFocus();
}


void DISPLAY_RIGHT::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString pwd;
	GetDlgItemText(IDC_EDIT5, pwd);
	if (pwd == CString(""))
	{
		::MessageBox(nullptr, TEXT("请在上方的方框中输入修改后的密码"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	switch (app->nCheckId)
	{
	case IDC_RADIO1:
	{
		if (const std::string name = app->AIM->return_currently_logged_in_administrator().return_username(); name == "admin")
		{
			::MessageBox(nullptr, TEXT("超级管理员禁止修改自身密码！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
			return;
		}
		app->AIM->revise_currently_logged_in_administrator()->change_password(static_cast<std::string>(CW2A(pwd)));
		break;
	}
	case IDC_RADIO2:
	{
		app->TIM->revise_currently_logged_in_teacher()->change_password(static_cast<std::string>(CW2A(pwd)));
		break;
	}
	case IDC_RADIO3:
	{
		app->SIM->revise_currently_logged_in_student()->change_password(static_cast<std::string>(CW2A(pwd)));
		break;
	}
	default:
	{
		break;
	}
	}
	::MessageBox(nullptr, TEXT("密码修改成功！"), TEXT("提示"), MB_ICONINFORMATION | MB_OK | MB_TASKMODAL);

}


void DISPLAY_RIGHT::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	app->m_bRestart = true;
	::WritePrivateProfileString(TEXT("Login options"), TEXT("auto login"), TEXT("false"), app->szIniPath);
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_CLOSE, 0, 0);

}


void DISPLAY_RIGHT::OnBnClickedButton4()//UNDONE: 不接受空格
{
	// TODO: 在此添加控件通知处理程序代码
	CString nick_name;
	GetDlgItemText(IDC_EDIT4, nick_name);
	if (nick_name == CString(""))
	{
		::MessageBox(nullptr, TEXT("请在上方的方框中输入修改后的昵称"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	switch (app->nCheckId)
	{
	case IDC_RADIO1:
	{
		if (const std::string name = app->AIM->return_currently_logged_in_administrator().return_username(); name == "admin")
		{
			::MessageBox(nullptr, TEXT("超级管理员禁止修改自身昵称！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
			return;
		}
		app->AIM->revise_currently_logged_in_administrator()->change_nick_name(static_cast<std::string>(CW2A(nick_name)));
		break;
	}
	case IDC_RADIO2:
	{
		app->TIM->revise_currently_logged_in_teacher()->change_nick_name(static_cast<std::string>(CW2A(nick_name)));
		break;
	}
	case IDC_RADIO3:
	{
		app->SIM->revise_currently_logged_in_student()->change_nick_name(static_cast<std::string>(CW2A(nick_name)));
		break;
	}
	default:
	{
		break;
	}
	}
	::MessageBox(nullptr, TEXT("昵称修改成功！"), TEXT("提示"), MB_ICONINFORMATION | MB_OK | MB_TASKMODAL);

}
