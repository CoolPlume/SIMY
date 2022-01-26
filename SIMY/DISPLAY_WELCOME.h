#pragma once



// DISPLAY_WELCOME 窗体视图

class DISPLAY_WELCOME : public CFormView
{
	DECLARE_DYNCREATE(DISPLAY_WELCOME)

protected:
	DISPLAY_WELCOME();           // 动态创建所使用的受保护的构造函数
	virtual ~DISPLAY_WELCOME();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WELCOME };
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
private:
	CStatic logo_picture;
	CFont wel_font;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnPaint();
	CStatic wel_text;
};


