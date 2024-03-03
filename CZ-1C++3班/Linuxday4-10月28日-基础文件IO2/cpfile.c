#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int copy_file(const char * readfname, const char * writefname)
{
	int fdr = open(readfname, O_RDONLY);
	int fdw = open(writefname, O_WRONLY | O_CREAT, 0644);
	if(fdr < 0 || fdw < 0)
	{
		return -1;
	}
	
	char buf[1024];

	int len = read(fdr, buf, sizeof(buf));
	while(len)
	{
		write(fdw, buf, len);
		len = read(fdr, buf, sizeof(buf));
	}

	close(fdr);
	close(fdw);

	return 0;
}
