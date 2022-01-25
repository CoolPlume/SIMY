
// SIMYDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SIMY.h"
#include "SIMYDlg.h"
#include "afxdialogex.h"
#include "CSelectView.h"
#include "CDispalyView.h"
#include "DISPLAYVIEW_LEFT.h"
#include "DISPLAY_RIGHT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSIMYDlg 对话框



CSIMYDlg::CSIMYDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIMY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ZKNUICO);
}

void CSIMYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSIMYDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//{{AFX_MSG_MAP(CChildView)
	ON_MESSAGE(WM_MyMessage_A, &CSIMYDlg::OnMyMessage_A)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CSIMYDlg 消息处理程序

BOOL CSIMYDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		CString strAboutMenu;
		const BOOL bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	
	CRect rect;
	// Get the rectangle of the custom window. The custom window
	// is just a a big button that is not visible and is disabled.
	// It's a trick to not use coordinates directly.
	GetDlgItem(IDC_CUTSOM_WINDOW)->GetWindowRect(&rect);

	// Move the splitter
	ScreenToClient(&rect);
	m_pMyFrame->MoveWindow(&rect);
	m_pMyFrame->ShowWindow(SW_SHOW);
	m_cSplitter.MoveWindow(0, 0, rect.Width(), rect.Height());
	m_cSplitter.ShowWindow(SW_SHOW);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSIMYDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSIMYDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		const int cxIcon = GetSystemMetrics(SM_CXICON);
		const int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		const int x = (rect.Width() - cxIcon + 1) / 2;
		const int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSIMYDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CSIMYDlg::OnMyMessage_A(WPARAM wParam, LPARAM lParam)
{
	//MessageBox(TEXT("123"));
	CAboutDlg dlg;
	dlg.DoModal();
	//return LRESULT();
	return 0;
}



void CAboutDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnOK();
}


int CSIMYDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	// Initialize a context for the view. CMyTreeView is my view and
	// is defined as :  class CMyListView : public CListView.
	CCreateContext ctx_left_view;
	CCreateContext ctx_right_view;
	ctx_left_view.m_pNewViewClass = RUNTIME_CLASS(DISPLAYVIEW_LEFT);
	ctx_left_view.m_pCurrentDoc = nullptr;
	ctx_left_view.m_pNewDocTemplate = nullptr;
	ctx_left_view.m_pLastView = nullptr;
	ctx_left_view.m_pCurrentFrame = nullptr;

	ctx_right_view.m_pNewViewClass = RUNTIME_CLASS(DISPLAY_RIGHT);
	ctx_right_view.m_pCurrentDoc = nullptr;
	ctx_right_view.m_pNewDocTemplate = nullptr;
	ctx_right_view.m_pLastView = nullptr;
	ctx_right_view.m_pCurrentFrame = nullptr;

	// Because the CFrameWnd needs a window class, we will create
	// a new one. I just copied the sample from MSDN Help.
	// When using it in your project, you may keep CS_VREDRAW and
	// CS_HREDRAW and then throw the other three parameters.
	const CString strMyClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW,
		::LoadCursor(nullptr, IDC_ARROW), static_cast<HBRUSH>(::GetStockObject(WHITE_BRUSH)),
		::LoadIcon(nullptr, IDI_APPLICATION));

	// Create the frame window with "this" as the parent
	m_pMyFrame = new CFrameWnd();
	m_pMyFrame->Create(strMyClass, _T(""), WS_CHILD, CRect(0, 0, 1, 1), this);
	m_pMyFrame->ShowWindow(SW_SHOW);
	m_pMyFrame->MoveWindow(0, 0, 500, 400);

	// and finally, create the splitter with the frame as
	// the parent
	m_cSplitter.CreateStatic(m_pMyFrame, 1, 2);
	m_cSplitter.CreateView(0, 0, RUNTIME_CLASS(DISPLAYVIEW_LEFT), CSize(300, 320), &ctx_left_view);
	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(DISPLAY_RIGHT), CSize(1100, 320), &ctx_right_view);

	auto* pview1 = dynamic_cast<DISPLAYVIEW_LEFT*>(m_cSplitter.GetPane(0, 0));
	pview1->OnInitialUpdate();
	return 0;
}


void CSIMYDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码

}


void CSIMYDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码


}
