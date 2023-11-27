/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loosorio <loosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:45:57 by loosorio          #+#    #+#             */
/*   Updated: 2023/11/27 19:39:27 by loosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specifires(char c, va_list *ap)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_params_c(va_arg(*ap, int)));
	if (c == 's')
		return (ft_params_s(va_arg(*ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_params_d_i(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_params_u(va_arg(*ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_params_x(va_arg(*ap, unsigned int), c));
	if (c == 'p')
		return (ft_params_p(va_arg(*ap, unsigned long), 0));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, &str[i], 1);
		else
			count += ft_specifires(str[++i], &ap);
		i++;
	}
	va_end(ap);
	return (count);
}
