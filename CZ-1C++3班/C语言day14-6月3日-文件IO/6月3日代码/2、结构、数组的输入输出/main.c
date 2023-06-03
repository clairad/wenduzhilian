#include <stdio.h>

typedef struct {
	double a;
	int b;
	char c;
	char d : 3;
	char e : 5;
	short f;
	char str[8];
}Test;

int main()
{
	FILE* pf = fopen("s.txt", "wb+");
#if 0 //结构体
	Test t = { 3.14, 1, 2, 3, 4, 5, "abcdefg" };
	fwrite(&t, 1, sizeof(Test), pf);
	fflush(pf);

	Test t2;
	rewind(pf);
	fread(&t2, 1, sizeof(Test), pf);
	printf("%lf %d %d %d %d %d %s",
		t2.a, t2.b, t2.c, t2.d, t2.e, t2.f, t2.str);
#elif 0 //数组
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	fwrite(arr, 10, sizeof(int), pf);
	fflush(pf);

	int arr1[10];
	rewind(pf);
	fread(arr1, 10, sizeof(int), pf);
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
#else 
	Test arrt[3] = {    {3.14, 1, 2, 3, 4, 5, "abcdefg"},
						{6.28, 2, 4, 8, 10,12,"hijklmn"},
						{10.1, 3, 4, 6, 8, 9, "opqrst"}};
	fwrite(arrt, 3, sizeof(Test), pf);
	fflush(pf);

	Test arrt2[3];
	rewind(pf);
	fread(arrt2, 3, sizeof(Test), pf);
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("%lf %d %d %d %d %d %s\n",
			arrt[i].a, arrt[i].b, arrt[i].c, arrt[i].d, arrt[i].e, arrt[i].f, arrt[i].str);
	}
	
#endif
	fclose(pf);
	return 0;
}
