
// Lottery.Arrange.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLotteryArrangeApp:
// �йش����ʵ�֣������ Lottery.Arrange.cpp
//

class CLotteryArrangeApp : public CWinAppEx
{
public:
	CLotteryArrangeApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLotteryArrangeApp theApp;