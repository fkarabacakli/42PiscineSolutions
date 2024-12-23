/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarabac <hkarabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:15:32 by hkarabac          #+#    #+#             */
/*   Updated: 2024/07/25 12:50:45 by hkarabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*tab;
	int	i;

	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
	{
		*range = 0;
		return (-1);
	}
	*range = tab;
	i = 0;
	while (i < len)
		tab[i++] = min++;
	return (len);
}
