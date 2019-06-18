
// MFCApp1Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApp1Dlg �Ի���



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


// CMFCApp1Dlg ��Ϣ�������

BOOL CMFCApp1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApp1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApp1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApp1Dlg::OnBnClickedButton14()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "0";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "1";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	
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
			printf("����������Ϊ0 %s",m_double3);
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "2";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "3";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "4";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "5";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "6";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "7";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "8";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(TRUE);
	m_IOData += "9";
	m_data1 += 1;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton13()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_IOData += "-";
	m_StrzDoulb1 = m_IOData;
	m_data2 = 2;
	m_data1 = 0;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton12()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_IOData += "*";
	m_StrzDoulb1 = m_IOData;
	m_data2 = 3;
	m_data1 = 0;
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton16()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (!m_IOData.IsEmpty())
	{
		m_IOData = m_IOData.Left(m_IOData.GetLength() - 1);
	}
	UpdateData(FALSE);
}


void CMFCApp1Dlg::OnBnClickedButton18()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
