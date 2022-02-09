// DISPLAY_SCORE_STUDENT.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_SCORE_STUDENT.h"
#include "DLG_SELECT_SUBJECT.h"


// DISPLAY_SCORE_STUDENT

IMPLEMENT_DYNCREATE(DISPLAY_SCORE_STUDENT, CFormView)

DISPLAY_SCORE_STUDENT::DISPLAY_SCORE_STUDENT()
	: CFormView(IDD_SCORE_STUDENT)
	, chinese(0)
	, mathematics(0)
	, foreign_language(0)
	, politics(0)
	, history(0)
	, geography(0)
	, physics(0)
	, chemical(0)
	, biology(0)
	, information_technology(0)
	, common_technology(0)
{

}

DISPLAY_SCORE_STUDENT::~DISPLAY_SCORE_STUDENT()
{
}

void DISPLAY_SCORE_STUDENT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, chinese);
	DDX_Text(pDX, IDC_EDIT2, mathematics);
	DDX_Text(pDX, IDC_EDIT3, foreign_language);
	DDX_Text(pDX, IDC_EDIT6, politics);
	DDX_Text(pDX, IDC_EDIT4, history);
	DDX_Text(pDX, IDC_EDIT8, geography);
	DDX_Text(pDX, IDC_EDIT5, physics);
	DDX_Text(pDX, IDC_EDIT7, chemical);
	DDX_Text(pDX, IDC_EDIT9, biology);
	DDX_Text(pDX, IDC_EDIT11, information_technology);
	DDX_Text(pDX, IDC_EDIT10, common_technology);
}

BEGIN_MESSAGE_MAP(DISPLAY_SCORE_STUDENT, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &DISPLAY_SCORE_STUDENT::OnBnClickedButton1)
END_MESSAGE_MAP()


// DISPLAY_SCORE_STUDENT 诊断

#ifdef _DEBUG
void DISPLAY_SCORE_STUDENT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAY_SCORE_STUDENT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAY_SCORE_STUDENT 消息处理程序


void DISPLAY_SCORE_STUDENT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	const student now_stu = app->SIM->return_currently_logged_in_student();
	chinese = now_stu.CIM.return_course_results(static_cast<int>(course_Type::chinese));
	mathematics= now_stu.CIM.return_course_results(static_cast<int>(course_Type::mathematics));
	foreign_language = now_stu.CIM.return_course_results(static_cast<int>(course_Type::foreign_language));
	politics = now_stu.CIM.return_course_results(static_cast<int>(course_Type::politics));
	history = now_stu.CIM.return_course_results(static_cast<int>(course_Type::history));
	geography = now_stu.CIM.return_course_results(static_cast<int>(course_Type::geography));
	physics = now_stu.CIM.return_course_results(static_cast<int>(course_Type::physics));
	chemical = now_stu.CIM.return_course_results(static_cast<int>(course_Type::chemical));
	biology = now_stu.CIM.return_course_results(static_cast<int>(course_Type::biology));
	information_technology = now_stu.CIM.return_course_results(static_cast<int>(course_Type::information_technology));
	common_technology = now_stu.CIM.return_course_results(static_cast<int>(course_Type::common_technology));

	UpdateData(false);
}


void DISPLAY_SCORE_STUDENT::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	DLG_SELECT_SUBJECT dlg;
	dlg.DoModal();
}
