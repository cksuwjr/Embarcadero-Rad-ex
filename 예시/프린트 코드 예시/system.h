//---------------------------------------------------------------------------

#ifndef systemH
#define systemH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "sButton.hpp"
#include "sPanel.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "sGroupBox.hpp"
#include "sEdit.hpp"
#include "sLabel.hpp"
#include "cyBaseLed.hpp"
#include "cyLed.hpp"
#include "sCheckBox.hpp"
#include "sSpinEdit.hpp"
//---------------------------------------------------------------------------
class TSystem_Form : public TForm
{
__published:	// IDE-managed Components
	TsPanel *sPanel1;
	TsButton *Close_Button;
	TsPanel *sPanel2;
	TsButton *Save_Button;
	TTimer *Timer;
	TTimer *System_Timer;
	TsGroupBox *sGroupBox5;
	TsLabel *sLabel142;
	TsLabel *sLabel20;
	TsLabel *sLabel22;
	TsLabel *sLabel23;
	TsLabel *sLabel27;
	TsLabel *sLabel28;
	TsLabel *sLabel29;
	TsLabel *sLabel11;
	TsLabel *sLabel12;
	TsLabel *sLabel13;
	TsLabel *sLabel14;
	TsLabel *sLabel38;
	TsLabel *sLabel39;
	TsLabel *sLabel40;
	TsDecimalSpinEdit *Barcode_Temp_Edit;
	TsEdit *Serial_Edit;
	TsEdit *Barcode_X_Edit;
	TsEdit *Barcode_Y_Edit;
	TsButton *Barcode_Print_Button;
	TsCheckBox *Parts_Number_Use_CheckBox;
	TsEdit *Parts_Number_Size_X_Edit;
	TsEdit *Parts_Number_X_Edit;
	TsEdit *Parts_Number_Y_Edit;
	TsEdit *Date_Y_Edit;
	TsEdit *Date_X_Edit;
	TsEdit *Date_Size_X_Edit;
	TsCheckBox *Date_Use_CheckBox;
	TsEdit *Barcode_Size_Edit;
	TsLabel *sLabel1;
	TsLabel *sLabel2;
	TsEdit *Print_Count_Edit;
	TsLabel *sLabel3;
	TsEdit *Print_Time_Edit;
	TsLabel *sLabel4;
	TsLabel *sLabel5;
	TsDecimalSpinEdit *Barcode_Width_Edit;
	TsLabel *sLabel6;
	TsDecimalSpinEdit *Barcode_Height_Edit;
	TsLabel *sLabel7;
	TsDecimalSpinEdit *Barcode_Font_Edit;
	TsLabel *sLabel8;
	TsLabel *sLabel9;
	TsLabel *sLabel10;
	TsEdit *Alc_Y_Edit;
	TsEdit *Alc_X_Edit;
	TsEdit *Alc_Size_X_Edit;
	TsCheckBox *Alc_Use_CheckBox;
	TsCheckBox *Product_4M_Use_CheckBox;
	TsEdit *Product_4M_Size_X_Edit;
	TsEdit *Product_4M_X_Edit;
	TsEdit *Product_4M_Y_Edit;
	TsLabel *sLabel15;
	TsLabel *sLabel16;
	TsLabel *sLabel17;
	TsLabel *sLabel18;
	TsLabel *sLabel19;
	TsLabel *sLabel21;
	TsEdit *Serial_Y_Edit;
	TsEdit *Serial_X_Edit;
	TsEdit *Serial_Size_X_Edit;
	TsCheckBox *Serial_Use_CheckBox;
	TsLabel *sLabel24;
	TsLabel *sLabel25;
	TsEdit *Parts_Number_Size_Y_Edit;
	TsEdit *Date_Size_Y_Edit;
	TsLabel *sLabel26;
	TsEdit *Alc_Size_Y_Edit;
	TsEdit *Product_4M_Size_Y_Edit;
	TsLabel *sLabel30;
	TsLabel *sLabel31;
	TsEdit *Serial_Size_Y_Edit;
	TsLabel *sLabel32;
	TsDecimalSpinEdit *Barcode_Gap_Edit;
	TsLabel *sLabel33;
	TsLabel *sLabel34;
	TsLabel *sLabel35;
	TsLabel *sLabel36;
	TsEdit *Company_Y_Edit;
	TsEdit *Company_X_Edit;
	TsEdit *Company_Size_X_Edit;
	TsCheckBox *Company_Use_CheckBox;
	TsEdit *Company_Size_Y_Edit;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Close_ButtonClick(TObject *Sender);
	void __fastcall Save_ButtonClick(TObject *Sender);
	void __fastcall Barcode_Print_ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSystem_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSystem_Form *System_Form;
//---------------------------------------------------------------------------
#endif
