/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarabac <hkarabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:43:24 by hkarabac          #+#    #+#             */
/*   Updated: 2024/07/24 06:08:57 by hkarabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(int i)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[i]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] <= 126 && str[i] >= 32))
		{
			ft_putchar('\\');
			ft_print_hex(str[i] / 16);
			ft_print_hex(str[i] % 16);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}
