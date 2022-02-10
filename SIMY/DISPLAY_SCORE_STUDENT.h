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
	CStatic row_text1;
	CStatic row_text_2;
	CFont row_font;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	std::array<std::string,12> row_text=
	{
		"书山有路勤为径","学海无涯苦作舟",
		"路漫漫其修远兮","吾将上下而求索",
		"让舞弊远离校园","让诚信常驻心中",
		"以实力争取优异成绩","以诚信展现良好学风",
		"黑发不知勤学早","白首方悔读书迟",
		"纸上得来终觉浅","绝知此事要躬行",
	};
	int row_index = 0;
};


