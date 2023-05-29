//---------------------------------------------------------------------------

#include <String>
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

String spiece;
String g;

bool press=false;
bool press1=true;
bool date=false;

void repeat()
{
	if (Form2->RadioGroup1->ItemIndex==-1)
	{
		Application->MessageBox(L"Выберете пол",L"Предупреждение", MB_OK);
	}
	if (Form2->ListBox1->ItemIndex==-1)
	{
		 Application->MessageBox(L"Выберете породу",L"Предупреждение", MB_OK);
	}
	if (Form2->Edit1->Text.IsEmpty())
	{
		 Application->MessageBox(L"Заполните поле Ф.И.О.",L"Предупреждение", MB_OK);
		 Form2->Edit1->SetFocus();
	}
	if (Form2->Edit2->Text.IsEmpty())
	{
		 Application->MessageBox(L"Заполните поле кличка",L"Предупреждение", MB_OK);
		 Form2->Edit2->SetFocus();
	}
	if (Form2->Edit6->Text.IsEmpty())
	{
		 Application->MessageBox(L"Заполните поле кличка отца",L"Предупреждение", MB_OK);
		 Form2->Edit6->SetFocus();
	}
	if (Form2->Edit7->Text.IsEmpty())
	{
		 Application->MessageBox(L"Заполните поле кличка матери",L"Предупреждение", MB_OK);
		 Form2->Edit7->SetFocus();
	}
	else if ((Form2->DateTimePicker1->Date==Date())&&(date==false))
	{
		 if (Application->MessageBox(L"Не хотите изменить дату рождения?",L"Предупреждение", MB_YESNO)==IDYES)
		 {
			 Form2->DateTimePicker1->SetFocus();
		 }
		 else
		 {
			Form2->DateTimePicker1->Date=Date();
			date=true;
		 }

	}
	return;
}


void choosespiece(TListBox *ListBox1)
{
	   if (ListBox1->ItemIndex==0)
		   spiece="Терьер";
	else if (ListBox1->ItemIndex==1)
		   spiece="Хаски";
	else if (ListBox1->ItemIndex==2)
			spiece="Овчарка";
	else if (ListBox1->ItemIndex==3)
			spiece="Шпиц";
	else if (ListBox1->ItemIndex==4)
			spiece="Бульдог";
	else if (ListBox1->ItemIndex==5)
			spiece="Мопс";
	else if (ListBox1->ItemIndex==6)
			spiece="Такса";
	else if (ListBox1->ItemIndex==7)
			spiece="Пудель";
	else if (ListBox1->ItemIndex==8)
			spiece="Корги";
	else if (ListBox1->ItemIndex==9)
			spiece="Другая порода";
}

void choosegender(TRadioGroup *RadioGroup1)
{
     if (RadioGroup1->ItemIndex==0)
		  g="мужской";
	else if (RadioGroup1->ItemIndex==1)
		  g="женский";
}

void changing(String* text)
{
	String text1;
	text1=AnsiLowerCase(*text);   //в нижнем регистре

	String text2=AnsiUpperCase(text1[1]); //верхний и нижние

	for (int i=2; i <= text1.Length(); i++)
	{
	   if (text1[i-1]==' ')
	   {
		  text2=text2+AnsiUpperCase(text1[i]);
	   }
	   else
			text2=text2+text1[i];
	}

	*text=text2;
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    if (((Form2->DateTimePicker1->Date!=Date())||(date==true))&&!(Edit1->Text.IsEmpty())&&!(Edit2->Text.IsEmpty())&&!(Edit6->Text.IsEmpty())&&!(Edit7->Text.IsEmpty())&&(Form2->RadioGroup1->ItemIndex!=-1)&&(Form2->ListBox1->ItemIndex!=-1))
	{
		int nrow;      //запись в таблицу

	  if (Form2->Caption=="Добавление")
	  {
			nrow=Form1->StringGrid1->RowCount-1;

			Form1->StringGrid1->Cells[0][nrow]=IntToStr(Form1->StringGrid1->RowCount-1);
			++Form1->StringGrid1->RowCount;
	  }
	  else
	  {
		  nrow=Form1->StringGrid1->Selection.Top;
	  }
        String fn=Edit1->Text;

		changing(&fn);
		Edit1->Text=fn;

		fn=Edit2->Text;
		changing(&fn);
		Edit2->Text=fn;

		fn=Edit6->Text;
		changing(&fn);
		Edit6->Text=fn;

		fn=Edit7->Text;
		changing(&fn);
		Edit7->Text=fn;

		Form1->StringGrid1->Cells[0][nrow]=nrow;
		Form1->StringGrid1->Cells[1][nrow]=Edit2->Text;

		choosespiece(ListBox1);

		Form1->StringGrid1->Cells[2][nrow]=spiece;

		choosegender(RadioGroup1);

		Form1->StringGrid1->Cells[3][nrow]=g;
		Form1->StringGrid1->Cells[4][nrow]=DateTimePicker1->Date;
		Form1->StringGrid1->Cells[5][nrow]=Edit6->Text;
		Form1->StringGrid1->Cells[6][nrow]=Edit7->Text;
		Form1->StringGrid1->Cells[7][nrow]=Edit1->Text;

		Form2->Edit1->Clear();   // очистка формы ввода
		Form2->Edit2->Clear();
		Form2->ListBox1->ItemIndex=-1;
		Form2->RadioGroup1->ItemIndex=-1;
		Form2->DateTimePicker1->Date=Date();
		Form2->Edit6->Clear();
		Form2->Edit7->Clear();
		Form1->Show();
		press1=true;
		press=true;
		date=false;
		Form2->Close();
	}
	else
	{
		repeat();
		press1=false;
		press=false;
	}
	//press=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::OnKeyPress(TObject *Sender, System::WideChar &Key)
{
    if( Key == VK_BACK )  //если нажимаем backspace
   return;
   if(!(((Key >= 1040) && (Key <= 1103)) || ( Key == VK_SPACE ) || ( Key == VK_RETURN )))
   {   // проверяем на удовлетворение символов полю (необходим текст с пробелами)
		ShowMessage("Введите либо буквы, либо пробел");
		Key = 0;
   }
   if (Key == VK_RETURN)   // при нажатии на Enter
   {
		Perform(WM_NEXTDLGCTL, 0, 0);
		if ((Sender==Edit1)&&(!Edit1->Text.IsEmpty()))
		{
			String fn=Edit1->Text;
			changing(&fn);
			Edit1->Text=fn;
		}
		if ((Sender==Edit2)&&(!Edit2->Text.IsEmpty()))
		{
			String fn=Edit2->Text;
			changing(&fn);
			Edit2->Text=fn;
		}
		if ((Sender==Edit6)&&(!Edit6->Text.IsEmpty()))
		{
			String fn=Edit6->Text;
			changing(&fn);
			Edit6->Text=fn;
		}
		if ((Sender==Edit7)&&(!Edit7->Text.IsEmpty()))
		{
			String fn=Edit7->Text;
			changing(&fn);
			Edit7->Text=fn;
		}

   }
}
//-------закрытие формы--------------------------------------------------------------------

void __fastcall TForm2::OnCloseQuery(TObject *Sender, bool &CanClose)
{
     if ((press==true)&&(press1==true))
	  {
			CanClose=true;
	  }
	  else
{
		 if (Form2->Button1->Caption=="Добавление")
		 {
		 	if ((Application->MessageBox(L"Вы уверены, что хотите отменить добавление?. В таком случае внесенные данные не будут добавлены!", L"Предупреждение", MB_YESNO)==IDYES))
			{
				CanClose=true;
				Form2->Edit1->Clear();   // очистка формы ввода
				Form2->Edit2->Clear();
				Form2->ListBox1->ItemIndex=-1;
				Form2->RadioGroup1->ItemIndex=-1;
				Form2->DateTimePicker1->Date=Date();
				Form2->Edit6->Clear();
				Form2->Edit7->Clear();
				Form1->Show();
			}
			else
			CanClose=false;
		 }
		 else
		 {

		 if ((Application->MessageBox(L"Вы уверены, что хотите отменить редактирование? В таком случае изменения не будут внесены!", L"Предупреждение", MB_YESNO)==IDYES))
		  {
				CanClose=true;
				Form2->Edit1->Clear();   // очистка формы ввода
				Form2->Edit2->Clear();
				Form2->ListBox1->ItemIndex=-1;
				Form2->RadioGroup1->ItemIndex=-1;
				Form2->DateTimePicker1->Date=Date();
				Form2->Edit6->Clear();
				Form2->Edit7->Clear();
				Form1->Show();
		  }
		  else
			CanClose=false;
		 }
}
	  press=false;
	  press1=true;
	  date=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
    Form2->DateTimePicker1->Date=Date();
}
//---------------------------------------------------------------------------

