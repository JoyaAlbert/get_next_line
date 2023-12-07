#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDONLY);
	for(int i = 0; i < 7; i++)
		printf("%s\n", get_next_line(fd));
}
