//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TStringGrid *StringGrid1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TButton *Button1;
	TEdit *Edit1;
	TStatusBar *StatusBar1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N13;
	TMenuItem *A1;
	TMenuItem *N30;
	TMenuItem *N37;
	TMenuItem *A2;
	TMenuItem *N31;
	TMenuItem *N38;
	TMenuItem *N25;
	TMenuItem *N32;
	TMenuItem *N39;
	TMenuItem *N26;
	TMenuItem *N33;
	TMenuItem *N40;
	TMenuItem *N27;
	TMenuItem *N34;
	TMenuItem *N41;
	TMenuItem *N28;
	TMenuItem *N35;
	TMenuItem *N42;
	TMenuItem *N29;
	TMenuItem *N36;
	TMenuItem *N43;
	TMenuItem *N44;
	TMenuItem *N47;
	TMenuItem *N45;
	TMenuItem *N46;
	TMenuItem *N210;
	TMenuItem *N211;
	TMenuItem *N48;
	TMenuItem *N49;
	TMenuItem *N50;
	TMenuItem *N51;
	TMenuItem *N52;
	TMenuItem *N53;
	TMenuItem *N54;
	TMenuItem *N55;
	TMenuItem *N56;
	TMenuItem *N57;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N58;
	TMenuItem *N59;
	TMenuItem *N60;
	TMenuItem *N61;
	TMenuItem *N62;
	TPopupMenu *PopupMenu2;
	TMenuItem *N63;
	TMenuItem *N64;
	TMenuItem *N65;
	TMenuItem *N66;
	TMenuItem *N67;
	TMenuItem *N68;
	TMenuItem *N69;
	TImageList *ImageList1;
	TSaveDialog *SaveDialog2;
	TMenuItem *N70;
	TMenuItem *N71;
	TMenuItem *N72;
	TMenuItem *N73;
	TMenuItem *N74;
	TMenuItem *N75;
	void __fastcall N8Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N17Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);
	void __fastcall N19Click(TObject *Sender);
	void __fastcall N20Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall N22Click(TObject *Sender);
	void __fastcall N23Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall N30Click(TObject *Sender);
	void __fastcall N37Click(TObject *Sender);
	void __fastcall N31Click(TObject *Sender);
	void __fastcall N38Click(TObject *Sender);
	void __fastcall N32Click(TObject *Sender);
	void __fastcall N39Click(TObject *Sender);
	void __fastcall N33Click(TObject *Sender);
	void __fastcall N40Click(TObject *Sender);
	void __fastcall N34Click(TObject *Sender);
	void __fastcall N41Click(TObject *Sender);
	void __fastcall N35Click(TObject *Sender);
	void __fastcall N42Click(TObject *Sender);
	void __fastcall N36Click(TObject *Sender);
	void __fastcall N43Click(TObject *Sender);
	void __fastcall N45Click(TObject *Sender);
	void __fastcall N46Click(TObject *Sender);
	void __fastcall N210Click(TObject *Sender);
	void __fastcall N48Click(TObject *Sender);
	void __fastcall N49Click(TObject *Sender);
	void __fastcall N50Click(TObject *Sender);
	void __fastcall N51Click(TObject *Sender);
	void __fastcall N52Click(TObject *Sender);
	void __fastcall N53Click(TObject *Sender);
	void __fastcall N54Click(TObject *Sender);
	void __fastcall N55Click(TObject *Sender);
	void __fastcall N56Click(TObject *Sender);
	void __fastcall N57Click(TObject *Sender);
	void __fastcall N58Click(TObject *Sender);
	void __fastcall N59Click(TObject *Sender);
	void __fastcall N60Click(TObject *Sender);
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall N47Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N63Click(TObject *Sender);
	void __fastcall N64Click(TObject *Sender);
	void __fastcall N65Click(TObject *Sender);
	void __fastcall N66Click(TObject *Sender);
	void __fastcall N67Click(TObject *Sender);
	void __fastcall N68Click(TObject *Sender);
	void __fastcall N69Click(TObject *Sender);
	void __fastcall N62Click(TObject *Sender);
	void __fastcall OnCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall N16Click(TObject *Sender);
	void __fastcall OnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall OnContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall N71Click(TObject *Sender);
	void __fastcall N72Click(TObject *Sender);
	void __fastcall N73Click(TObject *Sender);
	void __fastcall N74Click(TObject *Sender);
	void __fastcall N75Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
