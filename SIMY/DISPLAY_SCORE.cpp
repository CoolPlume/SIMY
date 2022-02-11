// DISPLAY_SCORE.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_SCORE.h"
#include "DLG_ADD_STUDENT.h"
#include "DLG_STUDENT_INFORMATION.h"
#include "DLG_CHANGE_SCORE.h"

// DISPLAY_SCORE

IMPLEMENT_DYNCREATE(DISPLAY_SCORE, CFormView)

DISPLAY_SCORE::DISPLAY_SCORE()
	: CFormView(IDD_SCORE)
{

}

DISPLAY_SCORE::~DISPLAY_SCORE()
{
}

void DISPLAY_SCORE::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, score_list);
	DDX_Control(pDX, IDC_EDIT1, find_content);
	DDX_Control(pDX, IDC_BUTTON1, btn_find);
}

BEGIN_MESSAGE_MAP(DISPLAY_SCORE, CFormView)
	ON_EN_SETFOCUS(IDC_EDIT1, &DISPLAY_SCORE::OnEnSetfocusEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &DISPLAY_SCORE::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &DISPLAY_SCORE::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &DISPLAY_SCORE::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &DISPLAY_SCORE::OnBnClickedButton2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &DISPLAY_SCORE::OnNMDblclkList1)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &DISPLAY_SCORE::OnHdnItemclickList1)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &DISPLAY_SCORE::OnLvnColumnclickList1)
	ON_BN_CLICKED(IDC_BUTTON8, &DISPLAY_SCORE::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON12, &DISPLAY_SCORE::OnBnClickedButton12)
END_MESSAGE_MAP()


// DISPLAY_SCORE 诊断

#ifdef _DEBUG
void DISPLAY_SCORE::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAY_SCORE::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAY_SCORE 消息处理程序


void DISPLAY_SCORE::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	score_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	//设置list样式：整行选中、显示网格线

	//插入标题
	score_list.InsertColumn(0, TEXT("学号"), LVCFMT_CENTER, 150);
	score_list.InsertColumn(1, TEXT("姓名"), LVCFMT_CENTER, 75);
	score_list.InsertColumn(2, TEXT("性别"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(3, TEXT("语文"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(4, TEXT("数学"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(5, TEXT("外语"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(6, TEXT("政治"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(7, TEXT("历史"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(8, TEXT("地理"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(9, TEXT("物理"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(10, TEXT("化学"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(11, TEXT("生物"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(12, TEXT("信计"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(13, TEXT("通计"), LVCFMT_CENTER, 50);
	score_list.InsertColumn(14, TEXT("总分"), LVCFMT_CENTER, 60);

	//遍历学生列表
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	auto stu_list = app->SIM->return_student_list();
	int cnt = 0;	//用于记录当前学生数 以此和list行数对应
	for (auto& i : stu_list)
	{
		score_list.InsertItem(cnt, TEXT("student"));
		const auto member = static_cast<CString>(i.return_username().c_str());	//学号
		score_list.SetItemText(cnt, 0, member);
		const auto name = static_cast<CString>(i.return_actual_name().c_str());	//姓名
		score_list.SetItemText(cnt, 1, name);
		const auto gender_flag = i.return_gender();	//性别
		CString gender;
		if(gender_flag==1)
		{
			gender = TEXT("男");
		}
		else
		{
			gender = TEXT("女");
		}
		score_list.SetItemText(cnt, 2, gender);

		//成绩
		const auto chinese_score= static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::chinese))).c_str());
		score_list.SetItemText(cnt, 3, chinese_score);
		const auto mathematics_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::mathematics))).c_str());
		score_list.SetItemText(cnt, 4, mathematics_score);
		const auto foreign_language_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::foreign_language))).c_str());
		score_list.SetItemText(cnt, 5, foreign_language_score);
		//对于小三门 选过的课才显示成绩
		if (i.CIM.return_the_selection_status(static_cast<int>(course_Type::politics)) == true)
		{
			const auto politics_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::politics))).c_str());
			score_list.SetItemText(cnt, 6, politics_score);
		}
		if (i.CIM.return_the_selection_status(static_cast<int>(course_Type::history)) == true)
		{
			const auto history_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::history))).c_str());
			score_list.SetItemText(cnt, 7, history_score);
		}
		if (i.CIM.return_the_selection_status(static_cast<int>(course_Type::geography)) == true)
		{
			const auto geography_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::geography))).c_str());
			score_list.SetItemText(cnt, 8, geography_score);
		}
		if (i.CIM.return_the_selection_status(static_cast<int>(course_Type::physics)) == true)
		{
			const auto physics_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::physics))).c_str());
			score_list.SetItemText(cnt, 9, physics_score);
		}
		if (i.CIM.return_the_selection_status(static_cast<int>(course_Type::chemical)) == true)
		{
			const auto chemical_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::chemical))).c_str());
			score_list.SetItemText(cnt, 10, chemical_score);
		}
		if (i.CIM.return_the_selection_status(static_cast<int>(course_Type::biology)) == true)
		{
			const auto biology_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::biology))).c_str());
			score_list.SetItemText(cnt, 11, biology_score);
		}
		if (i.CIM.return_the_selection_status(static_cast<int>(course_Type::information_technology)) == true)
		{
			const auto information_technology_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::information_technology))).c_str());
			score_list.SetItemText(cnt, 12, information_technology_score);
		}
		if (i.CIM.return_the_selection_status(static_cast<int>(course_Type::common_technology)) == true)
		{
			const auto common_technology_score = static_cast<CString>(std::to_string(i.CIM.return_course_results(static_cast<int>(course_Type::common_technology))).c_str());
			score_list.SetItemText(cnt, 13, common_technology_score);
		}
		auto total_score = static_cast<CString>(std::to_string(i.CIM.return_total_score()).c_str());
		score_list.SetItemText(cnt, 14, total_score);

		cnt++;
	}

	
	find_content.SetWindowTextW(TEXT("在此输入学号"));	//设置编辑框提示

}


void DISPLAY_SCORE::OnEnSetfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	//当查找输入框获得焦点时，清空原有内容
	find_content.SetWindowTextW(nullptr);
}


void DISPLAY_SCORE::OnBnClickedButton1()	//按钮：查找
{
	// TODO: 在此添加控件通知处理程序代码
	CString target_num;	//目标学号
	GetDlgItemText(IDC_EDIT1, target_num);
	if (target_num.IsEmpty() || target_num == TEXT("在此输入学号"))	//若查找输入框为空
	{
		::MessageBox(nullptr, TEXT("请在左侧文本框中输入要查找的学号！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}

	//遍历
	int i = 0;	
	const int line_count = score_list.GetItemCount();
	bool find_flag = false;	//查找结果
	for (; i < line_count; i++)
	{
		const CString num = score_list.GetItemText(i, 0);
		if (num == target_num)
		{
			//清空原有选择
			for (int j = 0; j < line_count; j++)
			{
				score_list.SetItemState(j, 0, -1);
			}
			//选择目标
			score_list.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
			score_list.SetFocus();
			score_list.EnsureVisible(i, true);
			find_flag = true;
		}
	}

	if (i == line_count && find_flag == false)	
	{
		::MessageBox(nullptr, TEXT("查无此人！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
	}

}


void DISPLAY_SCORE::OnBnClickedButton6()	//按钮：删除
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	if (app->nCheckId == IDC_RADIO1)
	{
		switch (const auto select = ::MessageBox(nullptr, TEXT("删除后无法撤回，是否继续？"), TEXT("警告"), MB_ICONWARNING | MB_YESNOCANCEL | MB_TASKMODAL); select)
		{
		case IDCANCEL:
		{
			__fallthrough;
		}
		case IDNO:	//取消
		{
			return;
		}
		case IDYES:	//继续
		{
			if (auto pos = score_list.GetFirstSelectedItemPosition(); pos == nullptr)
			{
				::MessageBox(nullptr, TEXT("没有被选中的项！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			}
			else
			{
				while (pos)
				{
					//删除所有被选中的项
					const auto npos = score_list.GetNextSelectedItem(pos);
					CString name = score_list.GetItemText(npos, 0);
					app->SIM->delete_student(static_cast<std::string>(CW2A(name)));
					score_list.DeleteItem(npos);
					pos = score_list.GetFirstSelectedItemPosition();
				}
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
	else  //非管理员没有权限删除人员
	{
		::MessageBox(nullptr, TEXT("权限不足！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
	}
}


void DISPLAY_SCORE::OnBnClickedButton7()	//按钮：添加
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	if (app->nCheckId == IDC_RADIO1)	//若是管理员 弹出添加对话框
	{
		DLG_ADD_STUDENT dlg;
		dlg.DoModal();
	}
	else  //其他人员没有权限
	{
		::MessageBox(nullptr, TEXT("权限不足！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
	}
}


void DISPLAY_SCORE::OnBnClickedButton2()	//按钮：详细信息\修改
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	if (const auto pos = score_list.GetFirstSelectedItemPosition(); pos == nullptr)	//未选中项时
	{
		::MessageBox(nullptr, TEXT("没有被选中的项！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
	}
	else  //弹出信息对话框
	{
		DLG_STUDENT_INFORMATION dlg;
		dlg.DoModal();
	}

}


void DISPLAY_SCORE::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)	//如果在列表上双击，则触发详细信息按钮
{
	auto pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	OnBnClickedButton2();

	*pResult = 0;
}


void DISPLAY_SCORE::OnHdnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	auto phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	*pResult = 0;
}


void DISPLAY_SCORE::OnLvnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult)	//点击表头 排序
{
	const auto pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	sort_column = pNMLV->iSubItem;//点击的列

	const int count = score_list.GetItemCount();
	for (int i = 0; i < count; i++)
		score_list.SetItemData(i, i);

	DATA data{};
	data.subitem = sort_column;
	data.plist = &score_list;

	sort_method = !sort_method;	//正序<-->倒序
	score_list.SortItems(list_compere, reinterpret_cast<LPARAM>(&data));

	*pResult = 0;
}

bool DISPLAY_SCORE::sort_method = true;

int DISPLAY_SCORE::list_compere(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)	//自定义排序方法
{
	const DATA* pListCtrl = reinterpret_cast<DATA*>(lParamSort);
	const auto col = pListCtrl->subitem; //点击的列项传递给col，用来判断点击了第几列

	//得到该列的前2项
	const auto strItem1 = (pListCtrl->plist)->GetItemText(static_cast<int>(lParam1), col);
	const auto strItem2 = (pListCtrl->plist)->GetItemText(static_cast<int>(lParam2), col);

	if (col == 1 || col == 2)  // CString
	{
		const auto tmp = strItem1.CompareNoCase(strItem2); //如果两个对象完全一致则返回0，如果小于lpsz，则返回-1。
		if (sort_method) // true--升序
		{
			if (tmp <= 0)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			if (tmp >= 0)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
	else if (col == 0 || (col >= 3 && col <= 14))  // int 
	{
		const auto n1 = _atoi64(CW2A(strItem1));
		const auto n2 = _atoi64(CW2A(strItem2));
		if (sort_method)//
		{
			if (n1 <= n2)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			if (n1 >= n2)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
	return -1;  // -1表示第一项在第二项前面，0表示两项相等
}


void DISPLAY_SCORE::OnBnClickedButton8()	//按钮：登记分数
{
	// TODO: 在此添加控件通知处理程序代码
	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	if (const auto pos = score_list.GetFirstSelectedItemPosition(); pos == nullptr)	//若未选中项
	{
		::MessageBox(nullptr, TEXT("没有被选中的项！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
	}
	else
	{
		DLG_CHANGE_SCORE dlg;
		dlg.DoModal();
	}
}


void DISPLAY_SCORE::OnBnClickedButton12()	//按钮：刷新
{
	// TODO: 在此添加控件通知处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_MyMessage_SCORES, 0, 0);
}
