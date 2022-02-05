#pragma once
#include "afxdialogex.h"


// DLG_ADD_STUDENT 对话框

class DLG_ADD_STUDENT : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_ADD_STUDENT)

public:
	DLG_ADD_STUDENT(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG_ADD_STUDENT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_STUDENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit username;
	CEdit actual_name;
	CComboBox gender;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	virtual void OnOK();
	virtual void OnCancel();
};
