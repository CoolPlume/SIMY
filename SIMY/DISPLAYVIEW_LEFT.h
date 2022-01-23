#pragma once



// DISPLAYVIEW_LEFT 窗体视图

class DISPLAYVIEW_LEFT : public CFormView
{
	DECLARE_DYNCREATE(DISPLAYVIEW_LEFT)

protected:
	DISPLAYVIEW_LEFT();           // 动态创建所使用的受保护的构造函数
	virtual ~DISPLAYVIEW_LEFT();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DISPLAYVIEW_LEFT };
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
	CStatic SHOW_IDENTITY;
public:
	virtual void OnInitialUpdate();
private:
	CString IDC_TEST;
	CTreeCtrl navigation;
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
};


