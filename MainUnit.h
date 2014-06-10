// ---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>

#include "FuzzyNumber.h"
#include <Vcl.CheckLst.hpp>

// ---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published: // IDE-managed Components

	TListView *ListViewNumbers;
	TChart *ChartFuzzy;
	TGroupBox *GroupBoxInput;
	TEdit *EditA;
	TEdit *EditL;
	TEdit *EditR;
	TButton *ButtonAdd;
	TButton *ButtonDelete;
	TLabel *LabelMiddle;
	TLabel *LabelLeft;
	TLabel *LabelRight;
	TGroupBox *GroupBoxOperation;
	TButton *ButtonInverse;
	TButton *ButtonSub;
	TButton *ButtonMultiply;
	TButton *ButtonSum;
	TLabel *Label1;
	TEdit *EditB;
	TListView *ListViewResult;
	TGroupBox *GroupBoxBumberType;
	TCheckBox *CheckBoxTriangle;
	TCheckBox *CheckBoxTrapezoidal;
	TLineSeries *Series5;
	TLineSeries *Series6;
	TLineSeries *Series7;
	TLineSeries *Series8;
	TLineSeries *Series9;
	TLineSeries *Series10;
	TLineSeries *Series1;
	TLineSeries *Series2;
	TLineSeries *Series3;
	TLineSeries *Series4;
	TButton *ButtonClear;

	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSumClick(TObject *Sender);
	void __fastcall ButtonSubClick(TObject *Sender);
	void __fastcall ButtonInverseClick(TObject *Sender);
	void __fastcall ButtonMultiplyClick(TObject *Sender);
	void __fastcall ListViewResultClick(TObject *Sender);
	void __fastcall ListViewNumbersClick(TObject *Sender);
	void __fastcall CheckBoxTriangleClick(TObject *Sender);
	void __fastcall CheckBoxTrapezoidalClick(TObject *Sender);
	void __fastcall EditAChange(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private: // User declarations
	void DrawFuzzyNumber(FuzzyNumber x);
	void TMainForm::DrawFuzzyNumberSeries(FuzzyNumber sum, int seriesNumber);
	void TMainForm::RedrawFuzzyNumberSeries();
	void TMainForm::AddResultError();
	void AddResultNumber(const FuzzyNumber &sum);
	FuzzyNumber ParseFuzzyLVItem(TListItem *item);

public: // User declarations
	__fastcall TMainForm(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif
