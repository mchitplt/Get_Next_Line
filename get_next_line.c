/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mupolat <mupolat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:30:44 by mupolat           #+#    #+#             */
/*   Updated: 2023/01/28 22:07:37 by mupolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_read_file(int fd, char *sts)
{
	int		check;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	check = 1;
	while (check != 0 && (!ft_strchr(sts)))
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[check] = '\0';
		sts = ft_strjoin(sts, buff);
	}
	free(buff);
	return (sts);
}

char	*ft_before_next_line(char	*sts)
{
	char	*to_return;
	int		i;

	i = 0;
	if (!sts[i])
		return (NULL);
	while (sts[i] && sts[i] != '\n')
		i++;
	to_return = malloc(sizeof(char) *(i + 2));
	if (!to_return)
		return (NULL);
	ft_strcpy(to_return, sts, i + 1);
	return (to_return);
}

char	*ft_new_line(char	*sts)
{
	char	*to_return;
	int		i;

	i = 0;
	if (!sts)
		return (NULL);
	while (sts[i] && sts[i] != '\n')
		i++;
	if (!sts[i])
	{
		free(sts);
		return (NULL);
	}
	to_return = malloc(sizeof(char) * (ft_strlen(sts) - i + 1));
	if (!to_return)
		return (NULL);
	i++;
	ft_strcpy(to_return, sts + i, ft_strlen(sts + i));
	free (sts);
	return (to_return);
}

char	*get_next_line(int fd)
{
	static char	*sts;
	char		*to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sts = ft_read_file(fd, sts);
	if (!sts)
		return (NULL);
	to_return = ft_before_next_line(sts);
	sts = ft_new_line(sts);
	return (to_return);
}
