object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1085#1077#1095#1105#1090#1082#1080#1084#1080' '#1095#1080#1089#1083#1072#1084#1080
  ClientHeight = 395
  ClientWidth = 689
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
  object EditM: TEdit
    Left = 8
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '5'
  end
  object EditL: TEdit
    Left = 144
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '2'
  end
  object EditR: TEdit
    Left = 280
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '2'
  end
  object ListViewNumbers: TListView
    Left = 410
    Top = 0
    Width = 279
    Height = 145
    Align = alRight
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
    TabOrder = 3
    ViewStyle = vsReport
    ExplicitHeight = 375
  end
  object ButtonAdd: TButton
    Left = 54
    Top = 41
    Width = 115
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1089#1087#1080#1089#1086#1082
    TabOrder = 4
    OnClick = ButtonAddClick
  end
  object ButtonDelete: TButton
    Left = 216
    Top = 41
    Width = 115
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1080#1079' '#1089#1087#1080#1089#1082#1072
    TabOrder = 5
    OnClick = ButtonDeleteClick
  end
  object ButtonSum: TButton
    Left = 54
    Top = 83
    Width = 41
    Height = 25
    Caption = '+'
    TabOrder = 6
    OnClick = ButtonSumClick
  end
  object EditResult: TEdit
    Left = 128
    Top = 114
    Width = 121
    Height = 21
    TabOrder = 7
    Text = 'EditResult'
  end
  object ButtonSub: TButton
    Left = 128
    Top = 83
    Width = 41
    Height = 25
    Caption = '-'
    TabOrder = 8
    OnClick = ButtonSubClick
  end
  object ChartFuzzy: TChart
    Left = 0
    Top = 145
    Width = 689
    Height = 250
    Legend.Visible = False
    Title.Text.Strings = (
      #1056#1077#1079#1091#1083#1100#1090#1072#1090)
    View3D = False
    Align = alBottom
    TabOrder = 9
    ExplicitLeft = 8
    ExplicitTop = 141
    ExplicitWidth = 400
    ColorPaletteIndex = 13
    object Series1: TAreaSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.ShapeStyle = fosRoundRectangle
      Marks.Visible = False
      SeriesColor = 10708548
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
end
