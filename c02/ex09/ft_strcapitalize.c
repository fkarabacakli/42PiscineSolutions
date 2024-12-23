/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarabac <hkarabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:13:40 by hkarabac          #+#    #+#             */
/*   Updated: 2024/07/24 05:48:10 by hkarabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chr_islow(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_chr_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_chr_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	after_space;
	int	i;

	after_space = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (after_space && ft_chr_islow(str[i]))
			str[i] -= 32;
		else if (!after_space && ft_chr_isupper(str[i]))
			str[i] += 32;
		if (!ft_chr_is_alpha(str[i]))
			after_space = 1;
		else
			after_space = 0;
		i++;
	}
	return (str);
}
