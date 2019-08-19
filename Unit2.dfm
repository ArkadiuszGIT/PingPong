object Form2: TForm2
  Left = 549
  Top = 302
  Width = 483
  Height = 265
  Caption = 'Instrukcja'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 173
    Height = 13
    Caption = 'Witaj w grze PingPong by Arkadiusz.'
  end
  object Label2: TLabel
    Left = 8
    Top = 32
    Width = 227
    Height = 13
    Caption = 'Lewy gracz steruje wciskaj'#261'c klawisze A oraz Z.'
  end
  object Label3: TLabel
    Left = 8
    Top = 48
    Width = 250
    Height = 13
    Caption = 'Prawy gracz steruje wciskaj'#261'c strza'#322'ki do g'#243'ry i do'#322'u.'
  end
  object Label4: TLabel
    Left = 8
    Top = 72
    Width = 123
    Height = 13
    Caption = 'Dla urozmaicenia zabawy:'
  end
  object Label5: TLabel
    Left = 8
    Top = 88
    Width = 435
    Height = 13
    Caption = 
      'Kiedy odbijesz pi'#322'k'#281' na '#347'rodku paletki, w'#243'wczas zmienisz jej k'#261't' +
      ' odbicia i pi'#322'ka przy'#347'pieszy.  '
  end
  object Label6: TLabel
    Left = 8
    Top = 104
    Width = 258
    Height = 13
    Caption = 'Im d'#322'u'#380'ej odbijasz, tym pi'#322'ka szybciej przemieszcza si'#281'.'
  end
  object Label7: TLabel
    Left = 8
    Top = 120
    Width = 162
    Height = 13
    Caption = 'Mo'#380'esz dowolnie zmienia pole gry.'
  end
  object Label8: TLabel
    Left = 8
    Top = 144
    Width = 65
    Height = 13
    Caption = 'Mi'#322'ej zabawy!'
  end
  object Button1: TButton
    Left = 200
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Ok!'
    TabOrder = 0
    OnClick = Button1Click
  end
end
