#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd = open("1.txt", O_RDWR | O_CREAT, 0644);
	
	write(fd, "Hello, world!\n", 14);

	lseek(fd, 0, SEEK_SET);

	char buf[64] = "";
	read(fd, buf, 63);

	puts(buf);
	close(fd);

	return 0;
}
