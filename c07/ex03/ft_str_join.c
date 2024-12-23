/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarabac <hkarabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:15:35 by hkarabac          #+#    #+#             */
/*   Updated: 2024/07/25 12:59:12 by hkarabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_len(int size, char **str, char *sep)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j] != '\0')
			j++;
		count += j;
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	count += i * (size - 1);
	return (count);
}

char	*ft_str_cpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	char	*str;
	char	*d;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	len = count_len(size, strs, sep);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	d = str;
	while (i < size)
	{
		str = ft_str_cpy(str, strs[i]);
		if (i != size - 1)
			str = ft_str_cpy(str, sep);
		i++;
	}
	*str = '\0';
	return (d);
}
