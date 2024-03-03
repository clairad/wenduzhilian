#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "cpfile.h"

int copy_dir(const char * dirread, const char * dirwrite)
{
	DIR * fdr = opendir(dirread);
	int ret = mkdir(dirwrite, 0755);
	if(ret < 0 || fdr == NULL)
	{
		return -1;
	}

	struct dirent * dirdata;

	char rdfile[256] = "";
	char wrfile[256] = "";
	strcpy(rdfile, dirread);
	strcpy(wrfile, dirwrite);
	int lenrd = strlen(rdfile);
	int lenwr = strlen(wrfile);
	if(rdfile[lenrd - 1] != '/')
	{
		rdfile[lenrd] = '/';
		lenrd++;
	}
	if(wrfile[lenwr - 1] != '/')
	{
		wrfile[lenwr] = '/';
		lenwr++;
	}

	dirdata	= readdir(fdr);
	while(dirdata)
	{
		if(dirdata->d_type == 8)
		{
			copy_file(
				strcat(rdfile, dirdata->d_name),
				strcat(wrfile, dirdata->d_name)
			);
			rdfile[lenrd] = 0;
			wrfile[lenwr] = 0;
		}
		dirdata	= readdir(fdr);
	}

	closedir(fdr);
	return 0;
}

int main(int argc, const char * argv[])
{
	int ret = copy_dir(argv[1], argv[2]);
	if(ret < 0)
	{
		perror("error");
	}

	return 0;
}
