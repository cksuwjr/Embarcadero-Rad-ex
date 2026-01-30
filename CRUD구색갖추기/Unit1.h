//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
enum class ProcessType{
	None,
	Create,
	Read,
	Update,
	Delete,
};

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *MemoValue;
	TButton *CreateBTN;
	TButton *ReadBTN;
	TButton *UpdateBTN;
	TButton *DeleteBTN;
	TEdit *IDValue;
	TLabel *Label1;
	TEdit *NameValue;
	TLabel *Label2;
	void __fastcall CreateBTNClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ReadBTNClick(TObject *Sender);
	void __fastcall UpdateBTNClick(TObject *Sender);
	void __fastcall DeleteBTNClick(TObject *Sender);
private:	// User declarations
	//MYSQL* conn;
	ProcessType ptype;
	void InitializeMemo(ProcessType newType);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
