//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "system.h"
#include "var.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sButton"
#pragma link "sPanel"
#pragma link "sGroupBox"
#pragma link "sEdit"
#pragma link "sLabel"
#pragma link "cyBaseLed"
#pragma link "cyLed"
#pragma link "sCheckBox"
#pragma link "sSpinEdit"
#pragma resource "*.dfm"
TSystem_Form *System_Form;
//---------------------------------------------------------------------------
__fastcall TSystem_Form::TSystem_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSystem_Form::FormShow(TObject *Sender)
{
	System_Form->Left = (Screen->Width - System_Form->Width) / 2;
	System_Form->Top = (Screen->Height - System_Form->Height) / 2;

	System_Load();
	Serial_Edit->Text = "1";

	Timer->Enabled = true;
	System_Timer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSystem_Form::Close_ButtonClick(TObject *Sender)
{
	Timer->Enabled = false;

	Main_Form->Enabled = true;

	System_Load();

	System_Timer->Enabled = false;

	Close();
}
//---------------------------------------------------------------------------
void __fastcall TSystem_Form::Save_ButtonClick(TObject *Sender)
{
	System_Save();

	ShowMessage("저장되었습니다.");
		System_Load();
}
//---------------------------------------------------------------------------

void __fastcall TSystem_Form::Barcode_Print_ButtonClick(TObject *Sender)
{
	System_Save();
	System_Load();

	unsigned short Year, Month, Day;
	Now().DecodeDate(&Year, &Month, &Day);

	AnsiString Date_Str;
	Date_Str = Date_Str.sprintf("%02d%02d%02d", Year - 2000, Month, Day);

	PrintBarcode(Date_Str.c_str(), Serial_Edit->Text.ToIntDef(1));
}
//---------------------------------------------------------------------------
