object Form1: TForm1
  Left = 624
  Top = 157
  Width = 597
  Height = 576
  Caption = 'NotatnikDC'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object tresc: TMemo
    Left = 0
    Top = 0
    Width = 581
    Height = 517
    Align = alClient
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    OnKeyDown = trescKeyDown
  end
  object MainMenu1: TMainMenu
    Left = 544
    Top = 8
    object Plik1: TMenuItem
      Caption = '&Plik'
      object Nowy1: TMenuItem
        Caption = '&Nowy    Ctr+N'
        OnClick = Nowy1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Otwrz1: TMenuItem
        Caption = '&Otw'#243'rz'
        OnClick = Otwrz1Click
      end
      object Zapisz1: TMenuItem
        Caption = 'Zapisz    Ctr+S'
        OnClick = Zapisz1Click
      end
      object Zapiszjako1: TMenuItem
        Caption = 'Zapisz jako'
        OnClick = Zapiszjako1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object DrukujCtrP1: TMenuItem
        Caption = 'Drukuj    Ctr+P'
        OnClick = DrukujCtrP1Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Zakocz1: TMenuItem
        Caption = 'Zako'#324'cz'
        OnClick = Zakocz1Click
      end
    end
    object Edycja1: TMenuItem
      Caption = '&Edycja'
      object WytnijCtrX1: TMenuItem
        Caption = 'Wytnij    Ctr+X'
        OnClick = WytnijCtrX1Click
      end
      object K1: TMenuItem
        Caption = 'Kopjuj    Ctr+C'
        OnClick = K1Click
      end
      object opjuj1: TMenuItem
        Caption = 'Wklej    Ctr+V'
        OnClick = opjuj1Click
      end
    end
    object Format1: TMenuItem
      Caption = '&Format'
      object Zawijaniewierszy1: TMenuItem
        Caption = 'Zawijanie wierszy'
        Checked = True
        OnClick = Zawijaniewierszy1Click
      end
      object Czcionka1: TMenuItem
        Caption = 'Czcionka...'
        OnClick = Czcionka1Click
      end
    end
    object Pomoc1: TMenuItem
      Caption = 'P&omoc'
      object Informacje1: TMenuItem
        Caption = 'Informacje'
        object Oprogramie1: TMenuItem
          Caption = 'Zapraszam na stron'#281
          OnClick = Oprogramie1Click
        end
        object Oprogramie2: TMenuItem
          Caption = 'O programie'
          OnClick = Oprogramie2Click
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Pliki tekstowe (TXT)|*.txt|Wszystkie Pliki|*.*'
    Left = 504
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Pliki tekstowe (TXT)|*.txt|Wszystkie Pliki|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 472
    Top = 8
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 440
    Top = 8
  end
  object PrintDialog1: TPrintDialog
    Left = 408
    Top = 8
  end
end
