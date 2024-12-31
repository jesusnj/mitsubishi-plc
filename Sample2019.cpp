
// Sample2019.cpp : アプリケーションのクラス動作を定義します。
//

#include "pch.h"
#include "framework.h"
#include "Sample2019.h"

/***************************************************/
#ifdef _WIN64
#include "..\..\..\..\Include\Wrapper\ActUtlType64_i.h"		// For ActUtlType64 Control
#include "..\..\..\..\Include\Wrapper\ActProgType64_i.h"	// For ActProgType64 Control
#include "..\..\..\..\Include\Wrapper\ActSupportMsg64_i.h"	// For ActSupportMsg64 Control
#else
#include "..\..\..\..\Include\ActUtlType_i.h"				// For ActUtlType Control
#include "..\..\..\..\Include\ActProgType_i.h"				// For ActProgType Control
#include "..\..\..\..\Include\ActSupportMsg_i.h"			// For ActSupportMsg Control
#endif

/***************************************************/

#include "Sample2019Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample2019App

BEGIN_MESSAGE_MAP(CSample2019App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
	ON_BN_CLICKED(IDC_TOGGLE_Y0, &CSample2019App::OnBnClickedToggleY0)
END_MESSAGE_MAP()


// CSample2019App の構築

CSample2019App::CSample2019App()
{
	// 再起動マネージャーをサポートします
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CSample2019App オブジェクト

CSample2019App theApp;


// CSample2019App の初期化

BOOL CSample2019App::InitInstance()
{

	/***************************************************/
	/*  Initialize OLE Library                         */
	if (!AfxOleInit())
	{
		AfxMessageBox(_T("AfxOleInit() failed."));
		return FALSE;
	}
	/***************************************************/

	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ダイアログにシェル ツリー ビューまたはシェル リスト ビュー コントロールが
	// 含まれている場合にシェル マネージャーを作成します。
	CShellManager *pShellManager = new CShellManager;

	// MFC コントロールでテーマを有効にするために、"Windows ネイティブ" のビジュアル マネージャーをアクティブ化
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
	
	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CSample2019Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//  記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ダイアログが <キャンセル> で消された時のコードを
		//  記述してください。
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// 上で作成されたシェル マネージャーを削除します。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	//  アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}



void CSample2019App::OnBnClickedToggleY0()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
}
