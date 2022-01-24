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
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_EN_SETFOCUS(IDC_EDIT2, &CLoginDlg::OnEnSetfocusEdit2)
	ON_EN_SETFOCUS(IDC_EDIT1, &CLoginDlg::OnEnSetfocusEdit1)
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

	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);

	if (login_username.IsEmpty() || login_password.IsEmpty() || login_username == TEXT("在此输入用户名") || login_password == TEXT("在此输入密码"))
	{
		::MessageBox(nullptr, TEXT("请输入用户名或密码"), TEXT("警告"), MB_ICONWARNING | MB_OK);
		return;
	}

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());

	const auto username = static_cast<std::string>(ATL::CW2AEX(login_username.GetString()));
	const auto password = static_cast<std::string>(ATL::CW2AEX(login_password.GetString()));

	app->nCheckId = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO3);
	if (app->nCheckId == 0)
	{
		::MessageBox(nullptr, TEXT("请选择身份"), TEXT("警告"), MB_ICONWARNING | MB_OK);
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
		::MessageBox(nullptr, TEXT("用户名或密码错误！"), TEXT("警告"), MB_ICONWARNING | MB_OK);
		return;
	}
	else
	{
		::MessageBox(nullptr, TEXT("登录成功！"), TEXT("提示"), MB_ICONINFORMATION | MB_OK);
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
	//exit(0);
	CDialogEx::OnCancel();
}
