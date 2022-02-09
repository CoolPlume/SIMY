#pragma once
#include "afxdialogex.h"


// DLG_SELECT_SUBJECT 对话框

class DLG_SELECT_SUBJECT : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_SELECT_SUBJECT)

public:
	DLG_SELECT_SUBJECT(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG_SELECT_SUBJECT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECTIVE_SUBJECTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CButton politics;
	CButton history;
	CButton geography;
	CButton physics;
	CButton chemical;
	CButton biology;
	CButton technology;
	afx_msg void OnBnClickedButton1();
};
