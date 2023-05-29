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
TForm1 *Form1;            //���������� � ��� ����� ��� ������!!!!
				 // �������� �������� ������ ������!!!!!!!

//��������� ��� �������� ������ ������ � ���������
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

int visalchoosespiece(String word) //�������� ������ � ����������� �� ��������� ������ �  ListBox1
{
	if (word=="������")
		   return 0;
	else if (word=="�����")
		   return 1;
	else if (word=="�������")
		   return 2;
	else if (word=="����")
		   return 3;
	else if (word=="�������")
		   return 4;
	else if (word=="����")
		   return 5;
	else if (word=="�����")
		   return 6;
	else if (word=="������")
		   return 7;
	else if (word=="�����")
		   return 8;
	else if (word=="������ ������")
		   return 9;
}

int visalchoosegender(String word) //�������� ������ � ����������� �� ��������� ������ � RadioGroup1
{
	 if (word=="�������")
		  return 0;
	else if (word=="�������")
		  return 1;
}

void owner()  //��������� � ������ ��� 1 �������
{
if (Form1->StringGrid1->RowCount==2)
	 ShowMessage("������ ������������! ������� ������ �������");
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
		ShowMessage("����� ���������� ���� ���!");
	else
		Form3->Show();

}

}

void popular(int row)  // ����� ���������� ������
{
if (row==2)
	 ShowMessage("������ ������������! ������� ������ �������");
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
			ShowMessage("������ ���� ��� ����");
		else if (nn > -1)
			ShowMessage("����� ���������� ������ - "+(String)Form1->StringGrid1->Cells[2][nn]);
		else
			ShowMessage("���� ��������� ������");
}
}

void unpopular(int row)  // ����� ������������ ������
{
if (row==2)
	 ShowMessage("������ ������������! ������� ������ �������");
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
		 ShowMessage("����� ���� ��� ���");
	}
	else
	{
		 ShowMessage("����� ������������ ������ - "+(String)Form3->StringGrid2->Cells[0][nn]);
    }


}
}


void sortbyage()    //���������� �� �������� � ������ �� ������
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

void spisok_po_porode(String word)  // ������ �� ������
{
if (Form1->StringGrid1->Cells[1][1].IsEmpty())
	 ShowMessage("������ ���� ��� ����");
else
{
   for (int i=1; i < Form4->StringGrid1->RowCount; i++)
		for (int j=0; j < Form4->StringGrid1->ColCount; j++)
			  Form4->StringGrid1->Cells[j][i]="";
   Form4->StringGrid1->RowCount=2;
   int op=1;
   Form4->Label1->Caption="������ �� ������ "+word;
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
		ShowMessage("����� ������ � ������ ���");
   else
   {
	   sortbyage();
	   Form4->Show();
   }

}
}

void search(String word, int column) //�����
{
if (Form1->StringGrid1->Cells[1][1].IsEmpty())
	 ShowMessage("������ ���� ��� ����");
else
{
	bool control=false;


	for (int i=1; i < Form6->StringGrid1->RowCount; i++)
		for (int j=0; j < Form6->StringGrid1->ColCount; j++)
			  Form6->StringGrid1->Cells[j][i]="";
	Form6->StringGrid1->RowCount=2;

	String word1;
	word1=AnsiLowerCase(word);   //� ������ ��������

	String word2=AnsiUpperCase(word1[1]); //������� � ������

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
		ShowMessage("�� ������� ������ �� �������. ��� ��������� ������ ���������, ��� ����� ������ ��� ������ ��������.");

}
}

void sort(int column, int choice)    //����������
{
if (Form1->StringGrid1->Cells[0][2].IsEmpty())
{
	ShowMessage("������� ���� ������� ��� ����������!");
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

void agesort(int choice)    //����������  �� �������� ��� ����� 1
{
if (Form1->StringGrid1->Cells[0][2].IsEmpty())
{
	ShowMessage("������� ���� ������� ��� ����������!");
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
//----------���������� ������-----------------------------------------------------------------
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
	Form2->Button1->Caption="��������";
	Form2->Caption="����������";
	Form2->Show();
	Form2->Edit1->SetFocus();
}
//----------������� ��� �����-----------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form7= new TForm7(this);
	Form7->ShowModal();
	Form7->Free();

	StringGrid1->ColWidths[0]=50; //������ ��������
	StringGrid1->ColWidths[1]=150;
	StringGrid1->ColWidths[2]=200;
	StringGrid1->ColWidths[3]=100;
	StringGrid1->ColWidths[4]=150;
	StringGrid1->ColWidths[5]=200;
	StringGrid1->ColWidths[6]=200;
	StringGrid1->ColWidths[7]=400;

	StringGrid1->Cells[0][0]="�";
	StringGrid1->Cells[1][0]="������";
	StringGrid1->Cells[2][0]="������";
	StringGrid1->Cells[3][0]="���";
	StringGrid1->Cells[4][0]="���� ��������";
	StringGrid1->Cells[5][0]="������ ����";
	StringGrid1->Cells[6][0]="������ ������";
	StringGrid1->Cells[7][0]="�.�.�. ���������";
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

	 StatusBar1->Panels->Items[0]->Text="���� ��� �������� ������";
	 StatusBar1->Panels->Items[1]->Text="��� ���������� ������";
	 StatusBar1->Panels->Items[2]->Text="��� ���������� ������";
}
//------------��������������---------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
     int nm = StringGrid1->Row;


	if (StringGrid1->Cells[0][nm]=="�")
	{
		ShowMessage("��������� ������������� ������!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("������ �����!");
	}
	else if (nm==0)
	{
		 ShowMessage("��� �������������� �������� ������!");
	}
	else
	{
	Form2->Button1->Caption="��������������";
	Form2->Caption="��������������";
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
//------------------��������---------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
    if (saving==false)
{
   if (Application->MessageBox(L"������ ��������� ��������� � ������� �����?",L"��������������", MB_YESNO)==IDYES)
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
			ShowMessage("������ ��� �������� �����");
		}
		else
		{
			filename = OpenDialog1->FileName; // ��������� filename

			Dogs dog;
			StringGrid1->RowCount = 2; // ��������� � ������ ������ ������
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
//------------���������---------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
      SaveDialog2->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog2->DefaultExt = "bin";

	std::ofstream outFile(filename.c_str(), std::ios::out | std::ios::binary);
	if (!outFile) {
	ShowMessage("������ ��� ���������� �����");
	}
	else
	{
		Dogs dog;
		int op=1;
		for (int i = 1; i < StringGrid1->RowCount-1; i++)
		{ // �������� � 1, ����� ���������� ���������

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
		ShowMessage("���� ������� ��������");
		saving=true;
		StatusBar1->Panels->Items[0]->Text=filename;
	}
}
//------------��������� ���---------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
    SaveDialog1->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog1->DefaultExt = "bin";
	if (SaveDialog1->Execute())
{

	filenamesaving = SaveDialog1->FileName; // ��������� filenamesaving

	if (first==0)
	{
		 filename=filenamesaving;
		 StatusBar1->Panels->Items[0]->Text=filename;
	}

	if ((filenamesaving==filename)&&(first==1))
	{
		 if (Application->MessageBox(L"������ ������������ ����?", L"��������������", MB_YESNO)==IDYES)
			TForm1::N3Click(SaveDialog2);
		 else
			 TForm1::N4Click(SaveDialog1);
	}
	else
{
	std::ofstream outFile(filenamesaving.c_str(), std::ios::out | std::ios::binary);
	if (!outFile) {
	ShowMessage("������ ��� ���������� �����");
	}
	else
	{
		Dogs dog;
		int op=1;
		for (int i = 1; i < StringGrid1->RowCount-1; i++)
		{ // �������� � 1, ����� ���������� ���������
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
		ShowMessage("���� ������� ��������");
		first=1;
		N3->Enabled=true;
		saving=true;
	}
}
}
}
//--------------��������-------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
	int nm = StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="�")
	{
		ShowMessage("��������� ������� ������!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("������ �����!");
	}
	else if (nm==0)
	{
		 ShowMessage("��� �������� �������� ������!");
	}
	else if ((Application->MessageBox(L"�� �������, ��� ������ ������� ������? ������������ ������ ����� ������!", L"��������������", MB_YESNO)==IDYES))
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
//------------�������� �����---------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
	Form1->Close();
}
//------------� ���������---------------------------------------------------------------

void __fastcall TForm1::N17Click(TObject *Sender)
{
	 ShowMessage("������ �������� 1.1. ��������� ��������� ������� 29.05.2023. ��������� ���� ���������� ����������. Email ������ - someone2004@mail.ru.");
}
//---------�������------------------------------------------------------------------

void __fastcall TForm1::N15Click(TObject *Sender)
{
	 ShowMessage("���� ����������� ������������ ��������: �.�.�. ���������, ������ � ������ ������, �� ��� � ���� ��������, ������ ���� � ������ ������. ������������ ������ ����� ����� ������, ��������������� �� ��������. ���������� ����� ���������� � ������������ ������. ����� ����������, ������� �� ���� ������. ��������� ����������� �������� ������.");
}
//-------------����� �� ������--------------------------------------------------------------

void __fastcall TForm1::N18Click(TObject *Sender)
{
     UnicodeString searchText = "";
	if (InputQuery("�����", "������� ������", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("������� ������ � ��������� ����!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,1);
	}
}
//----------------����� �� ������-----------------------------------------------------------

void __fastcall TForm1::N19Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("�����", "������� ������", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("������� ������ � ��������� ����!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,2);
	}
}
//-----------����� �� ����----------------------------------------------------------------

void __fastcall TForm1::N20Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("�����", "������� ���", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("������� ������ � ��������� ����!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,3);
	}
}
//-------------����� �� ���� ��������--------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("�����", "������� ���� ��������", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("������� ������ � ��������� ����!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,4);
	}
}
//--------------����� �� ������ ����-------------------------------------------------------------

void __fastcall TForm1::N22Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("�����", "������� ������ ����", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("������� ������ � ��������� ����!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,5);
	}
}
//------------����� �� ������ ������---------------------------------------------------------------

void __fastcall TForm1::N23Click(TObject *Sender)
{
      UnicodeString searchText = "";
	if (InputQuery("�����", "������� ������ ������", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("������� ������ � ��������� ����!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,6);
	}
}
//-------------����� �� ��� ���������--------------------------------------------------------------

void __fastcall TForm1::N24Click(TObject *Sender)
{
       UnicodeString searchText = "";
	if (InputQuery("�����", "������� �.�.�. ���������", searchText)==true)
	{
		if (searchText == "")
		{
		   ShowMessage("������� ������ � ��������� ����!");
		   TForm1::N18Click(N18);
		}
		else
			search(searchText,7);
	}
}
//------------����������---------------------------------------------------------------

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
//-----------����� ���������� ������----------------------------------------------------------------

void __fastcall TForm1::N45Click(TObject *Sender)
{
	popular(StringGrid1->RowCount-1);
}
//-----------����� ������������ ������----------------------------------------------------------------

void __fastcall TForm1::N46Click(TObject *Sender)
{
    unpopular(StringGrid1->RowCount-1);
}
//--------��������� ������ ��� 1 ������-------------------------------------------------------------------

void __fastcall TForm1::N210Click(TObject *Sender)
{
	 owner();
}
//----------������ �� ������-----------------------------------------------------------------

void __fastcall TForm1::N48Click(TObject *Sender)
{
    String ch="������";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N49Click(TObject *Sender)
{
     String ch="�����";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N50Click(TObject *Sender)
{
      String ch="�������";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N51Click(TObject *Sender)
{
     String ch="����";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N52Click(TObject *Sender)
{
      String ch="�������";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N53Click(TObject *Sender)
{
      String ch="����";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N54Click(TObject *Sender)
{
     String ch="�����";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N55Click(TObject *Sender)
{
     String ch="������";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N56Click(TObject *Sender)
{
     String ch="�����";
	spisok_po_porode(ch);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N57Click(TObject *Sender)
{
     	String ch="������ ������";
	spisok_po_porode(ch);
}
//------------���������� ������ ������---------------------------------------------------------------

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
	Form2->Button1->Caption="��������";
	Form2->Caption="����������";
	Form2->Show();
	Form2->Edit1->SetFocus();
}
//--------------�������������� �� ������ ������-------------------------------------------------------------

void __fastcall TForm1::N59Click(TObject *Sender)
{
    int nm = StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="�")
	{
		ShowMessage("��������� ������������� ������!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("������ �����!");
	}
	else if (nm==0)
	{
		 ShowMessage("��� �������������� �������� ������!");
	}
	else
	{
	Form2->Button1->Caption="��������������";
	Form2->Caption="��������������";
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
//------------�������� �� ������ ������---------------------------------------------------------------

void __fastcall TForm1::N60Click(TObject *Sender)
{
    int nm = StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="�")
	{
		ShowMessage("��������� ������� ������!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("������ �����!");
	}
	else if (nm==0)
	{
		 ShowMessage("��� �������� �������� ������!");
	}
	else if ((Application->MessageBox(L"�� �������, ��� ������ ������� ������? ������������ ������ ����� ������!", L"��������������", MB_YESNO)==IDYES))
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
//-------�����������--------------------------------------------------------------------
void __fastcall TForm1::N47Click(TObject *Sender)
{
   	int nm=StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="�")
	{
		ShowMessage("�� �������� ���������!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("������ �����!");
	}
	else if (nm==0)
	{
		 ShowMessage("��� ����������� ����������� �������� ������!");
	}
	else
	{
	bool m=false, f=false;

	Form5->Memo1->Lines->Strings[0]=StringGrid1->Cells[1][nm];  //dog


	String father=StringGrid1->Cells[5][nm];
	String mother=StringGrid1->Cells[6][nm];

	Form5->Memo2->Lines->Strings[0]=father;    //parents
	Form5->Memo3->Lines->Strings[0]=mother;

	for (int i=1; i < StringGrid1->RowCount; i++)     //������� � �������
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
//---------������ ��� �� �� ����� ������ ����------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	TPoint pt, pt2;

	pt.x=Button1->Left;
	pt.y=Button1->Top+Button1->Height;
	pt2=ClientToScreen(pt);
	PopupMenu2->Popup(pt2.x, pt2.y);
}
//---------����� �� ������------------------------------------------------------------------

void __fastcall TForm1::N63Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("������� ������ � ��������� ����!");
	else
		search(Edit1->Text,1);
	Form1->Edit1->Text="";
}
//-----------����� �� ������----------------------------------------------------------------

void __fastcall TForm1::N64Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("������� ������ � ��������� ����!");
	else
		search(Edit1->Text,2);
	Form1->Edit1->Text="";
}
//-----------����� �� ����----------------------------------------------------------------

void __fastcall TForm1::N65Click(TObject *Sender)
{
    if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("������� ������ � ��������� ����!");
	else
		search(Edit1->Text,3);
	Form1->Edit1->Text="";
}
//------------����� �� ���� ��������---------------------------------------------------------------

void __fastcall TForm1::N66Click(TObject *Sender)
{
   if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("������� ������ � ��������� ����!");
	else
		search(Edit1->Text,4);
	Form1->Edit1->Text="";
}
//-------------����� �� ������ ����--------------------------------------------------------------

void __fastcall TForm1::N67Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("������� ������ � ��������� ����!");
	else
		search(Edit1->Text,5);
	Form1->Edit1->Text="";
}
//-------------����� �� ������ ������--------------------------------------------------------------

void __fastcall TForm1::N68Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("������� ������ � ��������� ����!");
	else
		search(Edit1->Text,6);
	Form1->Edit1->Text="";
}
//-----------����� �� ��� ���������----------------------------------------------------------------

void __fastcall TForm1::N69Click(TObject *Sender)
{
     if (Form1->Edit1->Text.IsEmpty()==true)
		ShowMessage("������� ������ � ��������� ����!");
	else
		search(Edit1->Text,7);
    Form1->Edit1->Text="";
}
//------------����������� �� ������ ������ ����---------------------------------------------------------------

void __fastcall TForm1::N62Click(TObject *Sender)
{
    	int nm=StringGrid1->Row;

	if (StringGrid1->Cells[0][nm]=="�")
	{
		ShowMessage("�� �������� ���������!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("������ �����!");
	}
	else if (nm==0)
	{
		 ShowMessage("��� ����������� ����������� �������� ������!");
	}
	else
	{
	bool m=false, f=false;

	Form5->Memo1->Lines->Strings[0]=StringGrid1->Cells[1][nm];  //dog


	String father=StringGrid1->Cells[5][nm];
	String mother=StringGrid1->Cells[6][nm];

	Form5->Memo2->Lines->Strings[0]=father;    //parents
	Form5->Memo3->Lines->Strings[0]=mother;

	for (int i=1; i < StringGrid1->RowCount; i++)     //������� � �������
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
//--------�������� �����-------------------------------------------------------------------

void __fastcall TForm1::OnCloseQuery(TObject *Sender, bool &CanClose)
{
    if ((Application->MessageBox(L"�� �������, ��� ������ �����?", L"��������������", MB_YESNO)==IDYES))
	{
		if (saving==true)
		{
			CanClose=true;
		}
		else{
			 if (Application->MessageBox(L"������ ��������� ������� ����?", L"��������������", MB_YESNO)==IDYES)
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
//------------��������� ������ ���� ��� ��������� ������---------------------------------------------------------------
void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
	int nm = StringGrid1->Row;
	StatusBar1->Panels->Items[1]->Text="������ � "+IntToStr(nm)+" �������";
	int nc=StringGrid1->Col;
	StatusBar1->Panels->Items[2]->Text="�������� ������ ["+IntToStr(nm)+";"+IntToStr(nc)+"]";
}
//---------�������------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
     String fn = L"C:\\Users\\Asus\\Desktop\\��������\\�������.txt"; // ��� ���� � �����
	ShellExecute(0, L"open", fn.c_str(), NULL, 0, SW_SHOWNORMAL);
}
//-------------��������� �� ������ ������������--------------------------------------------------------------

void __fastcall TForm1::OnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
     ToolButton1->Hint="���������";
	ToolButton2->Hint="��������� ���";
	ToolButton3->Hint="�������";
	ToolButton4->Hint="�����";
	ToolButton6->Hint="��������";
	ToolButton7->Hint="�������������";
	ToolButton8->Hint="�������";
	ToolButton10->Hint="����������";
	ToolButton11->Hint="�����";
	ToolButton12->Hint="�����������";
	ToolButton14->Hint="�������";
}
//-------���������� ������ ������ ���� ��� ��� �� 2--------------------------------------------------------------------

void __fastcall TForm1::OnContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)

{
     Handled=true;
}
//--------���������� �����-------------------------------------------------------------------

void __fastcall TForm1::N71Click(TObject *Sender)
{
	Form1->Color=clBtnFace;     //������-�����
	Form2->Color=clBtnFace;
	Form3->Color=clBtnFace;
	Form4->Color=clBtnFace;
	Form5->Color=clBtnFace;
	Form6->Color=clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N72Click(TObject *Sender)
{
	 Form1->Color=clScrollBar;     //�����
	 Form2->Color=clScrollBar;
	 Form3->Color=clScrollBar;
	 Form4->Color=clScrollBar;
	 Form5->Color=clScrollBar;
	 Form6->Color=clScrollBar;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N73Click(TObject *Sender)
{
	Form1->Color=clGradientInactiveCaption;    //������-�������
	Form2->Color=clGradientInactiveCaption;
	Form3->Color=clGradientInactiveCaption;
	Form4->Color=clGradientInactiveCaption;
	Form5->Color=clGradientInactiveCaption;
	Form6->Color=clGradientInactiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N74Click(TObject *Sender)
{
	Form1->Color=clGradientActiveCaption;    //�������
	Form2->Color=clGradientActiveCaption;
	Form3->Color=clGradientActiveCaption;
	Form4->Color=clGradientActiveCaption;
	Form5->Color=clGradientActiveCaption;
	Form6->Color=clGradientActiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N75Click(TObject *Sender)
{
	Form1->Color=clMoneyGreen;      //�������
	Form2->Color=clMoneyGreen;
	Form3->Color=clMoneyGreen;
	Form4->Color=clMoneyGreen;
	Form5->Color=clMoneyGreen;
	Form6->Color=clMoneyGreen;
}
//---------------------------------------------------------------------------

