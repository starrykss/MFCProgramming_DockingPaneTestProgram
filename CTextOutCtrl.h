﻿#pragma once


// CTextOutCtrl 대화 상자

class CTextOutCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CTextOutCtrl)

public:
	CTextOutCtrl(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTextOutCtrl();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TEXTOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonTextout();
	afx_msg void OnClickedButtonColor();
	afx_msg void OnClickedButtonFont();
};
