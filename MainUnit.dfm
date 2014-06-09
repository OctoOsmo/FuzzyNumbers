object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1085#1077#1095#1105#1090#1082#1080#1084#1080' '#1095#1080#1089#1083#1072#1084#1080
  ClientHeight = 466
  ClientWidth = 715
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    715
    466)
  PixelsPerInch = 96
  TextHeight = 13
  object ListViewNumbers: TListView
    Left = 8
    Top = 261
    Width = 346
    Height = 196
    Anchors = [akLeft, akRight, akBottom]
    Columns = <
      item
        Caption = #8470
        Width = 30
      end
      item
        Caption = #1057#1077#1088#1077#1076#1080#1085#1072
        Width = 70
      end
      item
        Caption = #1051#1077#1074#1072#1103' '#1095#1072#1089#1090#1100
        Width = 85
      end
      item
        Caption = #1055#1088#1072#1074#1072#1103' '#1095#1072#1089#1090#1100
        Width = 85
      end>
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    ExplicitTop = 199
  end
  object ChartFuzzy: TChart
    Left = 360
    Top = 8
    Width = 354
    Height = 245
    Legend.Visible = False
    Title.Text.Strings = (
      #1056#1077#1079#1091#1083#1100#1090#1072#1090)
    View3D = False
    TabOrder = 1
    Anchors = [akLeft, akTop, akRight, akBottom]
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
  object ListViewResult: TListView
    Left = 360
    Top = 261
    Width = 354
    Height = 197
    Anchors = [akLeft, akRight, akBottom]
    Columns = <
      item
        Caption = #8470
        Width = 30
      end
      item
        Caption = #1057#1077#1088#1077#1076#1080#1085#1072
        Width = 70
      end
      item
        Caption = #1051#1077#1074#1072#1103' '#1095#1072#1089#1090#1100
        Width = 85
      end
      item
        Caption = #1055#1088#1072#1074#1072#1103' '#1095#1072#1089#1090#1100
        Width = 85
      end>
    RowSelect = True
    TabOrder = 2
    ViewStyle = vsReport
    OnClick = ListViewResultClick
    ExplicitTop = 199
  end
  object GroupBoxInput: TGroupBox
    Left = 8
    Top = 8
    Width = 346
    Height = 137
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
    TabOrder = 3
    object LabelMiddle: TLabel
      Left = 32
      Top = 29
      Width = 50
      Height = 13
      Caption = #1057#1077#1088#1077#1076#1080#1085#1072
    end
    object LabelLeft: TLabel
      Left = 128
      Top = 29
      Width = 63
      Height = 13
      Caption = #1051#1077#1074#1072#1103' '#1095#1072#1089#1090#1100
    end
    object LabelRight: TLabel
      Left = 231
      Top = 29
      Width = 69
      Height = 13
      Caption = #1055#1088#1072#1074#1072#1103' '#1095#1072#1089#1090#1100
    end
    object EditM: TEdit
      Left = 32
      Top = 48
      Width = 73
      Height = 21
      TabOrder = 0
      Text = '5'
    end
    object EditL: TEdit
      Left = 128
      Top = 48
      Width = 73
      Height = 21
      TabOrder = 1
      Text = '2'
    end
    object EditR: TEdit
      Left = 231
      Top = 48
      Width = 78
      Height = 21
      TabOrder = 2
      Text = '2'
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
  end
  object GroupBoxOperation: TGroupBox
    Left = 8
    Top = 151
    Width = 346
    Height = 104
    Caption = #1054#1087#1077#1088#1072#1094#1080#1080
    TabOrder = 4
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
end
