// DelCar.cpp : implementation file
//

#include "pch.h"
#include "CarsDB.h"
#include "DelCar.h"
#include "afxdialogex.h"


// DelCar dialog

IMPLEMENT_DYNAMIC(DelCar, CDialogEx)

DelCar::DelCar(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEL_CAR, pParent)
	, m_delCar(_T(""))
{

}

DelCar::~DelCar()
{
}

void DelCar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_delCar);
}


BEGIN_MESSAGE_MAP(DelCar, CDialogEx)
END_MESSAGE_MAP()


// DelCar message handlers
