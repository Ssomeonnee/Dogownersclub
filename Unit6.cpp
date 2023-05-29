//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormCreate(TObject *Sender)
{
    StringGrid1->ColWidths[0]=50; //ширина столбцов
	StringGrid1->ColWidths[1]=150;
	StringGrid1->ColWidths[2]=200;
	StringGrid1->ColWidths[3]=100;
	StringGrid1->ColWidths[4]=150;
	StringGrid1->ColWidths[5]=200;
	StringGrid1->ColWidths[6]=200;
	StringGrid1->ColWidths[7]=400;


	StringGrid1->Cells[0][0]="№";
	StringGrid1->Cells[1][0]="Кличка";
	StringGrid1->Cells[2][0]="Порода";
	StringGrid1->Cells[3][0]="Пол";
	StringGrid1->Cells[4][0]="Дата рождения";
	StringGrid1->Cells[5][0]="Кличка отца";
	StringGrid1->Cells[6][0]="Кличка матери";
	StringGrid1->Cells[7][0]="Ф.И.О. владельца";
}
//---------------------------------------------------------------------------

