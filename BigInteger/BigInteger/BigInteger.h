typedef unsigned short int un_short;
typedef unsigned long int un_long;

struct MBigInt
{
	int alloclen;
	int length;
	int sign;
	un_short *pBigInt;
};


#define BIT_PER_WORD 16;
#define INITIAL_BINT 49;
#define STEP_BINT 16;

int initMBInt(MBigInt *mbi,int size);
void deleteMBInt(MBigInt *mbi);
int extendMBInt(MBigInt *mbi, int size);
int trimMBInt(MBigInt *mbi);
int addMBInt1(MBigInt * dst, MBigInt *src1, MBigInt *src2);
int mp_add_d(MBigInt *mbi, int y);
int mp_mul_d(MBigInt *mbi, int radix);
int read_radix(MBigInt *a, const char *str);
int write_radix(MBigInt *a, char *str);
void assignMBInt(MBigInt *src1, MBigInt *src2);
int mulBasicMBInt(MBigInt *product, MBigInt *biA, MBigInt *biB);
void setZeroMBInt(MBigInt *mbi);
void trimLeft(char *str);
int compareMBInt(MBigInt *a, MBigInt *b);
int Left_shift_word(MBigInt *dst, int n);
int addMBInt2(MBigInt *dst, MBigInt *src1, MBigInt *src2);
int divMBInt(MBigInt *a, MBigInt *b, MBigInt *c, MBigInt *d);
void reverse_char(char *str);