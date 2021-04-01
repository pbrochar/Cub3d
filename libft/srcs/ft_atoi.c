/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:05:00 by pbrochar          #+#    #+#             */
/*   Updated: 2020/11/19 20:20:13 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				s;
	long int		nbr;

	nbr = 0;
	s = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			s *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (nbr * s < -2147483648 || nbr * s > 2147483647)
			return (s < 0 ? 0 : -1);
		nbr = (nbr * 10) + (*nptr - '0');
		nptr++;
	}
	return ((int)nbr * s);
}
