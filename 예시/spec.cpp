//---------------------------------------------------------------------------
#include <vcl.h>                // Visual Component Library
#pragma hdrstop
// 프리컴파일에 적합한 헤더 파일의 목록을 종료시키는데, 이것을
// 사용하면 프리컴파일된 헤더가 사용하는 디스크 공간의 양을 줄일 수 있습니다


#include "spec.h"

#include "var.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)      // 패키지된 유닛들이 의존할 순서를 결정하기 위해 초기화
#pragma link "sSkinProvider"     // pragma link ""링커에게 특정 라이브러리(.lib / .bpi)를 강제로 포함하라고 지시하는 문장
#pragma link "sButton"
#pragma link "sEdit"
#pragma link "sPanel"
#pragma link "sGroupBox"
#pragma link "sCheckBox"
#pragma link "sLabel"
#pragma link "sSpinEdit"
#pragma link "sDialogs"
#pragma link "sBitBtn"
#pragma link "sPageControl"
#pragma link "sRadioButton"
#pragma link "sComboBox"
#pragma link "cyBaseLed"
#pragma link "cyLed"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "sMemo"
#pragma link "acAlphaImageList"
#pragma link "sScrollBox"
#pragma link "sTrackBar"
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iLedMatrix"
#pragma link "iVCLComponent"
#pragma resource "*.dfm"
TSpec_Form *Spec_Form;
//---------------------------------------------------------------------------
__fastcall TSpec_Form::TSpec_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSpec_Form::FormShow(TObject *Sender)
{
	if(FileExists(Recent_Model_Open()))
		Model_Open(Recent_Model_Open());

	Timer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSpec_Form::Close_ButtonClick(TObject *Sender)
{
	Timer->Enabled = false;

	Main_Form->Enabled = true;

	if(FileExists(Recent_Model_Open()))
		Barcode_Model_Open(Recent_Model_Open());

	Close();
}
//---------------------------------------------------------------------------

void __fastcall TSpec_Form::Open_ButtonClick(TObject *Sender)
{
	OpenDialog->FileName = "";
	OpenDialog->DefaultExt = "*.SPEC";
	OpenDialog->InitialDir = SPEC_PATH;
	OpenDialog->Filter = "SPEC FILE (*.spc)|*.spc";

	if(OpenDialog->Execute())
	{
		Model_Open(OpenDialog->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TSpec_Form::Save_ButtonClick(TObject *Sender)
{
	SaveDialog->FileName = "";
	SaveDialog->DefaultExt = "*.SPEC";
	SaveDialog->InitialDir = SPEC_PATH;
	SaveDialog->Filter = "SPEC FILE (*.spc)|*.spc";

	if(SaveDialog->Execute())
	{
		Model_Save(SaveDialog->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TSpec_Form::TimerTimer(TObject *Sender)
{
	Timer->Enabled = false;

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

	Timer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSpec_Form::Output_Led_1Click(TObject *Sender)
{
	int Number = ((TcyLed *)Sender)->Name.SubString(strlen("Output_Led_") + 1, 2).ToInt() - 1;

	Output_Process(Number, ((TcyLed *)Sender)->LedValue);
}
//---------------------------------------------------------------------------

