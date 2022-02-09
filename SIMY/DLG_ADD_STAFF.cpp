// DLG_ADD_STAFF.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "afxdialogex.h"
#include "DLG_ADD_STAFF.h"


// DLG_ADD_STAFF 对话框

IMPLEMENT_DYNAMIC(DLG_ADD_STAFF, CDialogEx)

DLG_ADD_STAFF::DLG_ADD_STAFF(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_STAFF, pParent)
{

}

DLG_ADD_STAFF::~DLG_ADD_STAFF()
{
}

void DLG_ADD_STAFF::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, username);
	DDX_Control(pDX, IDC_EDIT2, actual_name);
	DDX_Control(pDX, IDC_COMBO1, gender);
}


BEGIN_MESSAGE_MAP(DLG_ADD_STAFF, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_ADD_STAFF::OnBnClickedButton1)
END_MESSAGE_MAP()


// DLG_ADD_STAFF 消息处理程序


BOOL DLG_ADD_STAFF::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());

	gender.AddString(TEXT("男"));
	gender.AddString(TEXT("女"));

	CString name;
	name = std::to_string((app->SIM->return_student_list_size() + 1)).c_str();
	username.SetWindowTextW(name);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DLG_ADD_STAFF::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void DLG_ADD_STAFF::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());

	CString username_string, actual_name_string, gender_string;
	GetDlgItemText(IDC_EDIT1, username_string);
	GetDlgItemText(IDC_EDIT2, actual_name_string);
	const auto combobox_index = gender.GetCurSel();
	if (combobox_index == -1)
	{
		::MessageBox(nullptr, TEXT("请选择性别"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}
	if (actual_name_string.IsEmpty())
	{
		::MessageBox(nullptr, TEXT("请输入姓名"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}
	gender.GetLBText(combobox_index, gender_string);

	teacher tea;
	tea.change_actual_name(static_cast<std::string>(CW2A(actual_name_string)));
	tea.change_username(static_cast<std::string>(CW2A(username_string)));
	int gender_number = 0;
	if (gender_string == TEXT("男"))
	{
		gender_number = 1;
	}
	else if (gender_string == TEXT("女"))
	{
		gender_number = 0;
	}
	tea.change_gender(gender_number);

	app->TIM->add_teacher(tea);

	::MessageBox(nullptr, TEXT("添加成功！"), TEXT("提示"), MB_ICONINFORMATION | MB_OK | MB_TASKMODAL);
	EndDialog(0);
}
