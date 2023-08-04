// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface
// (the "Fluent UI") and is provided only as referential material to supplement the
// Microsoft Foundation Classes Reference and related electronic documentation
// included with the MFC C++ library software.
// License terms to copy, use or distribute the Fluent UI are available separately.
// To learn more about our Fluent UI licensing program, please visit
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// planetarymotionView.cpp : implementation of the CplanetarymotionView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "planetarymotion.h"
#endif

#include "planetarymotionDoc.h"
#include "planetarymotionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CplanetarymotionView

IMPLEMENT_DYNCREATE(CplanetarymotionView, CView)

BEGIN_MESSAGE_MAP(CplanetarymotionView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CplanetarymotionView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BUTTON2, &CplanetarymotionView::Onstart)
	ON_COMMAND(ID_BUTTON3, &CplanetarymotionView::Onresume)
	ON_COMMAND(ID_BUTTON4, &CplanetarymotionView::Onsuspend)
END_MESSAGE_MAP()

// CplanetarymotionView construction/destruction

CplanetarymotionView::CplanetarymotionView() noexcept
{
	// TODO: add construction code here
	m_thread = NULL;
	icounter = 0;
	x1 = 590;
	y1 = 240;

	x2 = 440 + 190 * cos(5);
	y2 = 240 + 190 * sin(5);

	x3 = 440 + 90 * cos(5);
	y3 = 240 + 90* sin(5);

	x4 = x2 + 30 * cos(5);
	y4 = y2 + 30 * sin(5);


}

CplanetarymotionView::~CplanetarymotionView()
{
}

BOOL CplanetarymotionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CplanetarymotionView drawing

void CplanetarymotionView::OnDraw(CDC* pDC)
{
	CplanetarymotionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen blackPen, yellowpen, violetpen, greenPen,redpen,bluepen;

	CBrush yellowBrush(RGB(255,255 , 0));
	CBrush violetBrush(RGB(127, 0, 255));
	CBrush greenBrush(RGB(0, 255, 0));
	CBrush redBrush(RGB(255, 0,  0));
	CBrush blueBrush(RGB(0, 0, 139));


	redpen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	blackPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	yellowpen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	violetpen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	greenPen.CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	bluepen.CreatePen(PS_SOLID, 2, RGB(0, 0, 139));

	CPen* pOldPen = pDC->SelectObject(&blackPen);


	/*CString strCounter;
	strCounter.Format(L"The Counter is %d", m_iCounter);*/
	pDC->Ellipse(250, 50, 635, 430);
	pDC->Ellipse(300, 100, 585, 380);
	pDC->Ellipse(350, 150, 535, 330);
	pDC->Ellipse(x2 + 30, y2 + 30, x2- 30, y2 - 30);
	CPen* pOldPen0 = pDC->SelectObject(&yellowpen);
	CBrush* pOldBrush = pDC->SelectObject(&yellowBrush);
	pDC->Ellipse(400, 200, 480, 280);
	pDC->SelectObject(pOldBrush);
	

	
	CPen* pOldPen1 = pDC->SelectObject(&violetpen);
	pOldBrush = pDC->SelectObject(&violetBrush);
	pDC->Ellipse(x1 + 15, y1 + 15, x1 - 15, y1 - 15);
	CPen* pOldPen2 = pDC->SelectObject(&greenPen);
	pDC->SelectObject(&greenBrush);
	pDC->Ellipse(x2 + 10, y2 + 10, x2 - 10, y2 - 10);

	CPen* pOldPen3 = pDC->SelectObject(&redpen);
	pDC->SelectObject(&redBrush);
	pDC->Ellipse(x3 + 20, y3 + 20, x3 - 20, y3 - 20); 
	CPen* pOldPen4 = pDC->SelectObject(&bluepen);
	//code for inner planet of last  orbit
	pDC->SelectObject(&blueBrush);
	pDC->Ellipse(x4 + 8, y4 + 8, x4 - 8, y4 - 8);

	pDC->SelectObject(pOldBrush);

	// TODO: add draw code for native data here
}


// CplanetarymotionView printing


void CplanetarymotionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CplanetarymotionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CplanetarymotionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CplanetarymotionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CplanetarymotionView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CplanetarymotionView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CplanetarymotionView diagnostics

#ifdef _DEBUG
void CplanetarymotionView::AssertValid() const
{
	CView::AssertValid();
}

void CplanetarymotionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CplanetarymotionDoc* CplanetarymotionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CplanetarymotionDoc)));
	return (CplanetarymotionDoc*)m_pDocument;
}
#endif //_DEBUG


// CplanetarymotionView message handlers


void CplanetarymotionView::Onstart()
{
	// TODO: Add your command handler code here
	//AfxMessageBox(_T("start"));
	m_thread=AfxBeginThread(CplanetarymotionView::StarThread, this);
}


void CplanetarymotionView::Onresume()
{
	// TODO: Add your command handler code here
	m_thread->ResumeThread();
}


void CplanetarymotionView::Onsuspend()
{
	// TODO: Add your command handler code here
m_thread->SuspendThread();
}


UINT CplanetarymotionView::StarThread(LPVOID Param)
{
	// TODO: Add your implementation code here.
	CplanetarymotionView* pView = (CplanetarymotionView*)Param;
		double j = 0;
	while (true) 
	{

		//MyPoint.y = 200 + 50 * sin(pView->m_iCounter);
		//MyPoint.x = 100 + pView->m_iCounter;

		j = j + 6;
		int i = j + 5;
		int z = i + 5;
		
		

		pView->x1 = 440 + 140 * cos(j);
		pView->y1 = 240 + 140 * sin(j);

		pView->x2 = 440 + 190 * cos(i);
		pView->y2 = 240 + 190 * sin(i);

		pView->x3 = 440 + 90 * cos(z);
		pView->y3 = 240 + 90 * sin(z);
		
		//code for inner motion of last orbit
		pView->x4 =  pView->x2 + 20;
		pView->y4 =  pView->y2 + 20;
			
		
			



		pView->Invalidate();
		Sleep(500);
	}
	return 0;
}
 