#pragma once


// DelFirm dialog

class DelFirm : public CDialogEx
{
	DECLARE_DYNAMIC(DelFirm)

public:
	DelFirm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DelFirm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEL_FIRM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStringW m_delFirm;
};
