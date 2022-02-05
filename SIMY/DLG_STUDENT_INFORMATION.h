#pragma once
#include "afxdialogex.h"


// DLG_STUDENT_INFORMATION 对话框

class DLG_STUDENT_INFORMATION : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_STUDENT_INFORMATION)

public:
	DLG_STUDENT_INFORMATION(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG_STUDENT_INFORMATION();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_INFORMATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void dlg_init();
	CButton username_change;
	CEdit username;
	CEdit password;
	CButton password_change;
	CEdit actual_name;
	CButton actual_name_change;
	CEdit nick_name;
	CButton nick_name_change;
	CButton gender_change;
	CComboBox gender;
	CButton course_change;
	CButton politics;
	CButton history;
	CButton geography;
	CButton physics;
	CButton chemical;
	CButton biology;
	CButton technology;
};
