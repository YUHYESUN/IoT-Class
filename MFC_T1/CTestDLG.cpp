// CTestDLG.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_T1.h"
#include "CTestDLG.h"
#include "afxdialogex.h"



// CTestDLG 대화 상자

IMPLEMENT_DYNAMIC(CTestDLG, CDialogEx)

CTestDLG::CTestDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_Test1, pParent)
	/*, Item2(_T(""))
	, Item1(_T(""))
	, Item3(_T(""))*/
{

}

CTestDLG::~CTestDLG()
{
}

void CTestDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_Text1, cStatic_Test);
	//DDX_Control(pDX, IDC_EDIT1, Item1);
	////  DDX_Text(pDX, IDC_EDIT2, Item2);
	//DDX_Text(pDX, IDC_EDIT1, Item1);
	////  DDX_Control(pDX, IDC_EDIT3, Item3);
	//DDX_Text(pDX, IDC_EDIT3, Item3);
}


BEGIN_MESSAGE_MAP(CTestDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDLG::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTestDLG 메시지 처리기


BOOL CTestDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	//GetDlgItem(IDC_STATIC_Text1)->SetWindowTextW(L"Hi Hello Nice to Meet you");
	//L은 2byte 문자체계란 뜻 "" 앞에 써줘야함
	//setWindowTextW = Text의 내용 바꾸기 가능.GetWindowTextW = 문자열 되돌리기 
	// 
	// 
	
	CFont f;
	f.CreateFontW(36, 36, 0, 1, 0, 0, 0, 0, 0, OUT_DEFAULT_PRECIS, 0, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");
				
	//GetDlgItem(IDC_STATIC_Text1)->SetFont(&f);
	cStatic_Test.SetFont(&f);
	cStatic_Test.SetWindowTextW(L"안녕하세요 반가워요");


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


