#pragma once
#include "afxdialogex.h"


// DLG_STAFF_INFORMATION 对话框

class DLG_STAFF_INFORMATION : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_STAFF_INFORMATION)

public:
	DLG_STAFF_INFORMATION(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG_STAFF_INFORMATION();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAFF_INFORMATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit username;
	CComboBox gender;
	CEdit nick_name;
	CEdit actual_name;
	CEdit password;
	teacher* tea;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	CComboBox subject;
	afx_msg void OnBnClickedButton11();
};
