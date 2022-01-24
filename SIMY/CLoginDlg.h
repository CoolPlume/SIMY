#pragma once
#include "afxdialogex.h"


// CLoginDlg 对话框

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
private:
	CString login_username;
	CString login_password;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnSetfocusEdit2();
	afx_msg void OnEnSetfocusEdit1();
private:
	CEdit IDC_login_password;
	virtual void OnOK();
	virtual void OnCancel();
public:
	CButton IDC_REMEMBER;
};
