/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:58:41 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/05/28 11:48:15 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prtchr(char c)
{
	return (write(1, &c, 1));
}

int	ft_prtstr(char *s)
{
	int	i;
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	len = 0;
	while (s[i])
		len += write(1, &s[i++], 1);
	return (len);
}

static int	ft_prefs(const char *frmt, va_list arg_ptr)
{
	int	len;

	if (*frmt == 'c')
		len = ft_prtchr(va_arg(arg_ptr, int));
	else if (*frmt == 's')
		len = ft_prtstr(va_arg(arg_ptr, char *));
	else if (*frmt == 'p')
		len = ft_prtptr(va_arg(arg_ptr, unsigned long));
	else if (*frmt == 'd' || *frmt == 'i')
		len = ft_prtnbr(va_arg(arg_ptr, int));
	else if (*frmt == 'u')
		len = ft_prtunbr(va_arg(arg_ptr, unsigned int));
	else if (*frmt == 'x')
		len = ft_prthexlo(va_arg(arg_ptr, unsigned int));
	else if (*frmt == 'X')
		len = ft_prthexup(va_arg(arg_ptr, unsigned int));
	else if (*frmt == '%')
		len = ft_prtchr('%');
	else
		len = -1;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		tmp_len;
	va_list	arg_ptr;

	len = 0;
	if (!format)
		return (-1);
	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format != '%')
			len += ft_prtchr (*format);
		else if (*format == '%')
		{
			format++;
			tmp_len = ft_prefs(format, arg_ptr);
			if (tmp_len == -1)
				return (-1);
			else
				len += tmp_len;
		}
		format++;
	}
	va_end(arg_ptr);
	return (len);
}

/* int main (void)
{
	ft_printf("\n-- TEST 1: mixed string ------------------------------\n");
	char			*str = "%i H%cugo %s %x D%%ias %p %p";
	char			*st = "Miguel";
	char			c = 'y';
	
	int				*nl = NULL; 
	
	int				y = 1980;
	unsigned int 	ux = 4294967295;
	int 			x = 012;
	int 			*ptr_x;
	
	ptr_x = &x;

	ft_printf("\nlen ft_printf: %d\n", ft_printf (str, y, c, st, ux, nl, ptr_x));
	ft_printf("\n");
	printf ("\nlen printf: %d\n", printf(str, y, c, st, ux, nl, ptr_x));
	ft_printf("------------------------------------------------------\n\n");

	ft_printf("\n-- TEST 2: printf(NULL) ------------------------------\n");
	printf("printf result: %d\n", printf(NULL));	
	printf("\nft_printf result: %d\n", ft_printf(NULL));
	ft_printf("------------------------------------------------------\n\n");

	ft_printf("\n-- TEST 3: invalid fs --------------------------------\n");
	int printf_result;
	int ft_printf_result;
	printf("Printf:\n");
	printf_result = printf("%");
	printf("\nFt_printf:\n");
	ft_printf_result = ft_printf("%");
	printf("\nresultado printf: %d, resultado ft_printf: %d\n", printf_result,
	 ft_printf_result);
	ft_printf("------------------------------------------------------\n");
	return (0);
}
 */
