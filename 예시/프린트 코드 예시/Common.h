//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef CommonH
#define CommonH
//---------------------------------------------------------------------------
#include "var.h"
#pragma link "cyPanel"

bool KeyState(int Key);

void System_Save();
void System_Load();

bool Min_Max_Check(float Min, float Max, float Value);

void Recent_Model_Save(AnsiString FileName);
AnsiString Recent_Model_Open();
void Model_Save(AnsiString FilePath);
void Model_Open(AnsiString FilePath);
void Barcode_Model_Open(AnsiString FilePath);

bool Password_Check(AnsiString Password);
void Password_Change(AnsiString Password);

void Test_Model_Count_Display(AnsiString Model);
void Test_Model_Count_Save(AnsiString Model);

void Sleep_Process(DWORD Sleep_Ms);
void Sleep_Process_us(DWORD Sleep_us);
DWORD GetMicroSecond();

void PrintBarcode(char* date, int serial);
void Write_Log(AnsiString Data);

unsigned long StringToHex(char data[100]);
char CharToHex(char c);

#endif
