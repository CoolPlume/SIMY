
// SIMYDlg.h: 头文件
//

#pragma once





// CSIMYDlg 对话框
class CSIMYDlg : public CDialogEx
{
// 构造
public:
	CSIMYDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIMY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//{{AFX_MSG(CChildView)

	afx_msg LRESULT OnMyMessage_A(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMyMessage_INFORMATION(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMyMessage_SCORE(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMyMessage_WELCOME(WPARAM wParam, LPARAM lParam);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

private:
	CFrameWnd* m_pMyFrame;   // 分隔窗口
public:
	CSplitterWnd m_cSplitter;     // 左右分隔  
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
};
