//---------------------------------------------------------------------------

#ifndef BarcodeH
#define BarcodeH

#include "CPort.hpp"
//---------------------------------------------------------------------------

void Zebra_Init(TComPort *port, int temp);

void Zebra_Barcode_DataMatrix(TComPort *port, AnsiString barcode, int x, int y, int size);

void Zebra_Execute(TComPort *port);

#endif
