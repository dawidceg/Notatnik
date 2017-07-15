//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Printers.hpp>
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString nazwapliku="";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
        if (OpenDialog1 ->Execute())
        {   try {
                tresc->Lines->LoadFromFile(OpenDialog1->FileName);
                nazwapliku=OpenDialog1->FileName;
                }
            catch (...)
            {
                ShowMessage("B³¹d otwarcia pliku. Upewnij siê ¿e plik istnieje na dysku");
            }
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
        if (SaveDialog1 ->Execute())
        {   try {
                tresc->Lines->SaveToFile(SaveDialog1->FileName);
                nazwapliku=SaveDialog1->FileName;
                }
            catch (...)
            {
                ShowMessage("Zapis zakoñczy³ siê niepowodzeniem!");
            }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
        if(nazwapliku !="")
        {
                tresc->Lines->SaveToFile(nazwapliku);
        }
        else
        {
                Form1->Zapiszjako1Click(MainMenu1);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
        if (Application->MessageBox("Czy napewno utworzyæ nowy plik?", "PotwierdŸ",
        MB_YESNOCANCEL | MB_ICONQUESTION ) == IDYES)
        {
                tresc->Lines->Clear();
                nazwapliku="";
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::trescKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Shift.Contains(ssCtrl))
        {
                if ((Key ==  's') || (Key == 'S'))
                {
                        Form1->Zapisz1Click(MainMenu1);
                }
                if ((Key ==  'n') || (Key == 'N'))
                {
                        Form1->Otwrz1Click(OpenDialog1);
                }
                if ((Key ==  'p') || (Key == 'P'))
                {
                        Form1->DrukujCtrP1Click(PrintDialog1);
                }
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{
        if (Application->MessageBox("Czy napewno zakoñczyæ program?", "PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION ) == IDYES)
        {
                Application->Terminate();
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        if (Application->MessageBox("Czy napewno zakoñczyæ program?", "PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION ) == IDNO)
        {
                Action=caNone;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WytnijCtrX1Click(TObject *Sender)
{
        tresc->CutToClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::K1Click(TObject *Sender)
{
        tresc->CopyToClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::opjuj1Click(TObject *Sender)
{
        tresc->PasteFromClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zawijaniewierszy1Click(TObject *Sender)
{
        if (Zawijaniewierszy1->Checked==true)
        {
                Zawijaniewierszy1->Checked=false;
                tresc->WordWrap=false;
                tresc->ScrollBars=ssBoth;
        }
        else
        {
                Zawijaniewierszy1->Checked=true;
                tresc->WordWrap=true;
                tresc->ScrollBars=ssVertical;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Czcionka1Click(TObject *Sender)
{
        if (FontDialog1->Execute())
        {
                //kroj
                tresc->Font->Name = FontDialog1 ->Font->Name;
                //kolor
                tresc->Font->Color = FontDialog1 ->Font->Color;
                //rozmiar
                tresc->Font->Size = FontDialog1 ->Font->Size;
                //styl
                tresc->Font->Style = FontDialog1 ->Font->Style;
        } 
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Oprogramie2Click(TObject *Sender)
{
        Form2 ->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
        ShellExecute(NULL, "open", "http://", NULL, NULL, SW_SHOWNORMAL);         
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PrintMemo(TMemo *Memo, TPrintDialog *PrintDialog)
{
 int trips; 
 int dups;
 int firstpg;
 int lastpg;
 bool needsnewpg = false;

 pages->Text = Memo->Text;

 if(!PrintDialog->Execute())
  return; //je¿eli u¿ytkownik nie naciœnie OK, drukowanie zostanie anulowane.

 if(!PrintDialog->Collate)
 {
  trips = 1;
  dups  = PrintDialog->Copies;
 }
 else
 {
  trips = PrintDialog->Copies;
  dups  = 1;
 }

 if(PrintDialog->PrintRange == prAllPages)
 {
  firstpg = PrintDialog->MinPage; //Minimalna iloœæ drukowanych stron.
  lastpg  = PrintDialog->MaxPage; //Maksymalna iloœæ drukowanych stron.
 }
 else
 {
  firstpg = PrintDialog->FromPage; //Numer strony od której rozpocznie siê drukowanie.
  lastpg  = PrintDialog->ToPage;   //Numer strony na której skoñczy siê drukowanie
 }

 Printer()->BeginDoc(); //Inicjowanie pracy drukarki.
 Printer()->Canvas->Font->Size  = Memo->Font->Size;
 Printer()->Canvas->Font->Name = Memo->Font->Name;
 Printer()->Canvas->Font->Color = Memo->Font-> Color;
 Printer()->Canvas->Font->Style = Memo->Font->Style;

 Printer()->Title = "Wydruk"; //Tytu³ wydruku.

 for(int x = 0; x < trips; x++)             //dla ka¿dego obiegu
  for(int y = firstpg - 1; y < lastpg; y++) //dla ka¿dej strony
   for(int z = 0; z < dups; z++)            //dla ka¿dej otwartej strony
   {
    if(needsnewpg)
    Printer()->NewPage();

    PrintPage(y); //drukuj t¹ stronê.
    needsnewpg = true; //dalsze strony potrzebuj¹ przerw.
   }

 Printer()->EndDoc();
}
//-----------------------------------------------------------------------------
void __fastcall TForm1::PrintPage(int page)
{
 int pageline = 0;

 Printer()->Canvas->TextOut(20, (10 + Printer()->Canvas->TextHeight(" ")) * pageline, " ");
 pageline += 2;

 for(__int8 line = 0; line < pages->Count; line++)
 {
  __int8 h = (10 + Printer()->Canvas->TextHeight(" "));
  Printer()->Canvas->TextOut(20, h * pageline, pages->Strings[line].c_str());
  pageline++;
  if(pageline *h >= Printer()->PageHeight)
  {
   pageline = 0;
   Printer()->NewPage();
  }
 }
}
//--------------------------------------------------------------------------

void __fastcall TForm1::DrukujCtrP1Click(TObject *Sender)
{
        currentpage = 0;
        pages = new TStringList;
        PrintMemo(tresc, PrintDialog1);
}
//---------------------------------------------------------------------------


