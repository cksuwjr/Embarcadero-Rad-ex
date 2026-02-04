//---------------------------------------------------------------------------

#pragma hdrstop

#include "Sql.h"
#include "var.h"
#include "spec.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Sql_Data_Send(AnsiString Str)
{
	Main_Form->Sql_Timer = GetTickCount();

	Main_Form->ADOQuery1->Active = false;
	Main_Form->ADOQuery1->SQL->Clear();
	Main_Form->ADOQuery1->SQL->Add(Str);

	if(Str.Pos("insert") || Str.Pos("update") || Str.Pos("ALTER") || Str.Pos("delete"))
		Main_Form->ADOQuery1->ExecSQL();
	else
		Main_Form->ADOQuery1->Active = true;
}

void Sql_Data_Save()
{
	AnsiString Str;
	AnsiString Data;
	AnsiString Now_Date_Time = Now().CurrentDateTime();

	Str = Main_Form->Model_Name_Panel->Caption;

	Str = "insert into data values ('0',";

	Str += "'";
	Str += Main_Form->Model_Name_Panel->Caption;
	if(Main_Form->Master_Grid->Visible)
		Str += " (MASTER)";
	Str += "',";

	Str += "'";
	Str += Now_Date_Time;
	Str += "',";

	Str += "'";
	Str += Main_Form->Barcode_Edit->Text;
	Str += "',";

	Str += "'";
	Str += Main_Form->Test_State_Panel->Caption;
	Str += "','";

	Data = "";
	for(int i = 0 ; i < Main_Form->Test_Grid->RowCount - 1 ; i++)
	{
		Data += Main_Form->Test_Grid->Cells[TEST_GRID_ITEM][i + 1];
		Data += "|";
		Data += Main_Form->Test_Grid->Cells[TEST_GRID_MIN][i + 1];
		Data += "|";
		Data += Main_Form->Test_Grid->Cells[TEST_GRID_DATA][i + 1];
		Data += "|";
		Data += Main_Form->Test_Grid->Cells[TEST_GRID_MAX][i + 1];
		Data += "|";
		Data += Main_Form->Test_Grid->Cells[TEST_GRID_RESULT][i + 1];
		Data += "@";
	}
	Str += Data;

	Str += "')";

	Sql_Data_Send(Str);
}

/* 미사용
void Sql_Model_Search()
{
	Sql_Data_Send("select distinct MODEL_NAME from data");

	Data_Form->Model_ComboBox->Clear();

	for(int i = 0 ; i < Main_Form->ADOQuery1->RecordCount ; i++)
	{
		Data_Form->Model_ComboBox->AddItem(Main_Form->ADOQuery1->FieldByName("MODEL_NAME")->AsString, NULL);

		Main_Form->ADOQuery1->Next();
	}

	Data_Form->Model_ComboBox->ItemIndex = 0;
}
/*
void Sql_Count_Search()
{
	Sql_Data_Send("select NO from data2 ORDER BY NO desc limit 1");
	Data_Form->Log_Total_Count_Edit->Text = Main_Form->ADOQuery1->FieldByName("NO")->AsString;

	Sql_Data_Send("select NO from data2 where RESULT = '양품'");
	Data_Form->Log_Good_Count_Edit->Text = Main_Form->ADOQuery1->RecordCount;

	Sql_Data_Send("select NO from data2 where RESULT = '불량'");
	Data_Form->Log_Ng_Count_Edit->Text = Main_Form->ADOQuery1->RecordCount;

	if(Data_Form->Log_Total_Count_Edit->Text != "0")
	{
		Data_Form->Log_Good_Rate_Edit->Text = FormatFloat("0.0 %", Data_Form->Log_Good_Count_Edit->Text.ToDouble() / Data_Form->Log_Total_Count_Edit->Text.ToDouble() * 100.);
		Data_Form->Log_Ng_Rate_Edit->Text = FormatFloat("0.0 %", Data_Form->Log_Ng_Count_Edit->Text.ToDouble() / Data_Form->Log_Total_Count_Edit->Text.ToDouble() * 100.);
	}
	else
	{
		Data_Form->Log_Good_Rate_Edit->Text = "";
		Data_Form->Log_Ng_Rate_Edit->Text = "";
	}
}

void Sql_Log_Search()
{
	int Grid_Col;

	AnsiString Start_Date = Data_Form->Start_DateEdit->Date;
	AnsiString End_Date = Data_Form->End_DateEdit->Date + 1;

	AnsiString Str = "";

//  여기는 카운터 조회
	AnsiString Chart_Start_Date = Data_Form->Start_DateEdit->Date;
	AnsiString Chart_End_Date = Data_Form->Start_DateEdit->Date + 1;
	TDateTime Date_Time_Start_Date = Data_Form->Start_DateEdit->Date;

	// 여기는 데이터
	if(Data_Form->Date_All_CheckBox->Checked)
	{
		if(Data_Form->Model_All_CheckBox->Checked)
			Str = "select * from data";
		else
			Str = "select * from data where MODEL_NAME = '" + Data_Form->Model_ComboBox->Text + "'";
	}
	else
	{
		if(Data_Form->Model_All_CheckBox->Checked)
			Str = "select * from data where TEST_TIME >= '" + Start_Date + "' and TEST_TIME <= '" + End_Date + "'";
		else
			Str = "select * from data where TEST_TIME >= '" + Start_Date + "' and TEST_TIME <= '" + End_Date + "' and MODEL_NAME = '" + Data_Form->Model_ComboBox->Text + "'";
	}

	if(Data_Form->Result_RadioGroup->ItemIndex == 1) //양품만
	{
		if(Str.Pos("where"))
			Str += " and RESULT = '양품'";
		else
			Str += " where RESULT = '양품'";
	}
	else if(Data_Form->Result_RadioGroup->ItemIndex == 2) //불량만
	{
		if(Str.Pos("where"))
			Str += " and RESULT = '불량'";
		else
			Str += " where RESULT = '불량'";
	}

	Sql_Data_Send(Str);

	Sql_Data_View();

	Data_Form->Search_Total_Count_Edit->Text = Main_Form->ADOQuery1->RecordCount;
	if(Data_Form->Result_RadioGroup->ItemIndex == 0)
	{
		AnsiString Search_Str = Str;
		if(Str.Pos("where"))
			Search_Str += " and RESULT = '양품'";
		else
			Search_Str += " where RESULT = '양품'";

		Sql_Data_Send(Search_Str);
		Data_Form->Search_Good_Count_Edit->Text = Main_Form->ADOQuery1->RecordCount;

		Search_Str = Str;
		if(Str.Pos("where"))
			Search_Str += " and RESULT = '불량'";
		else
			Search_Str += " where RESULT = '불량'";

		Sql_Data_Send(Search_Str);
		Data_Form->Search_Ng_Count_Edit->Text = Main_Form->ADOQuery1->RecordCount;

		if(Data_Form->Search_Total_Count_Edit->Text != "0")
		{
			Data_Form->Search_Good_Rate_Edit->Text = FormatFloat("0.0 %", Data_Form->Search_Good_Count_Edit->Text.ToDouble() / Data_Form->Search_Total_Count_Edit->Text.ToDouble() * 100.);
			Data_Form->Search_Ng_Rate_Edit->Text = FormatFloat("0.0 %", Data_Form->Search_Ng_Count_Edit->Text.ToDouble() / Data_Form->Search_Total_Count_Edit->Text.ToDouble() * 100.);
		}
		else
		{
			Data_Form->Search_Good_Rate_Edit->Text = "";
			Data_Form->Search_Ng_Rate_Edit->Text = "";
		}
	}
	else
	{
		Data_Form->Search_Good_Count_Edit->Text = "";
		Data_Form->Search_Ng_Count_Edit->Text = "";
		Data_Form->Search_Good_Rate_Edit->Text = "";
		Data_Form->Search_Ng_Rate_Edit->Text = "";
	}
}

void Sql_Barcode_Search()
{
	int Grid_Col;

	AnsiString Str = "";

	Str = "select * from data where BARCODE like '%" + Data_Form->Barcode_Edit->Text + "%'";

	Sql_Data_Send(Str);

	Sql_Data_View();

	Data_Form->Search_Total_Count_Edit->Text = Main_Form->ADOQuery1->RecordCount;

	Data_Form->Search_Good_Count_Edit->Text = "";
	Data_Form->Search_Ng_Count_Edit->Text = "";
	Data_Form->Search_Good_Rate_Edit->Text = "";
	Data_Form->Search_Ng_Rate_Edit->Text = "";
}

void Sql_Info_Display(AnsiString Date)
{
	Data_Form->Time_Count_Chart->Series[0]->Clear();
	Data_Form->Good_Count_Chart->Series[0]->Clear();
	Data_Form->Ng_Count_Chart->Series[0]->Clear();
	Data_Form->Total_Count_Chart->Series[0]->Clear();
	Data_Form->Count_Chart->Series[0]->Clear();

	AnsiString Str;
	AnsiString Start_Date_Str, End_Date_Str;

	int Total_Count;

	int Count = 0;

	TDateTime Start_Date = StrToDateTime(Date);

	Start_Date_Str = Start_Date.DateTimeString();
	End_Date_Str = (Start_Date + 1).DateTimeString();

	for(int i = 0 ; i < Data_Form->Model_ComboBox->Items->Count ; i++)
	{
		Sql_Data_Send("select NO from data where MODEL_NAME = '" + Data_Form->Model_ComboBox->Items->Strings[i] + "' and RESULT = '양품' and TEST_TIME >= '" + Start_Date_Str + "' and TEST_TIME <= '" + End_Date_Str + "'");

		if(Main_Form->ADOQuery1->RecordCount)
			Data_Form->Good_Count_Chart->Series[0]->Add(Main_Form->ADOQuery1->RecordCount, Data_Form->Model_ComboBox->Items->Strings[i] + " ( " + IntToStr(Main_Form->ADOQuery1->RecordCount) + " )");
	}

	for(int i = 0 ; i < Data_Form->Model_ComboBox->Items->Count ; i++)
	{
		Sql_Data_Send("select NO from data where MODEL_NAME = '" + Data_Form->Model_ComboBox->Items->Strings[i] + "' and RESULT = '불량' and TEST_TIME >= '" + Start_Date_Str + "' and TEST_TIME <= '" + End_Date_Str + "'");

		if(Main_Form->ADOQuery1->RecordCount)
			Data_Form->Ng_Count_Chart->Series[0]->Add(Main_Form->ADOQuery1->RecordCount, Data_Form->Model_ComboBox->Items->Strings[i] + " ( " + IntToStr(Main_Form->ADOQuery1->RecordCount) + " )");
	}

	Sql_Data_Send("select NO from data where TEST_TIME >= '" + Start_Date_Str + "' and TEST_TIME <= '" + End_Date_Str + "'");
	if(Main_Form->ADOQuery1->RecordCount)
	{
		Data_Form->Total_Count_Chart->Series[0]->Add(Main_Form->ADOQuery1->RecordCount, "ALL ( " + IntToStr(Main_Form->ADOQuery1->RecordCount) + " )");
		Data_Form->Count_Chart->Series[0]->Add(0, "ALL ( " + IntToStr(Main_Form->ADOQuery1->RecordCount) + " )");
		Total_Count = Main_Form->ADOQuery1->RecordCount;
	}

	Sql_Data_Send("select NO from data where RESULT = '양품' and TEST_TIME >= '" + Start_Date_Str + "' and TEST_TIME <= '" + End_Date_Str + "'");
	if(Main_Form->ADOQuery1->RecordCount)
	{
		if(Total_Count)
			Str = Str.sprintf("GOOD ( %d  - %.2f %)", Main_Form->ADOQuery1->RecordCount, (double)Main_Form->ADOQuery1->RecordCount / (double)Total_Count * 100.);
		else
			Str = Str.sprintf("GOOD ( %d )", Main_Form->ADOQuery1->RecordCount);

		Data_Form->Total_Count_Chart->Series[0]->Add(Main_Form->ADOQuery1->RecordCount, Str, clLime);
		Data_Form->Count_Chart->Series[0]->Add(Main_Form->ADOQuery1->RecordCount, Str, clLime);
	}

	Sql_Data_Send("select NO from data where RESULT = '불량' and TEST_TIME >= '" + Start_Date_Str + "' and TEST_TIME <= '" + End_Date_Str + "'");
	if(Main_Form->ADOQuery1->RecordCount)
	{
		if(Total_Count)
			Str = Str.sprintf("N.G. ( %d  - %.2f %)", Main_Form->ADOQuery1->RecordCount, (double)Main_Form->ADOQuery1->RecordCount / (double)Total_Count * 100.);
		else
			Str = Str.sprintf("N.G. ( %d )", Main_Form->ADOQuery1->RecordCount);

		Data_Form->Total_Count_Chart->Series[0]->Add(Main_Form->ADOQuery1->RecordCount, Str, clRed);
		Data_Form->Count_Chart->Series[0]->Add(Main_Form->ADOQuery1->RecordCount, Str, clRed);
	}

	for(int j = 0 ; j < 24 ; j++)
	{
		Start_Date_Str = (Start_Date + (j * ONE_HOUR_TIME)).DateTimeString();
		End_Date_Str = (Start_Date + (j * ONE_HOUR_TIME + ONE_HOUR_TIME)).DateTimeString();

		Str = "select * from data where RESULT = '양품' and TEST_TIME >= '" + Start_Date_Str + "' and TEST_TIME <= '" + End_Date_Str + "'";

		Sql_Data_Send(Str);

		Count = Main_Form->ADOQuery1->RecordCount;

		Data_Form->Time_Count_Chart->Series[0]->AddXY(Start_Date.Val + ONE_HOUR_TIME * j, Count);
	}
}

void Sql_Data_View()
{
	AnsiString Str;
	AnsiString Data;
	int Grid_Col;
	int Max_Col = 0;

	Data_Form->Data_Grid->ColorRect(1, 1, Data_Form->Data_Grid->ColCount - 1, Data_Form->Data_Grid->RowCount - 1, clWhite);

	for(int i = 1 ; i < Data_Form->Data_Grid->ColCount ; i++)
	{
		for(int j = 1 ; j < Data_Form->Data_Grid->RowCount ; j++)
		{
			Data_Form->Data_Grid->Cells[i][j] = "";
		}
	}

	Data_Form->Data_Grid->RowCount = 2;

	if(Main_Form->ADOQuery1->RecordCount >= 1)
		Data_Form->Data_Grid->RowCount = Main_Form->ADOQuery1->RecordCount + 1;
	else
		return;


	for(int i = 0 ; i < Main_Form->ADOQuery1->RecordCount ; i++)
	{
		Grid_Col = 0;

		Data_Form->Data_Grid->Cells[Grid_Col++][i + 1] = i + 1;
		Data_Form->Data_Grid->Cells[Grid_Col++][i + 1] = Main_Form->ADOQuery1->FieldByName("MODEL_NAME")->AsString;
		Data_Form->Data_Grid->Cells[Grid_Col++][i + 1] = Main_Form->ADOQuery1->FieldByName("TEST_TIME")->AsString;
		Data_Form->Data_Grid->Cells[Grid_Col++][i + 1] = Main_Form->ADOQuery1->FieldByName("BARCODE")->AsString;

		Data_Form->Data_Grid->Cells[Grid_Col][i + 1] = Main_Form->ADOQuery1->FieldByName("RESULT")->AsString;
		if(Main_Form->ADOQuery1->FieldByName("RESULT")->AsString == "불량")
			Data_Form->Data_Grid->ColorRect(Grid_Col, i + 1, Grid_Col, i + 1, clRed);
		else
			Data_Form->Data_Grid->ColorRect(Grid_Col, i + 1, Grid_Col, i + 1, clWhite);
		Grid_Col++;

		Data = Main_Form->ADOQuery1->FieldByName("DATA")->AsString;
		while(true)
		{
			if(!Data.Pos("@"))
				break;

			Data_Form->Data_Grid->Cells[Grid_Col++][i + 1] = Data.SubString(1, Data.Pos("|") - 1);
			Data.Delete(1, Data.Pos("|"));
			Data_Form->Data_Grid->Cells[Grid_Col++][i + 1] = Data.SubString(1, Data.Pos("|") - 1);
			Data.Delete(1, Data.Pos("|"));
			Data_Form->Data_Grid->Cells[Grid_Col++][i + 1] = Data.SubString(1, Data.Pos("|") - 1);
			Data.Delete(1, Data.Pos("|"));
			Data_Form->Data_Grid->Cells[Grid_Col++][i + 1] = Data.SubString(1, Data.Pos("|") - 1);
			Data.Delete(1, Data.Pos("|"));

			Data_Form->Data_Grid->Cells[Grid_Col][i + 1] = Data.SubString(1, Data.Pos("@") - 1);
			if(Data.SubString(1, Data.Pos("@") - 1) == "N.G.")
				Data_Form->Data_Grid->ColorRect(Grid_Col, i + 1, Grid_Col, i + 1, clRed);
			else
				Data_Form->Data_Grid->ColorRect(Grid_Col, i + 1, Grid_Col, i + 1, clWhite);
			Grid_Col++;

			Data.Delete(1, Data.Pos("@"));

			if(!Data.Pos("@"))
				break;
		}


		if(Max_Col < Grid_Col)
			Max_Col = Grid_Col;

		Main_Form->ADOQuery1->Next();
	}
	Data_Form->Data_Grid->ColCount = Max_Col;

	Data_Form->Data_Grid->AutoSize = false;
	Data_Form->Data_Grid->AutoSize = true;
}

void Sql_Car_Load()
{
	AnsiString Str;

	Str = "select distinct CAR from model";

	Sql_Data_Send(Str);
}

void Sql_Car_Delete(AnsiString Car)
{
	AnsiString Str;

	Str = "delete from model where CAR = '" + Car + "' and NO != 0";

	Sql_Data_Send(Str);
}

void Sql_Car_Save(AnsiString Car)
{
	AnsiString Str;

	Str = "select * from model where CAR = '" + Car + "'";

	Sql_Data_Send(Str);

	if(Main_Form->ADOQuery1->RecordCount)
	{
		ShowMessage("Already registered.");
		return;
	}

	Str = "insert into model values ('0','" + Car + "','','','','','','','','','','','','','','0')";

	Sql_Data_Send(Str);
}

void Sql_Item_Load(AnsiString Car)
{
	AnsiString Str;

	Str = "select * from model where NO != 0 and CAR = '" + Car + "' order by MODEL_NAME asc";

	Sql_Data_Send(Str);
}

void Sql_Item_Delete(AnsiString Car, AnsiString Name)
{
	AnsiString Str;

	Str = "delete from model where CAR = '" + Car + "' and MODEL_NAME = '" + Name + "' and NO != 0";

	Sql_Data_Send(Str);
}

void Sql_Item_Save(AnsiString Car, AnsiString Name)
{
	AnsiString Str;
	AnsiString Data;
	AnsiString Value;

	//이미 아이템이 존재하는지 확인한다.
	Str = "select * from model where CAR = '" + Car + "' and MODEL_NAME = '" + Name + "'";
	Sql_Data_Send(Str);
	if(Main_Form->ADOQuery1->RecordCount)
	{
		switch(Application->MessageBoxA(L"The item is already registered. Do you want to update?", L"WARNING", MB_YESNO))
		{
			case ID_YES   :
				Sql_Item_Delete(Car, Name);
				break;
			case ID_NO   :
				return;
		}
	}

	Str = "";
	Str = "insert into model values ('0',";

	Str += "'";
	Str += Car;
	Str += "',";

	Str += "'";
	Str += Name;
	Str += "',";

	Data = "";
	//전류 데이터
	for(int i = 0 ; i < 4 ; i++)
	{
		if(Item.Gnd_Set[i])
			Data += "1,";
		else
			Data += "0,";
	}

	Str += "'";
	Str += Data;
	Str += "',";

	//Mux데이터
	for(int i = 0 ; i < 4 ; i++)
	{
		Data = "";

		for(int j = 0 ; j < MAX_ONOFF_COUNT ; j++)
		{
			if(Item.Signal_Set[i][j])
				Data += "1,";
			else
				Data += "0,";
		}

		Str += "'";
		Str += Data;
		Str += "',";
	}

	Data = "";
	for(int i = 0 ; i < MAX_ONOFF_COUNT ; i++)
	{
		if(Item.OnOff_Input_Set[i])
			Data += "1,";
		else
			Data += "0,";
	}

	Str += "'";
	Str += Data;
	Str += "',";

	Data = "";
	for(int i = 0 ; i < MAX_ONOFF_COUNT ; i++)
	{
		if(Item.OnOff_Input_Data[i])
			Data += "1,";
		else
			Data += "0,";
	}

	Str += "'";
	Str += Data;
	Str += "',";

	Data = "";
	for(int i = 0 ; i < MAX_ONOFF_COUNT ; i++)
	{
		if(Item.OnOff_Input_Set_2[i])
			Data += "1,";
		else
			Data += "0,";
	}

	Str += "'";
	Str += Data;
	Str += "',";

	Data = "";
	for(int i = 0 ; i < MAX_ONOFF_COUNT ; i++)
	{
		if(Item.OnOff_Input_Data_2[i])
			Data += "1,";
		else
			Data += "0,";
	}

	Str += "'";
	Str += Data;
	Str += "',";

	Data = Spec_Form->Min->Text;

	if(atof(Data.c_str()) < 0.1)
		Data = "0.0";

	Str += "'";
	Str += Data;
	Str += "',";

	Data = Spec_Form->Max->Text;
	if(atof(Data.c_str()) < 0.1)
		Data = "0.1";

	Str += "'";
	Str += Data;
	Str += "',";

	Data = Spec_Form->Input_Volt_Edit->Text;
	Str += "'";
	Str += Data;
	Str += "',";

	//CAN
	Data = "";

	Str += "'";
	Str += Item.TestType;
	Str += "')";

	Sql_Data_Send(Str);
}

void Sql_Item_Data_Load(AnsiString Car, AnsiString Name)
{
	AnsiString Str;
	AnsiString s;

	memset(&Item, 0, sizeof(Item));

	Str = "select * from model where CAR = '" + Car + "' and MODEL_NAME = '" + Name + "' order by MODEL_NAME asc";

	Sql_Data_Send(Str);

	if(Main_Form->ADOQuery1->RecordCount)
	{
		Str = Main_Form->ADOQuery1->FieldByName("GND")->AsString;
		for(int i = 0 ; i < 4 ; i++)
		{
			if(Str.SubString(1, 1) == "1")
				Item.Gnd_Set[i] = true;

			Str.Delete(1, Str.Pos(","));
		}

		for(int i = 0 ; i < 4 ; i++)
		{
			Str = Main_Form->ADOQuery1->FieldByName("SIGNAL_" + IntToStr(i + 1))->AsString;

			for(int j = 0 ; j < MAX_ONOFF_COUNT ; j++)
			{
				if(Str.SubString(1, 1) == "1")
					Item.Signal_Set[i][j] = true;

				Str.Delete(1, Str.Pos(","));
			}
		}

		Str = Main_Form->ADOQuery1->FieldByName("PULL_UP")->AsString;
		for(int i = 0 ; i < MAX_ONOFF_COUNT ; i++)
		{
			if(Str.SubString(1, 1) == "1")
				Item.OnOff_Input_Set[i] = true;

			Str.Delete(1, Str.Pos(","));
		}

		Str = Main_Form->ADOQuery1->FieldByName("PULL_UP_DATA")->AsString;
		for(int i = 0 ; i < MAX_ONOFF_COUNT ; i++)
		{
			if(Str.SubString(1, 1) == "1")
				Item.OnOff_Input_Data[i] = true;

			Str.Delete(1, Str.Pos(","));
		}

		Str = Main_Form->ADOQuery1->FieldByName("PULL_DN")->AsString;
		for(int i = 0 ; i < MAX_ONOFF_COUNT ; i++)
		{
			if(Str.SubString(1, 1) == "1")
				Item.OnOff_Input_Set_2[i] = true;

			Str.Delete(1, Str.Pos(","));
		}

		Str = Main_Form->ADOQuery1->FieldByName("PULL_DN_DATA")->AsString;
		for(int i = 0 ; i < MAX_ONOFF_COUNT ; i++)
		{
			if(Str.SubString(1, 1) == "1")
				Item.OnOff_Input_Data_2[i] = true;

			Str.Delete(1, Str.Pos(","));
		}

		Str = Main_Form->ADOQuery1->FieldByName("MIN")->AsString;
		Item.Min = atof(Str.c_str());
		Str = Main_Form->ADOQuery1->FieldByName("MAX")->AsString;
		Item.Max = atof(Str.c_str());
		Str = Main_Form->ADOQuery1->FieldByName("VOLT")->AsString;
		Item.Volt = atof(Str.c_str());

		Item.TestType = Main_Form->ADOQuery1->FieldByName("TEST_TYPE")->AsInteger;
	}
}

*/



