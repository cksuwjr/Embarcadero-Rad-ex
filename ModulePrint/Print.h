//---------------------------------------------------------------------------

#ifndef PrintH
#define PrintH
//---------------------------------------------------------------------------
#include <vcl.h>
#include "CPort.hpp"

extern bool Printing;
extern int Print_Count;

void Print_Process();
void Change_PrintStep(int PrintStep);
void Test_Barcode_Print();
void PrintStart();
void PrintBarcode(AnsiString Barcode_Data);

void PrintSetStart();
#endif
