/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:54:29 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/05/20 19:20:41 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen2(const char *s);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_read_and_check(char *buffer, unsigned int size, int fd);
int		ft_okspollish(char *buffer);
char	*get_next_line(int fd);
#endif
