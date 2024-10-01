/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:30:11 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/05/16 16:46:52 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_prtstr(char *s);
int	ft_prtchr(char c);
int	ft_prtnbr(int n);
int	ft_prthexlo(unsigned int n);
int	ft_prthexup(unsigned int n);
int	ft_prtptr(unsigned long n);
int	ft_prtunbr(unsigned int n);
int	ft_printf(const char *format, ...);

#endif
