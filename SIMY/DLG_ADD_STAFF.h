#pragma once
#include "afxdialogex.h"


// DLG_ADD_STAFF 对话框

class DLG_ADD_STAFF : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_ADD_STAFF)

public:
	DLG_ADD_STAFF(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG_ADD_STAFF();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_STAFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit username;
	CEdit actual_name;
	CComboBox gender;
	virtual void OnOK();
	afx_msg void OnBnClickedButton1();
};
