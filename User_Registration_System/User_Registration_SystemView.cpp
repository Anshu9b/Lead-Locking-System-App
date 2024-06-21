
// User_Registration_SystemView.cpp : implementation of the CUserRegistrationSystemView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "User_Registration_System.h"
#endif

#include "User_Registration_SystemDoc.h"
#include "User_Registration_SystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUserRegistrationSystemView

IMPLEMENT_DYNCREATE(CUserRegistrationSystemView, CView)

BEGIN_MESSAGE_MAP(CUserRegistrationSystemView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CUserRegistrationSystemView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CUserRegistrationSystemView construction/destruction

CUserRegistrationSystemView::CUserRegistrationSystemView() noexcept
{
	// TODO: add construction code here

}

CUserRegistrationSystemView::~CUserRegistrationSystemView()
{
}

BOOL CUserRegistrationSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CUserRegistrationSystemView drawing

void CUserRegistrationSystemView::OnDraw(CDC* /*pDC*/)
{
	CUserRegistrationSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CUserRegistrationSystemView printing


void CUserRegistrationSystemView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CUserRegistrationSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUserRegistrationSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUserRegistrationSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CUserRegistrationSystemView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CUserRegistrationSystemView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CUserRegistrationSystemView diagnostics

#ifdef _DEBUG
void CUserRegistrationSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CUserRegistrationSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUserRegistrationSystemDoc* CUserRegistrationSystemView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUserRegistrationSystemDoc)));
	return (CUserRegistrationSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CUserRegistrationSystemView message handlers
