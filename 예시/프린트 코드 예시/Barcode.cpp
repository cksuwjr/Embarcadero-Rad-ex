//---------------------------------------------------------------------------
#pragma hdrstop

#include "Barcode.h"
#include "var.h"
//---------------------------------------------------------------------------
void Zebra_Init(TComPort *port, int temp)
{

	port->WriteStr("^XA\r\n");
	AnsiString Str = "";
	Str = Str.sprintf("^MD%d\r\n", temp);
	port->WriteStr(Str);
}

void Zebra_Barcode_DataMatrix(TComPort *port, AnsiString barcode, int x, int y, int size)
{
	if(barcode == "")
		return;

	char s[200] = {0,};
	sprintf_s(s, sizeof(s), "^FO%d,%d\r\n", x, y);
	port->WriteStr(s);
	sprintf_s(s, sizeof(s), "^BXN,%d,200,,,5,,\r\n", size);
	port->WriteStr(s);
	sprintf(s, "^FH_^FD%s^FS\r\n", barcode);
	port->WriteStr(s);
}

void Zebra_Barcode_QR(TComPort *port, AnsiString barcode, int x, int y, int size)
{
	if(barcode == "")
		return;

	char s[200] = {0,};
	sprintf_s(s, sizeof(s), "^FO%03d,%03d\r\n", x, y);
	port->WriteStr(s);
	sprintf_s(s, sizeof(s), "^BQN,2,%d\r\n", size);
	port->WriteStr(s);
	sprintf(s, "^FDMM,A%s^FS\r\n", barcode);
	port->WriteStr(s);
}

void Zebra_Barcode_1D(TComPort *port, AnsiString barcode, int x, int y, int size)
{
	if(barcode == "")
		return;

	char s[200] = {0,};
	sprintf_s(s, sizeof(s), "^FO%d,%d^BY2,2.5\r\n", x, y);
	port->WriteStr(s);
	sprintf_s(s, sizeof(s), "^BCR,%d,N\r\n", size);
	port->WriteStr(s);
	sprintf(s, "^FD%s^FS\r\n", barcode);
	port->WriteStr(s);
}

void Zebra_Label(TComPort *port, AnsiString label, int x, int y, int x_size, int y_size, char Direction)
{
	if(label == "")
		return;

	char s[200] = {0,};
	sprintf_s(s, sizeof(s), "^FO%d,%d^A0%c,%d,%d\r\n", x, y, Direction, x_size, y_size);
	port->WriteStr(s);
	sprintf_s(s, sizeof(s), "^FD%s^FS\r\n", label);
	port->WriteStr(s);
}

void Zebra_Image(TComPort *port, AnsiString image_name, int x, int y)
{
	if(image_name == "")
		return;

	char s[200] = {0,};
	sprintf_s(s, sizeof(s), "^FO%03d,%03d^%s^FS\r\n", x, y, image_name);
	port->WriteStr(s);
}

void Zebra_Execute(TComPort *port)
{
	port->WriteStr("^XZ\r\n");
}
//==============================================================================
void Datamax_Init(TComPort *port, int temp)
{
	char s[200] = {0,};
 	memset(s,NULL,sizeof(s));
	strcpy(s,"M9999\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"c0000\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"e\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"Kf0035\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"DL\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"L\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"R0000\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"D11\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"PK\r\n");
	port->WriteStr(s);

	memset(s,NULL,sizeof(s));
	strcpy(s,"SK\r\n");
	port->WriteStr(s);;

	memset(s,NULL,sizeof(s));
	sprintf(s,"H%d\r\n", temp);
	port->WriteStr(s);
}

void Datamax_Barcode(TComPort *port, AnsiString barcode, int x, int y, int size, int direction)
{
	char s[200] = {0,};
	sprintf(s,"%01dW1c%1d%1d000%04d%04d2200000000%s\r\n"
	          ,direction
			  ,size
			  ,size
			  ,y
			  ,x
			  ,barcode);
	port->WriteStr(s);
}

void Datamax_Label(TComPort *port, AnsiString label, int x, int y, int size, int width, int height, int direction)
{
	char s[200] = {0,};
	sprintf(s,"%01d9%d%dS00%04d%04d%04d%04d%s\r\n"
			,direction
			,width
			,height
			,y
			,x
			,size
			,size
			,label);
	port->WriteStr(s);
}

void Datamax_Image(TComPort *port, AnsiString image_name, int x, int y, int width, int height, int direction)
{
	char s[200] = {0,};
	sprintf(s,"%01dY%d%d000%04d%04d%s\r\n"
			,direction
			,width
			,height
			,y
			,x
			,image_name);
	port->WriteStr(s);
}

void Datamax_Execute(TComPort *port, int num_of_print)
{
	char s[200] = {0,};
	memset(s,NULL,sizeof(s));
	sprintf(s,"Q%04d\r\n", num_of_print);
	port->WriteStr(s);;

	memset(s,NULL,sizeof(s));
	strcpy(s,"E\r\n");
	port->WriteStr(s);;
}
//==============================================================================
void Wincode_Init(TComPort *port, int temp, int gap, int label_size_x, int label_size_y, int printer_dpi)
{
	AnsiString Str;

	int mm_per_dot = 0;
	if(printer_dpi == 203)
		mm_per_dot = 8;
	else
		mm_per_dot = 12;

	Str.sprintf("sLABEL,%d,%d\r\n", label_size_x * mm_per_dot, label_size_y * mm_per_dot);
	port->WriteStr(Str);

	Str.sprintf("sGAP,%d,0\r\n", gap * mm_per_dot);
	port->WriteStr(Str);

	port->WriteStr("rSENSOR,0\r\n");//불투명0, 투명1

	port->WriteStr("sTPHY,0\r\n");//시작위치

	Str.sprintf("sDENSITY,%d\r\n", temp);
	port->WriteStr(Str);

	port->WriteStr("sSPEED,3\r\n");//프린트 속도

	port->WriteStr("sTHERMAL,1\r\n");//열모드

	port->WriteStr("sDIRECTION,1\r\n");//방향
}

void Wincode_Barcode_DataMatrix(TComPort *port, AnsiString barcode, int x, int y, int scaling)
{
	AnsiString Str;
	Str.sprintf("w2DB,DM,%d,%d,%d,%d,%d,%d,\"%s\"\r\n", x, y, 0, scaling, 50, 50, barcode);
	port->WriteStr(Str);
}

void Wincode_Barcode_QR(TComPort *port, AnsiString barcode, int x, int y, int scaling)
{
	AnsiString Str;
	Str.sprintf("w2DB,QR,%d,%d,%d,%d,%d,%d,\"%s\"\r\n", x, y, 0, 0, scaling, 0, barcode);
	port->WriteStr(Str);
}

void Wincode_Barcode_1D(TComPort *port, AnsiString barcode, int x, int y, int x_size, int y_size)
{
	AnsiString Str;
	//w1DB,P1,P2 ,P3,P4 ,P5,P6,P7,P8,[P9,][P10,][P11,][P12,][P13,][P14,][P15,] [P16,]”DATA1”
	//w1DB,48,240,0 ,C39,0 ,3 ,3 ,72,"12345678"↵

	//P1= X coordinate (dot) Value: 0 ~ maximum printing width
	//P2= Y coordinate (dot) Value: 0 ~ maximum printing length
	//P3= Rotation 0: No rotation 1: Rotate right 90 degrees 2: Rotate right 180 degrees 3: Rotate right 270 degrees
	//P4= Barcode Type
	//P5= Check digit 0=None 1=Enable to show text 2=Enable to hide text
	//P6= Narrow bar width (dot) Value: 1 ~ 30
	//P7= Ratio between narrow and wide bars (dot) Value: 2 ~ 60
	//P8= Bar code height (dot) Value: 1 ~ maximum printing length.
	int rotate = 0;
	Str.sprintf("w1DB,%d,%d,%d,C39,0,%d,3,%d,\"%s\"\r\n",x ,y ,rotate, x_size, y_size, barcode);
	port->WriteStr(Str);
}

void Wincode_Label(TComPort *port, AnsiString label, int x, int y, int size_x, int size_y, int font)
{
	AnsiString Str;
	Str.sprintf("wTEXT,%d,%d,%d,%d,%d,%d,%d,\"%s\"\r\n", x, y, 0, font, size_x, size_y, 0, label);
	port->WriteStr(Str);
}

void Wincode_Image(TComPort *port, AnsiString image_name, int x, int y)
{
	AnsiString Str;
	Str.sprintf("wLOADIMG,%d,%d,0,\"d:\\WPL_STUFF\\%s.bmp\"\r\n", x, y, image_name);
	port->WriteStr(Str);
}

void Wincode_Execute(TComPort *port, int num_of_print)
{
	AnsiString Str;
	Str.sprintf("wPRINT,%d\r\n", num_of_print);
	port->WriteStr(Str);
}
//==============================================================================
void Bixolon_Init(TComPort *port, int temp)
{
	AnsiString Str;

	port->WriteStr("SOB\r\n");//시작문자

	Str.sprintf("SD%d\r\n", temp);
	port->WriteStr(Str);
}

void Bixolon_Barcode_DataMatrix(TComPort *port, AnsiString barcode, int x, int y, int size)
{
	if(barcode == "")
		return;

	AnsiString Str;
	Str.sprintf("B2%d,%d,D,%d,N,'%s'\r\n", x, y, size, barcode);//빅솔론은 바코드 사이즈 1~4
	port->WriteStr(Str);
}

void Bixolon_Barcode_QR(TComPort *port, AnsiString barcode, int x, int y, int size, int rotate)
{
	if(barcode == "")
		return;

	AnsiString Str;
	Str.sprintf("B2%d,%d,Q,2,Q,%d,%d,'%s'\r\n", x, y, size, rotate, barcode);//p5:ECC레벨(L,M,Q,H), p7:로테이션(0,1,2,3)
	port->WriteStr(Str);
}

void Bixolon_Label(TComPort *port, AnsiString label, int x, int y, int x_size, int y_size, int font, int letter_spacing, int rotate, bool bold)
{
	AnsiString Bold_Str;
	if(!bold)
		Bold_Str = "N";
	else
		Bold_Str = "B";

	AnsiString Str;
	Str.sprintf("T%d,%d,%d,%d,%d,%d,%d,N,%s,' %s'\r\n", x, y, font, x_size, y_size, letter_spacing, rotate, Bold_Str, label);
	//Str.sprintf("V%d,%d,U,%d,%d,%d,N,N,N,0,L,0,'%s'\r\n", x, y, x_size, y_size, letter_spacing, label);
	port->WriteStr(Str);
}

void Bixolon_Execute(TComPort *port, int num_of_print)
{
	AnsiString Str;
	Str.sprintf("P%d\r\n", num_of_print);
	port->WriteStr(Str);
}
#pragma package(smart_init)
