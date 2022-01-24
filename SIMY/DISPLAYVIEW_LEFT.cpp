// DISPLAYVIEW_LEFT.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAYVIEW_LEFT.h"
#include "SIMYDlg.h"

// DISPLAYVIEW_LEFT

IMPLEMENT_DYNCREATE(DISPLAYVIEW_LEFT, CFormView)

DISPLAYVIEW_LEFT::DISPLAYVIEW_LEFT()
	: CFormView(IDD_DISPLAYVIEW_LEFT)
	, IDC_TEST(_T(""))
	, m_time(_T(""))
{

}

DISPLAYVIEW_LEFT::~DISPLAYVIEW_LEFT()
{
}

void DISPLAYVIEW_LEFT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_show_identity, SHOW_IDENTITY);
	DDX_Text(pDX, IDC_EDIT1, IDC_TEST);
	DDX_Control(pDX, IDC_TREE1, navigation);
	DDX_Text(pDX, IDC_TIME, m_time);
}

BEGIN_MESSAGE_MAP(DISPLAYVIEW_LEFT, CFormView)
	ON_WM_TIMER()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &DISPLAYVIEW_LEFT::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// DISPLAYVIEW_LEFT 诊断

#ifdef _DEBUG
void DISPLAYVIEW_LEFT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAYVIEW_LEFT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAYVIEW_LEFT 消息处理程序


void DISPLAYVIEW_LEFT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	//设置显示信息
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	CString identity;
	CString name;

	switch (app -> nCheckId)
	{
	case IDC_RADIO1:
	{
		identity = "管理员:";
		name = app -> AIM -> return_currently_logged_in_administrator().return_nick_name().c_str();
		break;
	}
	case IDC_RADIO2:
	{
		identity = "教师:";
		name = app -> TIM -> return_currently_logged_in_teacher().return_nick_name().c_str();
		break;
	}
	case IDC_RADIO3:
	{
		identity = "学生:";
		name = app -> SIM -> return_currently_logged_in_student().return_nick_name().c_str();
		break;
	}
	default:
	{
		identity = "未知:";
		name = "未知";
		break;
	}
	}

	SetDlgItemText(IDC_show_identity, identity);
	SetDlgItemText(IDC_show_name, name);


	UpdateData(false);

	//设置显示时间
	const CTime tm = CTime::GetCurrentTime();         //获取当前系统时间
	const CString strTime = tm.Format("%y年%m月%d日 %X");   //格式化系统时间。
	SetDlgItemText(IDC_TIME, strTime);        //初始化编辑框显示
	SetTimer(1, 1000, nullptr);         //启动定时器

	//设置导航树
	const HICON icon = AfxGetApp() -> LoadIconW(IDI_LOCATE);
	m_imageList.Create(32, 32, ILC_COLOR32, 1, 1);
	m_imageList.Add(icon);
	navigation.SetImageList(&m_imageList, TVSIL_NORMAL);

	navigation.InsertItem(TEXT("个人信息"), 0, 0, nullptr);
	navigation.InsertItem(TEXT("成绩查询"), 0, 0, nullptr);
	navigation.InsertItem(TEXT("关于"), 0, 0, nullptr);
	navigation.InsertItem(TEXT("待定"), 0, 0, nullptr);
	navigation.InsertItem(TEXT("待定"), 0, 0, nullptr);

}


void DISPLAYVIEW_LEFT::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	// TODO: 在此添加专用代码和/或调用基类

	CFormView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}


void DISPLAYVIEW_LEFT::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CFormView::OnTimer(nIDEvent);
	const CTime tm = CTime::GetCurrentTime(); 
	const CString strTime = tm.Format("%Y-%m-%d %H:%M:%S");
	SetDlgItemText(IDC_TIME, strTime);        //显示系统时间
}


void DISPLAYVIEW_LEFT::OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	//获取当前节点选中项目 CTreeCtrl::GetSelectedItem
	HTREEITEM item = navigation.GetSelectedItem();

	//获取选中项的文本内容 CTreeCtrl::GetItemText
	CString str = navigation.GetItemText(item);
	//MessageBox(str);

	if (str == TEXT("个人信息"))
	{

	}
	else if (str == TEXT("成绩查询"))
	{
		
	}
	else if (str == TEXT("关于"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_MyMessage_A, 0, 0);
	}
	else if (str == TEXT("待定"))
	{
		
	}
}
