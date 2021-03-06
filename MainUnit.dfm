object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1085#1077#1095#1105#1090#1082#1080#1084#1080' '#1095#1080#1089#1083#1072#1084#1080
  ClientHeight = 467
  ClientWidth = 778
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    778
    467)
  PixelsPerInch = 96
  TextHeight = 13
  object ListViewNumbers: TListView
    Left = 8
    Top = 260
    Width = 377
    Height = 199
    Anchors = [akLeft, akTop, akBottom]
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
    Width = 387
    Height = 246
    Legend.Visible = False
    Title.Text.Strings = (
      #1056#1077#1079#1091#1083#1100#1090#1072#1090)
    View3D = False
    TabOrder = 1
    Anchors = [akLeft, akTop, akRight, akBottom]
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      17
      15
      17)
    ColorPaletteIndex = 13
    object Series1: TLineSeries
      SeriesColor = clRed
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TLineSeries
      SeriesColor = clLime
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series3: TLineSeries
      SeriesColor = clYellow
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series4: TLineSeries
      SeriesColor = clBlue
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series5: TLineSeries
      SeriesColor = clAqua
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series6: TLineSeries
      SeriesColor = clFuchsia
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series7: TLineSeries
      SeriesColor = 8421440
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series8: TLineSeries
      SeriesColor = 4227200
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series9: TLineSeries
      SeriesColor = 33023
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series10: TLineSeries
      SeriesColor = 16744448
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object GroupBoxInput: TGroupBox
    Left = 8
    Top = 8
    Width = 376
    Height = 137
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
    TabOrder = 2
    object LabelMiddle: TLabel
      Left = 105
      Top = 29
      Width = 73
      Height = 13
      Caption = #1051#1077#1074'. '#1084#1086#1076#1072#1083#1100#1085'.'
    end
    object LabelLeft: TLabel
      Left = 15
      Top = 29
      Width = 61
      Height = 13
      Caption = #1051#1077#1074#1086#1077' '#1079#1085#1072#1095'.'
    end
    object LabelRight: TLabel
      Left = 284
      Top = 29
      Width = 59
      Height = 13
      Caption = #1055#1088#1072#1074'. '#1079#1085#1072#1095'.'
    end
    object Label1: TLabel
      Left = 194
      Top = 29
      Width = 79
      Height = 13
      Caption = #1055#1088#1072#1074'. '#1084#1086#1076#1072#1083#1100#1085'.'
    end
    object EditA: TEdit
      Left = 105
      Top = 48
      Width = 73
      Height = 21
      TabOrder = 0
      Text = '5'
      OnChange = EditAChange
    end
    object EditL: TEdit
      Left = 15
      Top = 48
      Width = 73
      Height = 21
      TabOrder = 1
      Text = '2'
    end
    object EditR: TEdit
      Left = 284
      Top = 48
      Width = 78
      Height = 21
      TabOrder = 2
      Text = '7'
    end
    object ButtonAdd: TButton
      Left = 17
      Top = 87
      Width = 109
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1089#1087#1080#1089#1086#1082
      TabOrder = 3
      OnClick = ButtonAddClick
    end
    object ButtonDelete: TButton
      Left = 132
      Top = 87
      Width = 109
      Height = 25
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1080#1079' '#1089#1087#1080#1089#1082#1072
      TabOrder = 4
      OnClick = ButtonDeleteClick
    end
    object EditB: TEdit
      Left = 195
      Top = 48
      Width = 73
      Height = 21
      Enabled = False
      TabOrder = 5
      Text = '5'
    end
    object ButtonClear: TButton
      Left = 247
      Top = 87
      Width = 109
      Height = 25
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1089#1087#1080#1089#1086#1082
      TabOrder = 6
      OnClick = ButtonClearClick
    end
  end
  object GroupBoxOperation: TGroupBox
    Left = 8
    Top = 151
    Width = 175
    Height = 104
    Caption = #1054#1087#1077#1088#1072#1094#1080#1080
    TabOrder = 3
    object ButtonInverse: TButton
      Left = 103
      Top = 63
      Width = 41
      Height = 25
      Caption = '1/x'
      TabOrder = 0
      OnClick = ButtonInverseClick
    end
    object ButtonSub: TButton
      Left = 103
      Top = 24
      Width = 41
      Height = 25
      Caption = '-'
      TabOrder = 1
      OnClick = ButtonSubClick
    end
    object ButtonMultiply: TButton
      Left = 31
      Top = 63
      Width = 41
      Height = 25
      Caption = '*'
      TabOrder = 2
      OnClick = ButtonMultiplyClick
    end
    object ButtonSum: TButton
      Left = 31
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
    Width = 382
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
  object GroupBoxBumberType: TGroupBox
    Left = 189
    Top = 151
    Width = 195
    Height = 103
    Caption = #1042#1080#1076' '#1074#1074#1086#1076#1080#1084#1099#1093' '#1095#1080#1089#1077#1083
    TabOrder = 5
    object CheckBoxTriangle: TCheckBox
      Left = 34
      Top = 32
      Width = 97
      Height = 17
      Caption = #1058#1088#1077#1091#1075#1086#1083#1100#1085#1099#1077
      Checked = True
      State = cbChecked
      TabOrder = 0
      OnClick = CheckBoxTriangleClick
    end
    object CheckBoxTrapezoidal: TCheckBox
      Left = 34
      Top = 67
      Width = 97
      Height = 17
      Caption = #1058#1088#1072#1087#1080#1094#1080#1074#1080#1076#1085#1099#1077
      TabOrder = 1
      OnClick = CheckBoxTrapezoidalClick
    end
  end
end
