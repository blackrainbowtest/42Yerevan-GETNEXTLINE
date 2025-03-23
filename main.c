#include "get_next_line.h"

/*
* main.c tests the get_next_line function
*/

int main(void)
{
    char *line;
	int maxCount = 5;
    int fd1 = open("test_file1.txt", O_RDONLY);
    int fd2 = open("test_file2.txt", O_RDONLY);
    int fd3 = open("test_file3.txt", O_RDONLY);
    
    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        perror("Error opening file");
        return (1);
    }

    printf("Reading from test_file1.txt:\n");
    while ((line = get_next_line(fd1)) != NULL && maxCount-- > 0)
    {
        printf("%s", line);
		// printf("\n%p\n", line);
        free(line);
    }
    close(fd1);
    printf("\n.\n");
	maxCount = 9;
    printf("\nReading from test_file2.txt:\n");
    while ((line = get_next_line(fd2)) != NULL && maxCount-- > 0)
    {
        printf("%s", line);
        // printf("maxCount: %d\n", maxCount);
        free(line);
    }
    close(fd2);

    // printf("\n.\n");
    maxCount = 3;
    printf("\nReading from test_file3.txt:\n");
    while ((line = get_next_line(fd3)) != NULL && maxCount-- > 0)
    {
        printf("%d", maxCount);
        printf("%s", line);
        free(line);
    }
    close(fd3);

    return (0);
}