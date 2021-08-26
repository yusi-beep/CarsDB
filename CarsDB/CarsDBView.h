
// CarsDBView.h : interface of the CCarsDBView class
//

#pragma once


class CCarsDBView : public CScrollView
{
protected: // create from serialization only
	CCarsDBView() noexcept;
	DECLARE_DYNCREATE(CCarsDBView)

// Attributes
public:
	CCarsDBDoc* GetDocument() const;
	CCARS *cset;
	CFIRMS *fset;
	CORDERS *oset;
	CCARS_MULTI *mset;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCarsDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	int flag;
	CString sortby;
	afx_msg void OnDeleteCar();
	afx_msg void OnViewCars();
	afx_msg void OnViewFirms();
	afx_msg void OnViewOrders();
	afx_msg void OnDeleteFirm();
	afx_msg void OnDeleteOrder();
	afx_msg void OnViewSor();
	afx_msg void OnServicesClear();
	afx_msg void OnAddCar();
	afx_msg void OnAddFirm();
	afx_msg void OnAddOrder();
	afx_msg void OnUpdateCar();
	afx_msg void OnUpdateCompany();
};

#ifndef _DEBUG  // debug version in CarsDBView.cpp
inline CCarsDBDoc* CCarsDBView::GetDocument() const
   { return reinterpret_cast<CCarsDBDoc*>(m_pDocument); }
#endif

