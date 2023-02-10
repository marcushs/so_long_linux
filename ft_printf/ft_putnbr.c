/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:53:38 by hleung            #+#    #+#             */
/*   Updated: 2022/11/21 18:47:22 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int				len;
	unsigned int	nbr;

	nbr = n;
	len = 0;
	if (n < 0)
	{
		len++;
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	len += ft_putchar(nbr % 10 + '0');
	return (len);
}
