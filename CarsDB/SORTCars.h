#pragma once


// SORTCars dialog

class SORTCars : public CDialogEx
{
	DECLARE_DYNAMIC(SORTCars)

public:
	SORTCars(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SORTCars();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEW_SORT_CARS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_sortby;
};
