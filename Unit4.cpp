//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
    StringGrid1->Cells[0][0]="№";
	StringGrid1->Cells[1][0]="Кличка";
	StringGrid1->Cells[2][0]="Пол";
	StringGrid1->Cells[3][0]="Дата рождения";
	StringGrid1->Cells[4][0]="Кличка отца";
	StringGrid1->Cells[5][0]="Кличка матери";
	StringGrid1->Cells[6][0]="Ф.И.О. владельца";

    StringGrid1->ColWidths[0]=50; //ширина столбцов
	StringGrid1->ColWidths[1]=150;
	StringGrid1->ColWidths[2]=100;
	StringGrid1->ColWidths[3]=150;
	StringGrid1->ColWidths[4]=200;
	StringGrid1->ColWidths[5]=200;
	StringGrid1->ColWidths[6]=400;
}
//---------------------------------------------------------------------------

