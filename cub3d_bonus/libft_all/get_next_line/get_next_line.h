/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:52:13 by ubuntu            #+#    #+#             */
/*   Updated: 2024/06/26 19:01:14 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libtf/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void					*ft_str_calloc(size_t elementCount);
char					*get_next_line(int fd);
char					*ft_strncpy(char *dest, char *src, int size);
char					*ft_strjoin_free(char *s1, char *s2);
int						ft_str_return(char *str);

typedef unsigned char	t_byte;

#endif