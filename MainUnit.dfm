object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1085#1077#1095#1105#1090#1082#1080#1084#1080' '#1095#1080#1089#1083#1072#1084#1080
  ClientHeight = 467
  ClientWidth = 774
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    774
    467)
  PixelsPerInch = 96
  TextHeight = 13
  object ListViewNumbers: TListView
    Left = 8
    Top = 260
    Width = 377
    Height = 197
    Anchors = [akLeft, akBottom]
    Columns = <
      item
        Caption = #8470
        Width = 30
      end
      item
        Caption = #1051#1077#1074'. '#1079#1085#1072#1095'.'
        Width = 85
      end
      item
        Caption = #1051#1077#1074'. '#1084#1086#1076#1072#1083#1100#1085'.'
        Width = 85
      end
      item
        Caption = #1055#1088#1072#1074'. '#1084#1086#1076#1072#1083#1100#1085'.'
        Width = 85
      end
      item
        Caption = #1055#1088#1072#1074'. '#1079#1085#1072#1095'.'
        Width = 85
      end>
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnClick = ListViewNumbersClick
  end
  object ChartFuzzy: TChart
    Left = 390
    Top = 8
    Width = 383
    Height = 246
    Legend.Visible = False
    Title.Text.Strings = (
      #1056#1077#1079#1091#1083#1100#1090#1072#1090)
    View3D = False
    TabOrder = 1
    Anchors = [akLeft, akTop, akRight, akBottom]
    ExplicitWidth = 453
    ExplicitHeight = 245
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TAreaSeries
      AreaChartBrush.Color = clGray
      AreaChartBrush.BackColor = clDefault
      DrawArea = True
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object GroupBoxInput: TGroupBox
    Left = 8
    Top = 8
    Width = 370
    Height = 137
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
    TabOrder = 2
    object LabelMiddle: TLabel
      Left = 102
      Top = 29
      Width = 73
      Height = 13
      Caption = #1051#1077#1074'. '#1084#1086#1076#1072#1083#1100#1085'.'
    end
    object LabelLeft: TLabel
      Left = 12
      Top = 29
      Width = 61
      Height = 13
      Caption = #1051#1077#1074#1086#1077' '#1079#1085#1072#1095'.'
    end
    object LabelRight: TLabel
      Left = 281
      Top = 29
      Width = 59
      Height = 13
      Caption = #1055#1088#1072#1074'. '#1079#1085#1072#1095'.'
    end
    object Label1: TLabel
      Left = 191
      Top = 29
      Width = 79
      Height = 13
      Caption = #1055#1088#1072#1074'. '#1084#1086#1076#1072#1083#1100#1085'.'
    end
    object EditA: TEdit
      Left = 102
      Top = 48
      Width = 73
      Height = 21
      TabOrder = 0
      Text = '5'
    end
    object EditL: TEdit
      Left = 12
      Top = 48
      Width = 73
      Height = 21
      TabOrder = 1
      Text = '2'
    end
    object EditR: TEdit
      Left = 281
      Top = 48
      Width = 78
      Height = 21
      TabOrder = 2
      Text = '7'
    end
    object ButtonAdd: TButton
      Left = 38
      Top = 87
      Width = 115
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1089#1087#1080#1089#1086#1082
      TabOrder = 3
      OnClick = ButtonAddClick
    end
    object ButtonDelete: TButton
      Left = 171
      Top = 87
      Width = 115
      Height = 25
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1080#1079' '#1089#1087#1080#1089#1082#1072
      TabOrder = 4
      OnClick = ButtonDeleteClick
    end
    object EditB: TEdit
      Left = 192
      Top = 48
      Width = 73
      Height = 21
      TabOrder = 5
      Text = '5'
    end
  end
  object GroupBoxOperation: TGroupBox
    Left = 8
    Top = 151
    Width = 370
    Height = 104
    Caption = #1054#1087#1077#1088#1072#1094#1080#1080
    TabOrder = 3
    object ButtonInverse: TButton
      Left = 259
      Top = 61
      Width = 41
      Height = 25
      Caption = '1/x'
      TabOrder = 0
      OnClick = ButtonInverseClick
    end
    object ButtonSub: TButton
      Left = 259
      Top = 22
      Width = 41
      Height = 25
      Caption = '-'
      TabOrder = 1
      OnClick = ButtonSubClick
    end
    object ButtonMultiply: TButton
      Left = 41
      Top = 63
      Width = 41
      Height = 25
      Caption = '*'
      TabOrder = 2
      OnClick = ButtonMultiplyClick
    end
    object ButtonSum: TButton
      Left = 41
      Top = 24
      Width = 41
      Height = 25
      Caption = '+'
      TabOrder = 3
      OnClick = ButtonSumClick
    end
  end
  object ListViewResult: TListView
    Left = 391
    Top = 260
    Width = 378
    Height = 199
    Anchors = [akLeft, akRight, akBottom]
    Columns = <
      item
        Caption = #8470
        Width = 30
      end
      item
        Caption = #1051#1077#1074'. '#1079#1085#1072#1095'.'
        Width = 85
      end
      item
        Caption = #1051#1077#1074'. '#1084#1086#1076#1072#1083#1100#1085'.'
        Width = 85
      end
      item
        Caption = #1055#1088#1072#1074'. '#1084#1086#1076#1072#1083#1100#1085'.'
        Width = 85
      end
      item
        Caption = #1055#1088#1072#1074'. '#1079#1085#1072#1095'.'
        Width = 85
      end>
    RowSelect = True
    TabOrder = 4
    ViewStyle = vsReport
    OnClick = ListViewResultClick
  end
end
