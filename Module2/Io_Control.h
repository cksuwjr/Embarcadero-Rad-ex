//---------------------------------------------------------------------------

#ifndef Io_ControlH
#define Io_ControlH
//---------------------------------------------------------------------------

void Io_Init();
void Io_Close();
void Input_Check();
void Output_IO();
bool Output_Process(int Output_Number, bool OnOff);
void Output_Init();

#endif
