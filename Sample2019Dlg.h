
// Sample2019Dlg.h : ヘッダー ファイル
//

#pragma once

// A structure for 'Sample of using threads'
typedef struct stMonitorData{
	CString cstrDev;
	LONG lSize;
	LONG* lValue;
};

// CSample2019Dlg ダイアログ
class CSample2019Dlg : public CDialogEx
{

	
// コンストラクション
public:
	afx_msg void OnBnClickedToggleY0();
	/***********************************************************************/
	// ACT Controls (Custom Interface)
#ifdef _WIN64
	IActUtlType64* m_pIUtlType;
	IActProgType64* m_pIProgType;
	IActSupportMsg64* m_pISupportMsg;
#else
	IActUtlType* m_pIUtlType;
	IActProgType* m_pIProgType;
	IActSupportMsg* m_pISupportMsg;
#endif

   /***********************************************************************/

	CSample2019Dlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAMPLE2019_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
//	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CString m_DeviceDataSet;
	CString m_DeviceDataRandom;
	CString m_DeviceDataBlock;
	CString m_DeviceNameSet;
	CString m_DeviceNameRandom;
	CString m_DeviceNameBlock;
	CString m_DeviceSizeRandom;
	CString m_DeviceSizeBlock;
	CString m_IOAddress;
	CString m_Minute;
	CString m_Month;
	CString m_ReturnCode;
	CString m_Second;
	CString m_StationNumber;
	CString m_Password;
	CString m_Status;
	CString m_Time;
	CString m_Week;
	CString m_Year;
	CString m_BufferAddress;
	CString m_BufferData;
	CString m_BufferSize;
	CString m_Code;
	CString m_Data;
	CString m_Day;
	int m_SelectCntl;

	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtnReaddevicerandom2();
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnGetdevice2();
	afx_msg void OnBnClickedBtnSetdevice2();
	afx_msg void OnBnClickedBtnGetdevice();
	afx_msg void OnBnClickedBtnSetdevice();
	afx_msg void OnBnClickedBtnWritedevicerandom2();
	afx_msg void OnBnClickedBtnReaddevicerandom();
	afx_msg void OnBnClickedBtnWritedevicerandom();
	afx_msg void OnBnClickedBtnReaddeviceblock2();
	afx_msg void OnBnClickedBtnWritedeviceblock2();
	afx_msg void OnBnClickedBtnReaddeviceblock();
	afx_msg void OnBnClickedBtnWritedeviceblock();
	afx_msg void OnBnClickedBtnGetcputype();
	afx_msg void OnBnClickedBtnSetcpustatus();
	afx_msg void OnBnClickedBtnGetclockdata();
	afx_msg void OnBnClickedBtnSetclockdata();
	afx_msg void OnBnClickedBtnReadbuffer();
	afx_msg void OnBnClickedBtnWritebuffer();
	afx_msg void OnBnClickedBtnGeterrormessage();


private :
	BOOL GetShortArray(CString cstrData, long& lSize, short* pshArray);
	BOOL GetLongArray(CString cstrData, long& lSize, long* plArray);
	void GetShortCString(short shValue[], long lSize, CString& cstrData);
	void GetLongCString(long lValue[], long lSize, CString& cstrData);
	BOOL ChangeNumber(CString cstrData, int iNumber);
	static	VOID	CALLBACK	TimerProc(
		HWND hWnd,		// A handle to the window associated with the timer.
		UINT iMsg,		// The WM_TIMER message.
		UINT iEvent,	// The timer's identifier.
		DWORD dwTime);	// The number of milliseconds that have elapsed since the system was started. 
public:
	void SwitchBtnStart(BOOL bStart);
	stMonitorData m_stData;
	afx_msg void OnBnClickedBtnStart();
	CString m_DeviceNameSample;
	afx_msg void OnBnClickedBtnStop();
};

