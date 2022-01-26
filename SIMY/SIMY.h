
// SIMY.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号

#include "student_information_management.h"
#include "administrator_information_management.h"
#include "teacher_information_management.h"

// CSIMYApp:
// 有关此类的实现，请参阅 SIMY.cpp
//

class CSIMYApp : public CWinApp
{
public:
	CSIMYApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()

public:
	student_information_management* SIM;
	administrator_information_management* AIM;
	teacher_information_management* TIM;
	int nCheckId = 0;
	virtual BOOL SaveAllModified();
	CString szIniPath;
	CSplitterWnd* child_window;
	bool m_bRestart = false;
};

extern CSIMYApp theApp;
constexpr UINT WM_MyMessage_A = WM_USER + 1001;
constexpr UINT WM_MyMessage_INFORMATION = WM_USER + 1002;
constexpr UINT WM_MyMessage_SCORES = WM_USER + 1003;
constexpr UINT WM_MyMessage_WELCOME = WM_USER + 1004;