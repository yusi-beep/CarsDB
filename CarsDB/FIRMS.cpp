// FIRMS.h : Implementation of the CFIRMS class



// CFIRMS implementation

// code generated on 10 март 2021 г., 10:51

#include "pch.h"
#include "FIRMS.h"
IMPLEMENT_DYNAMIC(CFIRMS, CRecordset)

CFIRMS::CFIRMS(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_company = L"";
	m_taxnum = L"";
	m_address = L"";
	m_number = L"";
	m_city = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CFIRMS::GetDefaultConnect()
{
	return _T("DSN=cars;DBQ=D:\\cars.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CFIRMS::GetDefaultSQL()
{
	return _T("[FIRMS]");
}

void CFIRMS::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Text(pFX, _T("[company]"), m_company);
	RFX_Text(pFX, _T("[taxnum]"), m_taxnum);
	RFX_Text(pFX, _T("[address]"), m_address);
	RFX_Text(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[city]"), m_city);

}
/////////////////////////////////////////////////////////////////////////////
// CFIRMS diagnostics

#ifdef _DEBUG
void CFIRMS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFIRMS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


