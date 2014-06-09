// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonAddClick(TObject *Sender) {
	try {
		if (StrToFloat(EditL->Text) < 0)
			throw Exception(_T("Левое значение должно быть неотрицательным"));
		if (StrToFloat(EditR->Text) < 0)
			throw Exception(_T("Правое значение должно быть неотрицательным"));
		StrToFloat(EditM->Text);

		TListItem *ListItem;
		ListItem = ListViewNumbers->Items->Add();
		ListItem->Caption = ListItem->Index;
		ListItem->SubItems->Add(EditM->Text);
		ListItem->SubItems->Add(EditL->Text);
		ListItem->SubItems->Add(EditR->Text);
	}
	catch (Exception &e) {
		MessageBox(0, e.ToString().c_str(), _T("Ошибка ввода"), MB_ICONWARNING);
		return;
	}

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
void TMainForm::DrawFuzzyNumber(FuzzyNumber sum) {
	ChartFuzzy->Series[0]->Clear();
	ChartFuzzy->Series[0]->AddXY(sum.m - sum.a, 0, FloatToStr(sum.m - sum.a));
	ChartFuzzy->Series[0]->AddXY(sum.m, 1, FloatToStr(sum.m));
	ChartFuzzy->Series[0]->AddXY(sum.m + sum.b, 0, FloatToStr(sum.m + sum.b));
}

// ---------------------------------------------------------------------------
void TMainForm::AddResultNumber(const FuzzyNumber &sum) {
	TListItem *ListItem;
	ListItem = ListViewResult->Items->Add();
	ListItem->Caption = ListItem->Index;
	ListItem->SubItems->Add(sum.m);
	ListItem->SubItems->Add(sum.a);
	ListItem->SubItems->Add(sum.b);
}

// ---------------------------------------------------------------------------
FuzzyNumber TMainForm::ParseFuzzyLVItem(TListItem *item) {
	FuzzyNumber x;

	x.m = StrToFloat(item->SubItems->operator[](0));
	x.a = StrToFloat(item->SubItems->operator[](1));
	x.b = StrToFloat(item->SubItems->operator[](2));

	return x;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonSumClick(TObject *Sender) {
	if (ListViewNumbers->Items->Count > 1) {
		FuzzyNumber x;
		FuzzyNumber sum;
		sum = ParseFuzzyLVItem(ListViewNumbers->Items->Item[0]);

		for (int i = 1; i < ListViewNumbers->Items->Count; ++i) {
			x = ParseFuzzyLVItem(ListViewNumbers->Items->Item[i]);
			sum = sum + x;
		}

		// add result
		{
			ListViewResult->Clear();
			AddResultNumber(sum);
		}

		DrawFuzzyNumber(sum);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonSubClick(TObject *Sender) {
	if (ListViewNumbers->Items->Count > 1) {
		FuzzyNumber x;
		FuzzyNumber sub;

		sub = ParseFuzzyLVItem(ListViewNumbers->Items->Item[0]);

		for (int i = 1; i < ListViewNumbers->Items->Count; ++i) {
			x = ParseFuzzyLVItem(ListViewNumbers->Items->Item[i]);
			sub = sub - x;
		}

		// add result
		{
			ListViewResult->Clear();
			AddResultNumber(sub);
		}

		DrawFuzzyNumber(sub);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonInverseClick(TObject *Sender) {
	if (ListViewNumbers->Items->Count > 0) {
		FuzzyNumber x, inverse;

		// clear results
		ListViewResult->Clear();

		for (int i = 0; i < ListViewNumbers->Items->Count; ++i) {
			x = ParseFuzzyLVItem(ListViewNumbers->Items->Item[i]);

			if ((x.m - x.a) * (x.m + x.b) <= 0) {
				MessageBox(0, _T("Обратного чилса не существует."),
					_T("Ошибка!"), MB_ICONERROR);
				return;
			}

			// check for zero middle value
			if (x.m != 0) {
				inverse.m = 1. / x.m;
			}
			else
				inverse.m = 0;

			// check for zero right value
			if (0 == (x.m + x.b))
				inverse.a = 0.0;
			else
				inverse.a = x.b * inverse.m / (x.m + x.b);

			// check for zero left value
			if (0 == (x.m - x.a))
				inverse.b = 0.0;
			else
				inverse.b = x.a * inverse.m / (x.m - x.a);

			// add result
			{
				AddResultNumber(inverse);
			}
			// draw the first inverted number
			if (0 == i)
				DrawFuzzyNumber(inverse);
		}

	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonMultiplyClick(TObject *Sender) {
	if (ListViewNumbers->Items->Count > 1) {
		FuzzyNumber x;
		FuzzyNumber mpy;

		mpy = ParseFuzzyLVItem(ListViewNumbers->Items->Item[0]);

		for (int i = 1; i < ListViewNumbers->Items->Count; ++i) {
			x = ParseFuzzyLVItem(ListViewNumbers->Items->Item[i]);
			mpy = mpy * x;
		}

		// add result
		{
			ListViewResult->Clear();
			AddResultNumber(mpy);
		}

		DrawFuzzyNumber(mpy);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::ListViewResultClick(TObject *Sender) {
	if (ListViewResult->RowSelect && -1 != ListViewResult->ItemIndex) {
		DrawFuzzyNumber(ParseFuzzyLVItem(ListViewResult->ItemFocused));
	}
}
// ---------------------------------------------------------------------------
