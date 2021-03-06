// CARS_MULTI.h : Declaration of the CCARS_MULTI

#pragma once

// code generated on 10 март 2021 г., 10:52

class CCARS_MULTI : public CRecordset
{
public:
	CCARS_MULTI(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCARS_MULTI)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	CStringW	m_CARSbrand;
	CStringW	m_CARSmodel;
	long	m_CARScar_year;
	long	m_CARSHP;
	CStringW	m_CARSRAMAnumber;
	CStringW	m_CARSenginenumber;
	double	m_CARSprice;
	CStringW	m_FIRMScompany;
	CStringW	m_FIRMStaxnum;
	CStringW	m_FIRMSaddress;
	CStringW	m_FIRMSnumber;
	CStringW	m_FIRMScity;
	long	m_ORDERSorder_num;
	CStringW	m_ORDERStaxnum;
	CTime	m_ORDERSorder;
	CStringW	m_ORDERSbrand_model;
	CStringW	m_ORDERSRAMA_num;
	long	m_ORDERSnumber_of_cars;
	double	m_ORDERStotal;
	BOOL	m_ORDERSpay;
	long	m_ORDERSlimit_days;

// Overrides
	// Wizard generated virtual function overrides
	public:
	virtual CString GetDefaultConnect();	// Default connection string

	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


