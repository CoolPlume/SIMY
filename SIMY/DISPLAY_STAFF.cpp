// DISPLAY_STAFF.cpp: 实现文件
//

#include "pch.h"
#include "SIMY.h"
#include "DISPLAY_STAFF.h"

struct DATA
{
	int subitem;
	CListCtrl* plist;
};

// DISPLAY_STAFF

IMPLEMENT_DYNCREATE(DISPLAY_STAFF, CFormView)

DISPLAY_STAFF::DISPLAY_STAFF()
	: CFormView(IDD_STAFF)
{

}

DISPLAY_STAFF::~DISPLAY_STAFF()
{
}

void DISPLAY_STAFF::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, staff_list);
	DDX_Control(pDX, IDC_EDIT1, find_content);
}

BEGIN_MESSAGE_MAP(DISPLAY_STAFF, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &DISPLAY_STAFF::OnBnClickedButton1)
	ON_EN_SETFOCUS(IDC_EDIT1, &DISPLAY_STAFF::OnEnSetfocusEdit1)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST2, &DISPLAY_STAFF::OnLvnColumnclickList2)
	ON_BN_CLICKED(IDC_BUTTON12, &DISPLAY_STAFF::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON6, &DISPLAY_STAFF::OnBnClickedButton6)
END_MESSAGE_MAP()


// DISPLAY_STAFF 诊断

#ifdef _DEBUG
void DISPLAY_STAFF::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DISPLAY_STAFF::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DISPLAY_STAFF 消息处理程序


void DISPLAY_STAFF::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	staff_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	staff_list.InsertColumn(0, TEXT("职工号"), LVCFMT_CENTER, 150);
	staff_list.InsertColumn(1, TEXT("姓名"), LVCFMT_CENTER, 75);
	staff_list.InsertColumn(2, TEXT("性别"), LVCFMT_CENTER, 50);

	const auto app = dynamic_cast<CSIMYApp*>(AfxGetApp());
	auto tea_list = app->TIM->return_teacher_list();
	int cnt = 0;
	for (auto& i : tea_list)
	{
		staff_list.InsertItem(cnt, TEXT("teacher"));
		const auto member = static_cast<CString>(i.return_username().c_str());
		staff_list.SetItemText(cnt, 0, member);
		const auto name = static_cast<CString>(i.return_actual_name().c_str());
		staff_list.SetItemText(cnt, 1, name);
		const auto gender_flag = i.return_gender();
		CString gender;
		if (gender_flag == 1)
		{
			gender = TEXT("男");
		}
		else
		{
			gender = TEXT("女");
		}
		staff_list.SetItemText(cnt, 2, gender);

		cnt++;
	}

	find_content.SetWindowTextW(TEXT("在此输入职工号"));
}


void DISPLAY_STAFF::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString target_num;
	GetDlgItemText(IDC_EDIT1, target_num);
	if (target_num.IsEmpty() || target_num == TEXT("在此输入职工号"))
	{
		::MessageBox(nullptr, TEXT("请在左侧文本框中输入要查找的职工号！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
		return;
	}

	//遍历
	int i = 0;
	const int line_count = staff_list.GetItemCount();
	bool find_flag = false;
	for (; i < line_count; i++)
	{
		const CString num = staff_list.GetItemText(i, 0);
		if (num == target_num)
		{
			//清空选择
			for (int j = 0; j < line_count; j++)
			{
				staff_list.SetItemState(j, 0, -1);
			}
			//选择
			staff_list.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
			staff_list.SetFocus();
			staff_list.EnsureVisible(i, true);
			find_flag = true;
		}
	}
	if (i == line_count && find_flag == false)
	{
		::MessageBox(nullptr, TEXT("查无此人！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
	}

}


void DISPLAY_STAFF::OnEnSetfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	find_content.SetWindowTextW(nullptr);
}


void DISPLAY_STAFF::OnLvnColumnclickList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	sort_column = pNMLV->iSubItem;//点击的列

	const int count = staff_list.GetItemCount();
	for (int i = 0; i < count; i++)
		staff_list.SetItemData(i, i);

	DATA data{};
	data.subitem = sort_column;
	data.plist = &staff_list;

	sort_method2 = !sort_method2;
	staff_list.SortItems(list_compere, reinterpret_cast<LPARAM>(&data));

	*pResult = 0;
}

bool DISPLAY_STAFF::sort_method2 = true;

int DISPLAY_STAFF::list_compere(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	const DATA* pListCtrl = reinterpret_cast<DATA*>(lParamSort);
	const auto col = pListCtrl->subitem; //点击的列项传递给col，用来判断点击了第几列

	//CString header[]={"姓名","年龄","编号"};  //假设现在的列头是这几项

	//得到该列的前2项
	const auto strItem1 = (pListCtrl->plist)->GetItemText(static_cast<int>(lParam1), col);
	const auto strItem2 = (pListCtrl->plist)->GetItemText(static_cast<int>(lParam2), col);

	if (col == 1 || col == 2)  // CString
	{
		const auto tmp = strItem1.CompareNoCase(strItem2); //如果两个对象完全一致则返回0，如果小于lpsz，则返回-1。
		if (DISPLAY_STAFF::sort_method2) // true--升序
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
	else if (col == 0)  // int 
	{
		const auto n1 = _atoi64(CW2A(strItem1));
		const auto n2 = _atoi64(CW2A(strItem2));
		if (DISPLAY_STAFF::sort_method2)//
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

void DISPLAY_STAFF::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_MyMessage_STAFF, 0, 0);
}


void DISPLAY_STAFF::OnBnClickedButton6()
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
		case IDNO:
		{
			return;
		}
		case IDYES:
		{
			if (auto pos = staff_list.GetFirstSelectedItemPosition(); pos == nullptr)
			{
				::MessageBox(nullptr, TEXT("没有被选中的项！"), TEXT("警告"), MB_ICONWARNING | MB_OK | MB_TASKMODAL);
			}
			else
			{
				while (pos)
				{
					const auto npos = staff_list.GetNextSelectedItem(pos);
					CString name = staff_list.GetItemText(npos, 0);
					app->TIM->delete_teacher(static_cast<std::string>(CW2A(name)));
					staff_list.DeleteItem(npos);
					pos = staff_list.GetFirstSelectedItemPosition();
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
	else
	{
		::MessageBox(nullptr, TEXT("权限不足！"), TEXT("错误"), MB_ICONERROR | MB_OK | MB_TASKMODAL);
	}
}
