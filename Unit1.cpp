//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;

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

void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
        b->Left += x;
        b->Top += y;

        //odbij od góry
        if(b->Top - 5 <= tlo->Top) y = -y;
        //odbij od do³u
        if(b->Top + b->Height + 5 >= tlo->Height) y = -y;

        //gol lewo
        if(b->Left <= bluep->Left - bluep->Width - 15)
        {
                Timer_pilka->Enabled = false;
                b->Visible = false;
                sndPlaySound("snd/Ball+Hit+Cheer.wav", SND_ASYNC);
        }
        else if( b->Top > bluep->Top - b->Height/2 &&
                 b->Top < bluep->Top + bluep->Height &&
                 b->Left - b->Width < bluep->Left)
                {
                        if(x < 0) x = -x;
                        sndPlaySound("snd/caughtball.wav", SND_ASYNC);
                }

        //gol prawo
        if(b->Left >= redp->Left + redp->Width + 15)
        {
                Timer_pilka->Enabled = false;
                b->Visible = false;
                sndPlaySound("snd/Ball+Hit+Cheer.wav", SND_ASYNC);
        }
        else if( b->Top > redp->Top - b->Height/2 &&
                 b->Top < redp->Top + redp->Height &&
                 b->Left + b->Width > redp->Left)
                {
                        if(x > 0) x = -x;
                        sndPlaySound("snd/caughtball.wav", SND_ASYNC);
                }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        bluep->Visible = true;
        redp->Visible = true;
        b->Visible = true;
        Timer_pilka->Enabled = true;
        Label1->Visible = false;
        Button1->Enabled = false;
        Button1->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
     Application->ShowMainForm = false;
}
//---------------------------------------------------------------------------

