#pragma once


// DelCar dialog

class DelCar : public CDialogEx
{
	DECLARE_DYNAMIC(DelCar)

public:
	DelCar(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DelCar();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEL_CAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_delCar;
};
