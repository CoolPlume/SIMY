#pragma once
#include "afxdialogex.h"


// DLG_CHANGE_SCORE 对话框

class DLG_CHANGE_SCORE : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_CHANGE_SCORE)

public:
	DLG_CHANGE_SCORE(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG_CHANGE_SCORE();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGE_SCORE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	student* now_stu;
	virtual void OnOK();
	afx_msg void OnBnClickedButton1();
	int chinese;
	int mathematics;
	int foreign_language;
	int choise1;
	int choise2;
	int choise3;
	int choise4;
};
