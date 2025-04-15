/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurgaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:46:23 by gurgaspa          #+#    #+#             */
/*   Updated: 2025/04/15 17:42:55 by gurgaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdio.h>

char	*ft_strjoin(char *s, char *d);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_find_line(char *ptr);
char	*ft_save_line(char *set);
char	*get_next_line(int fd);
char	*read_stroke(int fd, char *store);

#endif
