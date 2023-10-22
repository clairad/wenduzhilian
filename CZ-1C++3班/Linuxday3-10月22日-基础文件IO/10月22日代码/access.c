#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	if(access(argv[1], F_OK))
	{
		printf("文件不存在");
	}
	else
	{
		printf("文件存在");
	}

	return 0;
}
