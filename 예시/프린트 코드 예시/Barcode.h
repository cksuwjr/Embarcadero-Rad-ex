//---------------------------------------------------------------------------
#include "CPort.hpp"
#include <vcl.h>
#include <stdio.h>
#ifndef BarcodeH
#define BarcodeH
void Zebra_Init(TComPort *port, int temp);
void Zebra_Barcode_DataMatrix(TComPort *port, AnsiString barcode, int x, int y, int size);
void Zebra_Barcode_QR(TComPort *port, AnsiString barcode, int x, int y, int size);
void Zebra_Barcode_1D(TComPort *port, AnsiString barcode, int x, int y, int size);
void Zebra_Label(TComPort *port, AnsiString label, int x, int y, int x_size, int y_size, char Direction = 'N');
void Zebra_Image(TComPort *port, AnsiString image_name, int x, int y);
void Zebra_Execute(TComPort *port);


void Datamax_Init(TComPort *port, int temp);
void Datamax_Barcode(TComPort *port, AnsiString barcode, int x, int y, int size, int direction = 1);
void Datamax_Label(TComPort *port, AnsiString label, int x, int y, int size, int width, int height, int direction = 1);
void Datamax_Image(TComPort *port, AnsiString image_name, int x, int y, int width, int height, int direction = 1);
void Datamax_Execute(TComPort *port, int num_of_print = 1);


void Wincode_Init(TComPort *port, int temp, int gap, int label_size_x, int label_size_y, int printer_dpi = 203);
void Wincode_Barcode_DataMatrix(TComPort *port, AnsiString barcode, int x, int y, int scaling);
void Wincode_Barcode_QR(TComPort *port, AnsiString barcode, int x, int y, int scaling);
void Wincode_Barcode_1D(TComPort *port, AnsiString barcode, int x, int y, int x_size, int y_size);
void Wincode_Label(TComPort *port, AnsiString label, int x, int y, int size_x, int size_y, int font = 0);
void Wincode_Image(TComPort *port, AnsiString image_name, int x, int y);//ÀÌ¹ÌÁö ¹Ýµå½Ã D¿¡ ³ÖÀ»°Í
void Wincode_Execute(TComPort *port, int num_of_print = 1);


void Bixolon_Init(TComPort *port, int temp);
void Bixolon_Barcode_DataMatrix(TComPort *port, AnsiString barcode, int x, int y, int size);
void Bixolon_Barcode_QR(TComPort *port, AnsiString barcode, int x, int y, int size, int rotate = 0);
//폰트0~9, 사이즈확대정도1~4, 자간-10~10, 로테이션0~3, 굵게'N'or'B'
void Bixolon_Label(TComPort *port, AnsiString label, int x, int y, int x_size, int y_size, int font, int letter_spacing = -1, int rotate = 0, bool bold = false);
void Bixolon_Execute(TComPort *port, int num_of_print = 1);
//---------------------------------------------------------------------------
#endif

