#pragma once



// DISPLAY_SCORE 窗体视图

class DISPLAY_SCORE : public CFormView
{
	DECLARE_DYNCREATE(DISPLAY_SCORE)

protected:
	DISPLAY_SCORE();           // 动态创建所使用的受保护的构造函数
	virtual ~DISPLAY_SCORE();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE };
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
};


