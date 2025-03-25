#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    printf("%d", BUFFER_SIZE);
    if (fd < 0)
    {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Получено: %s", line);
        free(line);
    }
    
    close(fd);
    return 0;
}