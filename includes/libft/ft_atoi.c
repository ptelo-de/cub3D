/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:07:28 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/10/23 20:01:12 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = 10 * nb + (nptr[i] - 48);
		i++;
	}
	return (nb * sign);
}
// calculates the number an atribute can be translated
// does not allow buffer overflow or returning the number
// if trash values follow the digit part.

static void	ft_atoi_error(void)
{
	ft_putstr_fd("error in atoi2", 2);
	exit(1);
}

int	ft_atoi2(const char *nptr, int i, int sign)
{
	long long	nb;

	nb = 0;
	if (!nptr[0])
		ft_atoi_error();
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-') && nptr[i + 1] != 0)
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		if (nb * 10 < nb)
			ft_atoi_error();
		nb = 10 * nb + (nptr[i] - 48);
		i++;
	}
	nb = nb * sign;
	if ((nptr[i] != 0 && nptr[i] != '\n' && nptr[i] != ',') || nb > 2147483647
		|| nb < -2147483648)
		ft_atoi_error();
	return (nb);
}
