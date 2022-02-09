#pragma once



// DISPLAY_STAFF 窗体视图

class DISPLAY_STAFF : public CFormView
{
	DECLARE_DYNCREATE(DISPLAY_STAFF)

protected:
	DISPLAY_STAFF();           // 动态创建所使用的受保护的构造函数
	virtual ~DISPLAY_STAFF();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAFF };
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
	CListCtrl staff_list;
};


