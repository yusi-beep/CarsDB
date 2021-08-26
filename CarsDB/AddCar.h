#pragma once


// AddCar dialog

class AddCar : public CDialogEx
{
	DECLARE_DYNAMIC(AddCar)

public:
	AddCar(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddCar();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_CAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CString m_aBrand;
	CString m_aModel;
	CString m_aRNum;
	double m_aPrice;
	long m_aHP;
	long m_aYear;
	CString m_aENum;
};
