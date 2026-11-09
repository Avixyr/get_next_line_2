#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*s1;

	fd = open("test",O_RDONLY);
	s1 = get_next_line(fd);
	printf("[%s]",s1);
	free(s1);
	s1 = get_next_line(fd);
	printf("[%s]",s1);
	free(s1);
	// s1 = get_next_line(fd);
	// printf("[%s]",s1);
	// free(s1);
	close(fd);
}