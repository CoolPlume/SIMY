
// SIMYDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SIMY.h"
#include "SIMYDlg.h"
#include "afxdialogex.h"
#include "DISPLAYVIEW_LEFT.h"
#include "DISPLAY_RIGHT.h"
#include "DISPLAY_WELCOME.h"
#include "DISPLAY_SCORE.h"
#include "DISPLAY_SCORE_STUDENT.h"
#include "DISPLAY_STAFF.h"

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
	ON_MESSAGE(WM_MyMessage_INFORMATION, &CSIMYDlg::OnMyMessage_INFORMATION)
	ON_MESSAGE(WM_MyMessage_WELCOME, &CSIMYDlg::OnMyMessage_WELCOME)
	ON_MESSAGE(WM_MyMessage_SCORES, &CSIMYDlg::OnMyMessage_SCORE)
	ON_MESSAGE(WM_MyMessage_SCORE_STUDENT, &CSIMYDlg::OnMyMessage_SCORE_STUDENT)
	ON_MESSAGE(WM_MyMessage_STAFF, &CSIMYDlg::OnMyMessage_STAFF)

	//}}AFX_MSG_MAP
	ON_WM_CLOSE()
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
	CAboutDlg dlg;
	dlg.DoModal();

	return 0;
}

LRESULT CSIMYDlg::OnMyMessage_INFORMATION(WPARAM wParam, LPARAM lParam)
{
	//MessageBox(TEXT("123"));

	CCreateContext ctx_information;
	ctx_information.m_pNewViewClass = RUNTIME_CLASS(DISPLAY_RIGHT);
	ctx_information.m_pCurrentDoc = nullptr;
	ctx_information.m_pNewDocTemplate = nullptr;
	ctx_information.m_pLastView = dynamic_cast<CFormView*>(m_cSplitter.GetPane(0, 1));
	ctx_information.m_pCurrentFrame = reinterpret_cast<CFrameWnd*>(this);
	m_cSplitter.DeleteView(0, 1);
	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(DISPLAY_RIGHT), CSize(980, 640), &ctx_information);
	const auto pNewView = dynamic_cast<DISPLAY_RIGHT*>(m_cSplitter.GetPane(0, 1));
	m_cSplitter.RecalcLayout();
	pNewView->OnInitialUpdate();
	m_cSplitter.SetActivePane(0, 1);



	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	const auto* pview_right = dynamic_cast<DISPLAY_RIGHT*>(app->child_window->GetPane(0, 1));
	CString name, password, nick_name;
	switch (app->nCheckId)
	{
	case IDC_RADIO1:
	{
		name = app->AIM->return_currently_logged_in_administrator().return_username().c_str();
		password = app->AIM->return_currently_logged_in_administrator().return_password().c_str();
		nick_name = app->AIM->return_currently_logged_in_administrator().return_nick_name().c_str();
		break;
	}
	case IDC_RADIO2:
	{
		name = app->TIM->return_currently_logged_in_teacher().return_username().c_str();
		password = app->TIM->return_currently_logged_in_teacher().return_password().c_str();
		nick_name = app->TIM->return_currently_logged_in_teacher().return_nick_name().c_str();

		break;
	}
	case IDC_RADIO3:
	{
		name = app->SIM->return_currently_logged_in_student().return_username().c_str();
		password = app->SIM->return_currently_logged_in_student().return_password().c_str();
		nick_name = app->SIM->return_currently_logged_in_student().return_nick_name().c_str();

		break;
	}
	default:
	{
		break;
	}
	}
	::SetWindowTextW(pview_right->information_name, name);
	::SetWindowTextW(pview_right->information_password, password);
	::SetWindowTextW(pview_right->nick_name, nick_name);

	return LRESULT();
}

LRESULT CSIMYDlg::OnMyMessage_SCORE(WPARAM wParam, LPARAM lParam)
{
	CCreateContext ctx_score;
	ctx_score.m_pNewViewClass = RUNTIME_CLASS(DISPLAY_SCORE);
	ctx_score.m_pCurrentDoc = nullptr;
	ctx_score.m_pNewDocTemplate = nullptr;
	ctx_score.m_pLastView = dynamic_cast<CFormView*>(m_cSplitter.GetPane(0, 1));
	ctx_score.m_pCurrentFrame = reinterpret_cast<CFrameWnd*>(this);
	m_cSplitter.DeleteView(0, 1);
	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(DISPLAY_SCORE), CSize(980, 640), &ctx_score);
	const auto pNewView = dynamic_cast<DISPLAY_SCORE*>(m_cSplitter.GetPane(0, 1));
	m_cSplitter.RecalcLayout();
	pNewView->OnInitialUpdate();
	m_cSplitter.SetActivePane(0, 1);


	return LRESULT();
}

LRESULT CSIMYDlg::OnMyMessage_WELCOME(WPARAM wParam, LPARAM lParam)
{
	CCreateContext ctx_welcome;
	ctx_welcome.m_pNewViewClass = RUNTIME_CLASS(DISPLAY_WELCOME);
	ctx_welcome.m_pCurrentDoc = nullptr;
	ctx_welcome.m_pNewDocTemplate = nullptr;
	ctx_welcome.m_pLastView = dynamic_cast<CFormView*>(m_cSplitter.GetPane(0, 1));
	ctx_welcome.m_pCurrentFrame = reinterpret_cast<CFrameWnd*>(this);
	m_cSplitter.DeleteView(0, 1);
	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(DISPLAY_WELCOME), CSize(980, 640), &ctx_welcome);
	const auto pNewView = dynamic_cast<DISPLAY_WELCOME*>(m_cSplitter.GetPane(0, 1));
	m_cSplitter.RecalcLayout();
	pNewView->OnInitialUpdate();
	m_cSplitter.SetActivePane(0, 1);

	return LRESULT();
}

LRESULT CSIMYDlg::OnMyMessage_SCORE_STUDENT(WPARAM wParam, LPARAM lParam)
{
	CCreateContext ctx_score;
	ctx_score.m_pNewViewClass = RUNTIME_CLASS(DISPLAY_SCORE_STUDENT);
	ctx_score.m_pCurrentDoc = nullptr;
	ctx_score.m_pNewDocTemplate = nullptr;
	ctx_score.m_pLastView = dynamic_cast<CFormView*>(m_cSplitter.GetPane(0, 1));
	ctx_score.m_pCurrentFrame = reinterpret_cast<CFrameWnd*>(this);
	m_cSplitter.DeleteView(0, 1);
	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(DISPLAY_SCORE_STUDENT), CSize(980, 640), &ctx_score);
	const auto pNewView = dynamic_cast<DISPLAY_SCORE_STUDENT*>(m_cSplitter.GetPane(0, 1));
	m_cSplitter.RecalcLayout();
	pNewView->OnInitialUpdate();
	m_cSplitter.SetActivePane(0, 1);


	return LRESULT();
}

LRESULT CSIMYDlg::OnMyMessage_STAFF(WPARAM wParam, LPARAM lParam)
{
	CCreateContext ctx_welcome;
	ctx_welcome.m_pNewViewClass = RUNTIME_CLASS(DISPLAY_STAFF);
	ctx_welcome.m_pCurrentDoc = nullptr;
	ctx_welcome.m_pNewDocTemplate = nullptr;
	ctx_welcome.m_pLastView = dynamic_cast<CFormView*>(m_cSplitter.GetPane(0, 1));
	ctx_welcome.m_pCurrentFrame = reinterpret_cast<CFrameWnd*>(this);
	m_cSplitter.DeleteView(0, 1);
	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(DISPLAY_STAFF), CSize(980, 640), &ctx_welcome);
	const auto pNewView = dynamic_cast<DISPLAY_STAFF*>(m_cSplitter.GetPane(0, 1));
	m_cSplitter.RecalcLayout();
	pNewView->OnInitialUpdate();
	m_cSplitter.SetActivePane(0, 1);

	return LRESULT();
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

	ctx_right_view.m_pNewViewClass = RUNTIME_CLASS(DISPLAY_WELCOME);
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
	m_pMyFrame->MoveWindow(0, 0, 640, 320);

	// and finally, create the splitter with the frame as
	// the parent
	m_cSplitter.CreateStatic(m_pMyFrame, 1, 2);
	m_cSplitter.CreateView(0, 0, RUNTIME_CLASS(DISPLAYVIEW_LEFT), CSize(300, 640), &ctx_left_view);
	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(DISPLAY_WELCOME), CSize(980, 640), &ctx_right_view);

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	app->child_window = &m_cSplitter;

	auto* pview1 = dynamic_cast<DISPLAYVIEW_LEFT*>(m_cSplitter.GetPane(0, 0));
	pview1->OnInitialUpdate();
	//auto* pview2 = dynamic_cast<DISPLAY_WELCOME*>(m_cSplitter.GetPane(0, 1));
	//pview2->OnInitialUpdate();

	PostMessage(WM_MyMessage_WELCOME);

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


void CSIMYDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());

	//重启
	//MessageBox(TEXT("close"));
	TCHAR szPath[MAX_PATH];  // 获取当前应用程序的全路径
	GetModuleFileName(nullptr, szPath, MAX_PATH);
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION procInfo;
	memset(&startupInfo, 0x00, sizeof(STARTUPINFO));
	startupInfo.cb = sizeof(STARTUPINFO);

	delete app->AIM;	//保存
	delete app->SIM;
	delete app->TIM;

	if (app->m_bRestart) // 新建进程
	{
		::WritePrivateProfileString(TEXT("system"), TEXT("restart"), TEXT("true"), app->szIniPath);
		::CreateProcess(szPath, nullptr, nullptr, nullptr, FALSE, NORMAL_PRIORITY_CLASS, nullptr, nullptr, &startupInfo, &procInfo);
	}
	else
	{
		::WritePrivateProfileString(TEXT("system"), TEXT("restart"), TEXT("false"), app->szIniPath);
	}



	CDialogEx::OnClose();


}
