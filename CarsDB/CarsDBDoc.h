
// CarsDBDoc.h : interface of the CCarsDBDoc class
//


#pragma once
#include "CARS.h"
#include "FIRMS.h"
#include "ORDERS.h"
#include "SORTCars.h"
#include "CARS_MULTI.h"
#include "DelCar.h"
#include "DelFirm.h"
#include "DelOrder.h"
#include "AddCar.h"
#include "AddFirm.h"
#include "AddOrder.h"


class CCarsDBDoc : public CDocument
{
protected: // create from serialization only
	CCarsDBDoc() noexcept;
	DECLARE_DYNCREATE(CCarsDBDoc)

// Attributes
public:
	CCARS c;
	CFIRMS f;
	CORDERS o;
	CCARS_MULTI m;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CCarsDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
