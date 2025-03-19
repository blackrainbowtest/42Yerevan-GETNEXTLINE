#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	
	if (argc < 2) 
	{
		printf("Usage: %s <filename> ...\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	printf("%p\n", line);
	while (line)
	{
		printf("%s\n\n", "test");
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
