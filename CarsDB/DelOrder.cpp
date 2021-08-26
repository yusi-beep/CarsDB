// DelOrder.cpp : implementation file
//

#include "pch.h"
#include "CarsDB.h"
#include "DelOrder.h"
#include "afxdialogex.h"


// DelOrder dialog

IMPLEMENT_DYNAMIC(DelOrder, CDialogEx)

DelOrder::DelOrder(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEL_ORDER, pParent)
	, m_DelOrde(0)
{

}

DelOrder::~DelOrder()
{
}

void DelOrder::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_DelOrde);
}


BEGIN_MESSAGE_MAP(DelOrder, CDialogEx)
END_MESSAGE_MAP()


// DelOrder message handlers
