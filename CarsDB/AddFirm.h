#pragma once


// AddFirm dialog

class AddFirm : public CDialogEx
{
	DECLARE_DYNAMIC(AddFirm)

public:
	AddFirm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddFirm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_FIRM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_aTaxNum;
	CString m_aCompany;
	CString m_aAddress;
	CString m_aTel;
	CString m_aCity;
};
