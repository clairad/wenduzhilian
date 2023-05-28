#include <stdio.h>

int main()
{
	FILE* fp = fopen("1.txt", "w");
	fprintf(fp, "jioaniooenoivne");
	fclose(fp);

	char str[64] = "";
	FILE* fpr = fopen("1.txt", "r");
	fscanf(fpr, "%s", str);
	fclose(fpr);

	puts(str);
	return 0;
}
