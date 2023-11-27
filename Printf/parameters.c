/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loosorio <loosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:28:58 by loosorio          #+#    #+#             */
/*   Updated: 2023/11/27 19:44:13 by loosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_params_s(char *s)
{
	int	i;
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	count = 0;
	while (s[i])
		count += write (1, &s[i++], 1);
	return (count);
}

int	ft_params_d_i(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2", 2);
		count += write(1, "147483648", 9);
	}
	else if (n < 0)
	{
		count += write (1, "-", 1);
		count += ft_params_d_i(-n);
	}
	else if (n > 9)
	{
		count += ft_params_d_i(n / 10);
		count += ft_params_d_i(n % 10);
	}
	else
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_params_u(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_params_u(n / 10);
		count += ft_params_u(n % 10);
	}
	else 
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_params_x(unsigned int n, char c)
{
	char	*str;
	int		count;

	if (c == 'X')
		str = "0123456789ABCDEF";
	else if (c == 'x')
		str = "0123456789abcdef";
	count = 0;
	if (n > 15)
	{
		count += ft_params_x(n / 16, c);
		count += ft_params_x(n % 16, c);
	}
	else
		count += write(1, &str[n], 1);
	return (count);
}
