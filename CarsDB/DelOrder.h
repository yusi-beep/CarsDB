#pragma once


// DelOrder dialog

class DelOrder : public CDialogEx
{
	DECLARE_DYNAMIC(DelOrder)

public:
	DelOrder(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DelOrder();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEL_ORDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	long m_DelOrde;
};
