//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Common.h"

#include "var.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool KeyState(int Key)
{
	return GetAsyncKeyState(Key) & 0x8000;
}

void System_Save()
{
	TIniFile *System_File = new TIniFile(SYSTEM_FILE);

	System_File->WriteString("BARCODE", "TEMP", System_Form->Barcode_Temp_Edit->Text);
	System_File->WriteString("BARCODE", "WIDTH", System_Form->Barcode_Width_Edit->Text);
	System_File->WriteString("BARCODE", "HEIGHT", System_Form->Barcode_Height_Edit->Text);
	System_File->WriteString("BARCODE", "GAP", System_Form->Barcode_Gap_Edit->Text);
	System_File->WriteString("BARCODE", "FONT", System_Form->Barcode_Font_Edit->Text);

	System_File->WriteString("BARCODE", "PRINT_COUNT", System_Form->Print_Count_Edit->Text);
	System_File->WriteString("BARCODE", "PRINT_TIME", System_Form->Print_Time_Edit->Text);

	System_File->WriteString("BARCODE", "SIZE", System_Form->Barcode_Size_Edit->Text);
	System_File->WriteString("BARCODE", "X", System_Form->Barcode_X_Edit->Text);
	System_File->WriteString("BARCODE", "Y", System_Form->Barcode_Y_Edit->Text);

	System_File->WriteBool("BARCODE_PARTS_NUMBER", "USE", System_Form->Parts_Number_Use_CheckBox->Checked);
	System_File->WriteString("BARCODE_PARTS_NUMBER", "SIZEX", System_Form->Parts_Number_Size_X_Edit->Text);
	System_File->WriteString("BARCODE_PARTS_NUMBER", "SIZEY", System_Form->Parts_Number_Size_Y_Edit->Text);
	System_File->WriteString("BARCODE_PARTS_NUMBER", "X", System_Form->Parts_Number_X_Edit->Text);
	System_File->WriteString("BARCODE_PARTS_NUMBER", "Y", System_Form->Parts_Number_Y_Edit->Text);

	System_File->WriteBool("BARCODE_DATE", "USE", System_Form->Date_Use_CheckBox->Checked);
	System_File->WriteString("BARCODE_DATE", "SIZEX", System_Form->Date_Size_X_Edit->Text);
	System_File->WriteString("BARCODE_DATE", "SIZEY", System_Form->Date_Size_Y_Edit->Text);
	System_File->WriteString("BARCODE_DATE", "X", System_Form->Date_X_Edit->Text);
	System_File->WriteString("BARCODE_DATE", "Y", System_Form->Date_Y_Edit->Text);

	System_File->WriteBool("BARCODE_ALC", "USE", System_Form->Alc_Use_CheckBox->Checked);
	System_File->WriteString("BARCODE_ALC", "SIZEX", System_Form->Alc_Size_X_Edit->Text);
	System_File->WriteString("BARCODE_ALC", "SIZEY", System_Form->Alc_Size_Y_Edit->Text);
	System_File->WriteString("BARCODE_ALC", "X", System_Form->Alc_X_Edit->Text);
	System_File->WriteString("BARCODE_ALC", "Y", System_Form->Alc_Y_Edit->Text);

	System_File->WriteBool("BARCODE_4M", "USE", System_Form->Product_4M_Use_CheckBox->Checked);
	System_File->WriteString("BARCODE_4M", "SIZEX", System_Form->Product_4M_Size_X_Edit->Text);
	System_File->WriteString("BARCODE_4M", "SIZEY", System_Form->Product_4M_Size_Y_Edit->Text);
	System_File->WriteString("BARCODE_4M", "X", System_Form->Product_4M_X_Edit->Text);
	System_File->WriteString("BARCODE_4M", "Y", System_Form->Product_4M_Y_Edit->Text);

	System_File->WriteBool("BARCODE_SERIAL", "USE", System_Form->Serial_Use_CheckBox->Checked);
	System_File->WriteString("BARCODE_SERIAL", "SIZEX", System_Form->Serial_Size_X_Edit->Text);
	System_File->WriteString("BARCODE_SERIAL", "SIZEY", System_Form->Serial_Size_Y_Edit->Text);
	System_File->WriteString("BARCODE_SERIAL", "X", System_Form->Serial_X_Edit->Text);
	System_File->WriteString("BARCODE_SERIAL", "Y", System_Form->Serial_Y_Edit->Text);

	System_File->WriteBool("BARCODE_COMPANY", "USE", System_Form->Company_Use_CheckBox->Checked);
	System_File->WriteString("BARCODE_COMPANY", "SIZEX", System_Form->Company_Size_X_Edit->Text);
	System_File->WriteString("BARCODE_COMPANY", "SIZEY", System_Form->Company_Size_Y_Edit->Text);
	System_File->WriteString("BARCODE_COMPANY", "X", System_Form->Company_X_Edit->Text);
	System_File->WriteString("BARCODE_COMPANY", "Y", System_Form->Company_Y_Edit->Text);

	delete(System_File);
}

void System_Load()
{
	TIniFile *System_File = new TIniFile(SYSTEM_FILE);

	System_Form->Barcode_Temp_Edit->Text = System_File->ReadString("BARCODE", "TEMP", "");
	System_Form->Barcode_Width_Edit->Text = System_File->ReadString("BARCODE", "WIDTH", "");
	System_Form->Barcode_Height_Edit->Text = System_File->ReadString("BARCODE", "HEIGHT", "");
	System_Form->Barcode_Gap_Edit->Text = System_File->ReadString("BARCODE", "GAP", "");
	System_Form->Barcode_Font_Edit->Text = System_File->ReadString("BARCODE", "FONT", "");

	System_Form->Print_Count_Edit->Text = System_File->ReadString("BARCODE", "PRINT_COUNT", "");
	System_Form->Print_Time_Edit->Text = System_File->ReadString("BARCODE", "PRINT_TIME", "");

	System_Form->Barcode_Size_Edit->Text = System_File->ReadString("BARCODE", "SIZE", "");
	System_Form->Barcode_X_Edit->Text = System_File->ReadString("BARCODE", "X", "");
	System_Form->Barcode_Y_Edit->Text = System_File->ReadString("BARCODE", "Y", "");

	System_Form->Parts_Number_Use_CheckBox->Checked = System_File->ReadBool("BARCODE_PARTS_NUMBER", "USE", 0);
	System_Form->Parts_Number_Size_X_Edit->Text = System_File->ReadString("BARCODE_PARTS_NUMBER", "SIZEX", "");
	System_Form->Parts_Number_Size_Y_Edit->Text = System_File->ReadString("BARCODE_PARTS_NUMBER", "SIZEY", "");
	System_Form->Parts_Number_X_Edit->Text = System_File->ReadString("BARCODE_PARTS_NUMBER", "X", "");
	System_Form->Parts_Number_Y_Edit->Text = System_File->ReadString("BARCODE_PARTS_NUMBER", "Y", "");

	System_Form->Date_Use_CheckBox->Checked = System_File->ReadBool("BARCODE_DATE", "USE", 0);
	System_Form->Date_Size_X_Edit->Text = System_File->ReadString("BARCODE_DATE", "SIZEX", "");
	System_Form->Date_Size_Y_Edit->Text = System_File->ReadString("BARCODE_DATE", "SIZEY", "");
	System_Form->Date_X_Edit->Text = System_File->ReadString("BARCODE_DATE", "X", "");
	System_Form->Date_Y_Edit->Text = System_File->ReadString("BARCODE_DATE", "Y", "");

	System_Form->Alc_Use_CheckBox->Checked = System_File->ReadBool("BARCODE_ALC", "USE", 0);
	System_Form->Alc_Size_X_Edit->Text = System_File->ReadString("BARCODE_ALC", "SIZEX", "");
	System_Form->Alc_Size_Y_Edit->Text = System_File->ReadString("BARCODE_ALC", "SIZEY", "");
	System_Form->Alc_X_Edit->Text = System_File->ReadString("BARCODE_ALC", "X", "");
	System_Form->Alc_Y_Edit->Text = System_File->ReadString("BARCODE_ALC", "Y", "");

	System_Form->Product_4M_Use_CheckBox->Checked = System_File->ReadBool("BARCODE_4M", "USE", 0);
	System_Form->Product_4M_Size_X_Edit->Text = System_File->ReadString("BARCODE_4M", "SIZEX", "");
	System_Form->Product_4M_Size_Y_Edit->Text = System_File->ReadString("BARCODE_4M", "SIZEY", "");
	System_Form->Product_4M_X_Edit->Text = System_File->ReadString("BARCODE_4M", "X", "");
	System_Form->Product_4M_Y_Edit->Text = System_File->ReadString("BARCODE_4M", "Y", "");

	System_Form->Serial_Use_CheckBox->Checked = System_File->ReadBool("BARCODE_SERIAL", "USE", 0);
	System_Form->Serial_Size_X_Edit->Text = System_File->ReadString("BARCODE_SERIAL", "SIZEX", "");
	System_Form->Serial_Size_Y_Edit->Text = System_File->ReadString("BARCODE_SERIAL", "SIZEY", "");
	System_Form->Serial_X_Edit->Text = System_File->ReadString("BARCODE_SERIAL", "X", "");
	System_Form->Serial_Y_Edit->Text = System_File->ReadString("BARCODE_SERIAL", "Y", "");

	System_Form->Company_Use_CheckBox->Checked = System_File->ReadBool("BARCODE_COMPANY", "USE", 0);
	System_Form->Company_Size_X_Edit->Text = System_File->ReadString("BARCODE_COMPANY", "SIZEX", "");
	System_Form->Company_Size_Y_Edit->Text = System_File->ReadString("BARCODE_COMPANY", "SIZEY", "");
	System_Form->Company_X_Edit->Text = System_File->ReadString("BARCODE_COMPANY", "X", "");
	System_Form->Company_Y_Edit->Text = System_File->ReadString("BARCODE_COMPANY", "Y", "");

	Main_Form->Barcode_Temp = System_File->ReadInteger("BARCODE", "TEMP", 0);
	Main_Form->Barcode_Width = System_File->ReadInteger("BARCODE", "WIDTH", 0);
	Main_Form->Barcode_Height = System_File->ReadInteger("BARCODE", "HEIGHT", 0);
	Main_Form->Barcode_Gap = System_File->ReadInteger("BARCODE", "GAP", 0);
	Main_Form->Barcode_Font = System_File->ReadInteger("BARCODE", "FONT", 0);

	Main_Form->Print_Count = System_File->ReadInteger("BARCODE", "PRINT_COUNT", 0);
	Main_Form->Print_Time = System_File->ReadInteger("BARCODE", "PRINT_TIME", 0);

	Main_Form->Barcode_Size = System_File->ReadInteger("BARCODE", "SIZE", 0);
	Main_Form->Barcode_X = System_File->ReadInteger("BARCODE", "X", 0);
	Main_Form->Barcode_Y = System_File->ReadInteger("BARCODE", "Y", 0);

	Main_Form->Parts_Number_Use = System_File->ReadBool("BARCODE_PARTS_NUMBER", "USE", 0);
	Main_Form->Parts_Number_Size_X = System_File->ReadInteger("BARCODE_PARTS_NUMBER", "SIZEX", 0);
	Main_Form->Parts_Number_Size_Y = System_File->ReadInteger("BARCODE_PARTS_NUMBER", "SIZEY", 0);
	Main_Form->Parts_Number_X = System_File->ReadInteger("BARCODE_PARTS_NUMBER", "X", 0);
	Main_Form->Parts_Number_Y = System_File->ReadInteger("BARCODE_PARTS_NUMBER", "Y", 0);

	Main_Form->Date_Use = System_File->ReadBool("BARCODE_DATE", "USE", 0);
	Main_Form->Date_Size_X = System_File->ReadInteger("BARCODE_DATE", "SIZEX", 0);
	Main_Form->Date_Size_Y = System_File->ReadInteger("BARCODE_DATE", "SIZEY", 0);
	Main_Form->Date_X = System_File->ReadInteger("BARCODE_DATE", "X", 0);
	Main_Form->Date_Y = System_File->ReadInteger("BARCODE_DATE", "Y", 0);

	Main_Form->Alc_Use = System_File->ReadBool("BARCODE_ALC", "USE", 0);
	Main_Form->Alc_Size_X = System_File->ReadInteger("BARCODE_ALC", "SIZEX", 0);
	Main_Form->Alc_Size_Y = System_File->ReadInteger("BARCODE_ALC", "SIZEY", 0);
	Main_Form->Alc_X = System_File->ReadInteger("BARCODE_ALC", "X", 0);
	Main_Form->Alc_Y = System_File->ReadInteger("BARCODE_ALC", "Y", 0);

	Main_Form->Product_4M_Use = System_File->ReadBool("BARCODE_4M", "USE", 0);
	Main_Form->Product_4M_Size_X = System_File->ReadInteger("BARCODE_4M", "SIZEX", 0);
	Main_Form->Product_4M_Size_Y = System_File->ReadInteger("BARCODE_4M", "SIZEY", 0);
	Main_Form->Product_4M_X = System_File->ReadInteger("BARCODE_4M", "X", 0);
	Main_Form->Product_4M_Y = System_File->ReadInteger("BARCODE_4M", "Y", 0);

	Main_Form->Serial_Use = System_File->ReadBool("BARCODE_SERIAL", "USE", 0);
	Main_Form->Serial_Size_X = System_File->ReadInteger("BARCODE_SERIAL", "SIZEX", 0);
	Main_Form->Serial_Size_Y = System_File->ReadInteger("BARCODE_SERIAL", "SIZEY", 0);
	Main_Form->Serial_X = System_File->ReadInteger("BARCODE_SERIAL", "X", 0);
	Main_Form->Serial_Y = System_File->ReadInteger("BARCODE_SERIAL", "Y", 0);

	Main_Form->Company_Use = System_File->ReadBool("BARCODE_COMPANY", "USE", 0);
	Main_Form->Company_Size_X = System_File->ReadInteger("BARCODE_COMPANY", "SIZEX", 0);
	Main_Form->Company_Size_Y = System_File->ReadInteger("BARCODE_COMPANY", "SIZEY", 0);
	Main_Form->Company_X = System_File->ReadInteger("BARCODE_COMPANY", "X", 0);
	Main_Form->Company_Y = System_File->ReadInteger("BARCODE_COMPANY", "Y", 0);

	delete(System_File);
}

bool Min_Max_Check(float Min, float Max, float Value)
{
	if(Min < 0.01)
		Min = 0;

	if(Min > Value)
		return false;
	if(Max < Value)
		return false;
	return true;
}

void Recent_Model_Save(AnsiString FileName)
{
	TIniFile *System_File = new TIniFile(SYSTEM_FILE);

	System_File->WriteString("RECENT", "MODEL", FileName);

	delete(System_File);
}

AnsiString Recent_Model_Open()
{
	AnsiString FileName;

	TIniFile *System_File = new TIniFile(SYSTEM_FILE);

	FileName = System_File->ReadString("RECENT", "MODEL", "");

	delete(System_File);

	return FileName;
}

void Model_Save(AnsiString FilePath)
{
	AnsiString Str;

	FILE *fp;

	fp = fopen(FilePath.c_str(), "wb");

	if(fp == NULL)
	{
		ShowMessage("SPEC FILE OPEN ERROR");
		return;
	}

	__BARCODE_SPEC Barcode_Spec;

	memset(&Barcode_Spec, 0, sizeof(Barcode_Spec));

	AnsiString Model_Name = ExtractFileName(FilePath);
	Model_Name.Delete(Model_Name.Pos(".spc"), 4);

	Spec_Form->Model_Name_Edit->Text = Model_Name;

	strcpy(Barcode_Spec.Company, ((AnsiString)(Spec_Form->Company_Edit->Text)).c_str());
	strcpy(Barcode_Spec.Part_Number, ((AnsiString)(Spec_Form->Part_Number_Edit->Text)).c_str());
	strcpy(Barcode_Spec.Alc, ((AnsiString)(Spec_Form->Alc_Edit->Text)).c_str());
	strcpy(Barcode_Spec.Eo, ((AnsiString)(Spec_Form->Eo_Edit->Text)).c_str());
	strcpy(Barcode_Spec.Product_4M, ((AnsiString)(Spec_Form->Product_4M_Edit->Text)).c_str());
	strcpy(Barcode_Spec.Lot, ((AnsiString)(Spec_Form->Lot_Edit->Text)).c_str());

	fwrite(&Barcode_Spec, sizeof(Barcode_Spec), 1, fp);

	fclose(fp);

	Recent_Model_Save(FilePath);
}

void Model_Open(AnsiString FilePath)
{
	FILE *fp;

	fp = fopen(FilePath.c_str(), "rb");

	if(fp == NULL)
	{
		ShowMessage("SPEC FILE OPEN ERROR");
		return;
	}

	__BARCODE_SPEC Barcode_Spec;

	memset(&Barcode_Spec, 0, sizeof(Barcode_Spec));
	fread(&Barcode_Spec, sizeof(Barcode_Spec), 1, fp);

	fclose(fp);

	AnsiString Model_Name = ExtractFileName(FilePath);
	Model_Name.Delete(Model_Name.Pos(".spc"), 4);

	Spec_Form->Model_Name_Edit->Text = Model_Name;

	Spec_Form->Company_Edit->Text = Barcode_Spec.Company;
	Spec_Form->Part_Number_Edit->Text = Barcode_Spec.Part_Number;
	Spec_Form->Alc_Edit->Text = Barcode_Spec.Alc;
	Spec_Form->Eo_Edit->Text = Barcode_Spec.Eo;
	Spec_Form->Product_4M_Edit->Text = Barcode_Spec.Product_4M;
	Spec_Form->Lot_Edit->Text = Barcode_Spec.Lot;

	Recent_Model_Save(FilePath);
}

void Barcode_Model_Open(AnsiString FilePath)
{
	FILE *fp;

	AnsiString Str;
	unsigned short Year, Month, Day;

	fp = fopen(FilePath.c_str(), "rb");

	if(fp == NULL)
	{
		ShowMessage("SPEC FILE OPEN ERROR");
		return;
	}

	memset(&Barcode_Spec, 0, sizeof(Barcode_Spec));
	fread(&Barcode_Spec, sizeof(Barcode_Spec), 1, fp);

	AnsiString Model_Name = ExtractFileName(FilePath);
	Model_Name.Delete(Model_Name.Pos(".spc"), 4);

	Main_Form->Model_Name_Panel->Caption = Model_Name;

	Main_Form->Company_Panel->Caption = Barcode_Spec.Company;
	Main_Form->Part_Number_Panel->Caption = Barcode_Spec.Part_Number;
	Main_Form->Alc_Panel->Caption = Barcode_Spec.Alc;
	Main_Form->Eo_Panel->Caption = Barcode_Spec.Eo;
	Main_Form->Product_4M_Panel->Caption = Barcode_Spec.Product_4M;
	Main_Form->Lot_Panel->Caption = Barcode_Spec.Lot;

	fclose(fp);

	Recent_Model_Save(FilePath);
}

bool Password_Check(AnsiString Password)
{
	AnsiString Data;

	TIniFile *System_File = new TIniFile(SYSTEM_FILE);

	Data = System_File->ReadString("PASSWORD", "NUMBER", "");

	delete(System_File);

	if(Password == Data)
		return true;
	else
		return false;
}

void Password_Change(AnsiString Password)
{
	TIniFile *System_File = new TIniFile(SYSTEM_FILE);

	System_File->WriteString("PASSWORD", "NUMBER", Password);

	delete(System_File);
}

void Sleep_Process(DWORD Sleep_Ms)
{
	DWORD Start_Time = GetMicroSecond();

	while(GetMicroSecond() - Start_Time < (Sleep_Ms) * 1000)
	{
	}
}

void Sleep_Process_us(DWORD Sleep_us)
{
	DWORD Start_Time = GetMicroSecond();

	while(GetMicroSecond() - Start_Time < (Sleep_us))
	{
	}
}

DWORD GetMicroSecond()
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER now;

    if ( !QueryPerformanceFrequency(&frequency) )
		return GetTickCount();

	if ( !QueryPerformanceCounter(&now) )
		return GetTickCount();

    return ((now.QuadPart) / (frequency.QuadPart/1000000));
}

void PrintBarcode(char* date, int serial)
{
	char s[200];
	char data[255];
	char displayDate[20];

	Zebra_Init(
		Main_Form->Barcode_Port,
		Main_Form->Barcode_Temp);

	if(Main_Form->Parts_Number_Use)
	{
		Zebra_Label(
			Main_Form->Barcode_Port,
			Barcode_Spec.Part_Number,
			Main_Form->Parts_Number_X,
			Main_Form->Parts_Number_Y,
			Main_Form->Parts_Number_Size_X,
			Main_Form->Parts_Number_Size_Y,
			Main_Form->Barcode_Font);
	}

	if(Main_Form->Date_Use)
	{
		Zebra_Label(
			Main_Form->Barcode_Port,
			date,
			Main_Form->Date_X,
			Main_Form->Date_Y,
			Main_Form->Date_Size_X,
			Main_Form->Date_Size_Y,
			Main_Form->Barcode_Font);
	}

	if(Main_Form->Alc_Use
	&& AnsiString(Barcode_Spec.Alc) != "")
	{
		Zebra_Label(
			Main_Form->Barcode_Port,
			Barcode_Spec.Alc,
			Main_Form->Alc_X,
			Main_Form->Alc_Y,
			Main_Form->Alc_Size_X,
			Main_Form->Alc_Size_Y,
			Main_Form->Barcode_Font);
	}

	if(Main_Form->Product_4M_Use)
	{
		Zebra_Label(
			Main_Form->Barcode_Port,
			Barcode_Spec.Product_4M,
			Main_Form->Product_4M_X,
			Main_Form->Product_4M_Y,
			Main_Form->Product_4M_Size_X,
			Main_Form->Product_4M_Size_Y,
			Main_Form->Barcode_Font);
	}

	AnsiString Serial_Number;
	Serial_Number.sprintf("%07d", serial);

	if(Main_Form->Serial_Use)
	{
		Zebra_Label(
			Main_Form->Barcode_Port,
			Serial_Number,
			Main_Form->Serial_X,
			Main_Form->Serial_Y,
			Main_Form->Serial_Size_X,
			Main_Form->Serial_Size_Y,
			Main_Form->Barcode_Font);
	}

	if(Main_Form->Company_Use)
	{
		Zebra_Label(
			Main_Form->Barcode_Port,
			Barcode_Spec.Company,
			Main_Form->Company_X,
			Main_Form->Company_Y,
			Main_Form->Company_Size_X,
			Main_Form->Company_Size_Y,
			Main_Form->Barcode_Font);
	}

	AnsiString Barcode_Data = "";
	Barcode_Data.sprintf(
			"[)>06V%sP%s",
//			0x1E, 0x1D,
			Barcode_Spec.Company,/*, 0x1D,*/
			Barcode_Spec.Part_Number/*, 0x1D*/);
	/*Barcode_Data.sprintf("[)>_1E06_1DV%s_1DP%s_1DS%s_1DE%s_1DT%s%s%s%07d_1D_1E_04",
						Barcode_Spec.Company,
						Barcode_Spec.Part_Number,
						Barcode_Spec.Alc,
						Barcode_Spec.Eo,
						date,
						Barcode_Spec.Product_4M,
						Barcode_Spec.Lot,
						serial);*/

	AnsiString Barcode_Data_1, Barcode_Data_2, Barcode_Data_3;
	if(strlen(Barcode_Spec.Alc))
		Barcode_Data_1.sprintf("S%s", Barcode_Spec.Alc);
	if(strlen(Barcode_Spec.Eo))
		Barcode_Data_2.sprintf("E%s", Barcode_Spec.Eo);

	Barcode_Data_3.sprintf("T%s%s%s%07d",
				date,
				Barcode_Spec.Product_4M,
				Barcode_Spec.Lot,
				serial);

	Barcode_Data = Barcode_Data + Barcode_Data_1 + Barcode_Data_2 + Barcode_Data_3;

	if(Printing)
	{
		AnsiString Str;
		Str = FormatDateTime("YYYY-MM-DD HH:NN:SS", Now());
		Str += " | ";
		Str += Barcode_Data;

		Main_Form->Barcode_Memo->Lines->Add(Str);
		Write_Log(Str);
	}

	Zebra_Barcode_DataMatrix(
		Main_Form->Barcode_Port,
		Barcode_Data,
		Main_Form->Barcode_X,
		Main_Form->Barcode_Y,
		Main_Form->Barcode_Size);

	Zebra_Execute(Main_Form->Barcode_Port);
}

void Write_Log(AnsiString Data)
{
	ForceDirectories(LOG_PATH);
	AnsiString Path = LOG_PATH;

	Path += FormatDateTime("YYYY_MM_DD", Now());
	Path += ".txt";

	FILE *fp;
	if(FileExists(Path))
		fp = fopen(Path.c_str(), "ab");
	else
		fp = fopen(Path.c_str(), "wb");

	if(fp == NULL)
	{
		Main_Form->Barcode_Memo->Lines->Add("로그 저장 실패!");
		return;
	}

	AnsiString Str;
	Str += Data;
	Str += "\r\n";

	fwrite(Str.c_str(), Str.Length(), 1, fp);
	fclose(fp);
}

unsigned long StringToHex(char data[100])
{
	unsigned long Value = 0;
	char Length = 0;
	char i = 0;

	Length = strlen(data);

	for(i = 0; i < Length; i++)
	{
		Value |= CharToHex(data[i]) << (4 * ((Length - 1) - i));
	}

	return Value;
}

char CharToHex(char c)
{
	char Value = 0x00;

	if(('0' <= c) && (c <= '9'))
		Value = c - '0';
	else if(('A' <= c) && (c <= 'F'))
		Value = (c - 'A') + 10;
	else if(('a' <= c) && (c <= 'f'))
		Value = (c - 'a') + 10;

	return Value;
}
