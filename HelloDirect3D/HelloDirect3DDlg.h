
// HelloDirect3DDlg.h : header file
//

#pragma once


// CHelloDirect3DDlg dialog
class CHelloDirect3DDlg : public CDialogEx
{
// Construction
public:
	CHelloDirect3DDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HELLODIRECT3D_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()

private:
	byte nRedColor;
	D3DPRESENT_PARAMETERS d3dpp;
	CComPtr<IDirect3D9> m_d3d9;
	CComPtr<IDirect3DDevice9> m_d3d_Device;
	BOOL InitializeDirect3D();
	void DestroyDirect3D();
	void RenderScene();
};
