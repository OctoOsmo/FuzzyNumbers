// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "FuzzyNumber.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonAddClick(TObject *Sender) {
	TListItem *ListItem;
	// ListViewNumbers->Items->Add();
	// ListViewNumbers->Items->Item[ListViewNumbers->ItemIndex]->SubItems->Strings[0] = "M";
	ListItem = ListViewNumbers->Items->Add();
	ListItem->Caption = ListItem->Index;
	// ListViewNumbers->Items->Item[0]->SubItems->Append("1");
	ListItem->SubItems->Add(EditM->Text);
	ListItem->SubItems->Add(EditL->Text);
	ListItem->SubItems->Add(EditR->Text);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender) {
	/*

	 const char Names[6][2][10] =
	 {{"Rubble","Barny"},
	 {"Michael", "Johnson"},
	 {"Bunny", "Bugs"},
	 {"Silver", "HiHo"},
	 {"Simpson", "Bart"},
	 {"Squirrel", "Rockey"}};

	 TListColumn  *NewColumn;
	 TListItem  *ListItem;
	 TListView   *ListView = new TListView(this);

	 ListView->Parent = this;
	 ListView->Align = alBottom;
	 ListView->ViewStyle = vsReport;
	 NewColumn = ListView->Columns->Add();
	 NewColumn->Caption = "Last";

	 NewColumn = ListView->Columns->Add();
	 NewColumn->Caption = "First";
	 for (int i = 0; i < 6; i++)
	 {
	 ListItem = ListView->Items->Add();
	 ListItem->Caption = Names[i][0];
	 ListItem->SubItems->Add(Names[i][1]);
	 }

	 */
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonDeleteClick(TObject *Sender) {
	try {
		ListViewNumbers->SetFocus();
		ListViewNumbers->Selected->Delete();
		ListViewNumbers->Items->Item[ListViewNumbers->Items->Count - 1]
			->Selected = true;
	}
	catch (...) {
		ShowMessage("Не выделено на одного числа");
	}
}

// ---------------------------------------------------------------------------
void DrawFuzzyNumber(FuzzyNumber x) {
	ChartFuzzy->Series[0]->Clear();
	ChartFuzzy->Series[0]->AddXY(sum.m - sum.a, 0, FloatToStr(sum.m - sum.a));
	ChartFuzzy->Series[0]->AddXY(sum.m, 1, FloatToStr(sum.m));
	ChartFuzzy->Series[0]->AddXY(sum.m + sum.b, 0, FloatToStr(sum.m + sum.b));
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonSumClick(TObject *Sender) {
	if (ListViewNumbers->Items->Count > 1) {
		FuzzyNumber x;
		FuzzyNumber sum;
		sum.m = StrToFloat
			(ListViewNumbers->Items->Item[0]->SubItems->operator[](0));
		sum.a = StrToFloat
			(ListViewNumbers->Items->Item[0]->SubItems->operator[](1));
		sum.b = StrToFloat
			(ListViewNumbers->Items->Item[0]->SubItems->operator[](2));

		for (int i = 1; i < ListViewNumbers->Items->Count; ++i) {
			x.m = StrToFloat
				(ListViewNumbers->Items->Item[i]->SubItems->operator[](0));
			x.a = StrToFloat
				(ListViewNumbers->Items->Item[i]->SubItems->operator[](1));
			x.b = StrToFloat
				(ListViewNumbers->Items->Item[i]->SubItems->operator[](2));
			sum = sum + x;
		}
		EditResult->Text = FloatToStr(sum.m) + ";" + FloatToStr(sum.a) + ";" +
			FloatToStr(sum.b);
		DrawFuzzyNumber(sum);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonSubClick(TObject *Sender) {
	if (ListViewNumbers->Items->Count > 1) {
		FuzzyNumber x;
		FuzzyNumber sum;
		sum.m = StrToFloat
			(ListViewNumbers->Items->Item[0]->SubItems->operator[](0));
		sum.a = StrToFloat
			(ListViewNumbers->Items->Item[0]->SubItems->operator[](1));
		sum.b = StrToFloat
			(ListViewNumbers->Items->Item[0]->SubItems->operator[](2));

		for (int i = 1; i < ListViewNumbers->Items->Count; ++i) {
			x.m = StrToFloat
				(ListViewNumbers->Items->Item[i]->SubItems->operator[](0));
			x.a = StrToFloat
				(ListViewNumbers->Items->Item[i]->SubItems->operator[](1));
			x.b = StrToFloat
				(ListViewNumbers->Items->Item[i]->SubItems->operator[](2));
			sum = sum - x;
		}
		EditResult->Text = FloatToStr(sum.m) + ";" + FloatToStr(sum.a) + ";" +
			FloatToStr(sum.b);
	}
}
// ---------------------------------------------------------------------------
