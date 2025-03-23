#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
* main.c tests the get_next_line function
*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        char *line;
        int maxCount = 5;
        int fd = open(argv[i], O_RDONLY);

        if (fd == -1)
        {
            perror("Error opening file");
            continue;
        }

        printf("Reading from %s:\n", argv[i]);
        while ((line = get_next_line(fd)) != NULL && maxCount-- > 0)
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
        printf("\n...EOF...\n");
    }

    return (0);
}