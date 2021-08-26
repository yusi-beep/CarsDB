
// CarsDBView.cpp : implementation of the CCarsDBView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CarsDB.h"
#endif

#include "CarsDBDoc.h"
#include "CarsDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCarsDBView

IMPLEMENT_DYNCREATE(CCarsDBView, CScrollView)

BEGIN_MESSAGE_MAP(CCarsDBView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_DELETE_CAR, &CCarsDBView::OnDeleteCar)
	ON_COMMAND(ID_VIEW_CARS, &CCarsDBView::OnViewCars)
	ON_COMMAND(ID_VIEW_FIRMS, &CCarsDBView::OnViewFirms)
	ON_COMMAND(ID_VIEW_ORDERS, &CCarsDBView::OnViewOrders)
	ON_COMMAND(ID_DELETE_FIRM, &CCarsDBView::OnDeleteFirm)
	ON_COMMAND(ID_DELETE_ORDER, &CCarsDBView::OnDeleteOrder)
	ON_COMMAND(ID_VIEW_SOR, &CCarsDBView::OnViewSor)
	ON_COMMAND(ID_SERVICES_CLEAR, &CCarsDBView::OnServicesClear)
	ON_COMMAND(ID_ADD_CAR, &CCarsDBView::OnAddCar)
	ON_COMMAND(ID_ADD_FIRM, &CCarsDBView::OnAddFirm)
	ON_COMMAND(ID_ADD_ORDER, &CCarsDBView::OnAddOrder)
	ON_COMMAND(ID_UPDATE_CAR, &CCarsDBView::OnUpdateCar)
	ON_COMMAND(ID_UPDATE_COMPANY, &CCarsDBView::OnUpdateCompany)
END_MESSAGE_MAP()

// CCarsDBView construction/destruction

CCarsDBView::CCarsDBView() noexcept
{
	// TODO: add construction code here
	flag = 0;
	sortby = "";

}

CCarsDBView::~CCarsDBView()
{
}

BOOL CCarsDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CCarsDBView drawing

void CCarsDBView::OnDraw(CDC* pDC)
{
	CCarsDBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	int y = 10;
	CString str;
	switch (flag)
	{
	case 1:
	{
		cset->MoveFirst();
		while (!cset->IsEOF())
		{
			pDC->TextOutW(5, y, cset->m_brand);
			pDC->TextOutW(120, y, cset->m_model);
			str.Format(_T("%d"), cset->m_car_year);
			pDC->TextOutW(220, y, str);
			pDC->TextOutW(270, y, cset->m_enginenumber);
			str.Format(_T("%d"), cset->m_HP);
			pDC->TextOutW(470, y, str);
			pDC->TextOutW(550, y, cset->m_RAMAnumber);
			str.Format(_T("%15.2f"), cset->m_price);
			pDC->TextOutW(720, y, str);
			cset->MoveNext();
			y += 20;
		}

	}break;
	case 2:
	{
		fset->MoveFirst();
		while (!fset->IsEOF())
		{
			pDC->TextOutW(5, y, fset->m_company);
			pDC->TextOutW(100, y, fset->m_taxnum);
			pDC->TextOutW(200, y, fset->m_city);
			pDC->TextOutW(300, y, fset->m_number);
			pDC->TextOutW(420, y, fset->m_address);
			fset->MoveNext();
			y += 20;
		}
	}break;
	case 3:

	{
		mset->MoveFirst();
		while (!mset->IsEOF())
		{
			str.Format(_T("%d"), mset->m_ORDERSorder_num);
			pDC->TextOutW(5, y, str);
			pDC->TextOutW(20, y, mset->m_FIRMStaxnum);
			str = mset->m_ORDERSorder.Format("%d.%m.%y");
			pDC->TextOutW(150, y, str);
			str.Format(_T("%s %s"), mset->m_CARSbrand, mset->m_CARSmodel);
			pDC->TextOutW(250, y, str);
			pDC->TextOutW(400, y, mset->m_CARSRAMAnumber);
			str.Format(_T("%d"), mset->m_ORDERSnumber_of_cars);
			pDC->TextOutW(600, y, str);
			str.Format(_T("%15.2f"), mset->m_ORDERStotal);
			pDC->TextOutW(660, y, str);
			//pDC->TextOutW(600, y, mset->m_ORDERSpay);
			str.Format(_T("%ld"), mset->m_ORDERSlimit_days);
			pDC->TextOutW(810, y, str);
			mset->MoveNext();
			y += 20;
			

		}break;
		case 4:

			{
				if (cset->IsOpen()) cset->Close();
				cset->m_strSort = sortby;
				cset->Open();
				cset->MoveFirst();
				while (!cset->IsEOF())
				{
					pDC->TextOutW(5, y, cset->m_brand);
					pDC->TextOutW(180, y, cset->m_model);
					str.Format(_T("%d"), cset->m_car_year);
					pDC->TextOutW(280, y, str);
					str.Format(_T("%d"), cset->m_HP);
					pDC->TextOutW(480, y, str);
					pDC->TextOutW(620, y, cset->m_RAMAnumber);
					pDC->TextOutW(780, y, cset->m_enginenumber);
					str.Format(_T("%15.2f"), cset->m_price);
					pDC->TextOutW(960, y, str);
					cset->MoveNext();
					y += 20;
				}
				cset->Close();
				cset->m_strSort = "";
				cset->Open();
			}break;
		}
	}
	
}

void CCarsDBView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
	cset = &GetDocument()->c;
	if (cset->IsOpen())cset->Close();
	cset->Open();
	fset = &GetDocument()->f;
	if (fset->IsOpen())fset->Close();
	fset->Open();
	oset = &GetDocument()->o;
	if (oset->IsOpen())oset->Close();
	oset->Open();
	mset = &GetDocument()->m;
	mset->m_strFilter = "ORDERS.taxnum=FIRMS.taxnum AND ORDERS.RAMA_num=CARS.RAMA_number";
	if (mset->IsOpen())mset->Close();
	mset->Open();
}


// CCarsDBView printing

BOOL CCarsDBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCarsDBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCarsDBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCarsDBView diagnostics

#ifdef _DEBUG
void CCarsDBView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCarsDBView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCarsDBDoc* CCarsDBView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCarsDBDoc)));
	return (CCarsDBDoc*)m_pDocument;
}
#endif //_DEBUG


// CCarsDBView message handlers

void CCarsDBView::OnServicesClear()
{
	// TODO: Add your command handler code here
	flag = 0;
	Invalidate();
}

void CCarsDBView::OnViewCars()
{
	// TODO: Add your command handler code here
	flag = 1;
	Invalidate();
}


void CCarsDBView::OnViewFirms()
{
	// TODO: Add your command handler code here
	flag = 2;
	Invalidate();
}


void CCarsDBView::OnViewOrders()
{
	// TODO: Add your command handler code here
	flag = 3;
	Invalidate();
}


void CCarsDBView::OnViewSor()
{
	// TODO: Add your command handler code here
	SORTCars dlg;
	if (dlg.DoModal() == IDOK)
	{
		if (dlg.m_sortby == "Marka")
			sortby = "brand";
		else
		{
			if (dlg.m_sortby == "Model")
				sortby = "model";
			else
			{
				if (dlg.m_sortby == "Godina")
					sortby = "car_year";
				else
				{
					if (dlg.m_sortby == "Konski sili")
						sortby = "HP";
					else
					{
						if (dlg.m_sortby == "Nomer na RAMA")
							sortby = "RAMA_number";
						else
						{
							if (dlg.m_sortby == "Nomer na dvigatel")
								sortby = "engine_number";
							else
							{
								if (dlg.m_sortby == "Cena")
									sortby = "Price";
							}
						}
					}
				}
			}
		}
		flag = 4;
		Invalidate();
	}
}


void CCarsDBView::OnDeleteCar()
{
	// TODO: Add your command handler code here
	DelCar dlg;
	CString str;
	if (dlg.DoModal() == IDOK)
	{
		cset->MoveFirst();
		while (!cset->IsEOF() && cset->m_RAMAnumber != dlg.m_delCar)
		{
			cset->MoveNext();
		}
		if (cset->IsEOF())
		{
			str.Format(_T("Nqma kola s s nomer na RAMA: %s"), dlg.m_delCar);
			MessageBox(str, _T("Informaciq"), MB_ICONSTOP);
		}
		else
		{
			str.Format(_T("%s\n%s\n%d\n Delete?"), cset->m_brand, cset->m_model, cset->m_car_year);
			if (MessageBox(str, _T("Delete"), MB_YESNO + MB_ICONEXCLAMATION) == IDYES)
			{
				oset->MoveFirst();
				while (!oset->IsEOF())
				{
					if (oset->m_RAMA_num == dlg.m_delCar)
					{
						oset->Delete();
						oset->MovePrev();
					}
					oset->MoveNext();
				}
				oset->Close();
				oset->Open();
				cset->Delete();
				cset->MovePrev();
			}
		}

	}
	
}


void CCarsDBView::OnDeleteFirm()
{
	// TODO: Add your command handler code here
	DelFirm dlg;
	CString str;
	if (dlg.DoModal() == IDOK)
	{
		fset->MoveFirst();
		while (!fset->IsEOF() && fset->m_taxnum != dlg.m_delFirm)
		{
			fset->MoveNext();
		}
		if (fset->IsEOF())
		{
			str.Format(_T("Nqma firma s taxnum %s"), dlg.m_delFirm);
			MessageBox(str, _T("Informaciq"), MB_ICONSTOP);
		}
		else
		{
			str.Format(_T("%s\n%s\n%s\n"), fset->m_company, fset->m_city, fset->m_address);
			if (MessageBox(str, _T("Delete"), MB_YESNO + MB_ICONEXCLAMATION) == IDYES)
			{
				oset->MoveFirst();
				while (!oset->IsEOF())
				{
					if (oset->m_taxnum == dlg.m_delFirm)
					{
						oset->Delete();
						oset->MovePrev();
					}
					oset->MoveNext();
				}
				oset->Close();
				oset->Open();
				fset->Delete();
				fset->MovePrev();

			}

		}

	}
}


void CCarsDBView::OnDeleteOrder()
{
	// TODO: Add your command handler code here
	DelOrder dlg;
	CString str;
	if (dlg.DoModal() == IDOK)
	{
		oset->MoveFirst();
		while (!oset->IsEOF() && oset->m_order_num != dlg.m_DelOrde)
		{
			oset->MoveNext();
		}
		if (oset->IsEOF())
		{
			str.Format(_T("Nqma poruchka s nomer %s"), dlg.m_DelOrde);
			MessageBox(str, _T("Informaciq"), MB_ICONSTOP);
		}
		else
		{
			str.Format(_T("%s\n%s\n%s\n"), oset->m_taxnum, oset->m_brand_model, oset->m_RAMA_num);
			if (MessageBox(str, _T("Delete"), MB_YESNO + MB_ICONEXCLAMATION) == IDYES)
			{

				oset->Delete();
				oset->MovePrev();
			}
			oset->Close();
			oset->Open();

		}
	}
}





	

void CCarsDBView::OnAddCar()
{
	// TODO: Add your command handler code here
	AddCar dlg;
	cset->AddNew();
	if (dlg.DoModal() == IDOK)
	{
		cset->m_brand = dlg.m_aBrand;
		cset->m_car_year = dlg.m_aYear;
		cset->m_enginenumber = dlg.m_aENum;
		cset->m_HP = dlg.m_aHP;
		cset->m_model = dlg.m_aModel;
		cset->m_price = dlg.m_aPrice;
		cset->m_RAMAnumber = dlg.m_aRNum;
		cset->Update();
		cset->MoveLast();
	}
}



void CCarsDBView::OnAddFirm()
{
	// TODO: Add your command handler code here
	AddFirm dlg;
	fset->AddNew();
	if (dlg.DoModal() == IDOK)
	{
		fset->m_taxnum = dlg.m_aTaxNum;
		fset->m_company = dlg.m_aCompany;
		fset->m_address = dlg.m_aAddress;
		fset->m_number = dlg.m_aTel;
		fset->m_city = dlg.m_aCity;
		fset->Update();
		fset->MoveLast();
	}
}



void CCarsDBView::OnAddOrder()
{
	// TODO: Add your command handler code here
	AddOrder dlg;
	if (dlg.DoModal() == IDOK)
	{
		
		oset->MoveLast();

		
		long new_ID = oset->m_order_num + 1;
		oset->AddNew();
		oset->m_order_num = new_ID;
		oset->m_brand_model = dlg.m_aBrand;
		oset->m_limit_days = dlg.m_aLimit;
		oset->m_number_of_cars = dlg.m_aNumCars;
		oset->m_pay = dlg.m_aPay;
		oset->m_RAMA_num = dlg.m_aRamaNumber;
		oset->m_taxnum = dlg.m_aTaxnum;
		oset->m_total = dlg.m_aTotal;
		oset->m_order = GetCurrentTime();

		oset->Update();
		oset->Requery();
		oset->MoveLast();
	}
}




void CCarsDBView::OnUpdateCar()
{
	// TODO: Add your command handler code here
	DelCar dlg;
	if (dlg.DoModal() == IDOK)
	{
		if (!cset->IsOpen()) cset->Open();
		cset->MoveFirst();
		while (!cset->IsEOF() && cset->m_RAMAnumber != dlg.m_delCar)
		{
			cset->MoveNext();
		}
		if (cset->IsEOF())
		{
			CString str;
			str.Format(_T("There isn't car with frame number %d"), dlg.m_delCar);
			MessageBox(str, _T("Warning"), MB_ICONSTOP);
		}
		else
		{
			cset->Edit();
			AddCar c;

			c.m_aBrand = cset->m_brand;
			c.m_aENum = cset->m_enginenumber;
			c.m_aHP = cset->m_HP;
			c.m_aModel = cset->m_model;
			c.m_aPrice = cset->m_price;
			c.m_aRNum = cset->m_RAMAnumber;
			c.m_aYear = cset->m_car_year;
			UpdateData(FALSE);
			if (c.DoModal() == IDOK)
			{
				cset->m_brand = c.m_aBrand;
				cset->m_enginenumber = c.m_aENum;
				cset->m_HP = c.m_aHP;
				cset->m_model = c.m_aModel;
				cset->m_price = c.m_aPrice;
				cset->m_RAMAnumber = c.m_aRNum;
				cset->m_car_year = c.m_aYear;
				cset->Update();
			}
		}

	}
}



void CCarsDBView::OnUpdateCompany()
{
	// TODO: Add your command handler code here
	DelFirm dlg;
	if (dlg.DoModal() == IDOK)
	{
		if (!fset->IsOpen()) fset->Open();
		fset->MoveFirst();
		while (!fset->IsEOF() && fset->m_taxnum != dlg.m_delFirm)
		{
			fset->MoveNext();
		}
		if(fset->IsEOF())
		{
			CString str;
			str.Format(_T("This company whit tax number %s not exists!"), dlg.m_delFirm);
			MessageBox(str, _T("Change"), MB_ICONSTOP);
		}
		else
		{
			fset->Edit();
			AddFirm f;
			f.m_aAddress = fset->m_address;
			f.m_aCity = fset->m_city;
			f.m_aCompany = fset->m_company;
			f.m_aTaxNum = fset->m_taxnum;
			f.m_aTel = fset->m_number;
			UpdateData(FALSE);
			if (f.DoModal() == IDOK)
			{
				fset->m_address = f.m_aAddress;
				fset->m_city = f.m_aCity;
				fset->m_company = f.m_aCompany;
				fset->m_taxnum = f.m_aTaxNum;
				fset->m_number = f.m_aTel;
				fset->Update();
			}
		}
	}
}
/*
1.Не може да се добавя поръчка.
	Грешка:
	You cannot add or change a record because a related record is required in table "FIRMS".
2.






*/