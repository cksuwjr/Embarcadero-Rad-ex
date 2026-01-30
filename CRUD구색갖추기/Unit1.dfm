object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'ID NAME '#44288#47532' '#49884#49828#53596'('#50672#49845#50857')'
  ClientHeight = 275
  ClientWidth = 640
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 40
    Width = 21
    Height = 13
    Caption = 'ID : '
  end
  object Label2: TLabel
    Left = 232
    Top = 40
    Width = 37
    Height = 13
    Caption = 'Name : '
  end
  object MemoValue: TMemo
    Left = 32
    Top = 87
    Width = 473
    Height = 156
    Enabled = False
    Lines.Strings = (
      'MemoValue')
    TabOrder = 0
  end
  object CreateBTN: TButton
    Left = 519
    Top = 33
    Width = 90
    Height = 48
    Caption = 'CREATE'
    TabOrder = 1
    OnClick = CreateBTNClick
  end
  object ReadBTN: TButton
    Left = 519
    Top = 87
    Width = 90
    Height = 48
    Caption = 'READ'
    TabOrder = 2
    OnClick = ReadBTNClick
  end
  object UpdateBTN: TButton
    Left = 519
    Top = 141
    Width = 90
    Height = 48
    Caption = 'UPDATE'
    TabOrder = 3
    OnClick = UpdateBTNClick
  end
  object DeleteBTN: TButton
    Left = 519
    Top = 195
    Width = 90
    Height = 48
    Caption = 'DELETE'
    TabOrder = 4
    OnClick = DeleteBTNClick
  end
  object IDValue: TEdit
    Left = 59
    Top = 37
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object NameValue: TEdit
    Left = 275
    Top = 37
    Width = 121
    Height = 21
    TabOrder = 6
  end
end
