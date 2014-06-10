// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include <ustring.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner)
{
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonAddClick(TObject *Sender)
{
	try
	{
		double l, r, a, b;
		l = StrToFloat(EditL->Text);
		r = StrToFloat(EditR->Text);
		a = StrToFloat(EditA->Text);
		b = StrToFloat(EditB->Text);

		if (l > a)
			throw Exception
				(_T("Левое значение должно быть меньше правого модального значения")
				);
		if (a > b)
			throw Exception
				(_T("Левое модальное значение должно быть меньше правого значения")
				);
		if (b > r)
			throw Exception
				(_T("Правое модальное значение должно быть меньше правого значения")
				);

		TListItem *ListItem;
		ListItem = ListViewNumbers->Items->Add();
		ListItem->Caption = ListItem->Index;
		ListItem->SubItems->Add(EditL->Text);
		ListItem->SubItems->Add(EditA->Text);
		ListItem->SubItems->Add(EditB->Text);
		ListItem->SubItems->Add(EditR->Text);
		RedrawFuzzyNumberSeries();
	}
	catch (Exception &e)
	{
		MessageBox(0, e.ToString().c_str(), _T("Ошибка ввода"), MB_ICONWARNING);
		return;
	}

}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonDeleteClick(TObject *Sender)
{
	try
	{
		ListViewNumbers->SetFocus();
		ListViewNumbers->Selected->Delete();
		ListViewNumbers->Items->Item[ListViewNumbers->Items->Count - 1]
			->Selected = true;
		RedrawFuzzyNumberSeries();
		// ChartFuzzy->Series[ListViewNumbers->Selected->Index]->Clear();
	}
	catch (...)
	{
		ShowMessage("Не выделено на одного числа");
	}
}

// ---------------------------------------------------------------------------
void TMainForm::DrawFuzzyNumber(FuzzyNumber sum)
{
	ChartFuzzy->Series[0]->Clear();
	ChartFuzzy->Series[0]->AddXY(sum.m_l, 0,
		FloatToStrF(sum.m_l, ffGeneral, 4, 6));
	ChartFuzzy->Series[0]->AddXY(sum.m_a, 1,
		FloatToStrF(sum.m_a, ffGeneral, 4, 6));
	ChartFuzzy->Series[0]->AddXY(sum.m_b, 1,
		FloatToStrF(sum.m_b, ffGeneral, 4, 6));
	ChartFuzzy->Series[0]->AddXY(sum.m_r, 0,
		FloatToStrF(sum.m_r, ffGeneral, 4, 6));
}

// ---------------------------------------------------------------------------
void TMainForm::DrawFuzzyNumberSeries(FuzzyNumber sum, int seriesNumber)
{
	++seriesNumber;
	if (10 > seriesNumber)
	{
		ChartFuzzy->Series[seriesNumber]->Clear();
		ChartFuzzy->Series[seriesNumber]->AddXY(sum.m_l, 0,
			FloatToStrF(sum.m_l, ffGeneral, 4, 6));
		ChartFuzzy->Series[seriesNumber]->AddXY(sum.m_a, 1,
			FloatToStrF(sum.m_a, ffGeneral, 4, 6));
		ChartFuzzy->Series[seriesNumber]->AddXY(sum.m_b, 1,
			FloatToStrF(sum.m_b, ffGeneral, 4, 6));
		ChartFuzzy->Series[seriesNumber]->AddXY(sum.m_r, 0,
			FloatToStrF(sum.m_r, ffGeneral, 4, 6));
	}
	else
	{
		if (10 == seriesNumber)
			MessageBox(0, _T("На графике отобразится только 10 чисел."),
			_T("Предупреждение"), MB_OK);
	}
}

// ---------------------------------------------------------------------------
void TMainForm::RedrawFuzzyNumberSeries()
{
	int Count = ListViewNumbers->Items->Count;
	if (10 == Count)
		MessageBox(0, _T("На графике отобразится только 10 чисел."),
		_T("Предупреждение"), MB_OK);
	if (10 < Count)
		Count = 10;
	for (int i = 1; i <= Count; ++i) // Series number hardcode
	{
		FuzzyNumber listFuzzy =
			ParseFuzzyLVItem(ListViewNumbers->Items->operator[](i - 1));
		ChartFuzzy->Series[i]->Clear();
		ChartFuzzy->Series[i]->AddXY(listFuzzy.m_l, 0,
			FloatToStrF(listFuzzy.m_l, ffGeneral, 4, 6));
		ChartFuzzy->Series[i]->AddXY(listFuzzy.m_a, 1,
			FloatToStrF(listFuzzy.m_a, ffGeneral, 4, 6));
		ChartFuzzy->Series[i]->AddXY(listFuzzy.m_b, 1,
			FloatToStrF(listFuzzy.m_b, ffGeneral, 4, 6));
		ChartFuzzy->Series[i]->AddXY(listFuzzy.m_r, 0,
			FloatToStrF(listFuzzy.m_r, ffGeneral, 4, 6));
	}
	for (int i = Count + 1; i < 10; ++i)
		ChartFuzzy->Series[i]->Clear();
}

// ---------------------------------------------------------------------------
void TMainForm::AddResultNumber(const FuzzyNumber &sum)
{
	TListItem *ListItem;
	ListItem = ListViewResult->Items->Add();
	ListItem->Caption = ListItem->Index;
	ListItem->SubItems->Add(sum.m_l);
	ListItem->SubItems->Add(sum.m_a);
	ListItem->SubItems->Add(sum.m_b);
	ListItem->SubItems->Add(sum.m_r);
}

// ---------------------------------------------------------------------------
FuzzyNumber TMainForm::ParseFuzzyLVItem(TListItem *item)
{
	FuzzyNumber x;

	x.m_l = StrToFloat(item->SubItems->operator[](0));
	x.m_a = StrToFloat(item->SubItems->operator[](1));
	x.m_b = StrToFloat(item->SubItems->operator[](2));
	x.m_r = StrToFloat(item->SubItems->operator[](3));

	return x;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonSumClick(TObject *Sender)
{
	if (ListViewNumbers->Items->Count > 1)
	{
		FuzzyNumber x;
		FuzzyNumber sum;
		sum = ParseFuzzyLVItem(ListViewNumbers->Items->Item[0]);

		for (int i = 1; i < ListViewNumbers->Items->Count; ++i)
		{
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

void __fastcall TMainForm::ButtonSubClick(TObject *Sender)
{
	if (ListViewNumbers->Items->Count > 1)
	{
		FuzzyNumber x;
		FuzzyNumber sub;

		sub = ParseFuzzyLVItem(ListViewNumbers->Items->Item[0]);

		for (int i = 1; i < ListViewNumbers->Items->Count; ++i)
		{
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
void __fastcall TMainForm::ButtonInverseClick(TObject *Sender)
{
	if (ListViewNumbers->Items->Count > 0)
	{
		FuzzyNumber x, inverse;

		// clear results
		ListViewResult->Clear();

		for (int i = 0; i < ListViewNumbers->Items->Count; ++i)
		{
			x = ParseFuzzyLVItem(ListViewNumbers->Items->Item[i]);

			if ((x.m_l * x.m_r) <= 0)
			{
				MessageBox(0, _T("Обратного числа не существует."),
					_T("Ошибка!"), MB_ICONERROR);
				return;
			}

			inverse = FuzzyNumber::getInverse(x);

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

void __fastcall TMainForm::ButtonMultiplyClick(TObject *Sender)
{
	if (ListViewNumbers->Items->Count > 1)
	{
		FuzzyNumber x;
		FuzzyNumber mpy;

		mpy = ParseFuzzyLVItem(ListViewNumbers->Items->Item[0]);

		for (int i = 1; i < ListViewNumbers->Items->Count; ++i)
		{
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

void __fastcall TMainForm::ListViewResultClick(TObject *Sender)
{
	if (ListViewResult->RowSelect && -1 != ListViewResult->ItemIndex)
	{
		DrawFuzzyNumber(ParseFuzzyLVItem(ListViewResult->ItemFocused));
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ListViewNumbersClick(TObject *Sender)
{
	if (ListViewNumbers->RowSelect && -1 != ListViewNumbers->ItemIndex)
	{
		// DrawFuzzyNumber(ParseFuzzyLVItem(ListViewNumbers->ItemFocused));
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::CheckBoxTriangleClick(TObject *Sender)
{
	if (true == CheckBoxTriangle->Checked)
	{
		EditB->Enabled = false;
		CheckBoxTrapezoidal->Checked = false;
	}
	else
	{
		EditB->Enabled = true;
		CheckBoxTrapezoidal->Checked = true;
	}
	ListViewNumbers->Clear();
	for (int i = 0; i < ChartFuzzy->SeriesCount(); ++i)
		ChartFuzzy->Series[i]->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::CheckBoxTrapezoidalClick(TObject *Sender)
{
	if (true == CheckBoxTrapezoidal->Checked)
	{
		EditB->Enabled = true;
		CheckBoxTriangle->Checked = false;
	}
	else
	{
		EditB->Enabled = false;
		CheckBoxTriangle->Checked = true;
	}
	ListViewNumbers->Clear();
	for (int i = 0; i < ChartFuzzy->SeriesCount(); ++i)
		ChartFuzzy->Series[i]->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::EditAChange(TObject *Sender)
{
	if (true == CheckBoxTriangle->Checked)
	{
		EditB->Text = EditA->Text;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonClearClick(TObject *Sender)
{
	ListViewNumbers->Clear();
	for (int i = 0; i < ChartFuzzy->SeriesCount(); ++i)
		ChartFuzzy->Series[i]->Clear();
}
// ---------------------------------------------------------------------------
