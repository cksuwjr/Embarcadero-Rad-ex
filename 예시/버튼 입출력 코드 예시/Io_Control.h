//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef Io_ControlH
#define Io_ControlH

void Io_Init();
void Io_Close();

void Input_Check();

void Output_Init();
void Signal_Detect_OnOff(bool OnOff);
void Output_Io();
bool Output_Process(int Output_Number, bool OnOff);
//---------------------------------------------------------------------------
#endif
