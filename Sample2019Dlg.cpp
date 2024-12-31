
// Sample2019Dlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "Sample2019.h"
#include "afxdialogex.h"

/***************************************************/
#ifdef _WIN64
#include "..\..\..\..\Include\Wrapper\ActUtlType64_i.h"		// For ActUtlType64 Control
#include "..\..\..\..\Include\Wrapper\ActUtlType64_i.c"		// For CustomInterface
#include "..\..\..\..\Include\Wrapper\ActProgType64_i.h"	// For ActProgType64 Control
#include "..\..\..\..\Include\Wrapper\ActProgType64_i.c"	// For CustomInterface
#include "..\..\..\..\Include\Wrapper\ActSupportMsg64_i.h"	// For ActSupportMsg Control
#include "..\..\..\..\Include\Wrapper\ActSupportMsg64_i.c"	// For CustomInterface
#else
#include "..\..\..\..\Include\ActUtlType_i.h"				// For ActUtlType Control
#include "..\..\..\..\Include\ActUtlType_i.c"				// For CustomInterface
#include "..\..\..\..\Include\ActProgType_i.h"				// For ActProgType Control
#include "..\..\..\..\Include\ActProgType_i.c"				// For CustomInterface
#include "..\..\..\..\Include\ActSupportMsg_i.h"			// For ActSupportMsg Control
#include "..\..\..\..\Include\ActSupportMsg_i.c"			// For CustomInterface
#endif
/***************************************************/

#include "Sample2019Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif







// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

/*******************************************************/
/* Not need CAboutDlg when hide a version information. */

//class CAboutDlg : public CDialogEx
//{
//public:
//	CAboutDlg();
//
//	// ダイアログ データ
//#ifdef AFX_DESIGN_TIME
//	enum { IDD = IDD_ABOUTBOX };
//#endif
//
//protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
//
//// 実装
//protected:
//	DECLARE_MESSAGE_MAP()
//};
//
//CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
//{
//}
//
//void CAboutDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//}
//
//BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//END_MESSAGE_MAP()

/*******************************************************/

// CSample2019Dlg ダイアログ



CSample2019Dlg::CSample2019Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SAMPLE2019_DIALOG, pParent)
	, m_DeviceDataSet(_T(""))
	, m_DeviceDataRandom(_T(""))
	, m_DeviceDataBlock(_T(""))
	, m_DeviceNameSet(_T(""))
	, m_DeviceNameRandom(_T(""))
	, m_DeviceNameBlock(_T(""))
	, m_DeviceSizeRandom(_T(""))
	, m_DeviceSizeBlock(_T(""))
	, m_IOAddress(_T(""))
	, m_Minute(_T(""))
	, m_Month(_T(""))
	, m_ReturnCode(_T(""))
	, m_Second(_T(""))
	, m_Status(_T(""))
	, m_Time(_T(""))
	, m_Week(_T(""))
	, m_StationNumber(_T(""))
	, m_Password(_T(""))
	, m_Year(_T(""))
	, m_BufferAddress(_T(""))
	, m_BufferData(_T(""))
	, m_BufferSize(_T(""))
	, m_Code(_T(""))
	, m_Data(_T(""))
	, m_Day(_T(""))
	, m_SelectCntl(0)
	, m_DeviceNameSample(_T(""))
{
	// Set fixed values of the structure for 'Sample of using threads'
	m_stData.lSize = 1;
	m_stData.lValue = new long[m_stData.lSize];
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample2019Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TXT_DEVICEDATA1, m_DeviceDataSet);
	DDX_Text(pDX, IDC_TXT_DEVICEDATA2, m_DeviceDataRandom);
	DDX_Text(pDX, IDC_TXT_DEVICEDATA3, m_DeviceDataBlock);
	DDX_Text(pDX, IDC_TXT_DEVICENAME1, m_DeviceNameSet);
	DDX_Text(pDX, IDC_TXT_DEVICENAME2, m_DeviceNameRandom);
	DDX_Text(pDX, IDC_TXT_DEVICENAME3, m_DeviceNameBlock);
	DDX_Text(pDX, IDC_TXT_DEVICESIZE2, m_DeviceSizeRandom);
	DDX_Text(pDX, IDC_TXT_DEVICESIZE3, m_DeviceSizeBlock);
	DDX_Text(pDX, IDC_TXT_IOADDRESS, m_IOAddress);
	DDX_Text(pDX, IDC_TXT_MINUTE, m_Minute);
	DDX_Text(pDX, IDC_TXT_MONTH, m_Month);
	DDX_Text(pDX, IDC_TXT_RETURNCODE, m_ReturnCode);
	DDX_Text(pDX, IDC_TXT_SECOND, m_Second);
	DDX_Text(pDX, IDC_TXT_STATIONNUMBER, m_StationNumber);
	DDX_Text(pDX, IDC_TXT_PASSWORD, m_Password);
	DDX_Text(pDX, IDC_TXT_STATUS, m_Status);
	DDX_Text(pDX, IDC_TXT_TIME, m_Time);
	DDX_Text(pDX, IDC_TXT_WEEK, m_Week);
	DDX_Text(pDX, IDC_TXT_STATIONNUMBER, m_StationNumber);
	DDX_Text(pDX, IDC_TXT_YEAR, m_Year);
	DDX_Text(pDX, IDC_TXT_BUFFERADDRESS, m_BufferAddress);
	DDX_Text(pDX, IDC_TXT_BUFFERDATA, m_BufferData);
	DDX_Text(pDX, IDC_TXT_BUFFERSIZE, m_BufferSize);
	DDX_Text(pDX, IDC_TXT_CODE, m_Code);
	DDX_Text(pDX, IDC_TXT_DATA, m_Data);
	DDX_Text(pDX, IDC_TXT_DAY, m_Day);
	DDX_Radio(pDX, IDC_RADIO_ACTUTLTYPE, m_SelectCntl);
	DDX_Text(pDX, IDC_TXT_DEVICENAME5, m_DeviceNameSample);
}
BEGIN_MESSAGE_MAP(CSample2019Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_READDEVICERANDOM2, &CSample2019Dlg::OnBnClickedBtnReaddevicerandom2)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CSample2019Dlg::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CSample2019Dlg::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BTN_GETDEVICE2, &CSample2019Dlg::OnBnClickedBtnGetdevice2)
	ON_BN_CLICKED(IDC_BTN_SETDEVICE2, &CSample2019Dlg::OnBnClickedBtnSetdevice2)
	ON_BN_CLICKED(IDC_BTN_GETDEVICE, &CSample2019Dlg::OnBnClickedBtnGetdevice)
	ON_BN_CLICKED(IDC_BTN_SETDEVICE, &CSample2019Dlg::OnBnClickedBtnSetdevice)
	ON_BN_CLICKED(IDC_BTN_WRITEDEVICERANDOM2, &CSample2019Dlg::OnBnClickedBtnWritedevicerandom2)
	ON_BN_CLICKED(IDC_BTN_READDEVICERANDOM, &CSample2019Dlg::OnBnClickedBtnReaddevicerandom)
	ON_BN_CLICKED(IDC_BTN_WRITEDEVICERANDOM, &CSample2019Dlg::OnBnClickedBtnWritedevicerandom)
	ON_BN_CLICKED(IDC_BTN_READDEVICEBLOCK2, &CSample2019Dlg::OnBnClickedBtnReaddeviceblock2)
	ON_BN_CLICKED(IDC_BTN_WRITEDEVICEBLOCK2, &CSample2019Dlg::OnBnClickedBtnWritedeviceblock2)
	ON_BN_CLICKED(IDC_BTN_READDEVICEBLOCK, &CSample2019Dlg::OnBnClickedBtnReaddeviceblock)
	ON_BN_CLICKED(IDC_BTN_WRITEDEVICEBLOCK, &CSample2019Dlg::OnBnClickedBtnWritedeviceblock)
	ON_BN_CLICKED(IDC_BTN_GETCPUTYPE, &CSample2019Dlg::OnBnClickedBtnGetcputype)
	ON_BN_CLICKED(IDC_BTN_SETCPUSTATUS, &CSample2019Dlg::OnBnClickedBtnSetcpustatus)
	ON_BN_CLICKED(IDC_BTN_GETCLOCKDATA, &CSample2019Dlg::OnBnClickedBtnGetclockdata)
	ON_BN_CLICKED(IDC_BTN_SETCLOCKDATA, &CSample2019Dlg::OnBnClickedBtnSetclockdata)
	ON_BN_CLICKED(IDC_BTN_READBUFFER, &CSample2019Dlg::OnBnClickedBtnReadbuffer)
	ON_BN_CLICKED(IDC_BTN_WRITEBUFFER, &CSample2019Dlg::OnBnClickedBtnWritebuffer)
	ON_BN_CLICKED(IDC_BTN_GETERRORMESSAGE, &CSample2019Dlg::OnBnClickedBtnGeterrormessage)
	ON_BN_CLICKED(IDC_BTN_START, &CSample2019Dlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &CSample2019Dlg::OnBnClickedBtnStop)
END_MESSAGE_MAP()

// CSample2019Dlg メッセージ ハンドラー

BOOL CSample2019Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	/***************************************************/
	/* Hide a version information					   */
//	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
//	ASSERT(IDM_ABOUTBOX < 0xF000);
//
//	CMenu* pSysMenu = GetSystemMenu(FALSE);
//	if (pSysMenu != nullptr)
//	{
//		BOOL bNameValid;
//		CString strAboutMenu;
//		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
//		ASSERT(bNameValid);
//		if (!strAboutMenu.IsEmpty())
//		{
//			pSysMenu->AppendMenu(MF_SEPARATOR);
//			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
//		}
//	}
	/***************************************************/

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	/***************************************************/
	/* ACT Compornent Instance Create				   */
	HRESULT hr;

#ifdef _WIN64
	// ActUtlType64 Control
	hr = CoCreateInstance(CLSID_ActUtlType64,
		NULL,
		CLSCTX_LOCAL_SERVER,
		IID_IActUtlType64,
		(LPVOID*)&m_pIUtlType);
	if (!SUCCEEDED(hr))
	{
		AfxMessageBox(_T("ActUtlType64 CoCreateInstance() failed."));
		EndDialog(IDOK);
	}

	// ActProgType64 Control
	hr = CoCreateInstance(CLSID_ActProgType64,
		NULL,
		CLSCTX_LOCAL_SERVER,
		IID_IActProgType64,
		(LPVOID*)&m_pIProgType);
	if (!SUCCEEDED(hr))
	{
		AfxMessageBox(_T("ActProgType64 CoCreateInstance() failed."));
		EndDialog(IDOK);
	}

	// ActSupportMsg64 Control
	hr = CoCreateInstance(CLSID_ActSupportMsg64,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IActSupportMsg64,
		(LPVOID*)&m_pISupportMsg);
	if (!SUCCEEDED(hr))
	{
		AfxMessageBox(_T("ActSupportMsg64 CoCreateInstance() failed."));
		EndDialog(IDOK);
	}
#else
	// ActUtlType Control
	hr = CoCreateInstance(CLSID_ActUtlType,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IActUtlType,
		(LPVOID*)&m_pIUtlType);
	if (!SUCCEEDED(hr))
	{
		AfxMessageBox(_T("ActUtlType CoCreateInstance() failed."));
		EndDialog(IDOK);
	}

	// ActProgType Control
	hr = CoCreateInstance(CLSID_ActProgType,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IActProgType,
		(LPVOID*)&m_pIProgType);
	if (!SUCCEEDED(hr))
	{
		AfxMessageBox(_T("ActProgType CoCreateInstance() failed."));
		EndDialog(IDOK);
	}

	// ActSupportMsg Control
	hr = CoCreateInstance(CLSID_ActSupportMsg,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IActSupportMsg,
		(LPVOID*)&m_pISupportMsg);
	if (!SUCCEEDED(hr))
	{
		AfxMessageBox(_T("ActSupportMsg CoCreateInstance() failed."));
		EndDialog(IDOK);
	}
#endif
	/*                                                 */
	/***************************************************/

	// Disabled Stop button.
	(CButton*)GetDlgItem(IDC_BTN_STOP)->EnableWindow(FALSE);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// Not need OnSysCommand method when hide a version information.
//void CSample2019Dlg::OnSysCommand(UINT nID, LPARAM lParam)
//{
//	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
//	{
//		CAboutDlg dlgAbout;
//		dlgAbout.DoModal();
//	}
//	else
//	{
//		CDialogEx::OnSysCommand(nID, lParam);
//	}
//}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CSample2019Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CSample2019Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSample2019Dlg::OnBnClickedBtnOpen()
{
	long	lRet;
	BSTR	bstrPassword = NULL;
	CString MsgStr;
	HRESULT	hr;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	//
	// Processing of Open method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		// Check the target of TextBox.
		if (m_StationNumber == "")
		{
			MsgStr.LoadString(IDS_STRING102);
			AfxMessageBox(MsgStr, MB_ICONSTOP);
			CWnd::UpdateData(FALSE);
			return;
		}

		// Set the value of 'LogicalStationNumber' to the property.
		m_pIUtlType->put_ActLogicalStationNumber(::_ttoi(m_StationNumber));
		// Set the string of 'Password' to the property.
		bstrPassword = m_Password.AllocSysString();
		m_pIUtlType->put_ActPassword(bstrPassword);
		// Free the allocated area.
		::SysFreeString(bstrPassword);
		// The Open method is executed.
		hr = m_pIUtlType->Open(&lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		// If not use the default value of the property, 
		// Set a suitable value before the Open wethod.
		// ( Even if set after the Open method, not reflected in the communication. )
		// ---> e.g., Change the 'UnitType' to RUSB, the 'ProtocolType' to USB, and the 'CpuType' to R08CPU. 
		m_pIProgType->put_ActUnitType(4100);		// UNIT_RUSB
		m_pIProgType->put_ActProtocolType(13);		// PROTOCOL_USB
		m_pIProgType->put_ActCpuType(4098);			// CPU_R08CPU
		
		// Other propety is set a default value.
		m_pIProgType->put_ActBaudRate(19200);
		m_pIProgType->put_ActConnectUnitNumber(0);
		m_pIProgType->put_ActControl(8);
		m_pIProgType->put_ActCpuTimeOut(0);
		m_pIProgType->put_ActDataBits(8);
		m_pIProgType->put_ActDestinationIONumber(0);
		m_pIProgType->put_ActDestinationPortNumber(0);
		m_pIProgType->put_ActDidPropertyBit(1);
		m_pIProgType->put_ActDsidPropertyBit(1);
		m_pIProgType->put_ActHostAddress(_T("1.1.1.1"));
		m_pIProgType->put_ActIntelligentPreferenceBit(0);
		m_pIProgType->put_ActIONumber(1023);
		m_pIProgType->put_ActMultiDropChannelNumber(0);
		m_pIProgType->put_ActNetworkNumber(0);
		m_pIProgType->put_ActPacketType(1);
		m_pIProgType->put_ActParity(1);
		m_pIProgType->put_ActPassword(_T(""));
		m_pIProgType->put_ActPortNumber(1);
		m_pIProgType->put_ActSourceNetworkNumber(0);
		m_pIProgType->put_ActSourceStationNumber(0);
		m_pIProgType->put_ActStationNumber(255);
		m_pIProgType->put_ActStopBits(0);
		m_pIProgType->put_ActSumCheck(0);
		m_pIProgType->put_ActTargetSimulator(0);
		m_pIProgType->put_ActThroughNetworkType(0);
		m_pIProgType->put_ActTimeOut(10000);
		m_pIProgType->put_ActUnitNumber(0);

		// The Open method is executed.
		hr = m_pIProgType->Open(&lRet);
	}
	
	if (SUCCEEDED(hr))	// Compornent Communication is succeeded?
	{
		// When the Open method is succeeded, disable the TextBox of 'LogocalStationNumber'.
		if (m_SelectCntl == 0 && lRet == 0x00)
		{
			(CButton*)GetDlgItem(IDC_TXT_STATIONNUMBER)->EnableWindow(FALSE);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	CWnd::UpdateData(FALSE);
}



void CSample2019Dlg::OnBnClickedBtnClose()
{
	long	lRet;
	HRESULT	hr;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	//
	// Processing of Close method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->Close(&lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->Close(&lRet);
	}

	if (SUCCEEDED(hr))	// Compornent Communication is succeeded?
	{
		// When the Open method is succeeded, enable the TextBox of 'LogocalStationNumber'.
		if (m_SelectCntl == 0 && lRet == 0x00)
		{
			(CButton*)GetDlgItem(IDC_TXT_STATIONNUMBER)->EnableWindow(TRUE);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnGetdevice2()
{
	short	shValue;
	long	lRet;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameSet == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = m_DeviceNameSet.AllocSysString();

	//
	// Processing of GetDevice2 method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->GetDevice2(szDev, &shValue, &lRet);
	}
	else		 			// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->GetDevice2(szDev, &shValue, &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			m_Data.Format(_T("%d"), shValue);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnSetdevice2()
{
	short	shValue;
	long	lRet;
	CString cstrCheck;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameSet == "" || m_DeviceDataSet == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// If the string is not an integer value, this process is end.
	if (!ChangeNumber(m_DeviceDataSet, 10))
	{
		CWnd::UpdateData(FALSE);
		return;
	}
	shValue = _ttoi(m_DeviceDataSet);

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = m_DeviceNameSet.AllocSysString();

	//
	// Processing of SetDevice2 method
	//
	if (m_SelectCntl == 0) 	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->SetDevice2(szDev, shValue, &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{	
		hr = m_pIProgType->SetDevice2(szDev, shValue, &lRet);
	}

	if (SUCCEEDED(hr))	// Compornent Communication is succeeded?
	{
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnGetdevice()
{
	long	lValue;
	long	lRet;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameSet == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = m_DeviceNameSet.AllocSysString();

	//
	// Processing of GetDevice method
	//
	if (m_SelectCntl == 0) 	// ActUtlType Control(CustomInterface)
	{ 
		hr = m_pIUtlType->GetDevice(szDev, &lValue, &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->GetDevice(szDev, &lValue, &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			m_Data.Format(_T("%d"), lValue);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnSetdevice()
{
	long	lValue;
	long	lRet;
	CString cstrCheck;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameSet == "" || m_DeviceDataSet == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}
	
	// If the string is not an integer value, this process is end.
	if (!ChangeNumber(m_DeviceDataSet, 10))
	{
		CWnd::UpdateData(FALSE);
		return;
	}
	lValue = _ttoi(m_DeviceDataSet);

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = m_DeviceNameSet.AllocSysString();

	//
	// Processing of SetDevice method
	//
	if(m_SelectCntl == 0) 	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->SetDevice(szDev, lValue, &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->SetDevice(szDev, lValue, &lRet);
	}

	if (SUCCEEDED(hr))	// Compornent Communication is succeeded?
	{
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnReaddevicerandom2()
{
	short*	shValue;
	long	lSize;
	long	lRet;
	CString deviceName;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);
	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameRandom == "" || m_DeviceSizeRandom == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	deviceName = m_DeviceNameRandom;
	deviceName.Replace(_T("\r\n"), _T("\n"));
	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = deviceName.AllocSysString();

	lSize = _ttoi(m_DeviceSizeRandom);

	shValue = new short[lSize];

	//
	// Processing of ReadDeviceRandom2 method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
			hr = m_pIUtlType->ReadDeviceRandom2(szDev, lSize, &shValue[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->ReadDeviceRandom2(szDev, lSize, &shValue[0], &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			GetShortCString(shValue, lSize, m_Data);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	// Free the allocated memory.
	delete[] shValue;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnWritedevicerandom2()
{
	short*	shValue;
	long	lRet;
	long	lSize;
	long	lArraySize;
	CString deviceName;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameRandom == "" || m_DeviceSizeRandom == "" || m_DeviceDataRandom == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	deviceName = m_DeviceNameRandom;
	deviceName.Replace(_T("\r\n"), _T("\n"));
	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = deviceName.AllocSysString();
	
	lSize = _ttoi(m_DeviceSizeRandom);
	
	// Check the 'DeviceData'.(If succeeded, the value is gotten.)
	shValue = new short[lSize];
	if (!GetShortArray(m_DeviceDataRandom, lArraySize, &shValue[0]))
	{
		CWnd::UpdateData(FALSE);
		return;
	}

	// Check for the lSize to be the same as the lArraySize.
	if (lSize != lArraySize)
	{
		MsgStr.LoadString(IDS_STRING103);
		AfxMessageBox(MsgStr, MB_ICONSTOP);

		CWnd::UpdateData(FALSE);
		return;
	}

	//
	// Processing of WriteDeviceRandom2 method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->WriteDeviceRandom2(szDev, lSize, &shValue[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->WriteDeviceRandom2(szDev, lSize, &shValue[0], &lRet);
	}

	if (SUCCEEDED(hr))	// Compornent Communication is succeeded?
	{
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	// Free the allocated memory.
	delete[] shValue;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnReaddevicerandom()
{
	long*	lValue;
	long	lRet;
	long	lSize;
	CString deviceName;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameRandom == "" || m_DeviceSizeRandom == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}
	
	deviceName = m_DeviceNameRandom;
	deviceName.Replace(_T("\r\n"), _T("\n"));
	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = deviceName.AllocSysString();

	lSize = _ttoi(m_DeviceSizeRandom);
	lValue = new long[lSize];

	//
	// Processing of ReadDeviceRandom method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->ReadDeviceRandom(szDev, lSize, &lValue[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->ReadDeviceRandom(szDev, lSize, &lValue[0], &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			GetLongCString(lValue, lSize, m_Data);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);
	
	// Free the allocated memory.
	delete[] lValue;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnWritedevicerandom()
{
	long*	lValue;
	long	lRet;
	long	lSize;
	long	lArraySize;
	CString deviceName;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameRandom == "" || m_DeviceSizeRandom == "" || m_DeviceDataRandom == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	deviceName = m_DeviceNameRandom;
	deviceName.Replace(_T("\r\n"), _T("\n"));
	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = deviceName.AllocSysString();
	
	lSize = _ttoi(m_DeviceSizeRandom);
	
	// Check the 'DeviceData'.(If succeeded, the value is gotten.)
	lValue = new long[lSize];
	if (!GetLongArray(m_DeviceDataRandom, lArraySize, &lValue[0]))
	{
		CWnd::UpdateData(FALSE);
		return;
	}

	// Check for the lSize to be the same as the lArraySize.
	if (lSize != lArraySize)
	{
		MsgStr.LoadString(IDS_STRING103);
		AfxMessageBox(MsgStr, MB_ICONSTOP);

		CWnd::UpdateData(FALSE);
		return;
	}

	//
	// Processing of WriteDeviceRandom method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->WriteDeviceRandom(szDev, lSize, &lValue[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->WriteDeviceRandom(szDev, lSize, &lValue[0], &lRet);
	}

	if (SUCCEEDED(hr))	// Compornent Communication is succeeded?
	{
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	// Free the allocated memory.
	delete[] lValue;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnReaddeviceblock2()
{
	short*	shValue;
	long	lSize;
	long	lRet;
	CString deviceName;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameBlock == "" || m_DeviceSizeBlock == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = m_DeviceNameBlock.AllocSysString();
	
	lSize = _ttoi(m_DeviceSizeBlock);
	
	shValue = new short[lSize];

	//
	// Processing of ReadDeviceBlock2 method
	//
	if (m_SelectCntl == 0)  // ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->ReadDeviceBlock2(szDev, lSize, &shValue[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->ReadDeviceBlock2(szDev, lSize, &shValue[0], &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			GetShortCString(shValue, lSize, m_Data);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	// Free the allocated memory.
	delete[] shValue;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnWritedeviceblock2()
{
	short*	shValue;
	long	lRet;
	long	lSize;
	long	lArraySize;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameBlock == "" || m_DeviceSizeBlock == "" || m_DeviceDataBlock == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = m_DeviceNameBlock.AllocSysString();
	
	lSize = _ttoi(m_DeviceSizeBlock);
	
	// Check the 'DeviceData'.(If succeeded, the value is gotten.)
	shValue = new short[lSize];
	if (!GetShortArray(m_DeviceDataBlock, lArraySize, &shValue[0]))
	{
		CWnd::UpdateData(FALSE);
		return;
	}

	// Check for the lSize to be the same as the lArraySize.
	if (lSize != lArraySize)
	{
		MsgStr.LoadString(IDS_STRING103);
		AfxMessageBox(MsgStr, MB_ICONSTOP);

		CWnd::UpdateData(FALSE);
		return;
	}

	//
	// Processing of WriteDeviceBlock2 method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->WriteDeviceBlock2(szDev, lSize, &shValue[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->WriteDeviceBlock2(szDev, lSize, &shValue[0], &lRet);
	}

	if (SUCCEEDED(hr))	// Compornent Communication is succeeded?
	{
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	// Free the allocated memory.
	delete[] shValue;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnReaddeviceblock()
{
	long	*lValue;
	long	lSize;
	long	lRet;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameBlock == "" || m_DeviceSizeBlock == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = m_DeviceNameBlock.AllocSysString();

	lSize = _ttoi(m_DeviceSizeBlock);
	
	lValue = new long[lSize];

	//
	// Processing of ReadDeviceBlock method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->ReadDeviceBlock(szDev, lSize, &lValue[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->ReadDeviceBlock(szDev, lSize, &lValue[0], &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			GetLongCString(lValue, lSize, m_Data);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	// Free the allocated memory.
	delete[] lValue;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnWritedeviceblock()
{
	long*	lValue;
	long	lRet;
	long	lSize;
	long	lArraySize;
	CString	MsgStr;
	HRESULT	hr;
	BSTR	szDev = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_DeviceNameBlock == "" || m_DeviceSizeBlock == "" || m_DeviceDataBlock == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = m_DeviceNameBlock.AllocSysString();

	lSize = _ttoi(m_DeviceSizeBlock);
	
	// Check the 'DeviceData'.(If succeeded, the value is gotten.)
	lValue = new long[lSize];
	if (!GetLongArray(m_DeviceDataBlock, lArraySize, &lValue[0]))
	{
		CWnd::UpdateData(FALSE);
		return;
	}

	// Check for the lSize to be the same as the lArraySize.
	if (lSize != lArraySize)
	{
		MsgStr.LoadString(IDS_STRING103);
		AfxMessageBox(MsgStr, MB_ICONSTOP);

		CWnd::UpdateData(FALSE);
		return;
	}

	//
	// Processing of WriteDeviceBlock method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->WriteDeviceBlock(szDev, lSize, &lValue[0], &lRet);
	}
	else	// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->WriteDeviceBlock(szDev, lSize, &lValue[0], &lRet);
	}

	if (SUCCEEDED(hr))	// Compornent Communication is succeeded?
	{
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szDev);

	// Free the allocated memory.
	delete[] lValue;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnGetcputype()
{
	long	lCpuCode;
	long	lRet;
	HRESULT	hr;
	BSTR	szCpu = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	//
	// Processing of GetCpuType method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->GetCpuType(&szCpu, &lCpuCode, &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->GetCpuType(&szCpu, &lCpuCode, &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			m_Data.Format(_T("%s\r\n0x%08x"), szCpu, lCpuCode);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szCpu);

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnSetcpustatus()
{
	long	lOperation;
	long	lRet;
	CString MsgStr;
	HRESULT	hr;
	BSTR	szCpu = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_Status == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}
	lOperation = _ttoi(m_Status);

	//
	// Processing of SetCpuStatus method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->SetCpuStatus(lOperation, &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->SetCpuStatus(lOperation, &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szCpu);

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnGetclockdata()
{
	short	shYear;
	short	shMonth;
	short	shDay;
	short	shWeek;
	short	shTime;
	short	shMinute;
	short	shSecond;
	long	lRet;
	HRESULT	hr;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	//
	// Processing of GetClockData method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->GetClockData(&shYear, &shMonth, &shDay, &shWeek, &shTime, &shMinute, &shSecond, &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->GetClockData(&shYear, &shMonth, &shDay, &shWeek, &shTime, &shMinute, &shSecond, &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			m_Data.Format(_T("Year: %d\r\nMonth: %d\r\nDay: %d\r\nWeek: %d\r\nHour: %d\r\nMinute: %d\r\nSecond: %d"),
							shYear, shMonth, shDay, shWeek, shTime, shMinute, shSecond);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnSetclockdata()
{
	short	shYear;
	short	shMonth;
	short	shDay;
	short	shWeek;
	short	shTime;
	short	shMinute;
	short	shSecond;
	long	lRet;
	CString MsgStr;
	HRESULT	hr;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_Year == "" || m_Month == "" || m_Day == "" || m_Week == "" || m_Time == "" || m_Minute == "" || m_Second == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}
	shYear = _ttoi(m_Year);
	shMonth = _ttoi(m_Month);
	shDay = _ttoi(m_Day);
	shWeek = _ttoi(m_Week);
	shTime = _ttoi(m_Time);
	shMinute = _ttoi(m_Minute);
	shSecond = _ttoi(m_Second);

	//
	// Processing of SetClockData method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->SetClockData(shYear, shMonth, shDay, shWeek, shTime, shMinute, shSecond, &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->SetClockData(shYear, shMonth, shDay, shWeek, shTime, shMinute, shSecond, &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnReadbuffer()
{
	long	lIOAddress;
	long	lBufferAddress;
	long	lBufferSize;
	short*	shBufferData;
	long	lRet;
	CString cstrIOAddress;
	CString MsgStr;
	HRESULT	hr;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_IOAddress == "" || m_BufferAddress == "" || m_BufferSize == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}
	lIOAddress = _ttoi(m_IOAddress);
	lBufferAddress = _ttoi(m_BufferAddress);
	lBufferSize = _ttoi(m_BufferSize);

	shBufferData = new short[lBufferSize];

	//
	// Processing of ReadBuffer method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->ReadBuffer(lIOAddress, lBufferAddress, lBufferSize, &shBufferData[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->ReadBuffer(lIOAddress, lBufferAddress, lBufferSize, &shBufferData[0], &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			GetShortCString(shBufferData, lBufferSize, m_Data);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated memory.
	delete[] shBufferData;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnWritebuffer()
{
	long	lIOAddress;
	long	lBufferAddress;
	long	lBufferSize;
	long	lArraySize;
	short*	shBufferData;
	long	lRet;
	CString MsgStr;
	HRESULT	hr;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_IOAddress == "" || m_BufferAddress == "" || m_BufferSize == "" || m_BufferData == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}
	lIOAddress = _ttoi(m_IOAddress);
	lBufferAddress = _ttoi(m_BufferAddress);
	lBufferSize = _ttoi(m_BufferSize);

	// Check the 'BufferData'.(If succeeded, the value is gotten.)
	shBufferData = new short[lBufferSize];
	if (!GetShortArray(m_BufferData, lArraySize, &shBufferData[0]))
	{
		CWnd::UpdateData(FALSE);
		return;
	}

	// Check for the lBufferSize to be the same as the lArraySize.
	if (lBufferSize != lArraySize)
	{
		MsgStr.LoadString(IDS_STRING103);
		AfxMessageBox(MsgStr, MB_ICONSTOP);

		CWnd::UpdateData(FALSE);
		return;
	}

	//
	// Processing of WriteBuffer method
	//
	if (m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = m_pIUtlType->WriteBuffer(lIOAddress, lBufferAddress, lBufferSize, &shBufferData[0], &lRet);
	}
	else					// ActProgType Control(CustomInterface)
	{
		hr = m_pIProgType->WriteBuffer(lIOAddress, lBufferAddress, lBufferSize, &shBufferData[0], &lRet);
	}

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated memory.
	delete[] shBufferData;

	CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnGeterrormessage()
{
	long		lErrorCode;
	long		lRet;
	CString		MsgStr;
	CString		cstrTopOfCode;
	HRESULT		hr;
	BSTR		szErrorMessage = NULL;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";

	// Check the target of TextBox.
	if (m_Code == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// Get a LongType value form 'Code'.
	cstrTopOfCode = m_Code.Left(2);
	if (cstrTopOfCode == _T("0X"))	// hexadecimal
	{
		// Check for 'Code' to be expressed as a hexadecimal number.
		if (!ChangeNumber(m_Code, 16))
		{
			CWnd::UpdateData(FALSE);
			return;
		}
		lErrorCode = _tcstoul(m_Code, NULL, 16);

	}
	else							// decimal
	{  
		// Check for 'Code' to be expressed as a decimal number.
		if (!ChangeNumber(m_Code, 10))
		{
			CWnd::UpdateData(FALSE);
			return;
		}
		lErrorCode = _ttoi(m_Code);
	}

	// Processing of GetErrorMessage method
	hr = m_pISupportMsg->GetErrorMessage(lErrorCode, &szErrorMessage, &lRet);

	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			m_Data.Format(_T("%s"), szErrorMessage);
		}
		// The return code of the method is displayed by the hexadecimal.
		m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);
	}
	else
	{
		m_ReturnCode = "Component communication failed.";
	}

	// Free the allocated area.
	::SysFreeString(szErrorMessage);

	CWnd::UpdateData(FALSE);
}

BOOL CSample2019Dlg::GetShortArray(CString cstrData, long& lSize, short* pshArray)
{
	int		iCount = 0;
	int		iCurPos = 0;
	CString cstrTemp;

	// Get the string until first '\r\n'.
	cstrTemp = cstrData.Tokenize(_T("\r\n"), iCurPos);

	// If get an empty stirng, 
	// Finish the proccess of getting each element of ShortType array.
	while (_T("") != cstrTemp)
	{
		// Check for 'CStringType value' to be expressed as a decimal number.
		if (!ChangeNumber(cstrTemp, 10))
		{
			return false;
		}

		pshArray[iCount] = _ttoi(cstrTemp);
		iCount++;

		// Get the string until next '\r\n'.
		cstrTemp = cstrData.Tokenize(_T("\r\n"), iCurPos);

	}

	// Get the size of 'pshArray'.
	lSize = iCount;
	return true;
}


BOOL CSample2019Dlg::GetLongArray(CString cstrData, long& lSize, long *plArray)
{
	int		iCount = 0;
	int		iCurPos = 0;
	CString cstrTemp;

	// Get the string until first '\r\n'.
	cstrTemp = cstrData.Tokenize(_T("\r\n"), iCurPos);

	// If get an empty stirng,
	// Finish the proccess of getting each element of LongType array.
	while (_T("") != cstrTemp)
	{
		// Check for CStringType value to be expressed as a decimal number.
		if (!ChangeNumber(cstrTemp, 10))
		{
			return false;
		}

		plArray[iCount] = _ttoi(cstrTemp);
		iCount++;

		// Get the string until next '\r\n'.
		cstrTemp = cstrData.Tokenize(_T("\r\n"), iCurPos);

	}

	// Get the size of 'plArray'.
	lSize = iCount;
	return true;
}

void CSample2019Dlg::GetShortCString(short shValue[], long lSize, CString& cstr)
{
	int		iNumber;
	CString cstrData;
	
	// Get CStirngType value from ShortType array.
	for (iNumber = 0; iNumber < lSize; iNumber++)
	{
		if (cstr == _T(""))
		{
			cstrData.Format(_T("%d"), shValue[iNumber]);
		}
		else
		{
			cstrData.Format(_T("\r\n%d"), shValue[iNumber]);
		}
			cstr += cstrData;
	}
}

void CSample2019Dlg::GetLongCString(long lValue[], long lSize, CString& cstr)
{
	int		iNumber;
	CString cstrData;

	// Get CStirngType value from LongType array.
	for (iNumber = 0; iNumber < lSize; iNumber++)
	{
		if (cstr == _T(""))
		{
			cstrData.Format(_T("%d"), lValue[iNumber]);
		}
		else
		{
			cstrData.Format(_T("\r\n%d"), lValue[iNumber]);
		}
		cstr += cstrData;
	}
}

BOOL CSample2019Dlg::DestroyWindow()
{
	/************************************/
	/*Clear ACT Controls				*/
	if (m_pIUtlType != NULL)
	{
		m_pIUtlType->Release();
	}
	if (m_pIProgType != NULL)
	{
		m_pIProgType->Release();
	}
	if (m_pISupportMsg != NULL)
	{
		m_pISupportMsg->Release();
	}

	// Free the allocated memory.
	delete[] m_stData.lValue;
	/*                                  */
	/************************************/
	
	return CDialogEx::DestroyWindow();
}

BOOL CSample2019Dlg::ChangeNumber(CString cstrData, int iNumber) {
	
	TCHAR*	pszEnd;
	CString MsgStr;

	// Change the string to a number by a base 'Number'.
	_tcstol(cstrData, &pszEnd, iNumber);
	
	// If failed to change, this process is end.
	if (*pszEnd != _T('\0'))
	{
		MsgStr.LoadString(IDS_STRING104);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		return false;
	}

	return true;
}


BOOL CSample2019Dlg::PreTranslateMessage(MSG* pMsg)
{
	/*******************************************************/
	/*Prevent the program tremination when pressed Enter.  */

	// Check for the pressed key.
	if (WM_KEYDOWN == pMsg->message)
	{
		// Prevent the program tremination when pressed Enter.
		if (VK_RETURN == pMsg->wParam)
		{
			// Check for a control type. ( Button or other control )
			if (BS_DEFPUSHBUTTON != ((CButton*)GetFocus())->GetButtonStyle())
			{
				return FALSE;
			}
		}
	}
	/*******************************************************/

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CSample2019Dlg::OnBnClickedBtnStart()
{
	CString	MsgStr;

	CWnd::UpdateData(TRUE);

	// Displayed output data is cleared.
	m_ReturnCode = "";
	m_Data = "";
	

	// Check the target of TextBox.
	if (m_DeviceNameSample == "")
	{
		MsgStr.LoadString(IDS_STRING102);
		AfxMessageBox(MsgStr, MB_ICONSTOP);
		CWnd::UpdateData(FALSE);
		return;
	}

	// Disable Start button.
	SwitchBtnStart(FALSE);

	m_stData.cstrDev = m_DeviceNameSample;
	m_stData.cstrDev.Replace(_T("\r\n"), _T("\n"));
	
	// Run TimerProc every 5000ms.
	::SetTimer(this->m_hWnd,0,5000,(TIMERPROC)TimerProc);

	CWnd::UpdateData(FALSE);
}

VOID CALLBACK CSample2019Dlg::TimerProc(
	HWND	hWnd,
	UINT	uiMsg,
	UINT	uiID,
	DWORD	dwTime)
{
	long	lRet;
	HRESULT	hr;
	BSTR	szDev;

	// Set a pointer to a CWnd object.
	CSample2019Dlg* lpDlg = (CSample2019Dlg*)CWnd::FromHandle(hWnd);
	
	lpDlg->CWnd::UpdateData(TRUE);

	// Allocate the BSTR-Type String area. (After use, you have to free it.)
	szDev = lpDlg->m_stData.cstrDev.AllocSysString();

	//
	// ReadDeviceRandom
	//
	if (lpDlg->m_SelectCntl == 0)	// ActUtlType Control(CustomInterface)
	{
		hr = lpDlg->m_pIUtlType->ReadDeviceRandom(szDev,
												lpDlg->m_stData.lSize,
												&(lpDlg->m_stData.lValue[0]),
												&lRet);
	}
	else							// ActProgType Control(CustomInterface)
	{
		hr = lpDlg->m_pIProgType->ReadDeviceRandom(szDev,
												lpDlg->m_stData.lSize,
												&(lpDlg->m_stData.lValue[0]),
												&lRet);
	}
	
	if (SUCCEEDED(hr)) // Compornent Communication is succeeded?
	{
		// The return code of the method is displayed by the hexadecimal.
		lpDlg->m_ReturnCode.Format(_T("0x%08x [HEX]"), lRet);

		// When the method is succeeded, display the read data.
		if (lRet == 0x00)
		{
			lpDlg->GetLongCString(lpDlg->m_stData.lValue,
								lpDlg->m_stData.lSize,
								lpDlg->m_Data);
			// Disable Start button.
			lpDlg->SwitchBtnStart(FALSE);
		}
		else
		{
			// Stop the timer.
			::KillTimer(lpDlg->m_hWnd, 0);
			// Enable Start button.
			lpDlg->SwitchBtnStart(TRUE);
		}
	}
	else
	{
		lpDlg->m_ReturnCode = "Component communication failed.";
		// Stop the timer.
		::KillTimer(lpDlg->m_hWnd, 0);
		// Enable Start button.
		lpDlg->SwitchBtnStart(TRUE);
	}

	// Free the allocated area.
	::SysFreeString(szDev);
	
	lpDlg->CWnd::UpdateData(FALSE);
}


void CSample2019Dlg::OnBnClickedBtnStop()
{
	CWnd::UpdateData(TRUE);

	// Stop the timer.
	::KillTimer(this->m_hWnd, 0);
	// Enable Start button.
	SwitchBtnStart(TRUE);
	
	CWnd::UpdateData(FALSE);

	return;
}

void CSample2019Dlg::SwitchBtnStart(BOOL bStart)
{
	// When Start button is enabled, bStart is set TRUE. 
	// When Start button is disabled, bStart is set FALSE.
	if(bStart == TRUE)
	{
		// The case of TRUE:
		// Start button and DeviceData TextBox are enabled, Stop button is disabled.
		(CButton*)GetDlgItem(IDC_BTN_START)->EnableWindow(TRUE);
		(CButton*)GetDlgItem(IDC_BTN_STOP)->EnableWindow(FALSE);
		(CEdit*)GetDlgItem(IDC_TXT_DEVICENAME5)->EnableWindow(TRUE);
	}
	else
	{
		// The case of FALSE:
		// Start button and DeviceData TextBox are disabled, Stop button is enabled.
		(CButton*)GetDlgItem(IDC_BTN_START)->EnableWindow(FALSE);
		(CButton*)GetDlgItem(IDC_BTN_STOP)->EnableWindow(TRUE);
		(CEdit*)GetDlgItem(IDC_TXT_DEVICENAME5)->EnableWindow(FALSE);
	}
}