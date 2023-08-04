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

// planetarymotionView.h : interface of the CplanetarymotionView class
//

#pragma once


class CplanetarymotionView : public CView
{
	CWinThread* m_thread;
	CArray<CPoint, CPoint> m_PointArray;
protected: // create from serialization only
	CplanetarymotionView() noexcept;
	DECLARE_DYNCREATE(CplanetarymotionView)

// Attributes
public:
	CplanetarymotionDoc* GetDocument() const;
	int icounter;
	int x1, y1, x2, y2,x3,y3 ,x4,y4;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CplanetarymotionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onstart();
	afx_msg void Onresume();
	afx_msg void Onsuspend();
	static UINT StarThread(LPVOID Param);
};

#ifndef _DEBUG  // debug version in planetarymotionView.cpp
inline CplanetarymotionDoc* CplanetarymotionView::GetDocument() const
   { return reinterpret_cast<CplanetarymotionDoc*>(m_pDocument); }
#endif

