//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Dask.h"
#include "Print.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sButton"
#pragma link "CPort"
#pragma resource "*.dfm"
TForm1 *Form1;

bool Printing;
int Print_Count = 1;
int Print_Time = 1000;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sButton1Click(TObject *Sender)
{
	 PrintStart();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	 if(Printing)
		Print_Process();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	ComPort1->Open();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	ComPort1->Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SpinButton1DownClick(TObject *Sender)
{
	if(Print_Count > 1)
		Print_Count -= 1;

	sButton1->Caption = IntToStr(Print_Count) + "회 출력";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpinButton1UpClick(TObject *Sender)
{
	Print_Count += 1;

	sButton1->Caption = IntToStr(Print_Count) + "회 출력";
}
//---------------------------------------------------------------------------

