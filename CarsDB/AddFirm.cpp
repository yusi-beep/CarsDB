// AddFirm.cpp : implementation file
//

#include "pch.h"
#include "CarsDB.h"
#include "AddFirm.h"
#include "afxdialogex.h"


// AddFirm dialog

IMPLEMENT_DYNAMIC(AddFirm, CDialogEx)

AddFirm::AddFirm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_FIRM, pParent)
	, m_aTaxNum(_T(""))
	, m_aCompany(_T(""))
	, m_aAddress(_T(""))
	, m_aTel(_T(""))
	, m_aCity(_T(""))
{

}

AddFirm::~AddFirm()
{
}

void AddFirm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_aTaxNum);
	DDX_Text(pDX, IDC_EDIT2, m_aCompany);
	DDX_Text(pDX, IDC_EDIT3, m_aAddress);
	DDX_Text(pDX, IDC_EDIT4, m_aTel);
	DDX_Text(pDX, IDC_EDIT5, m_aCity);
}


BEGIN_MESSAGE_MAP(AddFirm, CDialogEx)
END_MESSAGE_MAP()


// AddFirm message handlers
