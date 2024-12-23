/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarabac <hkarabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:23:35 by hkarabac          #+#    #+#             */
/*   Updated: 2024/07/23 18:44:51 by hkarabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_base(char *str, int i)
{
	int	len;
	int	j;

	len = ft_strlen(str);
	if (len - i <= 1)
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

int	ft_atoi_number(char *str, char *base, int i)
{
	int	len;
	int	number;
	int	k;

	number = 0;
	len = ft_strlen(base);
	while (str[i] != '\0')
	{
		k = 0;
		while (1)
		{
			if (str[i] == base[k])
				break ;
			if (base[k] == '\0')
				return (number);
			k++;
		}
		number *= len;
		number += k;
		i++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	minus = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	if (!check_base(base, 0))
		return (0);
	return (minus * ft_atoi_number(str, base, i));
}
