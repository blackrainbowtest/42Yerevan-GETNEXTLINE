#include "get_next_line.h"

/*
* int file descriptor
* return (char *)
*/
char	*get_next_line(int fd)
{
	ssize_t	bts_rd;
	static t_list	*p_head;

	bts_rd = read(0, buffer, 0);
	if (bts_rd == -1)
		return (NULL);

}
