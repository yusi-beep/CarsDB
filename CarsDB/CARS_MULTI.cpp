// CARS_MULTI.h : Implementation of the CCARS_MULTI class



// CCARS_MULTI implementation

// code generated on 10 март 2021 г., 10:52

#include "pch.h"
#include "CARS_MULTI.h"
IMPLEMENT_DYNAMIC(CCARS_MULTI, CRecordset)

CCARS_MULTI::CCARS_MULTI(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_CARSbrand = L"";
	m_CARSmodel = L"";
	m_CARScar_year = 0;
	m_CARSHP = 0;
	m_CARSRAMAnumber = L"";
	m_CARSenginenumber = L"";
	m_CARSprice = 0.0;
	m_FIRMScompany = L"";
	m_FIRMStaxnum = L"";
	m_FIRMSaddress = L"";
	m_FIRMSnumber = L"";
	m_FIRMScity = L"";
	m_ORDERSorder_num = 0;
	m_ORDERStaxnum = L"";
	m_ORDERSorder;
	m_ORDERSbrand_model = L"";
	m_ORDERSRAMA_num = L"";
	m_ORDERSnumber_of_cars = 0;
	m_ORDERStotal = 0.0;
	m_ORDERSpay = FALSE;
	m_ORDERSlimit_days = 0;
	m_nFields = 21;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CCARS_MULTI::GetDefaultConnect()
{
	return _T("DSN=cars;DBQ=D:\\cars.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CCARS_MULTI::GetDefaultSQL()
{
	return _T("[CARS],[FIRMS],[ORDERS]");
}

void CCARS_MULTI::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Text(pFX, _T("[CARS].[brand]"), m_CARSbrand);
	RFX_Text(pFX, _T("[CARS].[model]"), m_CARSmodel);
	RFX_Long(pFX, _T("[CARS].[car_year]"), m_CARScar_year);
	RFX_Long(pFX, _T("[CARS].[HP]"), m_CARSHP);
	RFX_Text(pFX, _T("[CARS].[RAMA_number]"), m_CARSRAMAnumber);
	RFX_Text(pFX, _T("[CARS].[engine_number]"), m_CARSenginenumber);
	RFX_Double(pFX, _T("[CARS].[price]"), m_CARSprice);
	RFX_Text(pFX, _T("[FIRMS].[company]"), m_FIRMScompany);
	RFX_Text(pFX, _T("[FIRMS].[taxnum]"), m_FIRMStaxnum);
	RFX_Text(pFX, _T("[FIRMS].[address]"), m_FIRMSaddress);
	RFX_Text(pFX, _T("[FIRMS].[number]"), m_FIRMSnumber);
	RFX_Text(pFX, _T("[FIRMS].[city]"), m_FIRMScity);
	RFX_Long(pFX, _T("[ORDERS].[order_num]"), m_ORDERSorder_num);
	RFX_Text(pFX, _T("[ORDERS].[taxnum]"), m_ORDERStaxnum);
	RFX_Date(pFX, _T("[ORDERS].[order]"), m_ORDERSorder);
	RFX_Text(pFX, _T("[ORDERS].[brand_model]"), m_ORDERSbrand_model);
	RFX_Text(pFX, _T("[ORDERS].[RAMA_num]"), m_ORDERSRAMA_num);
	RFX_Long(pFX, _T("[ORDERS].[number_of_cars]"), m_ORDERSnumber_of_cars);
	RFX_Double(pFX, _T("[ORDERS].[total]"), m_ORDERStotal);
	RFX_Bool(pFX, _T("[ORDERS].[pay]"), m_ORDERSpay);
	RFX_Long(pFX, _T("[ORDERS].[limit_days]"), m_ORDERSlimit_days);

}
/////////////////////////////////////////////////////////////////////////////
// CCARS_MULTI diagnostics

#ifdef _DEBUG
void CCARS_MULTI::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCARS_MULTI::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


