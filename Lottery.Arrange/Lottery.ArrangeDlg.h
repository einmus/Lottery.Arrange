
// Lottery.ArrangeDlg.h : ͷ�ļ�
//

#pragma once

#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// CLotteryArrangeDlg �Ի���
class CLotteryArrangeDlg : public CDialog
{
private:
// ����
	CFont m_Font0;
	CFont m_Font1;
public:
	CLotteryArrangeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOTTERYARRANGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtondoit();
};
