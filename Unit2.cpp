//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        Form2->Visible = false;
        Application->ShowMainForm = true;
        Form1->Visible = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

