//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TListView *ListViewNumbers;
	TChart *ChartFuzzy;
	TAreaSeries *Series1;
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
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSumClick(TObject *Sender);
	void __fastcall ButtonSubClick(TObject *Sender);
	void __fastcall ButtonInverseClick(TObject *Sender);
	void __fastcall ButtonMultiplyClick(TObject *Sender);
	void __fastcall ListViewResultClick(TObject *Sender);
	void __fastcall ListViewNumbersClick(TObject *Sender);
private:	// User declarations
	void DrawFuzzyNumber(FuzzyNumber x);
	void AddResultNumber(const FuzzyNumber &sum);
	FuzzyNumber ParseFuzzyLVItem(TListItem *item);

public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
