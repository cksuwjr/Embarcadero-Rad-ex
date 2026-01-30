//---------------------------------------------------------------------------

#ifndef specH
#define specH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "sSkinProvider.hpp"
#include "sButton.hpp"
#include "sEdit.hpp"
#include "sPanel.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "sGroupBox.hpp"
#include "sCheckBox.hpp"
#include "sLabel.hpp"
#include "sSpinEdit.hpp"
#include "sDialogs.hpp"
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include "sBitBtn.hpp"
#include <Vcl.Buttons.hpp>
#include "sPageControl.hpp"
#include <Vcl.ComCtrls.hpp>
#include "sRadioButton.hpp"
#include "sComboBox.hpp"
#include "cyBaseLed.hpp"
#include "cyLed.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Vcl.Grids.hpp>
#include "sMemo.hpp"
#include <Vcl.ImgList.hpp>
#include "acAlphaImageList.hpp"
#include "sScrollBox.hpp"
#include "sTrackBar.hpp"
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iLedMatrix.hpp"
#include "iVCLComponent.hpp"
//---------------------------------------------------------------------------
class TSpec_Form : public TForm
{
__published:	// IDE-managed Components
	TsPanel *sPanel1;
	TsEdit *Model_Name_Edit;
	TsButton *Close_Button;
	TsButton *Open_Button;
	TsButton *Save_Button;
	TsOpenDialog *OpenDialog;
	TsSaveDialog *SaveDialog;
	TTimer *Timer;
	TsPanel *sPanel2;
	TsGroupBox *sGroupBox31;
	TsLabel *sLabel262;
	TsLabel *sLabel263;
	TsEdit *Company_Edit;
	TsEdit *Part_Number_Edit;
	TsLabel *sLabel3;
	TsEdit *Alc_Edit;
	TsLabel *sLabel4;
	TsEdit *Eo_Edit;
	TsLabel *sLabel5;
	TsEdit *Product_4M_Edit;
	TsLabel *sLabel6;
	TsEdit *Lot_Edit;
	TsGroupBox *sGroupBox1;
	TcyLed *Output_Led_1;
	TcyLed *Output_Led_2;
	TsLabel *sLabel1;
	TsLabel *sLabel64;
	TcyLed *Input_Led_2;
	TsLabel *sLabel113;
	TcyLed *Input_Led_3;
	TsLabel *sLabel94;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Close_ButtonClick(TObject *Sender);
	void __fastcall Open_ButtonClick(TObject *Sender);
	void __fastcall Save_ButtonClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall Output_Led_1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TSpec_Form(TComponent* Owner);

	AnsiString Str;

	int Index;

	double Data;
};
//---------------------------------------------------------------------------
extern PACKAGE TSpec_Form *Spec_Form;
//---------------------------------------------------------------------------
#endif
