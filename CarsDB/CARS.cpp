// CARS.h : Implementation of the CCARS class



// CCARS implementation

// code generated on 10 март 2021 г., 10:51

#include "pch.h"
#include "CARS.h"
IMPLEMENT_DYNAMIC(CCARS, CRecordset)

CCARS::CCARS(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_brand = L"";
	m_model = L"";
	m_car_year = 0;
	m_HP = 0;
	m_RAMAnumber = L"";
	m_enginenumber = L"";
	m_price = 0.0;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CCARS::GetDefaultConnect()
{
	return _T("DSN=cars;DBQ=D:\\cars.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CCARS::GetDefaultSQL()
{
	return _T("[CARS]");
}

void CCARS::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Text(pFX, _T("[brand]"), m_brand);
	RFX_Text(pFX, _T("[model]"), m_model);
	RFX_Long(pFX, _T("[car_year]"), m_car_year);
	RFX_Long(pFX, _T("[HP]"), m_HP);
	RFX_Text(pFX, _T("[RAMA_number]"), m_RAMAnumber);
	RFX_Text(pFX, _T("[engine_number]"), m_enginenumber);
	RFX_Double(pFX, _T("[price]"), m_price);

}
/////////////////////////////////////////////////////////////////////////////
// CCARS diagnostics

#ifdef _DEBUG
void CCARS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCARS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


