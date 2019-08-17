//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::bluetopTimer(TObject *Sender)
{
        if (bluep->Top > 5) bluep->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::bluebotTimer(TObject *Sender)
{
        if (bluep->Top + bluep->Height < tlo->Height - 5) bluep->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::redtopTimer(TObject *Sender)
{
        if (redp->Top > 5) redp->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::redbotTimer(TObject *Sender)
{
        if (redp->Top + redp->Height < tlo->Height - 5) redp->Top +=10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
          if (Key == VK_UP) redtop->Enabled = true;
          if (Key == VK_DOWN) redbot->Enabled = true;
          if (Key == 'A') bluetop->Enabled = true;
          if (Key == 'Z') bluebot->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
          if (Key == VK_UP) redtop->Enabled = false;
          if (Key == VK_DOWN) redbot->Enabled = false;
          if (Key == 'A') bluetop->Enabled = false;
          if (Key == 'Z') bluebot->Enabled = false;
}
//---------------------------------------------------------------------------
 