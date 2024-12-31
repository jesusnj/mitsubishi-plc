
// Sample2019.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CSample2019App:
// このクラスの実装については、Sample2019.cpp を参照してください
//

class CSample2019App : public CWinApp
{
public:
	CSample2019App();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedToggleY0();
};



extern CSample2019App theApp;



