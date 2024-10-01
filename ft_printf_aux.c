/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:18:47 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/05/18 14:19:52 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prtnbr(int n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = 0;
	if (n == 0)
		return (ft_prtchr('0'));
	if (nbr < 0)
	{
		len += ft_prtchr('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_prtnbr(nbr / 10);
	len += ft_prtchr(nbr % 10 + '0');
	return (len);
}

int	ft_prthexlo(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_prthexlo(n / 16);
	len += ft_prtchr("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_prthexup(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_prthexup(n / 16);
	len += ft_prtchr("0123456789ABCDEF"[n % 16]);
	return (len);
}

int	ft_prtptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len = ft_prtstr("(nil)");
		return (len);
	}
	if (n >= 16)
		len += ft_prtptr(n / 16);
	if (len == 0)
		len += ft_prtstr("0x");
	len += ft_prtchr("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_prtunbr(unsigned int n)
{
	short	len;

	len = 0;
	if (n == 0)
		return (ft_prtchr('0'));
	if (n >= 10)
		len += ft_prtunbr(n / 10);
	len += ft_prtchr(n % 10 + '0');
	return (len);
}
