// SORTCars.cpp : implementation file
//

#include "pch.h"
#include "CarsDB.h"
#include "SORTCars.h"
#include "afxdialogex.h"


// SORTCars dialog

IMPLEMENT_DYNAMIC(SORTCars, CDialogEx)

SORTCars::SORTCars(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VIEW_SORT_CARS, pParent)
	, m_sortby(_T(""))
{

}

SORTCars::~SORTCars()
{
}

void SORTCars::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_sortby);
}


BEGIN_MESSAGE_MAP(SORTCars, CDialogEx)
END_MESSAGE_MAP()


// SORTCars message handlers
