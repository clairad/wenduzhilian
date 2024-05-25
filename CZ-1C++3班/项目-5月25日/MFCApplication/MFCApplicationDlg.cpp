
// MFCApplicationDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationDlg 对话框



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplicationDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplicationDlg 消息处理程序

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// 获取ComboBox控件的指针  
	CComboBox* pComboOptions = (CComboBox*)GetDlgItem(IDC_COMBO_OPTIONS);
	if (pComboOptions)
	{
		// 添加选项到ComboBox  
		pComboOptions->AddString(_T(" "));
		pComboOptions->AddString(_T("第1选项"));
		pComboOptions->AddString(_T("第2选项"));
		pComboOptions->AddString(_T("第3选项"));

		// 可选：设置默认选择（例如，设置为第一个选项）  
		pComboOptions->SetCurSel(0);
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

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
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplicationDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int a = GetDlgItemInt(IDC_EDIT1);
	int b = GetDlgItemInt(IDC_EDIT2);
	SetDlgItemInt(IDC_EDIT3, a + b);
}


void CMFCApplicationDlg::OnBnClickedButton2()
{
	// 获取RadioButton的指针  
	CButton* pRadioFirst = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton* pRadioSecond = (CButton*)GetDlgItem(IDC_RADIO2);
	CButton* pRadioThird = (CButton*)GetDlgItem(IDC_RADIO3);

	// 获取CEdit的指针  
	CEdit* pEditResult = (CEdit*)GetDlgItem(IDC_EDIT4);

	// 初始化结果字符串  
	CString strResult;

	// 检查哪个RadioButton被选中了  
	if (pRadioFirst && pRadioFirst->GetCheck() == BST_CHECKED)
	{
		strResult = _T("你选择了第一选项");
	}
	else if (pRadioSecond && pRadioSecond->GetCheck() == BST_CHECKED)
	{
		strResult = _T("你选择了第二选项");
	}
	else if (pRadioThird && pRadioThird->GetCheck() == BST_CHECKED)
	{
		strResult = _T("你选择了第三选项");
	}
	else
	{
		strResult = _T("没有选项被选中");
	}

	// 将结果字符串显示在CEdit控件中  
	pEditResult->SetWindowText(strResult);
}


void CMFCApplicationDlg::OnBnClickedButton3()
{
	/// 假设你的ComboBox控件的ID为IDC_COMBO_OPTIONS  
	// 并且你的CEdit控件的ID为IDC_EDIT_RESULT  

	// 获取ComboBox和CEdit的指针  
	CComboBox* pComboOptions = (CComboBox*)GetDlgItem(IDC_COMBO_OPTIONS);
	CEdit* pEditResult = (CEdit*)GetDlgItem(IDC_EDIT4);

	if (pComboOptions && pEditResult)
	{
		// 获取ComboBox的当前选择  
		int nSel = pComboOptions->GetCurSel();
		if (nSel != CB_ERR) // CB_ERR表示没有选择项  
		{
			// 获取选中的文本  
			CString strSelected;
			pComboOptions->GetLBText(nSel, strSelected);

			// 或者，如果你知道选项的顺序和文本，可以直接根据索引设置文本  
			// 例如：  
			// CString strResult;  
			// switch (nSel)  
			// {  
			// case 0: strResult = _T("你选择了第一选项"); break;  
			// case 1: strResult = _T("你选择了第二选项"); break;  
			// case 2: strResult = _T("你选择了第三选项"); break;  
			// }  

			// 将选中的文本显示在CEdit控件中  
			pEditResult->SetWindowText(strSelected); // 或者使用strResult，如果你使用了switch语句  
		}
		else
		{
			// 没有选项被选中，可以设置默认的文本或进行错误处理  
			pEditResult->SetWindowText(_T("没有选项被选中"));
		}
	}
}
