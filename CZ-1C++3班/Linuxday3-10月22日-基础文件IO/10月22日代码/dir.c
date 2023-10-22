#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char path[256] = "path/";
	int len = strlen(path);
	DIR * fd = opendir(path);

	struct dirent * dirdata;


	dirdata	= readdir(fd);
	while(dirdata)
	{
		printf("%s\t", dirdata->d_name);
		if(dirdata->d_type == 8)
		{
			int fd = open(strcat(path, dirdata->d_name), O_WRONLY | O_APPEND);
			write(fd, path, strlen(path));
			close(fd);
			path[len] = 0;
		}
		dirdata	= readdir(fd);
	}
	putchar(10);
	
	
	/*printf("d_ino:%d\nd_off:%d\nd_reclen:%d\nd_type:%c\nd_name:%s\n", 
		dirdata->d_ino,
		dirdata->d_off,
		dirdata->d_reclen,
		dirdata->d_type,
		dirdata->d_name);*/

	closedir(fd);
	return 0;
;}
