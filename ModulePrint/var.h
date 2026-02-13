#ifndef varh
#define varh



#define ONE	0
#define SET	1

#define DELAY_TIME 1000

#define COUNT_FILE "C:\\Users\\user\\Desktop\\DataExercise\\Count.ini"


enum
{
	STEP_INIT = 0,
	STEP_PRINT_ONE,
	STEP_PRINT_SET,
	STEP_PRINT_SET_DELAY,
	STEP_END
};


typedef struct __Barcode_SPEC__
{
	char Company[100];
	char Part_Number[100];
	char Alc[100];
	char Eo[100];
	char Product_4M[100];
	char Lot[100];
	char Reserve[100];
}__BARCODE_SPEC;

#endif
