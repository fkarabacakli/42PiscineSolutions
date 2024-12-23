/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarabac <hkarabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:14:30 by hkarabac          #+#    #+#             */
/*   Updated: 2024/07/17 18:22:18 by hkarabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	odd;
	int	count;

	count = 0;
	odd = 1;
	while (nb > 0)
	{
		nb -= odd;
		odd += 2;
		count++;
	}
	if (nb == 0)
		return (count);
	return (0);
}
