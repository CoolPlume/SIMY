#pragma once



// DISPLAY_SCORE_STUDENT 窗体视图

class DISPLAY_SCORE_STUDENT : public CFormView
{
	DECLARE_DYNCREATE(DISPLAY_SCORE_STUDENT)

protected:
	DISPLAY_SCORE_STUDENT();           // 动态创建所使用的受保护的构造函数
	virtual ~DISPLAY_SCORE_STUDENT();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_STUDENT };
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
	virtual void OnInitialUpdate();
	int chinese;
	int mathematics;
	int foreign_language;
	int politics;
	int history;
	int geography;
	int physics;
	int chemical;
	int biology;
	int information_technology;
	int common_technology;
	afx_msg void OnBnClickedButton1();
};


