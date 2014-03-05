
// Lottery.ArrangeDlg.h : 头文件
//

#pragma once

#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// CLotteryArrangeDlg 对话框
class CLotteryArrangeDlg : public CDialog
{
private:
// 构造
	CFont m_Font0;
	CFont m_Font1;
public:
	CLotteryArrangeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LOTTERYARRANGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtondoit();
};
