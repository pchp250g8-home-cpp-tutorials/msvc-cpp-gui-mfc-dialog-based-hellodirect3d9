
// HelloDirect3DDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "HelloDirect3D.h"
#include "HelloDirect3DDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloDirect3DDlg dialog



CHelloDirect3DDlg::CHelloDirect3DDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HELLODIRECT3D_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHelloDirect3DDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHelloDirect3DDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CHelloDirect3DDlg message handlers

BOOL CHelloDirect3DDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	nRedColor = 0;
	// TODO: Add extra initialization here
	if (!InitializeDirect3D())
	{
		MessageBox(_T("Error Loading DirectX"), _T("Error"));
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHelloDirect3DDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		RenderScene();
		//CDialogEx::OnPaint();
	}
}

void CHelloDirect3DDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	DestroyDirect3D();
	CDialogEx::OnClose();
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHelloDirect3DDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CHelloDirect3DDlg::InitializeDirect3D()
{
	D3DDISPLAYMODE d3ddm;
	HRESULT hr;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	ZeroMemory(&d3ddm, sizeof(d3ddm));
	m_d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_d3d9 == nullptr) return FALSE;
	hr = m_d3d9->GetAdapterDisplayMode(0, &d3ddm);
	if (FAILED(hr)) return FALSE;
	d3dpp.Windowed = TRUE;
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	hr = m_d3d9->CreateDevice(0, D3DDEVTYPE_HAL, m_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_d3d_Device);
	if (FAILED(hr)) return FALSE;
	return TRUE;
}

void CHelloDirect3DDlg::DestroyDirect3D()
{
	m_d3d_Device.Release();
	m_d3d9.Release();
}

void CHelloDirect3DDlg::RenderScene()
{
	if (m_d3d9 == nullptr) return;
	if (m_d3d_Device == nullptr) return;
	m_d3d_Device->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(nRedColor++, 0, 0), 0, 0);
	m_d3d_Device->BeginScene();
	m_d3d_Device->EndScene();
	m_d3d_Device->Present(nullptr, nullptr, 0, nullptr);
}
BOOL CHelloDirect3DDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return FALSE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}
