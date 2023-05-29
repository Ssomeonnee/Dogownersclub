//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
    StringGrid1->Cells[0][0]="№";
	StringGrid1->Cells[1][0]="Ф.И.О. владельца";
	StringGrid1->Cells[2][0]="Количество собак";


	StringGrid1->ColWidths[0]=50; //ширина столбцов
	StringGrid1->ColWidths[1]=400;
	StringGrid1->ColWidths[2]=200;
}
//---------------------------------------------------------------------------

