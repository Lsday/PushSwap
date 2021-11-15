/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:00:47 by oronda            #+#    #+#             */
/*   Updated: 2021/11/15 17:49:59 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	nb;
	int		signe;

	nb = 0;
	signe = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe *= -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (999999999999);
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = 10 * nb + (*nptr - '0');
		nptr++;
	}
	return ((long)(nb * signe));
}
