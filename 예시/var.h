#ifndef varH
#define varH                       // 만약 varH가 정의 안되어있으면 지금부터 정의하기.

#include <stdio.h>                 // 입출력 라이브러리
#include <stdlib.h>                // 메모리, 유틸 malloc 사용 위한 라이브러리
#include <dos.h>                   // 인테럽트, 시간 함수
#include <sys/stat.h>              // 파일 정보
#include <fcntl.h>                 // 파일 옵션
#include <io.h>                    // 저수준 I/O 입출력
#include <math.h>                  // 수학
#include <process.h>               // 프로세스
#include <string>                  // 문자열
#include <iostream.h>              // 입출력 헤더파일
#include <dir.h>                   // 디렉토리
#include <winsock2.h>              // 네트워크
#include "IniFiles.hpp"            // INI 설정

#include "main.h"                  // 그 외 직접만든 헤더파일들
#include "spec.h"
#include "data.h"
#include "system.h"

#include "Sql.h"                   // DB처리 모듈
#include "Common.h"
#include "Password.h"
#include "Barcode.h"
#include "Dask.h"
#include "Io_Control.h"
								   // 사용자 정의 값
#define PROGRAM_TITLE               	"KA4 CPAD BARCODE PROGRAM"

#define PROGRAM_TEST					0

#define SPEC_PATH                   	"C:\\KA4 CPAD BARCODE\\SPEC\\"
#define LOG_PATH                    	"C:\\KA4 CPAD BARCODE\\DATA\\"
#define SYSTEM_FILE                 	"C:\\KA4 CPAD BARCODE\\SYSTEM\\System.ini"
#define COUNT_FILE						"C:\\KA4 CPAD BARCODE\\SYSTEM\\Count.ini"

#define ONE_HOUR_TIME					0.041667388025		// 1시간
#define ONE_SECOND_TIME					1.1574274451388888888888888888889e-5		// 1초

#define DELAY_TIME						1000

#define ON 								1
#define OFF                             0
#define MAX_INPUT_COUNT					16                          // 핀이 32개니까 I 16 O 16
#define MAX_OUTPUT_COUNT				16

// INPUT
#define INPUT_BTN_1						1
#define INPUT_BTN_2 					2

// OUTPUT
#define OUTPUT_BTN_LIGHT_1				0
#define OUTPUT_BTN_LIGHT_2              1

#define ONE	0
#define SET	1

// STEP
enum
{
	STEP_INIT = 0,
	STEP_PRINT_ONE,
	STEP_PRINT_SET,
	STEP_PRINT_SET_DELAY,
	STEP_END
};

#define TEST_DEFAULT_DELAY_TIME			500
#define TEST_SENSOR_CHECK_TIME			5000

#define NO_TEST							0
#define TEST_OK							1
#define TEST_NG							2

typedef struct __BARCODE_SPEC__{

	char	Company[100];
	char	Part_Number[100];
	char	Alc[100];
	char	Eo[100];
	char	Product_4M[100];
	char	Lot[100];
	char	Reserve[100];

}__BARCODE_SPEC;

extern bool 			Printing;
extern int  			Print_Step;
extern DWORD 			Print_Delay_Time;

extern __BARCODE_SPEC	Barcode_Spec;

extern bool 			Input_Data[MAX_INPUT_COUNT];
extern bool 			Output_Data[MAX_OUTPUT_COUNT];
#endif
