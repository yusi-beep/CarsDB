// AddOrder.cpp : implementation file
//

#include "pch.h"
#include "CarsDB.h"
#include "AddOrder.h"
#include "afxdialogex.h"
#include "CARS.h"
#include "FIRMS.h"


// AddOrder dialog

IMPLEMENT_DYNAMIC(AddOrder, CDialogEx)

AddOrder::AddOrder(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_ORDER, pParent)
	, m_aTaxnum(_T(""))
	, m_aRamaNumber(_T(""))
	, m_aBrand(_T(""))
	, m_aNumCars(0)
	, m_aPay(FALSE)
	, m_aLimit(0)
{

}

AddOrder::~AddOrder()
{
}

void AddOrder::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_aTaxnum);
	DDX_CBString(pDX, IDC_COMBO2, m_aRamaNumber);
	DDX_Text(pDX, IDC_brand, m_aBrand);
	DDX_Text(pDX, IDC_numbercars, m_aNumCars);
	DDX_Text(pDX, IDC_total, m_aTotal);
	DDX_Check(pDX, IDC_pay, m_aPay);
	DDX_Text(pDX, IDC_limit, m_aLimit);
}


BEGIN_MESSAGE_MAP(AddOrder, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &AddOrder::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &AddOrder::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// AddOrder message handlers



BOOL AddOrder::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CCARS cset;
	cset.Open();
	CComboBox* c = (CComboBox*)GetDlgItem(IDC_COMBO2);

	c->ResetContent();

	while (!cset.IsEOF())
	{
		c->AddString(cset.m_RAMAnumber);
		cset.MoveNext();
	}
	cset.Close();

	CFIRMS fset;
	fset.Open();
	CComboBox* f = (CComboBox*)GetDlgItem(IDC_COMBO1);
	fset.MoveFirst();
	f->ResetContent();
	CString str;
	while (!fset.IsEOF())
	{
		f->AddString(fset.m_taxnum);
		fset.MoveNext();
	}
	fset.Close();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}



void AddOrder::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	/*CFIRMS f;
	f.Open();
	CComboBox* pfirm = (CComboBox*)GetDlgItem(IDC_COMBO1);
	long l = pfirm->GetCurSel();
	f.SetAbsolutePosition(l + 1);
	
	UpdateData(FALSE);
	f.Close();*/
}


void AddOrder::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	CCARS c;
	c.Open();
	CComboBox* pcars = (CComboBox*)GetDlgItem(IDC_COMBO2);
	long l = pcars->GetCurSel();
	c.SetAbsolutePosition(l + 1);
	CString str;
	str.Format(_T("%s %s"), c.m_brand, c.m_model);
	m_aBrand = str;
	UpdateData(FALSE);
	c.Close();
}
