/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loosorio <loosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:50:27 by loosorio          #+#    #+#             */
/*   Updated: 2023/11/27 19:40:41 by loosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params_p(unsigned long n, int i)
{
	int		count;
	char	*str;

	count = 0;
	if (n == 0 && i == 0)
		return (write(1, "(nil)", 5));
	str = "0123456789abcdef";
	if (i == 0)
		count += write(1, "0x", 2);
	if (n > 15)
	{
		count += ft_params_p(n / 16, 1);
		count += ft_params_p(n % 16, 1);
	}
	else
		count += write(1, &str[n], 1);
	return (count);
}
