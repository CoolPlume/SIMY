﻿// DLG_STUDENT_INFORMATION.cpp: 实现文件
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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}