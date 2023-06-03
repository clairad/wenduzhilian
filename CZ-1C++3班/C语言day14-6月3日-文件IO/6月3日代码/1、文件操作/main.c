#include <stdio.h>

int main()
{
#if 0 //两个指针
	FILE* pfw = fopen("1.txt", "w");
	FILE* pfr = fopen("1.txt", "r");
	
	int i = 65;
	fwrite(&i, sizeof(int), 1, pfw);
	fflush(pfw);
	int j;
	fread(&j, sizeof(int), 1, pfr);
	printf("%d", j);
	fclose(pfw);
	fclose(pfr);
#else //一个指针
	FILE* pf = fopen("1.txt", "w+");

	int i = 68;
	fwrite(&i, sizeof(int), 1, pf);
	fflush(pf);

	//rewind(pf);
	//fseek(pf, 0, SEEK_SET);
	fseek(pf, -(int)sizeof(int), SEEK_CUR);
	//fseek(pf, -(int)sizeof(int), SEEK_END);
	int j;
	fread(&j, sizeof(int), 1, pf);
	fseek(pf, 0, SEEK_END);
	printf("%d %d %d", j, ftell(pf), feof(pf));
	if (feof(pf))
	{
		printf(" 是文件末尾");
	}

	fclose(pf);
#endif
	return 0;
}
