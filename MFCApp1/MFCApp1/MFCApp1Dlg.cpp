
// MFCApp1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApp1.h"
#include "MFCApp1Dlg.h"
#include "afxdialogex.h"
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApp1Dlg 对话框



CMFCApp1Dlg::CMFCApp1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApp1Dlg::IDD, pParent)
	, m_IOdata(_T(""))
	, m_StrzDoulb1(_T(""))
	, m_StrzDoulb2(_T(""))
	, m_data1(0)
	, m_data2(0)
	, m_double1(0)
	, m_double2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApp1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_IOData);
}

BEGIN_MESSAGE_MAP(CMFCApp1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApp1Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApp1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApp1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApp1Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApp1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApp1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApp1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApp1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApp1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApp1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApp1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApp1Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApp1Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApp1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApp1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApp1Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApp1Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApp1Dlg::OnBnClickedButton18)
END_MESSAGE_MAP()


// CMFCApp1Dlg 消息处理程序

BOOL CMFCApp1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
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

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApp1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApp1Dlg::OnPaint()
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
HCURSOR CMFCApp1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApp1Dlg::OnBnClickedButton14()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "0";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "1";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_IOData += "+";
	//UpdateData(FALSE);
	m_StrzDoulb1 = m_IOData;
	m_data2 = 1;
	m_data1 = 0;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton15()
{
	// TODO:  在此添加控件通知处理程序代码

	
	m_double1 = atof(m_StrzDoulb1);
	m_StrzDoulb2 = m_IOData.Right(m_data1);
	m_double2 = atof(m_StrzDoulb2);
	double m_double3;
	switch (m_data2)
	{
	case 1:
		m_double3 = m_double1 + m_double2;
		break;
	case 2:
		m_double3 = m_double1 - m_double2;
		break;
	case 3:
		m_double3 = m_double1 * m_double2;
		break;
	case 4:
		if (m_double2 == 0)
		{
			printf("被除数不能为0 %s",m_double3);
		}
		else
		{
			m_double3 = m_double1 / m_double2;
		}
		break;
	default:
		break;
	}
	m_IOData.Format("%0.2f", m_double3);
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "2";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "3";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "4";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "5";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "6";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton9()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "7";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton10()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "8";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton11()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	m_IOData += "9";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton13()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (-1 == m_IOData.Find("."))
	{
		m_IOData += ".";
	}
	//m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton8()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_IOData += "-";
	m_StrzDoulb1 = m_IOData;
	m_data2 = 2;
	m_data1 = 0;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton12()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_IOData += "*";
	m_StrzDoulb1 = m_IOData;
	m_data2 = 3;
	m_data1 = 0;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton16()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_IOData += "/";
	UpdateData(FALSE);
	m_StrzDoulb1 = m_IOData;
	m_data2 = 4;
	m_data1 = 0;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton17()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!m_IOData.IsEmpty())
	{
		m_IOData = m_IOData.Left(m_IOData.GetLength() - 1);
	}
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton18()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_data1 = 0;
	m_data2 = 0;
	m_double1 = 0;
	m_double2 = 0;
	m_IOData = " ";
	m_StrzDoulb1 = " ";
	m_StrzDoulb2 = " ";
	UpdateData(FALSE);
}
