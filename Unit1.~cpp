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

int x = -3;
int y = -3;

int redScore = 0;
int blueScore = 0;

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

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
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
                Timer_ball->Enabled = false;
                b->Visible = false;
                sndPlaySound("snd/Ball+Hit+Cheer.wav", SND_ASYNC);
                redScore++;
                Label3->Caption = IntToStr(redScore);
                Button1->Enabled = true;
                Button1->Visible = true;
                if(redScore == 5)
                {
                          Label5->Visible = true;
                          redScore = 0;
                          blueScore = 0;
                } else if(redScore < 5 && blueScore <5)
                {
                        Button2->Enabled = true;
                        Button2->Visible = true;
                }
        }
        else if(b->Top > bluep->Top - b->Height + bluep->Height/2 &&
                b->Top < bluep->Top + bluep->Height + b->Height - bluep->Height/2 &&
                b->Left - b->Width < bluep->Left)
                {
                        if(x < 0)
                        {
                                x = -x;
                                x++;
                        }
                        sndPlaySound("snd/caughtball.wav", SND_ASYNC);
                }
        else if( b->Top > bluep->Top - b->Height/2 &&
                 b->Top < bluep->Top + bluep->Height + b->Height/2 &&
                 b->Left - b->Width < bluep->Left)
                {
                        if(x < 0) x = -x;
                        sndPlaySound("snd/caughtball.wav", SND_ASYNC);
                }

        //gol prawo
        if(b->Left >= redp->Left + redp->Width + 15)
        {
                Timer_ball->Enabled = false;
                b->Visible = false;
                sndPlaySound("snd/Ball+Hit+Cheer.wav", SND_ASYNC);
                blueScore++;
                Label2->Caption = IntToStr(blueScore);
                Button1->Enabled = true;
                Button1->Visible = true;
                if(blueScore == 5)
                {
                          Label4->Visible = true;
                          blueScore = 0;
                          redScore = 0;
                }else if(redScore < 5 && blueScore <5)
                {
                        Button2->Enabled = true;
                        Button2->Visible = true;
                }
        }
        else if(b->Top > redp->Top - b->Height + redp->Height/2 &&
                b->Top < redp->Top + redp->Height + b->Height - bluep->Height/2 &&
                b->Left + b->Width > redp->Left)
                {
                        if(x > 0)
                        {
                                x = -x;
                                x--;
                        }
                        sndPlaySound("snd/caughtball.wav", SND_ASYNC);
                }
        else if( b->Top > redp->Top - b->Height/2 &&
                 b->Top < redp->Top + redp->Height + b->Height/2 &&
                 b->Left + b->Width > redp->Left)
                {
                        if(x > 0) x = -x;
                        sndPlaySound("snd/caughtball.wav", SND_ASYNC);
                }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        blueScore = 0;
        redScore = 0;
        Label3->Caption = IntToStr(redScore);
        Label2->Caption = IntToStr(blueScore);
        x = -3;
        y = -3;
        b->Top = 200;
        b->Left = 432;
        bluep->Visible = true;
        redp->Visible = true;
        b->Visible = true;
        Timer_ball->Enabled = true;
        Label2->Visible = true;
        Label3->Visible = true;
        Label1->Visible = false;
        Label4->Visible = false;
        Label5->Visible = false;
        Button1->Enabled = false;
        Button1->Visible = false;
        Button2->Enabled = false;
        Button2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
     Application->ShowMainForm = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
         Button2->Enabled = false;
         Button2->Visible = false;
         Button1->Enabled = false;
         Button1->Visible = false;
         x = -3;
         y = -3;
         b->Top = 200;
         b->Left = 432;
         b->Visible = true;
         Timer_ball->Enabled = true;
}
//---------------------------------------------------------------------------

