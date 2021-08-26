// DelFirm.cpp : implementation file
//

#include "pch.h"
#include "CarsDB.h"
#include "DelFirm.h"
#include "afxdialogex.h"


// DelFirm dialog

IMPLEMENT_DYNAMIC(DelFirm, CDialogEx)

DelFirm::DelFirm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEL_FIRM, pParent)
	, m_delFirm(_T(""))
{

}

DelFirm::~DelFirm()
{
}

void DelFirm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_delFirm);
}


BEGIN_MESSAGE_MAP(DelFirm, CDialogEx)
END_MESSAGE_MAP()


// DelFirm message handlers
