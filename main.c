#include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    if (fd < 0)
    {
        printf("file open error\n");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("get: %s", line);
        free(line);
    }
    
    close(fd);
    return 0;
}