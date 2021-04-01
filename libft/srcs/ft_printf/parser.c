/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:41:22 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/02 12:16:49 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	pf_istype(char c)
{
	int		i;
	char	*type;

	type = "xXpdisc%u";
	i = 0;
	while (type[i])
	{
		if (type[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	pf_isflag(char c)
{
	int		i;
	char	*flag;

	flag = "0";
	i = 0;
	while (flag[i])
	{
		if (flag[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
