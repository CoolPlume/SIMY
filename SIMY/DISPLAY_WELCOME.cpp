// DISPLAY_WELCOME.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_WELCOME.h"


// DISPLAY_WELCOME

IMPLEMENT_DYNCREATE(DISPLAY_WELCOME, CFormView)

DISPLAY_WELCOME::DISPLAY_WELCOME()
	: CFormView(IDD_WELCOME)
{

}

DISPLAY_WELCOME::~DISPLAY_WELCOME()
{
}

void DISPLAY_WELCOME::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOGO_PICTURE, logo_picture);
	DDX_Control(pDX, IDC_WEL_TEXT, wel_text);
}

BEGIN_MESSAGE_MAP(DISPLAY_WELCOME, CFormView)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DISPLAY_WELCOME 诊断

#ifdef _DEBUG
void DISPLAY_WELCOME::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAY_WELCOME::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAY_WELCOME 消息处理程序


void DISPLAY_WELCOME::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	//从资源中加载图片  
	CBitmap bitmap;
	//加载指定位图资源 Bmp图片ID  
	bitmap.LoadBitmap(IDB_logo);
	//获取对话框上的句柄 图片控件ID  
	auto* p = dynamic_cast<CStatic*>(GetDlgItem(IDC_LOGO_PICTURE));
	//设置静态控件窗口风格为位图居中显示  
	p->ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//将图片设置到Picture控件上  
	p->SetBitmap(bitmap);

	wel_font.CreatePointFont(250, L"黑体", nullptr);
	GetDlgItem(IDC_WEL_TEXT)->SetFont(&wel_font);

}


void DISPLAY_WELCOME::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CFormView::OnPaint()


}
