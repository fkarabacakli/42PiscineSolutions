/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarabac <hkarabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:40:55 by hkarabac          #+#    #+#             */
/*   Updated: 2024/07/23 18:50:03 by hkarabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_chr(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_base(char *str)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(str);
	if (len <= 1)
		return (0);
	while (i < len)
	{
		if (!check_chr(str[i]))
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_number(int nbr, char *base, int len)
{
	long int	min;

	min = nbr;
	if (min < 0)
	{
		write(1, "-", 1);
		min *= -1;
	}
	if (min >= len)
		print_number(min / len, base, len);
	write(1, &base[min % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	if (check_base(base))
	{
		len = ft_strlen(base);
		print_number(nbr, base, len);
	}
}
