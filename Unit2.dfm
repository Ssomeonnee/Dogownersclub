object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077
  ClientHeight = 511
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnCloseQuery = OnCloseQuery
  OnCreate = FormCreate
  TextHeight = 15
  object Label9: TLabel
    Left = 22
    Top = 405
    Width = 83
    Height = 15
    Caption = #1050#1083#1080#1095#1082#1072' '#1084#1072#1090#1077#1088#1080
  end
  object Label8: TLabel
    Left = 22
    Top = 371
    Width = 68
    Height = 15
    Caption = #1050#1083#1080#1095#1082#1072' '#1086#1090#1094#1072
  end
  object Label7: TLabel
    Left = 22
    Top = 331
    Width = 83
    Height = 15
    Caption = #1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103
  end
  object Label6: TLabel
    Left = 24
    Top = 262
    Width = 23
    Height = 15
    Caption = #1055#1086#1083
  end
  object Label5: TLabel
    Left = 22
    Top = 200
    Width = 42
    Height = 15
    Caption = #1055#1086#1088#1086#1076#1072
  end
  object Label4: TLabel
    Left = 24
    Top = 160
    Width = 40
    Height = 15
    Caption = #1050#1083#1080#1095#1082#1072
  end
  object Label3: TLabel
    Left = 72
    Top = 120
    Width = 94
    Height = 15
    Caption = #1044#1072#1085#1085#1099#1077' '#1086' '#1089#1086#1073#1072#1082#1077
  end
  object Label2: TLabel
    Left = 24
    Top = 72
    Width = 36
    Height = 15
    Caption = #1060'.'#1048'.'#1054'.'
  end
  object Label1: TLabel
    Left = 72
    Top = 32
    Width = 113
    Height = 15
    Caption = #1044#1072#1085#1085#1099#1077' '#1086' '#1074#1083#1072#1076#1077#1083#1100#1094#1077
  end
  object Button1: TButton
    Left = 176
    Top = 449
    Width = 105
    Height = 41
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit7: TEdit
    Left = 128
    Top = 405
    Width = 297
    Height = 23
    TabOrder = 4
    OnKeyPress = OnKeyPress
  end
  object Edit6: TEdit
    Left = 128
    Top = 376
    Width = 297
    Height = 23
    TabOrder = 3
    OnKeyPress = OnKeyPress
  end
  object Edit2: TEdit
    Left = 128
    Top = 157
    Width = 297
    Height = 23
    TabOrder = 2
    OnKeyPress = OnKeyPress
  end
  object Edit1: TEdit
    Left = 72
    Top = 69
    Width = 353
    Height = 23
    TabOrder = 1
    OnKeyPress = OnKeyPress
  end
  object ListBox1: TListBox
    Left = 126
    Top = 200
    Width = 299
    Height = 41
    ItemHeight = 15
    Items.Strings = (
      #1058#1077#1088#1100#1077#1088
      #1061#1072#1089#1082#1080
      #1054#1074#1095#1072#1088#1082#1072
      #1064#1087#1080#1094
      #1041#1091#1083#1100#1076#1086#1075
      #1052#1086#1087#1089
      #1058#1072#1082#1089#1072' '
      #1055#1091#1076#1077#1083#1100
      #1050#1086#1088#1075#1080
      #1044#1088#1091#1075#1072#1103' '#1087#1086#1088#1086#1076#1072)
    TabOrder = 5
  end
  object RadioGroup1: TRadioGroup
    Left = 126
    Top = 247
    Width = 59
    Height = 66
    Items.Strings = (
      #1084
      #1078)
    TabOrder = 6
  end
  object DateTimePicker1: TDateTimePicker
    Left = 128
    Top = 331
    Width = 186
    Height = 23
    Date = 45064.000000000000000000
    Time = 0.780467754630080900
    TabOrder = 7
  end
end
