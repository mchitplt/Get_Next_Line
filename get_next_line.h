/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mupolat <mupolat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:47:25 by mupolat           #+#    #+#             */
/*   Updated: 2023/01/28 21:14:44 by mupolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include   <stdlib.h>
# include   <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		ft_strchr(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strcpy(char *s1, char *s2, int n);
char	*get_next_line(int fd);

#endif