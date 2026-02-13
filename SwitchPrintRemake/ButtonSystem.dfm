object IOForm: TIOForm
  Left = 0
  Top = 0
  Caption = #51077#52636#47141' '#50672#49845' '#54532#47196#44536#47016
  ClientHeight = 295
  ClientWidth = 544
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 176
    Width = 70
    Height = 48
    Alignment = taCenter
    Caption = #51077#47141
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object Label2: TLabel
    Left = 48
    Top = 48
    Width = 70
    Height = 48
    Alignment = taCenter
    Caption = #52636#47141
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object InputLed2: TcyLed
    Left = 200
    Top = 168
    Width = 81
    Height = 73
    LedValue = False
    ReadOnly = True
    Bevels = <
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end
      item
        Width = 3
      end
      item
        Style = bcLowered
      end
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end>
    LedColorOn = clLime
    LedColorOff = clBlack
    LedColorDisabled = 22963
    ShapeLedColorOn = clGreen
    ShapeLedColorOff = 16384
    ShapeLedColorDisabled = 13416
  end
  object InputLed3: TcyLed
    Left = 376
    Top = 168
    Width = 81
    Height = 73
    LedValue = False
    ReadOnly = True
    Bevels = <
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end
      item
        Width = 3
      end
      item
        Style = bcLowered
      end
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end>
    LedColorOn = clLime
    LedColorOff = clBlack
    LedColorDisabled = 22963
    ShapeLedColorOn = clGreen
    ShapeLedColorOff = 16384
    ShapeLedColorDisabled = 13416
  end
  object OutputLed1: TcyLed
    Left = 200
    Top = 48
    Width = 81
    Height = 73
    OnClick = Output_Led_Click
    LedValue = False
    Bevels = <
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end
      item
        Width = 3
      end
      item
        Style = bcLowered
      end
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end>
    LedColorOn = clLime
    LedColorOff = clBlack
    LedColorDisabled = 22963
    ShapeLedColorOn = clGreen
    ShapeLedColorOff = 16384
    ShapeLedColorDisabled = 13416
  end
  object OutputLed2: TcyLed
    Left = 376
    Top = 48
    Width = 81
    Height = 73
    OnClick = Output_Led_Click
    LedValue = False
    Bevels = <
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end
      item
        Width = 3
      end
      item
        Style = bcLowered
      end
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end>
    LedColorOn = clLime
    LedColorOff = clBlack
    LedColorDisabled = 22963
    ShapeLedColorOn = clGreen
    ShapeLedColorOff = 16384
    ShapeLedColorDisabled = 13416
  end
  object Timer: TTimer
    Interval = 10
    OnTimer = TimerTimer
    Left = 16
    Top = 8
  end
end
