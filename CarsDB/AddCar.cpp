// AddCar.cpp : implementation file
//

#include "pch.h"
#include "CarsDB.h"
#include "AddCar.h"
#include "afxdialogex.h"


// AddCar dialog

IMPLEMENT_DYNAMIC(AddCar, CDialogEx)

AddCar::AddCar(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_CAR, pParent)
	, m_aBrand(_T(""))
	, m_aModel(_T(""))
	, m_aRNum(_T(""))
	,m_aPrice(0.0)
	, m_aHP(0)
	, m_aYear(0)
	, m_aENum(_T(""))
{

}

AddCar::~AddCar()
{
}

void AddCar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_aBrand);
	DDX_Text(pDX, IDC_EDIT1, m_aModel);
	DDX_Text(pDX, IDC_EDIT2, m_aRNum);
	DDX_Text(pDX, IDC_EDIT3, m_aPrice);
	DDX_Text(pDX, IDC_EDIT4, m_aHP);
	DDX_Text(pDX, IDC_EDIT5, m_aYear);
	DDX_Text(pDX, IDC_EDIT6, m_aENum);
}


BEGIN_MESSAGE_MAP(AddCar, CDialogEx)
END_MESSAGE_MAP()


// AddCar message handlers
