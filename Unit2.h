//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label9;
	TLabel *Label8;
	TLabel *Label7;
	TLabel *Label6;
	TLabel *Label5;
	TLabel *Label4;
	TLabel *Label3;
	TLabel *Label2;
	TLabel *Label1;
	TButton *Button1;
	TEdit *Edit7;
	TEdit *Edit6;
	TEdit *Edit2;
	TEdit *Edit1;
	TListBox *ListBox1;
	TRadioGroup *RadioGroup1;
	TDateTimePicker *DateTimePicker1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall OnKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall OnCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
