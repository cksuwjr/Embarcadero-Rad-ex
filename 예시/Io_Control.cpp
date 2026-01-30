//---------------------------------------------------------------------------
#include <vcl.h>                // Visual Component Library
#pragma hdrstop                 // 프리컴파일에 적합한 헤더 파일의 목록을 종료시키는데, 이것을
								// 사용하면 프리컴파일된 헤더가 사용하는 디스크 공간의 양을 줄일 수 있습니다

#include "Io_Control.h"
#include "var.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)     // 패키지된 유닛들이 의존할 순서를 결정하기 위해 초기화

int Card_7230;                  // 카드 7230 PCI - 7230 (ADLINK)

// Io 초기화
void Io_Init()
{
	Card_7230 = -1;				// 카드 비 초기화상태(-1)

#if !PROGRAM_TEST                            // PROGRAM_TEST 가 0이면 실행 1이면 비실행
	Card_7230 = Register_Card(PCI_7230, 0);  // 카드 값 초기화 (0)

	if(Card_7230 < 0)
	{
		ShowMessage("PCI_7230 카드 초기화 실패");
		return;
	}

	Output_Init();
#endif
}

void Io_Close()                 //   I/O 보드 사용을 끝낼 때 호출하는 종료(해제) 함수
{
#if !PROGRAM_TEST
	Output_Init();              //  결과 초기화

	Release_Card(Card_7230);    //  I/O 보드를 완전히 해제하는 “최종 정리” 함수
#endif
}

void Input_Check()              //  입력체크
{
#if !PROGRAM_TEST
	U32     DIValue = 0x00;     //  디지털 입력 값 변수

	if(Card_7230 >= 0)
		DI_ReadPort(Card_7230, 0, &DIValue);

	// 카드가 초기화되어있으면
	// Digital 출력(O) 포트에 값을 실제로 써주기
	// Do_WritePort(보드번호, DO 포트 번호, 출력할 비트값=DoValue)

	for(int i = 0 ; i < MAX_INPUT_COUNT ; i++)
	{
		if(DIValue & 0x01 << i)                     // DiValue & ( 0x01 << i)  => i번째 비트만 마스킹해서 결과 보기, 값에 따라(=0이냐) tf
			Input_Data[i] = true;
		else
			Input_Data[i] = false;
	}
#endif
}

void Output_Init()      // 결과값 초기화
{
#if !PROGRAM_TEST

	// 메모리 세팅 (세팅할 메모리 주소 값, 초기화값, 길이(보통 SizeOf로 적음))
	memset(&Output_Data, 0, sizeof(Output_Data));

	Output_Io();
#endif
}

void Output_Io()       // 결과값 입력
{
	U32 DoValue = 0x00;          // 디지털 출력값 변수

	for(int i = 0 ; i < MAX_OUTPUT_COUNT ; i++)
	{
		if(Output_Data[i])
			DoValue |= 0x01 << i;
			// Output_Data[i]가 초기화된 상태면 DoValue = DoValue | (0x01 << i);
			// 1. 이진수로 0000 0001 를 왼쪽으로 i 비트 이동( << i)
			// i = 0 => 0000 0001 = 0x01
			// i = 1 => 0000 0010 = 0x02
			// i = 2 => 0000 0100 = 0x04

			// 2. DoValue |= mask;
			// 기존 DoValue 값 유지하면서 해당 비트만 1로 켠다 (1이면 그대로 1 아니고 0이면 1로)

			// 결론 : 이 함수는 DoValue를 Output_Data[i]가 초기화되었으면 각 값마다 1로 만들어주는것
	}

#if !PROGRAM_TEST
	if(Card_7230 >= 0)                            // 카드가 초기화되어있으면
		DO_WritePort(Card_7230, 0, DoValue);      // Digital 출력(O) 포트에 값을 실제로 써주기
												  // Do_WritePort(보드번호, DO 포트 번호, 출력할 비트값=DoValue)
#endif
}

bool Output_Process(int Output_Number, bool OnOff)    //  출력과정
{
	Input_Check();                                    // 입력 체크=> 출력데이터 bool배열입력(0,1) =>결과 입력

	switch(Output_Number)
	{

	}

	Output_Data[Output_Number] = OnOff;

	Output_Io();

	return true;
}
