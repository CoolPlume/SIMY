#pragma once



// DISPLAY_RIGHT 窗体视图

class DISPLAY_RIGHT : public CFormView
{
	DECLARE_DYNCREATE(DISPLAY_RIGHT)

protected:
	DISPLAY_RIGHT();           // 动态创建所使用的受保护的构造函数
	virtual ~DISPLAY_RIGHT();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DISPLAY_RIGHT };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton logout;
	CEdit information_name;
	CEdit information_password;
public:
	CButton information_password_hidden;
	CButton information_password_change;
public:
	CEdit information_password_change_content;
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};


