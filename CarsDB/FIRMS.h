// FIRMS.h : Declaration of the CFIRMS

#pragma once

// code generated on 10 март 2021 г., 10:51

class CFIRMS : public CRecordset
{
public:
	CFIRMS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFIRMS)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	CStringW	m_company;
	CStringW	m_taxnum;
	CStringW	m_address;
	CString		m_number;
	CStringW	m_city;

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


