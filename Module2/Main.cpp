//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "var.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cyBaseLed"
#pragma link "cyLed"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

bool Input_Data[MAX_INPUT_COUNT];
bool Output_Data[MAX_OUTPUT_COUNT];


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerTimer(TObject *Sender)
{
	Timer->Enabled = false;


	// 스위치 입출력


	Input_Check();

	for(int i = 0; i < MAX_INPUT_COUNT; i++)
	{
		TcyLed* Led = (TcyLed *)FindComponent("InputLed" + IntToStr(i));
		if(Led != NULL) Led->LedValue = Input_Data[i];
	}

	for(int i = 0; i < MAX_OUTPUT_COUNT; i++)
	{
		TcyLed* Led = (TcyLed *)FindComponent("OutputLed" + IntToStr(i + 1));
		if(Led != NULL) Led->LedValue = Output_Data[i];
	}

	Timer->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::OutputLed0Click(TObject *Sender)
{
	int Number = ((TcyLed *)Sender)->Name.SubString(strlen("OutputLed") + 1, 2).ToInt() - 1;

	Output_Process(Number, ((TcyLed *)Sender)->LedValue);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Io_Init();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	Io_Close();
}
//---------------------------------------------------------------------------

