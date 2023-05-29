//---------------------------------------------------------------------------
#pragma hdrstop
#include<fstream>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;            //ПЕРЕЗАПИСЬ и имя файла при записи!!!!
				 // отменить удаление первой строки!!!!!!!

//перемнные для контроля работы кнопок и сообщений
String filename;
String filenamesaving;
int first=0;
bool saving=true;


struct Dogs
{
	int id;
	char name[100];
	char spiece[100];
	char gender[100];
	char date[100];
	char fname[100];
	char mname[100];
	char fio[100];
};

int visalchoosespiece(String word) //значение строки в зависимости от выбранной кнопки в  ListBox1
{
	if (word=="Терьер")
		   return 0;
	else if (word=="Хаски")
		   return 1;
	else if (word=="Овчарка")
		   return 2;
	else if (word=="Шпиц")
		   return 3;
	else if (word=="Бульдог")
		   return 4;
	else if (word=="Мопс")
		   return 5;
	else if (word=="Такса")
		   return 6;
	else if (word=="Пудель")
		   return 7;
	else if (word=="Корги")
		   return 8;
	else if (word=="Другая порода")
		   return 9;
}

int visalchoosegender(String word) //значение строки в зависимости от выбранной кнопки в RadioGroup1
{
	 if (word=="мужской")
		  return 0;
	else if (word=="женский")
		  return 1;
}

void owner()  //владельцы с больше чем 1 собакой
{
if (Form1->StringGrid1->RowCount==2)
	 ShowMessage("Данных недостаточно! Введите больше записей");
else
{
   Form3->StringGrid2->RowCount=1;
   Form3->StringGrid1->RowCount=2;
   int c=0;
   for (int i=1; i < Form1->StringGrid1->RowCount-1; i++)
   {
		Form3->StringGrid2->Cells[0][c]=Form1->StringGrid1->Cells[7][i];
		Form3->StringGrid2->RowCount++;
		c++;
   }

   for (int i=0; i < Form3->StringGrid2->RowCount-1; i++)
		for (int j=i+1; j < Form3->StringGrid2->RowCount-1; j++)
		{
			if (AnsiCompareStr(Form3->StringGrid2->Cells[0][i],Form3->StringGrid2->Cells[0][j])>0)
			{
				 Form3->StringGrid2->Cells[0][Form3->StringGrid2->RowCount]=Form3->StringGrid2->Cells[0][i];
				 Form3->StringGrid2->Cells[0][i]=Form3->StringGrid2->Cells[0][j];
				 Form3->StringGrid2->Cells[0][j]=Form3->StringGrid2->Cells[0][Form3->StringGrid2->RowCount];
			}
		}

	int op=1, count =0;

	for (int i=0; i < Form3->StringGrid2->RowCount-1; i++)
	{
		 if (Form3->StringGrid2->Cells[0][i]==Form3->StringGrid2->Cells[0][i+1])
			  count++;
		 else
		 {
			 if (count>0)
			 {
				 Form3->StringGrid1->Cells[1][op]=Form3->StringGrid2->Cells[0][i];
				 Form3->StringGrid1->Cells[0][op]=IntToStr(op);
				 Form3->StringGrid1->Cells[2][op]=IntToStr(count+1);
				 op++;
				 Form3->StringGrid1->RowCount++;
				 count=0;
			 }
			 else
				count=0;
		 }

	}

	if (Form3->StringGrid1->Cells[0][1].IsEmpty())
		ShowMessage("Таких владельцев пока нет!");
	else
		Form3->Show();

}

}

void popular(int row)  // самая популярная порода
{
if (row==2)
	 ShowMessage("Данных недостаточно! Введите больше записей");
else
{

	 int maxcount=1, nn=-1;

	for (int i = 0; i < Form1->StringGrid1->RowCount-1; i++)
	{
		int count=0;

		for (int j = i; j < Form1->StringGrid1->RowCount-1; j++)

			if (Form1->StringGrid1->Cells[2][i] == Form1->StringGrid1->Cells[2][j])
				count++;

		if (maxcount < count)
		{
			maxcount = count;
			nn = i;
		}
		else if (maxcount == count)
		{
			nn=-1;
		}
	}
		if (Form1->StringGrid1->Cells[2][1].IsEmpty())
			ShowMessage("Список пока что пуст");
		else if (nn > -1)
			ShowMessage("Самая популярная порода - "+(String)Form1->StringGrid1->Cells[2][nn]);
		else
			ShowMessage("Пока побеждает дружба");
}
}

void unpopular(int row)  // самая непопулярная порода
{
if (row==2)
	 ShowMessage("Данных недостаточно! Введите больше записей");
else
{
	for (int i=1; i < Form1->StringGrid1->RowCount; i++)
		   Form3->StringGrid2->Cells[0][i]="";

   Form3->StringGrid2->RowCount=2;

   int c=0;
   for (int i=1; i < Form1->StringGrid1->RowCount-1; i++)
   {
		Form3->StringGrid2->Cells[0][c]=Form1->StringGrid1->Cells[2][i];
		Form3->StringGrid2->RowCount++;
		c++;
   }
   Form3->StringGrid2->RowCount--;

   for (int i=0; i < Form3->StringGrid2->RowCount-1; i++)
		for (int j=i+1; j < Form3->StringGrid2->RowCount-1; j++)
		{
			if (AnsiCompareStr(Form3->StringGrid2->Cells[0][i],Form3->StringGrid2->Cells[0][j])>0)
			{
				 Form3->StringGrid2->Cells[0][Form3->StringGrid2->RowCount]=Form3->StringGrid2->Cells[0][i];
				 Form3->StringGrid2->Cells[0][i]=Form3->StringGrid2->Cells[0][j];
				 Form3->StringGrid2->Cells[0][j]=Form3->StringGrid2->Cells[0][Form3->StringGrid2->RowCount];
			}
		}

	 int count=0, min=10,nn=-1;

	for (int i=0; i < Form3->StringGrid2->RowCount-1; i++)
	{
		 if (Form3->StringGrid2->Cells[0][i]==Form3->StringGrid2->Cells[0][i+1])
		 {
			count++;
		 }
		 else
		 {
			 count++;
			 if (((i!=0)&&(Form3->StringGrid2->Cells[0][i]!=Form3->StringGrid2->Cells[0][i-1])&&(Form3->StringGrid2->Cells[0][i]!=Form3->StringGrid2->Cells[0][i+1]))||((i==0)&&(Form3->StringGrid2->Cells[0][i]!=Form3->StringGrid2->Cells[0][i+1]))||((Form3->StringGrid2->Cells[0][i]!=Form3->StringGrid2->Cells[0][i-1])&&(Form3->StringGrid2->Cells[0][i+1].IsEmpty())))
			 {
				 count=1;
				 nn=i;
			 }
			 if (min==count)
			 {
				  nn=-1;
			 }
			 if (min>count)
			 {
				  min=count;
				  nn=i;
			 }


			 count=0;

		 }
	}

	if (nn==-1)
	{
		 ShowMessage("Таких пока что нет");
	}
	else
	{
		 ShowMessage("Самая непопулярная порода - "+(String)Form3->StringGrid2->Cells[0][nn]);
    }


}
}


void sortbyage()    //сортировка по возрасту в списке по породе
{
	int i,j;
	 for (i=1; i < Form4->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form4->StringGrid1->RowCount-1; j++)
		{
			if (StrToDate(Form4->StringGrid1->Cells[3][i])>StrToDate(Form4->StringGrid1->Cells[3][j]))
			{
				 Form4->StringGrid1->Rows[Form4->StringGrid1->RowCount]=Form4->StringGrid1->Rows[i];
				 Form4->StringGrid1->Rows[i]=Form4->StringGrid1->Rows[j];
				 Form4->StringGrid1->Rows[j]=Form4->StringGrid1->Rows[Form4->StringGrid1->RowCount];
			}
		}
		for (j=1; j < Form4->StringGrid1->RowCount-1; j++)
			  Form4->StringGrid1->Cells[0][j]=IntToStr(j);

}

void spisok_po_porode(String word)  // список по породе
{
if (Form1->StringGrid1->Cells[1][1].IsEmpty())
	 ShowMessage("Список пока что пуст");
else
{
   for (int i=1; i < Form4->StringGrid1->RowCount; i++)
		for (int j=0; j < Form4->StringGrid1->ColCount; j++)
			  Form4->StringGrid1->Cells[j][i]="";
   Form4->StringGrid1->RowCount=2;
   int op=1;
   Form4->Label1->Caption="Список по породе "+word;
   for (int i = 1; i < Form1->StringGrid1->RowCount-1; i++)
   {
	   if (Form1->StringGrid1->Cells[2][i]==word)
	   {
		   Form4->StringGrid1->Cells[0][op]=IntToStr(op);
		   Form4->StringGrid1->Cells[1][op]=Form1->StringGrid1->Cells[1][i];
		   Form4->StringGrid1->Cells[2][op]=Form1->StringGrid1->Cells[3][i];
		   Form4->StringGrid1->Cells[3][op]=Form1->StringGrid1->Cells[4][i];
		   Form4->StringGrid1->Cells[4][op]=Form1->StringGrid1->Cells[5][i];
		   Form4->StringGrid1->Cells[5][op]=Form1->StringGrid1->Cells[6][i];
		   Form4->StringGrid1->Cells[6][op]=Form1->StringGrid1->Cells[7][i];
		   op++;
		   Form4->StringGrid1->RowCount++;
	   }
   }

   if (Form4->StringGrid1->Cells[1][1].IsEmpty())
		ShowMessage("Такой породы в списке нет");
   else
   {
	   sortbyage();
	   Form4->Show();
   }

}
}

void search(String word, int column) //поиск
{
if (Form1->StringGrid1->Cells[1][1].IsEmpty())
	 ShowMessage("Список пока что пуст");
else
{
	bool control=false;


	for (int i=1; i < Form6->StringGrid1->RowCount; i++)
		for (int j=0; j < Form6->StringGrid1->ColCount; j++)
			  Form6->StringGrid1->Cells[j][i]="";
	Form6->StringGrid1->RowCount=2;

	String word1;
	word1=AnsiLowerCase(word);   //в нижнем регистре

	String word2=AnsiUpperCase(word1[1]); //верхний и нижние

	for (int i=2; i <= word1.Length(); i++)
	{
	   word2=word2+word1[i];
	}

	int c=1;

	for (int i=1; i < Form1->StringGrid1->RowCount; i++)
	{

		if ((Form1->StringGrid1->Cells[column][i].Pos(word1)==1)||(Form1->StringGrid1->Cells[column][i].Pos(word2)==1))
		{
			Form6->StringGrid1->Cells[0][c]=c;
			Form6->StringGrid1->Cells[1][c]=Form1->StringGrid1->Cells[1][i];
			Form6->StringGrid1->Cells[2][c]=Form1->StringGrid1->Cells[2][i];
			Form6->StringGrid1->Cells[3][c]=Form1->StringGrid1->Cells[3][i];
			Form6->StringGrid1->Cells[4][c]=Form1->StringGrid1->Cells[4][i];
			Form6->StringGrid1->Cells[5][c]=Form1->StringGrid1->Cells[5][i];
			Form6->StringGrid1->Cells[6][c]=Form1->StringGrid1->Cells[6][i];
			Form6->StringGrid1->Cells[7][c]=Form1->StringGrid1->Cells[7][i];
			c++;
			Form6->StringGrid1->RowCount++;
			control=true;
		}
	}
	if (control==true)
		Form6->Show();
	else
		ShowMessage("По запросу ничего не найдено. Для успешного поиска убедитесь, что текст введен без лишних пробелов.");

}
}

void sort(int column, int choice)    //сортировка
{
if (Form1->StringGrid1->Cells[0][2].IsEmpty())
{
	ShowMessage("Слишком мало записей для сортировки!");
}
else
{
if (choice==1) {
	int i,j;
	 for (i=1; i < Form1->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form1->StringGrid1->RowCount-1; j++)
		{
			if (AnsiCompareStr(Form1->StringGrid1->Cells[column][i],Form1->StringGrid1->Cells[column][j])>0)
			{
				 Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount]=Form1->StringGrid1->Rows[i];
				 Form1->StringGrid1->Rows[i]=Form1->StringGrid1->Rows[j];
				 Form1->StringGrid1->Rows[j]=Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount];
			}
		}
		for (j=1; j < Form1->StringGrid1->RowCount-1; j++)
			  Form1->StringGrid1->Cells[0][j]=IntToStr(j);
}
else
{
     int i,j;
	 for (i=1; i < Form1->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form1->StringGrid1->RowCount-1; j++)
		{
			if (AnsiCompareStr(Form1->StringGrid1->Cells[column][i],Form1->StringGrid1->Cells[column][j])<0)
			{
				 Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount]=Form1->StringGrid1->Rows[i];
				 Form1->StringGrid1->Rows[i]=Form1->StringGrid1->Rows[j];
				 Form1->StringGrid1->Rows[j]=Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount];
			}
		}
        for (j=1; j < Form1->StringGrid1->RowCount-1; j++)
			  Form1->StringGrid1->Cells[0][j]=IntToStr(j);
}
}
}

void agesort(int choice)    //сортировка  по возрасту для формы 1
{
if (Form1->StringGrid1->Cells[0][2].IsEmpty())
{
	ShowMessage("Слишком мало записей для сортировки!");
}
else
{
if (choice==1) {
	int i,j;
	 for (i=1; i < Form1->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form1->StringGrid1->RowCount-1; j++)
		{
			if (StrToDate(Form1->StringGrid1->Cells[4][i])>StrToDate(Form1->StringGrid1->Cells[4][j]))
			{
				 Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount]=Form1->StringGrid1->Rows[i];
				 Form1->StringGrid1->Rows[i]=Form1->StringGrid1->Rows[j];
				 Form1->StringGrid1->Rows[j]=Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount];
			}
		}
        for (j=1; j < Form1->StringGrid1->RowCount-1; j++)
			  Form1->StringGrid1->Cells[0][j]=IntToStr(j);
}
else
{
     int i,j;
	 for (i=1; i < Form1->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form1->StringGrid1->RowCount-1; j++)
		{
			if (StrToDate(Form1->StringGrid1->Cells[4][i])<StrToDate(Form1->StringGrid1->Cells[4][j]))
			{
				 Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount]=Form1->StringGrid1->Rows[i];
				 Form1->StringGrid1->Rows[i]=Form1->StringGrid1->Rows[j];
				 Form1->StringGrid1->Rows[j]=Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount];
			}
		}
        for (j=1; j < Form1->StringGrid1->RowCount-1; j++)
			  Form1->StringGrid1->Cells[0][j]=IntToStr(j);
}
}
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//----------добавление записи-----------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
	N11->Enabled=true;
	N4->Enabled=true;
	N9->Enabled=true;
	N10->Enabled=true;
	N59->Enabled=true;
	N60->Enabled=true;

	ToolButton10->Enabled=true;
	ToolButton11->Enabled=true;
	ToolButton12->Enabled=true;
	ToolButton7->Enabled=true;
	ToolButton8->Enabled=true;
	ToolButton1->Enabled=true;
	ToolButton2->Enabled=true;

	N62->Enabled=true;
	Edit1->Enabled=true;
	Button1->Enabled=true;
	saving=false;
	Form2->Button1->Caption="Добавить";
	Form2->Caption="Добавление";
	Form2->Show();
	Form2->Edit1->SetFocus();
}
//----------внешний вид формы-----------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form7= new TForm7(this);
	Form7->ShowModal();
	Form7->Free();

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
	N11->Enabled=false;
	N3->Enabled=false;
	N4->Enabled=false;
	N9->Enabled=false;
	N10->Enabled=false;
	N59->Enabled=false;
	N60->Enabled=false;
	N62->Enabled=false;
	Edit1->Enabled=false;
	Button1->Enabled=false;

	ToolButton10->Enabled=false;
	ToolButton11->Enabled=false;
	ToolButton12->Enabled=false;

	 StatusBar1->Panels->Items[0]->Text="Пока нет открытых файлов";
	 StatusBar1->Panels->Items[1]->Text="Нет выделенной строки";
	 StatusBar1->Panels->Items[2]->Text="Нет выделенной ячейки";
}
//------------редактирование---------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
     int nm = StringGrid1->Row;


	if (StringGrid1->Cells[0][nm]=="№")
	{
		ShowMessage("Заголовок редактировать нельзя!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("Строка пуста!");
	}
	else if (nm==0)
	{
		 ShowMessage("Для редактирования выделите строку!");
	}
	else
	{
	Form2->Button1->Caption="Редактирование";
	Form2->Caption="Редактирование";
	Form2->Edit1->Text=Form1->StringGrid1->Cells[7][nm];
	Form2->Edit2->Text=Form1->StringGrid1->Cells[1][nm];

	Form2->ListBox1->ItemIndex=visalchoosespiece(Form1->StringGrid1->Cells[2][nm]);

	Form2->RadioGroup1->ItemIndex=visalchoosegender(Form1->StringGrid1->Cells[3][nm]);

	Form2->DateTimePicker1->Date=Form1->StringGrid1->Cells[4][nm];

	Form2->Edit6->Text=Form1->StringGrid1->Cells[5][nm];
	Form2->Edit7->Text=Form1->StringGrid1->Cells[6][nm];

	Form2->Show();
	Form2->Edit1->SetFocus();
	}
	saving=false;
}
//------------------открытие---------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
    if (saving==false)
{
   if (Application->MessageBox(L"Хотите сохранить изменения в текущем файле?",L"Предупреждение", MB_YESNO)==IDYES)
		{
		TForm1::N3Click(SaveDialog2);
		TForm1::N2Click(OpenDialog1);
		}
   else
   {
	   saving=true;
	   TForm1::N2Click(OpenDialog1);
   }
}
else
{
	OpenDialog1->Filter = "Binary files (*.bin)|*.bin";
	OpenDialog1->DefaultExt = "bin";
	if (OpenDialog1->Execute())
	{

		std::ifstream inFile(OpenDialog1->FileName.c_str(), std::ios::in | std::ios::binary);
		if (!inFile)
		{
			ShowMessage("Ошибка при открытии файла");
		}
		else
		{
			filename = OpenDialog1->FileName; // Обновляем filename

			Dogs dog;
			StringGrid1->RowCount = 2; // Заголовок и первая строка данных
			while (inFile.read((char*)&dog, sizeof(Dogs)))
			{
				StringGrid1->Cells[0][StringGrid1->RowCount - 1] = IntToStr(dog.id);
				StringGrid1->Cells[1][StringGrid1->RowCount - 1] = dog.name;
				StringGrid1->Cells[2][StringGrid1->RowCount - 1] = dog.spiece;
				StringGrid1->Cells[3][StringGrid1->RowCount - 1] = dog.gender;
				StringGrid1->Cells[4][StringGrid1->RowCount - 1] = dog.date;
				StringGrid1->Cells[5][StringGrid1->RowCount - 1] = dog.fname;
				StringGrid1->Cells[6][StringGrid1->RowCount - 1] = dog.mname;
				StringGrid1->Cells[7][StringGrid1->RowCount - 1] = dog.fio;
				StringGrid1->RowCount++;
			}

			inFile.close();

			N11->Enabled=true;
			N4->Enabled=true;
			N9->Enabled=true;
			N10->Enabled=true;

			ToolButton10->Enabled=true;
			ToolButton11->Enabled=true;
			ToolButton12->Enabled=true;
			ToolButton7->Enabled=true;
			ToolButton8->Enabled=true;
			ToolButton1->Enabled=true;
			ToolButton2->Enabled=true;

			N59->Enabled=true;
			N60->Enabled=true;
			N62->Enabled=true;
			N3->Enabled=true;
			Edit1->Enabled=true;
			Button1->Enabled=true;
			first=1;
			saving=true;
			StatusBar1->Panels->Items[0]->Text=filename;
		}
	}
}
}
//------------сохранить---------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
      SaveDialog2->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog2->DefaultExt = "bin";

	std::ofstream outFile(filename.c_str(), std::ios::out | std::ios::binary);
	if (!outFile) {
	ShowMessage("Ошибка при сохранении файла");
	}
	else
	{
		Dogs dog;
		int op=1;
		for (int i = 1; i < StringGrid1->RowCount-1; i++)
		{ // Начинаем с 1, чтобы пропустить заголовок

			dog.id=op;
			op++;
			strncpy(dog.name, AnsiString(StringGrid1->Cells[1][i]).c_str(), sizeof(dog.name));
			strncpy(dog.spiece, AnsiString(StringGrid1->Cells[2][i]).c_str(), sizeof(dog.spiece));
			strncpy(dog.gender, AnsiString(StringGrid1->Cells[3][i]).c_str(), sizeof(dog.gender));
			strncpy(dog.date, AnsiString(StringGrid1->Cells[4][i]).c_str(), sizeof(dog.date));
			strncpy(dog.fname, AnsiString(StringGrid1->Cells[5][i]).c_str(), sizeof(dog.fname));
			strncpy(dog.mname, AnsiString(StringGrid1->Cells[6][i]).c_str(), sizeof(dog.mname));
			strncpy(dog.fio, AnsiString(StringGrid1->Cells[7][i]).c_str(), sizeof(dog.fio));
			outFile.write((char*)&dog, sizeof(Dogs));
		}
		outFile.close();
		ShowMessage("Файл успешно сохранен");
		saving=true;
		StatusBar1->Panels->Items[0]->Text=filename;
	}
}
//------------сохранить как---------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
    SaveDialog1->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog1->DefaultExt = "bin";
	if (SaveDialog1->Execute())
{

	filenamesaving = SaveDialog1->FileName; // Обновляем filenamesaving

	if (first==0)
	{
		 filename=filenamesaving;
		 StatusBar1->Panels->Items[0]->Text=filename;
	}

	if ((filenamesaving==filename)&&(first==1))
	{
		 if (Application->MessageBox(L"Хотите перезаписать файл?", L"Предупреждение", MB_YESNO)==IDYES)
			TForm1::N3Click(SaveDialog2);
		 else
			 TForm1::N4Click(SaveDialog1);
	}
	else
{
	std::ofstream outFile(filenamesaving.c_str(), std::ios::out | std::ios::binary);
	if (!outFile) {
	ShowMessage("Ошибка при сохранении файла");
	}
	else
	{
		Dogs dog;
		int op=1;
		for (int i = 1; i < StringGrid1->RowCount-1; i++)
		{ // Начинаем с 1, чтобы пропустить заголовок
			dog.id=op;
			op++;
			strncpy(dog.name, AnsiString(StringGrid1->Cells[1][i]).c_str(), sizeof(dog.name));
			strncpy(dog.spiece, AnsiString(StringGrid1->Cells[2][i]).c_str(), sizeof(dog.spiece));
			strncpy(dog.gender, AnsiString(StringGrid1->Cells[3][i]).c_str(), sizeof(dog.gender));
			strncpy(dog.date, AnsiString(StringGrid1->Cells[4][i]).c_str(), sizeof(dog.date));
			strncpy(dog.fname, AnsiString(StringGrid1->Cells[5][i]).c_str(), sizeof(dog.fname));
			strncpy(dog.mname, AnsiString(StringGrid1->Cells[6][i]).c_str(), sizeof(dog.mname));
			strncpy(dog.fio, AnsiString(StringGrid1->Cells[7][i]).c_str(), sizeof(dog.fio));
			outFile.write((char*)&dog, sizeof(Dogs));
		}
		outFile.close();
		ShowMessage("Файл успешно сохранен");
		first=1;
		N3->Enabled=true;
		saving=true;
	}
}
}
}
//--------------удаление-------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
	int nm = StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="№")
	{
		ShowMessage("Заголовок удалять нельзя!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("Строка пуста!");
	}
	else if (nm==0)
	{
		 ShowMessage("Для удаления выделите строку!");
	}
	else if ((Application->MessageBox(L"Вы уверены, что хотите удалить строку? Восстановить запись будет нельзя!", L"Предупреждение", MB_YESNO)==IDYES))
	{
		for (int i=nm+1; i < StringGrid1->RowCount; i++)
			 for (int j=0; j < StringGrid1->ColCount; j++)
				   StringGrid1->Cells[j][i-1]=StringGrid1->Cells[j][i];
		StringGrid1->RowCount--;
	 for (int i=1; i < StringGrid1->RowCount-1; i++)
			 StringGrid1->Cells[0][i]=IntToStr(i);
	saving=false;
	}
}
//------------закрытие формы---------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
	Form1->Close();
}
//------------о программе---------------------------------------------------------------

void __fastcall TForm1::N17Click(TObject *Sender)
{
	 ShowMessage("Версия продукта 1.1. Последние изменения внесены 29.05.2023. Добавлены темы оформления приложения. Email автора - someone2004@mail.ru.");
}
//---------задание------------------------------------------------------------------

void __fastcall TForm1::N15Click(TObject *Sender)
{
	 ShowMessage("Клуб собаководов регистрирует сведения: Ф.И.О. владельца, кличка и порода собаки, ее пол и дата рождения, клички отца и матери собаки. Сформировать списки собак одной породы, отсортированные по возрасту. Определить самую популярную и непопулярную породы. Найти владельцев, имеющих не одну собаку. Составить родословную заданной собаки.");
}
//-------------поиск по кличке--------------------------------------------------------------

void __fastcall TForm1::N18Click(TObject *Sender)
{
     UnicodeString searchText = "";
	if (InputQuery("Поиск", "Введите кличку", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("Введите запрос в поисковое поле!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,1);
	}
}
//----------------поиск по породе-----------------------------------------------------------

void __fastcall TForm1::N19Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("Поиск", "Введите породу", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("Введите запрос в поисковое поле!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,2);
	}
}
//-----------поиск по полу----------------------------------------------------------------

void __fastcall TForm1::N20Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("Поиск", "Введите пол", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("Введите запрос в поисковое поле!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,3);
	}
}
//-------------поиск по дате рождения--------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("Поиск", "Введите дату рождения", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("Введите запрос в поисковое поле!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,4);
	}
}
//--------------поиск по кличке отца-------------------------------------------------------------

void __fastcall TForm1::N22Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("Поиск", "Введите кличку отца", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("Введите запрос в поисковое поле!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,5);
	}
}
//------------поиск по кличке матери---------------------------------------------------------------

void __fastcall TForm1::N23Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("Поиск", "Введите кличку матери", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("Введите запрос в поисковое поле!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,6);
	}
}
//-------------поиск по фио владельца--------------------------------------------------------------

void __fastcall TForm1::N24Click(TObject *Sender)
{
       UnicodeString searchText = "";
	if (InputQuery("Поиск", "Введите Ф.И.О. владельца", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("Введите запрос в поисковое поле!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,7);
	}
}
//------------сортировки---------------------------------------------------------------

void __fastcall TForm1::N30Click(TObject *Sender)
{
     sort(1,1);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N37Click(TObject *Sender)
{
     sort(1,0);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
     sort(2,1);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N38Click(TObject *Sender)
{
      sort(2,0);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N32Click(TObject *Sender)
{
       sort(3,1);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N39Click(TObject *Sender)
{
       sort(3,0);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N33Click(TObject *Sender)
{
       agesort(1);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N40Click(TObject *Sender)
{
      agesort(0);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N34Click(TObject *Sender)
{
      sort(5,1);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
      sort(5,0);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N35Click(TObject *Sender)
{
       sort(6,1);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N42Click(TObject *Sender)
{
       sort(6,0);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N36Click(TObject *Sender)
{
      sort(7,1);
	saving=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N43Click(TObject *Sender)
{
       sort(7,0);
	saving=false;
}
//-----------самая популярная порода----------------------------------------------------------------

void __fastcall TForm1::N45Click(TObject *Sender)
{
	popular(StringGrid1->RowCount-1);
}
//-----------самая непопулярная порода----------------------------------------------------------------

void __fastcall TForm1::N46Click(TObject *Sender)
{
    unpopular(StringGrid1->RowCount-1);
}
//--------владельцы больше чем 1 собаки-------------------------------------------------------------------

void __fastcall TForm1::N210Click(TObject *Sender)
{
	 owner();
}
//----------список по породе-----------------------------------------------------------------

void __fastcall TForm1::N48Click(TObject *Sender)
{
    String ch="Терьер";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N49Click(TObject *Sender)
{
     String ch="Хаски";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N50Click(TObject *Sender)
{
      String ch="Овчарка";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N51Click(TObject *Sender)
{
     String ch="Шпиц";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N52Click(TObject *Sender)
{
      String ch="Бульдог";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N53Click(TObject *Sender)
{
      String ch="Мопс";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N54Click(TObject *Sender)
{
     String ch="Такса";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N55Click(TObject *Sender)
{
     String ch="Пудель";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N56Click(TObject *Sender)
{
     String ch="Корги";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N57Click(TObject *Sender)
{
     	String ch="Другая порода";
	spisok_po_porode(ch);
}
//------------добавление правая кнопка---------------------------------------------------------------

void __fastcall TForm1::N58Click(TObject *Sender)
{
    N11->Enabled=true;
	N4->Enabled=true;
	N9->Enabled=true;
	N10->Enabled=true;
	N59->Enabled=true;
	N60->Enabled=true;

	ToolButton10->Enabled=true;
	ToolButton11->Enabled=true;
	ToolButton12->Enabled=true;
	ToolButton7->Enabled=true;
	ToolButton8->Enabled=true;
	ToolButton1->Enabled=true;
	ToolButton2->Enabled=true;

	N62->Enabled=true;
	Edit1->Enabled=true;
	Button1->Enabled=true;
	saving=false;
	Form2->Button1->Caption="Добавить";
	Form2->Caption="Добавление";
	Form2->Show();
	Form2->Edit1->SetFocus();
}
//--------------редактирование по правой кнопке-------------------------------------------------------------

void __fastcall TForm1::N59Click(TObject *Sender)
{
    int nm = StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="№")
	{
		ShowMessage("Заголовок редактировать нельзя!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("Строка пуста!");
	}
	else if (nm==0)
	{
		 ShowMessage("Для редактирования выделите строку!");
	}
	else
	{
	Form2->Button1->Caption="Редактирование";
	Form2->Caption="Редактирование";
	Form2->Edit1->Text=Form1->StringGrid1->Cells[7][nm];
	Form2->Edit2->Text=Form1->StringGrid1->Cells[1][nm];

	Form2->ListBox1->ItemIndex=visalchoosespiece(Form1->StringGrid1->Cells[2][nm]);

	Form2->RadioGroup1->ItemIndex=visalchoosegender(Form1->StringGrid1->Cells[3][nm]);

	Form2->DateTimePicker1->Date=Form1->StringGrid1->Cells[4][nm];

	Form2->Edit6->Text=Form1->StringGrid1->Cells[5][nm];
	Form2->Edit7->Text=Form1->StringGrid1->Cells[6][nm];

	Form2->Show();
	Form2->Edit1->SetFocus();
	}
	saving=false;
}
//------------удаление по правой кнопке---------------------------------------------------------------

void __fastcall TForm1::N60Click(TObject *Sender)
{
    int nm = StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="№")
	{
		ShowMessage("Заголовок удалять нельзя!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("Строка пуста!");
	}
	else if (nm==0)
	{
		 ShowMessage("Для удаления выделите строку!");
	}
	else if ((Application->MessageBox(L"Вы уверены, что хотите удалить строку? Восстановить запись будет нельзя!", L"Предупреждение", MB_YESNO)==IDYES))
	{
		for (int i=nm+1; i < StringGrid1->RowCount; i++)
			 for (int j=0; j < StringGrid1->ColCount; j++)
				   StringGrid1->Cells[j][i-1]=StringGrid1->Cells[j][i];
		StringGrid1->RowCount--;
	 for (int i=1; i < StringGrid1->RowCount-1; i++)
			 StringGrid1->Cells[0][i]=IntToStr(i);
	saving=false;
	}
}
//-------Родословная--------------------------------------------------------------------
void __fastcall TForm1::N47Click(TObject *Sender)
{
   	int nm=StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="№")
	{
		ShowMessage("Вы выделили заголовок!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("Строка пуста!");
	}
	else if (nm==0)
	{
		 ShowMessage("Для составления родословной выделите строку!");
	}
	else
	{
	bool m=false, f=false;

	Form5->Memo1->Lines->Strings[0]=StringGrid1->Cells[1][nm];  //dog


	String father=StringGrid1->Cells[5][nm];
	String mother=StringGrid1->Cells[6][nm];

	Form5->Memo2->Lines->Strings[0]=father;    //parents
	Form5->Memo3->Lines->Strings[0]=mother;

	for (int i=1; i < StringGrid1->RowCount; i++)     //дедушки и бабушки
	{
		if (StringGrid1->Cells[1][i]==father) //by father
		{
			Form5->Memo4->Lines->Strings[0]=StringGrid1->Cells[5][i];
			Form5->Memo4->Lines->Strings[1]=StringGrid1->Cells[6][i];
			f=true;
		}
		if (StringGrid1->Cells[1][i]==mother)  //by mother
		{
			Form5->Memo5->Lines->Strings[0]=StringGrid1->Cells[5][i];
			Form5->Memo5->Lines->Strings[1]=StringGrid1->Cells[6][i];
			m=true;
		}
	}

	Form5->Label7->Visible=f;
	Form5->Label4->Visible=f;
	Form5->Memo4->Visible=f;

	Form5->Label7->Visible=m;
	Form5->Label5->Visible=m;
	Form5->Memo5->Visible=m;

	Form5->Show();
	}

}
//---------работа поп ап по левой кнопке мыши------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	TPoint pt, pt2;

	pt.x=Button1->Left;
	pt.y=Button1->Top+Button1->Height;
	pt2=ClientToScreen(pt);
	PopupMenu2->Popup(pt2.x, pt2.y);
}
//---------поиск по кличке------------------------------------------------------------------

void __fastcall TForm1::N63Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("Введите запрос в поисковое поле!");
	else
		search(Edit1->Text,1);
	Form1->Edit1->Text="";
}
//-----------поиск по породе----------------------------------------------------------------

void __fastcall TForm1::N64Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("Введите запрос в поисковое поле!");
	else
		search(Edit1->Text,2);
	Form1->Edit1->Text="";
}
//-----------поиск по полу----------------------------------------------------------------

void __fastcall TForm1::N65Click(TObject *Sender)
{
    if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("Введите запрос в поисковое поле!");
	else
		search(Edit1->Text,3);
	Form1->Edit1->Text="";
}
//------------поиск по дате рождения---------------------------------------------------------------

void __fastcall TForm1::N66Click(TObject *Sender)
{
   if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("Введите запрос в поисковое поле!");
	else
		search(Edit1->Text,4);
	Form1->Edit1->Text="";
}
//-------------поиск по кличке отца--------------------------------------------------------------

void __fastcall TForm1::N67Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("Введите запрос в поисковое поле!");
	else
		search(Edit1->Text,5);
	Form1->Edit1->Text="";
}
//-------------поиск по кличке матери--------------------------------------------------------------

void __fastcall TForm1::N68Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("Введите запрос в поисковое поле!");
	else
		search(Edit1->Text,6);
	Form1->Edit1->Text="";
}
//-----------поиск по фио владельца----------------------------------------------------------------

void __fastcall TForm1::N69Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("Введите запрос в поисковое поле!");
	else
		search(Edit1->Text,7);
    Form1->Edit1->Text="";
}
//------------родословная по правой кнопке мыши---------------------------------------------------------------

void __fastcall TForm1::N62Click(TObject *Sender)
{
    	int nm=StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="№")
	{
		ShowMessage("Вы выделили заголовок!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("Строка пуста!");
	}
	else if (nm==0)
	{
		 ShowMessage("Для составления родословной выделите строку!");
	}
	else
	{
	bool m=false, f=false;

	Form5->Memo1->Lines->Strings[0]=StringGrid1->Cells[1][nm];  //dog


	String father=StringGrid1->Cells[5][nm];
	String mother=StringGrid1->Cells[6][nm];

	Form5->Memo2->Lines->Strings[0]=father;    //parents
	Form5->Memo3->Lines->Strings[0]=mother;

	for (int i=1; i < StringGrid1->RowCount; i++)     //дедушки и бабушки
	{
		if (StringGrid1->Cells[1][i]==father) //by father
		{
			Form5->Memo4->Lines->Strings[0]=StringGrid1->Cells[5][i];
			Form5->Memo4->Lines->Strings[1]=StringGrid1->Cells[6][i];
			f=true;
		}
		if (StringGrid1->Cells[1][i]==mother)  //by mother
		{
			Form5->Memo5->Lines->Strings[0]=StringGrid1->Cells[5][i];
			Form5->Memo5->Lines->Strings[1]=StringGrid1->Cells[6][i];
			m=true;
		}
	}

	Form5->Label7->Visible=f;
	Form5->Label4->Visible=f;
	Form5->Memo4->Visible=f;

	Form5->Label7->Visible=m;
	Form5->Label5->Visible=m;
	Form5->Memo5->Visible=m;

	Form5->Show();
	}

}
//--------закрытие формы-------------------------------------------------------------------

void __fastcall TForm1::OnCloseQuery(TObject *Sender, bool &CanClose)
{
    if ((Application->MessageBox(L"Вы уверены, что хотите выйти?", L"Предупреждение", MB_YESNO)==IDYES))
	{
		if (saving==true)
		{
			CanClose=true;
		}
		else{
			 if (Application->MessageBox(L"Хотите сохранить текущий файл?", L"Предупреждение", MB_YESNO)==IDYES)
			 {
				if (first==0)
				{
				   TForm1::N4Click(SaveDialog1);
				   CanClose=true;
				}
				else
				{
					TForm1::N3Click(SaveDialog1);
					CanClose=true;
				}
			 }

		}
	}
	else
		CanClose=false;
}
//------------обновлене статус бара при выделении ячейки---------------------------------------------------------------
void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
	int nm = StringGrid1->Row;
	StatusBar1->Panels->Items[1]->Text="Работа с "+IntToStr(nm)+" строкой";
	int nc=StringGrid1->Col;
	StatusBar1->Panels->Items[2]->Text="Выделена ячейка ["+IntToStr(nm)+";"+IntToStr(nc)+"]";
}
//---------Справка------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
     String fn = L"C:\\Users\\Asus\\Desktop\\курсовая\\Справка.txt"; // тут путь к файлу
	ShellExecute(0, L"open", fn.c_str(), NULL, 0, SW_SHOWNORMAL);
}
//-------------Подсказки на панели инструментов--------------------------------------------------------------

void __fastcall TForm1::OnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
     ToolButton1->Hint="Сохранить";
	ToolButton2->Hint="Сохранить как";
	ToolButton3->Hint="Открыть";
	ToolButton4->Hint="Выход";
	ToolButton6->Hint="Добавить";
	ToolButton7->Hint="Редактировать";
	ToolButton8->Hint="Удалить";
	ToolButton10->Hint="Сортировка";
	ToolButton11->Hint="Поиск";
	ToolButton12->Hint="Родословная";
	ToolButton14->Hint="Справка";
}
//-------отключение правой кнопки мыши для поп ап 2--------------------------------------------------------------------

void __fastcall TForm1::OnContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)

{
     Handled=true;
}
//--------оформление формы-------------------------------------------------------------------

void __fastcall TForm1::N71Click(TObject *Sender)
{
	Form1->Color=clBtnFace;     //светло-серый
	Form2->Color=clBtnFace;
	Form3->Color=clBtnFace;
	Form4->Color=clBtnFace;
	Form5->Color=clBtnFace;
	Form6->Color=clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N72Click(TObject *Sender)
{
	 Form1->Color=clScrollBar;     //серый
	 Form2->Color=clScrollBar;
	 Form3->Color=clScrollBar;
	 Form4->Color=clScrollBar;
	 Form5->Color=clScrollBar;
	 Form6->Color=clScrollBar;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N73Click(TObject *Sender)
{
	Form1->Color=clGradientInactiveCaption;    //светло-голубой
	Form2->Color=clGradientInactiveCaption;
	Form3->Color=clGradientInactiveCaption;
	Form4->Color=clGradientInactiveCaption;
	Form5->Color=clGradientInactiveCaption;
	Form6->Color=clGradientInactiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N74Click(TObject *Sender)
{
	Form1->Color=clGradientActiveCaption;    //голубой
	Form2->Color=clGradientActiveCaption;
	Form3->Color=clGradientActiveCaption;
	Form4->Color=clGradientActiveCaption;
	Form5->Color=clGradientActiveCaption;
	Form6->Color=clGradientActiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N75Click(TObject *Sender)
{
	Form1->Color=clMoneyGreen;      //зеленый
	Form2->Color=clMoneyGreen;
	Form3->Color=clMoneyGreen;
	Form4->Color=clMoneyGreen;
	Form5->Color=clMoneyGreen;
	Form6->Color=clMoneyGreen;
}
//---------------------------------------------------------------------------

