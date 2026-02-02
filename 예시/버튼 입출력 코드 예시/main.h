//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvSmoothTouchKeyBoard.hpp"
#include "sBitBtn.hpp"
#include "sDialogs.hpp"
#include "sLabel.hpp"
#include "sPanel.hpp"
#include "sSkinManager.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cyBaseLed.hpp"
#include "cyBasePanel.hpp"
#include "cyLed.hpp"
#include "cyPanel.hpp"
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iPlot.hpp"
#include "iPlotComponent.hpp"
#include "iSevenSegmentDisplay.hpp"
#include "iSevenSegmentInteger.hpp"
#include "iVCLComponent.hpp"
#include "sButton.hpp"
#include "sEdit.hpp"
#include "sGroupBox.hpp"
#include "sPageControl.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "sStatusBar.hpp"
#include "CPort.hpp"
#include "acProgressBar.hpp"
#include "sSkinProvider.hpp"
#include <Vcl.FileCtrl.hpp>
#include "sMemo.hpp"
#include "acAlphaImageList.hpp"
#include <Vcl.ImgList.hpp>
#include "sCheckBox.hpp"
#include "iSevenSegmentAnalog.hpp"
#include "sScrollBox.hpp"
#include "iLedMatrix.hpp"
//---------------------------------------------------------------------------
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
	TsPanel *Title_Panel;
	TsLabel *Title_Label;
	TsBitBtn *Exit_Button;
	TsBitBtn *Model_Button;
	TsBitBtn *System_Button;
	TsSkinManager *sSkinManager1;
	TAdvSmoothPopupTouchKeyBoard *TouchKeyBoard;
	TTimer *Timer;
	TsOpenDialog *OpenDialog;
	TsSaveDialog *SaveDialog;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TsPanel *sPanel1;
	TsGroupBox *sGroupBox1;
	TsButton *Test_Model_Open_Button;
	TsPanel *Model_Name_Panel;
	TsGroupBox *sGroupBox29;
	TsGroupBox *sGroupBox2;
	TsStatusBar *StatusBar;
	TsSkinProvider *sSkinProvider1;
	TsPanel *Test_Message_Panel;
	TComPort *Barcode_Port;
	TsGroupBox *sGroupBox3;
	TsLabel *sLabel262;
	TsLabel *sLabel263;
	TsLabel *sLabel3;
	TsLabel *sLabel4;
	TsLabel *sLabel5;
	TsLabel *sLabel6;
	TsPanel *Part_Number_Panel;
	TsPanel *Alc_Panel;
	TsPanel *Product_4M_Panel;
	TsPanel *Lot_Panel;
	TsPanel *Eo_Panel;
	TsPanel *Company_Panel;
	TsGroupBox *sGroupBox4;
	TsMemo *Barcode_Memo;
	TCheckBox *One;
	TCheckBox *Set;
	TsButton *Delete_Memo;
	TsButton *Print_Button;
	TsButton *Print_Set_Button;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall Exit_ButtonClick(TObject *Sender);
	void __fastcall Model_ButtonClick(TObject *Sender);
	void __fastcall Test_Model_Open_ButtonClick(TObject *Sender);
	void __fastcall System_ButtonClick(TObject *Sender);
	void __fastcall Delete_MemoClick(TObject *Sender);
	void __fastcall Print_ButtonClick(TObject *Sender);
	void __fastcall Print_Set_ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMain_Form(TComponent* Owner);

	void __fastcall TMain_Form::Print_Process();
	void __fastcall TMain_Form::Test_Barcode_Print();

	AnsiString Str;

	bool	Model_Flag;
	bool	Count_Flag;

	DWORD	Sql_Timer;

	int		Barcode_Temp;
	int		Barcode_Width;
	int		Barcode_Height;
	int		Barcode_Gap;
	int		Barcode_Font;

	int		Print_Count;
	int		Print_Time;

	int		Barcode_Size;
	int		Barcode_X;
	int		Barcode_Y;

	bool	Parts_Number_Use;
	int		Parts_Number_Size_X;
	int		Parts_Number_Size_Y;
	int		Parts_Number_X;
	int		Parts_Number_Y;

	bool	Date_Use;
	int		Date_Size_X;
	int		Date_Size_Y;
	int		Date_X;
	int		Date_Y;

	bool	Alc_Use;
	int		Alc_Size_X;
	int		Alc_Size_Y;
	int		Alc_X;
	int		Alc_Y;

	bool	Product_4M_Use;
	int		Product_4M_Size_X;
	int		Product_4M_Size_Y;
	int		Product_4M_X;
	int		Product_4M_Y;

	bool	Serial_Use;
	int		Serial_Size_X;
	int		Serial_Size_Y;
	int		Serial_X;
	int		Serial_Y;

	bool	Company_Use;
	int		Company_Size_X;
	int		Company_Size_Y;
	int		Company_X;
	int		Company_Y;
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
