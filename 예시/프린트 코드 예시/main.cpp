//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

// 프리컴파일에 적합한 헤더 파일의 목록을 종료시키는데, 이것을
// 사용하면 프리컴파일된 헤더가 사용하는 디스크 공간의 양을 줄일 수 있습니다

#include "main.h"
#include "var.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)                     // 패키지된 유닛들이 의존할 순서를 결정하기 위해 초기화
#pragma link "AdvSmoothTouchKeyBoard"           // pragma link ""링커에게 특정 라이브러리(.lib / .bpi)를 강제로 포함하라고 지시하는 문장
#pragma link "sBitBtn"
#pragma link "sDialogs"
#pragma link "sLabel"
#pragma link "sPanel"
#pragma link "sSkinManager"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cyBaseLed"
#pragma link "cyBasePanel"
#pragma link "cyLed"
#pragma link "cyPanel"
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iPlot"
#pragma link "iPlotComponent"
#pragma link "iSevenSegmentDisplay"
#pragma link "iSevenSegmentInteger"
#pragma link "iVCLComponent"
#pragma link "sButton"
#pragma link "sEdit"
#pragma link "sGroupBox"
#pragma link "sPageControl"
#pragma link "sStatusBar"
#pragma link "CPort"
#pragma link "acProgressBar"
#pragma link "sSkinProvider"
#pragma link "sMemo"
#pragma link "acAlphaImageList"
#pragma link "sCheckBox"
#pragma link "iSevenSegmentAnalog"
#pragma link "sScrollBox"
#pragma link "iLedMatrix"
#pragma resource "*.dfm"
TMain_Form *Main_Form;

bool 			Printing;
int  			Print_Step;
DWORD			Print_Tick;           // DWORD = 부호 없는 32비트 정수
DWORD 			Print_Delay_Time;

bool			Print_Mode;	// 단일/다중 출력 구분
int				Print_i;    // 프린팅 수(다중 출력시 체크하기 위함)
bool			Print_End;  // 마지막 프린트 체크

__BARCODE_SPEC	Barcode_Spec;

bool Input_Data[MAX_INPUT_COUNT];
bool Output_Data[MAX_OUTPUT_COUNT];

//---------------------------------------------------------------------------
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormShow(TObject *Sender)
{
	System_Load();
	Title_Label->Caption = PROGRAM_TITLE;

#if !PROGRAM_TEST
	Io_Init();

	Barcode_Port->Open();

	//ADOConnection1->Connected = true;

#endif
	//가장 최근 모델 열기
	if(FileExists(Recent_Model_Open()))
		Barcode_Model_Open(Recent_Model_Open());

	Printing = false;

	Timer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::TimerTimer(TObject *Sender)
{
	Timer->Enabled = false;

	if(Now().DateTimeString() != StatusBar->Panels->Items[0]->Text)
		StatusBar->Panels->Items[0]->Text = Now().DateTimeString();

	Main_Form->AlphaBlend = !Main_Form->Enabled;

	// 데이터 베이스 슬립모드 방지
	/*if(GetTickCount() - Sql_Timer > 1800000)
	{
		Sql_Data_Send("select distinct MODEL_NAME from data");
	}*/

	if(!Main_Form->Enabled)
	{
		Timer->Enabled = true;
		return;
	}

	Input_Check();

	//IO데이터
	for(int i = 0 ; i < MAX_INPUT_COUNT ; i++)
	{
		if(((TcyLed *)FindComponent("Input_Led_" + IntToStr(i + 1))) != NULL)
			((TcyLed *)FindComponent("Input_Led_" + IntToStr(i + 1)))->LedValue = Input_Data[i];
	}

	for(int i = 0 ; i < MAX_OUTPUT_COUNT ; i++)
	{
		if(((TcyLed *)FindComponent("Output_Led_" + IntToStr(i + 1))) != NULL)
			((TcyLed *)FindComponent("Output_Led_" + IntToStr(i + 1)))->LedValue = Output_Data[i];
	}

	//검사 유무에 따른 활성상태 설정
	if(Title_Panel->Enabled == Printing)
		Title_Panel->Enabled = !Printing;
	if(Test_Model_Open_Button->Enabled == Printing)
		Test_Model_Open_Button->Enabled = !Printing;

	if(Printing)
	{
		Print_Process();
	}
	else
	{

	}

	Timer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Print_Process()
{
	switch(Print_Step)
	{
		case STEP_INIT:
			// 모델 오픈 확인
			if(Model_Name_Panel->Caption == "")
			{
				Printing = false;
				Test_Message_Panel->Caption = "모델을 열어주세요.";
				break;
			}

			// 바코드 스펙 기입 확인
			if(!strlen(Barcode_Spec.Company))
			{
				Printing = false;
				Test_Message_Panel->Caption = "업체 코드 값이 없습니다.";
				break;
			}

			if(!strlen(Barcode_Spec.Part_Number))
			{
				Printing = false;
				Test_Message_Panel->Caption = "부품 번호 값이 없습니다.";
				break;
			}
			/*
			if(!strlen(Barcode_Spec.Alc))
			{
				Printing = false;
				Test_Message_Panel->Caption = "서열코드 값이 없습니다.";
				break;
			}

			if(!strlen(Barcode_Spec.Eo))
			{
				Printing = false;
				Test_Message_Panel->Caption = "EO 번호 값이 없습니다.";
				break;
			}
			*/
			if(!strlen(Barcode_Spec.Product_4M))
			{
				Printing = false;
				Test_Message_Panel->Caption = "부품4M 값이 없습니다.";
				break;
			}

			if(!strlen(Barcode_Spec.Lot))
			{
				Printing = false;
				Test_Message_Panel->Caption = "LOT 값이 없습니다.";
				break;
			}

            // 초기화
			Print_i = 0;
			Print_End = false;

			if(Print_Mode == ONE)
				Print_Step = STEP_PRINT_ONE;
			else if(Print_Mode == SET)
				Print_Step = STEP_PRINT_SET;
			else
				Print_Step = STEP_PRINT_ONE;

			Print_Tick = GetTickCount();
			break;

		case STEP_PRINT_ONE:
			Test_Message_Panel->Caption = "바코드 출력중...";
			if(!Print_End)
				Test_Barcode_Print();
			Print_End = true;

			// 일정시간 대기했다가 넘어감
			if(GetTickCount() - Print_Tick > Print_Time)
			{
				Print_Tick = GetTickCount();
				Print_Step = STEP_END;
			}
			break;

		case STEP_PRINT_SET:	// 다중 출력 모드
			Test_Message_Panel->Caption = "바코드 출력중...";
			Test_Barcode_Print();
			Print_i++;
			Print_Tick = GetTickCount();

			if(Print_i == Print_Count)
				Print_End = true;
			else
				Print_End = false;

			Print_Step = STEP_PRINT_SET_DELAY;
			break;

		case STEP_PRINT_SET_DELAY:
			if(GetTickCount() - Print_Tick > Print_Time)	// 환경설정에서 설정한 시간만큼 대기 - 실제 출력되는 시간과 비슷하게 셋팅하는게 좋음
			{
				if(Print_End)
				{
					Print_Step = STEP_END;
					Print_Tick = GetTickCount();
				}
				else
					Print_Step = STEP_PRINT_SET;
			}
			break;

		case STEP_END:
			Test_Message_Panel->Caption = "바코드 출력 종료";

			if(GetTickCount() - Print_Tick > DELAY_TIME)
			{
				if(GetTickCount() - Print_Tick > 300)
				{
					Printing = false;
				}
			}
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Exit_ButtonClick(TObject *Sender)
{
	switch(Application->MessageBoxA(L"프로그램을 종료할까요?", L"WARNING", MB_YESNO))
	{
		case ID_YES   :
#if !PROGRAM_TEST
						Barcode_Port->Close();
						//ADOConnection1->Close();
#endif
						Close();
						break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Model_ButtonClick(TObject *Sender)
{
	Model_Flag = true;
	Count_Flag = false;
	Main_Form->Enabled = false;
	Password_Form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Test_Model_Open_ButtonClick(TObject *Sender)
{
	OpenDialog->DefaultExt = "*.SPEC";
	OpenDialog->InitialDir = SPEC_PATH;
	OpenDialog->Filter = "SPEC FILE (*.spc)|*.spc";

	if(OpenDialog->Execute())
	{
		Barcode_Model_Open(OpenDialog->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::System_ButtonClick(TObject *Sender)
{
	Model_Flag = false;
	Count_Flag = false;
	Main_Form->Enabled = false;

	Password_Form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Test_Barcode_Print()
{
	AnsiString Date;
	int Count;

	unsigned short Year, Month, Day;
	unsigned short Hour, Minute, Second, mSecond;

	Now().DecodeDate(&Year, &Month, &Day);
	Now().DecodeTime(&Hour, &Minute, &Second, &mSecond);

	Date = Date.sprintf("%02d%02d%02d", Year - 2000, Month, Day);

	// BARCODE COUNT(SERIAL)
	TIniFile *Count_File = new TIniFile(COUNT_FILE);

	Count = Count_File->ReadInteger("BARCODE", Model_Name_Panel->Caption + Date, 0) + 1;
	Count_File->WriteInteger("BARCODE", Model_Name_Panel->Caption + Date, Count);

	delete(Count_File);

	//10000번대부터 출력
	int Serial = Count + 10000;

	PrintBarcode(Date.c_str(), Serial);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Delete_MemoClick(TObject *Sender)
{
	Barcode_Memo->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Print_ButtonClick(TObject *Sender)
{
	Print_Mode = ONE;
	Print_Step = STEP_INIT;
	Printing = true;
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Print_Set_ButtonClick(TObject *Sender)
{
	Print_Mode = SET;
	Print_Step = STEP_INIT;
	Printing = true;
}
//---------------------------------------------------------------------------

