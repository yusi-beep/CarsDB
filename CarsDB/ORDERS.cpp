// ORDERS.h : Implementation of the CORDERS class



// CORDERS implementation

// code generated on 10 март 2021 г., 10:52

#include "pch.h"
#include "ORDERS.h"
IMPLEMENT_DYNAMIC(CORDERS, CRecordset)

CORDERS::CORDERS(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_order_num = 0;
	m_taxnum = L"";
	m_order;
	m_brand_model = L"";
	m_RAMA_num = L"";
	m_number_of_cars = 0;
	m_total = 0.0;
	m_pay = FALSE;
	m_limit_days = 0;
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CORDERS::GetDefaultConnect()
{
	return _T("DSN=cars;DBQ=D:\\cars.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CORDERS::GetDefaultSQL()
{
	return _T("[ORDERS]");
}

void CORDERS::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[order_num]"), m_order_num);
	RFX_Text(pFX, _T("[taxnum]"), m_taxnum);
	RFX_Date(pFX, _T("[order]"), m_order);
	RFX_Text(pFX, _T("[brand_model]"), m_brand_model);
	RFX_Text(pFX, _T("[RAMA_num]"), m_RAMA_num);
	RFX_Long(pFX, _T("[number_of_cars]"), m_number_of_cars);
	RFX_Double(pFX, _T("[total]"), m_total);
	RFX_Bool(pFX, _T("[pay]"), m_pay);
	RFX_Long(pFX, _T("[limit_days]"), m_limit_days);

}
/////////////////////////////////////////////////////////////////////////////
// CORDERS diagnostics

#ifdef _DEBUG
void CORDERS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CORDERS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


