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
public:
	virtual void OnInitialUpdate();
	CListCtrl score_list;
	CEdit find_content;
	CButton btn_find;
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHdnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	static bool sort_method;
	static int CALLBACK list_compere(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
	int sort_column{};
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton12();
};

struct DATA
{
	int subitem;
	CListCtrl* plist;
};
