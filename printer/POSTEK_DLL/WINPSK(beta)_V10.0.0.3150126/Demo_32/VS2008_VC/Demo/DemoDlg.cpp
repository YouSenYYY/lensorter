
// DemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "PTKPRN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RETURN_OK            0    // Return OK
#define RETURN_LOADDLLERROR  3001    // Loaddll Error

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDemoDlg 对话框




CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDemoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDemoDlg 消息处理程序

BOOL CDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//load dll
int CDemoDlg::InitDll()
{

#ifdef _UNICODE
	m_hDllHandle=LoadLibrary(_T("WINPSK_u.dll"));
	if(m_hDllHandle == NULL)
	{	
		MessageBox(_T("Can't load WINPSK_u.dll"),_T("LoadDLL"),MB_OK);
		return RETURN_LOADDLLERROR;
	}

#else
	m_hDllHandle=LoadLibrary(_T("WINPSK.dll"));
	if(m_hDllHandle == NULL)
	{	
		MessageBox(_T("Can't load WINPSK.dll"),_T("LoadDLL"),MB_OK);
		return RETURN_LOADDLLERROR;
	}
#endif
	DWORD gle = GetLastError();

	OpenPort = (fOpenPort)GetProcAddress(m_hDllHandle,"OpenPort");
	SetPCComPort = (fSetPCComPort)GetProcAddress(m_hDllHandle,"SetPCComPort");
	ClosePort = (fClosePort)GetProcAddress(m_hDllHandle,"ClosePort");
	PTK_GetErrState = (fPTK_GetErrState)GetProcAddress(m_hDllHandle,"PTK_GetErrState");
	PTK_PrintLabel = (fPTK_PrintLabel)GetProcAddress(m_hDllHandle,"PTK_PrintLabel");
	PTK_GetInfo = (fPTK_GetInfo)GetProcAddress(m_hDllHandle,"PTK_GetInfo");
	PTK_ClearBuffer = (fPTK_ClearBuffer)GetProcAddress(m_hDllHandle,"PTK_ClearBuffer");
	PTK_SetDarkness = (fPTK_SetDarkness)GetProcAddress(m_hDllHandle,"PTK_SetDarkness");
	PTK_SetPrintSpeed = (fPTK_SetPrintSpeed)GetProcAddress(m_hDllHandle,"PTK_SetPrintSpeed");
	PTK_SetLabelHeight = (fPTK_SetLabelHeight)GetProcAddress(m_hDllHandle,"PTK_SetLabelHeight");
	PTK_SetLabelWidth = (fPTK_SetLabelWidth)GetProcAddress(m_hDllHandle,"PTK_SetLabelWidth");
	PTK_SetDirection = (fPTK_SetDirection)GetProcAddress(m_hDllHandle,"PTK_SetDirection");
	PTK_DrawText = (fPTK_DrawText)GetProcAddress(m_hDllHandle,"PTK_DrawText");
	PTK_DrawTextEx = (fPTK_DrawTextEx)GetProcAddress(m_hDllHandle,"PTK_DrawTextEx");
	PTK_DrawTextTrueTypeW = (fPTK_DrawTextTrueTypeW)GetProcAddress(m_hDllHandle,"PTK_DrawTextTrueTypeW");
	PTK_DrawBarcode = (fPTK_DrawBarcode)GetProcAddress(m_hDllHandle,"PTK_DrawBarcode");
	PTK_DrawBarcodeEx = (fPTK_DrawBarcodeEx)GetProcAddress(m_hDllHandle,"PTK_DrawBarcodeEx");

	PTK_DrawBar2D_DATAMATRIX = (fPTK_DrawBar2D_DATAMATRIX)GetProcAddress(m_hDllHandle,"PTK_DrawBar2D_DATAMATRIX");
	PTK_DrawBar2D_QR = (fPTK_DrawBar2D_QR)GetProcAddress(m_hDllHandle,"PTK_DrawBar2D_QR");
	PTK_DrawBar2D_QREx = (fPTK_DrawBar2D_QREx)GetProcAddress(m_hDllHandle,"PTK_DrawBar2D_QREx");
	PTK_DrawBar2D_MaxiCode = (fPTK_DrawBar2D_MaxiCode)GetProcAddress(m_hDllHandle,"PTK_DrawBar2D_MaxiCode");
	PTK_DrawBar2D_Pdf417 = (fPTK_DrawBar2D_Pdf417)GetProcAddress(m_hDllHandle,"PTK_DrawBar2D_Pdf417");
	PTK_DrawBar2D_HANXIN = (fPTK_DrawBar2D_HANXIN)GetProcAddress(m_hDllHandle,"PTK_DrawBar2D_HANXIN");

	PTK_PcxGraphicsList = (fPTK_PcxGraphicsList)GetProcAddress(m_hDllHandle,"PTK_PcxGraphicsList");
	PTK_PcxGraphicsDel  = (fPTK_PcxGraphicsDel)GetProcAddress(m_hDllHandle,"PTK_PcxGraphicsDel");
	PTK_PcxGraphicsDownload = (fPTK_PcxGraphicsDownload)GetProcAddress(m_hDllHandle,"PTK_PcxGraphicsDownload");
	PTK_DrawPcxGraphics = (fPTK_DrawPcxGraphics)GetProcAddress(m_hDllHandle,"PTK_DrawPcxGraphics");
	PTK_PrintPCX = (fPTK_PrintPCX)GetProcAddress(m_hDllHandle,"PTK_PrintPCX");
    PTK_BinGraphicsList = (fPTK_BinGraphicsList)GetProcAddress(m_hDllHandle,"PTK_BinGraphicsList");
	PTK_BinGraphicsDel = (fPTK_BinGraphicsDel)GetProcAddress(m_hDllHandle,"PTK_BinGraphicsDel");
	PTK_BinGraphicsDownload = (fPTK_BinGraphicsDownload)GetProcAddress(m_hDllHandle,"PTK_BinGraphicsDownload");	
	PTK_RecallBinGraphics = (fPTK_RecallBinGraphics)GetProcAddress(m_hDllHandle,"PTK_RecallBinGraphics");
    PTK_DrawBinGraphics = (fPTK_DrawBinGraphics)GetProcAddress(m_hDllHandle,"PTK_DrawBinGraphics");
	PTK_BmpGraphicsDownload = (fPTK_BmpGraphicsDownload)GetProcAddress(m_hDllHandle,"PTK_BmpGraphicsDownload");

	PTK_DrawRectangle = (fPTK_DrawRectangle)GetProcAddress(m_hDllHandle,"PTK_DrawRectangle");
	PTK_DrawLineXor = (fPTK_DrawLineXor)GetProcAddress(m_hDllHandle,"PTK_DrawLineXor");
	PTK_DrawLineOr = (fPTK_DrawLineOr)GetProcAddress(m_hDllHandle,"PTK_DrawLineOr");
	PTK_DrawDiagonal = (fPTK_DrawDiagonal)GetProcAddress(m_hDllHandle,"PTK_DrawDiagonal");
	PTK_DrawWhiteLine= (fPTK_DrawWhiteLine)GetProcAddress(m_hDllHandle,"PTK_DrawWhiteLine");

	PTK_RWRFIDLabel  = (fPTK_RWRFIDLabel)GetProcAddress(m_hDllHandle,"PTK_RWRFIDLabel");
	PTK_SetRFLabelPWAndLockRFLabel = (fPTK_SetRFLabelPWAndLockRFLabel)GetProcAddress(m_hDllHandle,"PTK_SetRFLabelPWAndLockRFLabel");
	PTK_SetRFIDLabelRetryCount = (fPTK_SetRFIDLabelRetryCount)GetProcAddress(m_hDllHandle,"PTK_SetRFIDLabelRetryCount");
	PTK_SetRFID  = (fPTK_SetRFID)GetProcAddress(m_hDllHandle,"PTK_SetRFID");

    PTK_FeedBack  = (fPTK_FeedBack)GetProcAddress(m_hDllHandle,"PTK_FeedBack");
	PTK_ErrorReportUSB =  (fPTK_ErrorReportUSB)GetProcAddress(m_hDllHandle,"PTK_ErrorReportUSB");
	PTK_ErrorReport = (fPTK_ErrorReport)GetProcAddress(m_hDllHandle,"PTK_ErrorReport");
//	PTK_ErrorReportEx = (fPTK_ErrorReportEx)GetProcAddress(m_hDllHandle,"PTK_ErrorReportEx");

	PTK_GetUSBID = (fPTK_GetUSBID)GetProcAddress(m_hDllHandle,"PTK_GetUSBID");
	PTK_SendFile = (fPTK_SendFile)GetProcAddress(m_hDllHandle,"PTK_SendFile");
	PTK_SoftFontList = (fPTK_SoftFontList)GetProcAddress(m_hDllHandle,"PTK_SoftFontList");
	PTK_SoftFontDel = (fPTK_SoftFontDel)GetProcAddress(m_hDllHandle,"PTK_SoftFontDel");

	PTK_FormList = (fPTK_FormList)GetProcAddress(m_hDllHandle,"PTK_FormList");
	PTK_FormDel = (fPTK_FormDel)GetProcAddress(m_hDllHandle,"PTK_FormDel");
	PTK_FormDownload = (fPTK_FormDownload)GetProcAddress(m_hDllHandle,"PTK_FormDownload");
	PTK_DefineCounter = (fPTK_DefineCounter)GetProcAddress(m_hDllHandle,"PTK_DefineCounter");
	PTK_DefineVariable= (fPTK_DefineVariable)GetProcAddress(m_hDllHandle,"PTK_DefineVariable");

	PTK_FormEnd = (fPTK_FormEnd)GetProcAddress(m_hDllHandle,"PTK_FormEnd");
	PTK_ExecForm = (fPTK_ExecForm)GetProcAddress(m_hDllHandle,"PTK_ExecForm");
    PTK_Download = (fPTK_Download)GetProcAddress(m_hDllHandle,"PTK_Download");
	PTK_DownloadInitVar = (fPTK_DownloadInitVar)GetProcAddress(m_hDllHandle,"PTK_DownloadInitVar");

	PTK_PrintLabelAuto = (fPTK_PrintLabelAuto)GetProcAddress(m_hDllHandle,"PTK_PrintLabelAuto");

	PTK_PrintConfiguration = (fPTK_PrintConfiguration)GetProcAddress(m_hDllHandle,"PTK_PrintConfiguration");
	PTK_DisableBackFeed = (fPTK_DisableBackFeed)GetProcAddress(m_hDllHandle,"PTK_DisableBackFeed");
	PTK_EnableBackFeed = (fPTK_EnableBackFeed)GetProcAddress(m_hDllHandle,"PTK_EnableBackFeed");
	PTK_EnableFLASH = (fPTK_EnableFLASH)GetProcAddress(m_hDllHandle,"PTK_EnableFLASH");

	PTK_DisableFLASH = (fPTK_DisableFLASH)GetProcAddress(m_hDllHandle,"PTK_DisableFLASH");
	PTK_Reset = (fPTK_Reset)GetProcAddress(m_hDllHandle,"PTK_Reset");
	PTK_FeedMedia = (fPTK_FeedMedia)GetProcAddress(m_hDllHandle,"PTK_FeedMedia");
	PTK_MediaDetect = (fPTK_MediaDetect)GetProcAddress(m_hDllHandle,"PTK_MediaDetect");
	PTK_CutPage= (fPTK_CutPage)GetProcAddress(m_hDllHandle,"PTK_CutPage");
	PTK_CutPageEx = (fPTK_CutPageEx)GetProcAddress(m_hDllHandle,"PTK_CutPageEx");
	PTK_SetPrinterState = (fPTK_SetPrinterState)GetProcAddress(m_hDllHandle,"PTK_SetPrinterState");
	PTK_SetCoordinateOrigin = (fPTK_SetCoordinateOrigin)GetProcAddress(m_hDllHandle,"PTK_SetCoordinateOrigin");
	PTK_SetFontGap = (fPTK_SetFontGap)GetProcAddress(m_hDllHandle,"PTK_SetFontGap");
	PTK_SetBarCodeFontName = (fPTK_SetBarCodeFontName)GetProcAddress(m_hDllHandle,"PTK_SetBarCodeFontName");
	PTK_SetCharSets = (fPTK_SetCharSets)GetProcAddress(m_hDllHandle,"PTK_SetCharSets");

	return RETURN_OK;

}

// free dll
int CDemoDlg::FreeDll()
{
	if (m_hDllHandle != NULL)
	{
		FreeLibrary(m_hDllHandle);
	}
	return RETURN_OK;
}


//  Get Rfid tag information from printer
void CDemoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int nErrorcode = 0;
	TCHAR strRFData[1024] = {0};

	if(InitDll() != RETURN_OK) 
	{
		MessageBox(_T("Can't load  WINPSK.dll file"));
		return ;
	}

	nErrorcode = OpenPort("POSTEK iQ/200");  // 通过驱动采用这种方式，参数请输入打印机驱动名，配套使用ClosePort()关闭,请配套使用。

	for (int i1=0;i1<1;i1++)
	{
		nErrorcode = PTK_ClearBuffer();      // 设置打印标签高度和间隙或黑标等（单位为像素点），及是否需要偏移
		if(nErrorcode != 0) {break;}
		nErrorcode = PTK_SetLabelHeight (376,20,0, FALSE);      // 设置打印标签高度和间隙或黑标等（单位为像素点），及是否需要偏移
		if(nErrorcode != 0) {break;}
		nErrorcode = PTK_SetLabelWidth (800);          // 设置打印标签宽度（单位为像素点）
		if(nErrorcode != 0) {break;}
		nErrorcode = PTK_SetDarkness( 10 );            // 设置打印头发热温度
		if(nErrorcode != 0) {break;}
		nErrorcode = PTK_SetPrintSpeed( 5 );           // 设置打印机打印速度
		if(nErrorcode != 0) {break;}

		//画矩形
		nErrorcode = PTK_DrawRectangle(58,15,3,558,312);
		if(nErrorcode != 0) {break;}

		// 打印PCX图形， 方法一
		 nErrorcode = PTK_PcxGraphicsDel(_T("PCX"));
		if(nErrorcode != 0) {break;}
		nErrorcode = PTK_PcxGraphicsDownload(_T("PCX"),_T("logo.pcx"));
		if(nErrorcode != 0) {break;}
		nErrorcode = PTK_DrawPcxGraphics(80,20,_T("PCX"));
		if(nErrorcode != 0) {break;}
		

		// ´打印PCX图形， 方法二
		// PTK_PrintPCX(80,30,pchar('logo.pcx'));


		// 打印一个条码
		nErrorcode = PTK_DrawBarcode(300, 23, 0, _T("1"), 2, 2, 50, 'B', _T("123456789"));
		if(nErrorcode != 0) {break;}

		// 画表格分割线
		nErrorcode = PTK_DrawLineOr(58,100,500,3);
		if(nErrorcode != 0) {break;}

		// 打印一行TrueTypeFont文字;
		nErrorcode = PTK_DrawTextTrueTypeW (80, 120, 40, 0, _T("Arial"), 1, 400, 0, 0, 0, _T("A1"), _T("TrueTypeFont"));
		if(nErrorcode != 0) {break;}

		// 打印一行文本文字（内置字体或下载软字体）
		nErrorcode = PTK_DrawText(80, 168, 0, 3, 1, 1, 'N', _T("Internal Soft Font"));
		if(nErrorcode != 0) {break;}

		//打印PDF417码
		nErrorcode = PTK_DrawBar2D_Pdf417(80,210,400,300,0,0,3,7,10,2,0,0,_T("123456789"));//PDF417Âë
		if(nErrorcode != 0) {break;}

		// 打印QR码
		nErrorcode = PTK_DrawBar2D_QR(420,120,180,180,0,3,2,0,0,_T( "Postek Electronics Co., Ltd."));
		if(nErrorcode != 0) {break;}

		// 打印一行TrueTypeFont文字（旋转效果）

		nErrorcode = PTK_DrawTextTrueTypeW(520, 102, 22, 0, _T("Arial"), 2, 400, 0, 0, 0, _T("A2"), _T("www.postek.com.cn"));
		if(nErrorcode != 0) {break;}
		nErrorcode = PTK_DrawTextTrueTypeW(80, 260, 19, 0, _T("Arial"), 1, 700, 0, 0, 0, _T("A3"), _T("Use different ID_NAME for different Truetype font objects"));
		if(nErrorcode != 0) {break;}

		//打印机打印响应
		nErrorcode=PTK_PrintLabel(1,1);
		if(nErrorcode != 0) {break;}

	}
	
	ClosePort();

	FreeDll();
}




