#pragma once


// AddOrder dialog

class AddOrder : public CDialogEx
{
	DECLARE_DYNAMIC(AddOrder)

public:
	AddOrder(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddOrder();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_ORDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStringW m_aTaxnum;
	CString m_aRamaNumber;
	CString m_aBrand;
	long m_aNumCars;
	double m_aTotal;
	BOOL m_aPay;
	long m_aLimit;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
};
