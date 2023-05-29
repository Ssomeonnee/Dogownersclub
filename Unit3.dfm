object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1083#1072#1076#1077#1083#1100#1094#1099' 2 '#1080' '#1073#1086#1083#1077#1077' '#1089#1086#1073#1072#1082
  ClientHeight = 410
  ClientWidth = 485
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 163
    Top = 24
    Width = 151
    Height = 15
    Caption = #1042#1083#1072#1076#1077#1083#1100#1094#1099' 2 '#1080' '#1073#1086#1083#1077#1077' '#1089#1086#1073#1072#1082
  end
  object StringGrid1: TStringGrid
    Left = 19
    Top = 56
    Width = 438
    Height = 337
    ColCount = 3
    RowCount = 2
    FixedRows = 0
    TabOrder = 0
    RowHeights = (
      24
      24)
  end
  object StringGrid2: TStringGrid
    Left = 43
    Top = 399
    Width = 320
    Height = 120
    ColCount = 1
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    TabOrder = 1
    Visible = False
  end
end
