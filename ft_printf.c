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

/*int	main()
{
#include <limits.h>

	char c = 'a';
	char *str = "Hello World!";
	void *ptr = &c;
	int n = 42;
	int hexN = 48576;
	int mine;
	int original;

	//Test for %%
	original = printf("%%%%: %%\n");
	mine = ft_printf("%%%%: %%\n");
	if (original != mine)
		printf("Error of %%%%\n");

	//Test for %c
	original = printf("%%c: %c\n", c);
	mine = ft_printf("%%c: %c\n", c);
	if (original != mine)
		printf("Error on %%c\n");

	//Test for %s
	original = printf("%%s: %s\n", str);
	mine = ft_printf("%%s: %s\n", str);
	if (original != mine)
		printf("Error on %%s\n");

	//Test for %d and %i 
	original = printf("%%d: %d\n", n);
	mine = ft_printf("%%d: %d\n", n);
	if (original != mine)
		printf("Error on %%d\n");
	

	original = printf("%%i: %i\n", n);
	mine = ft_printf("%%i: %i\n", n);
	if (original != mine)
		printf("Error on %%i\n");

	//Test for %u
	original = printf("%%u: %u\n", UINT_MAX);
	mine = ft_printf("%%u: %u\n", UINT_MAX);
	if (original != mine)
		printf("Error on %%u\n");

	//Test for %x and %X
	original = printf("%%x: %x\n", hexN);
	mine = ft_printf("%%x: %x\n", hexN);
	if (original != mine)
		printf("Error on %%x\n");

	original = printf("%%X: %X\n", hexN);
	mine = ft_printf("%%X: %X\n", hexN);
	if (original != mine)
		printf("Error on %%X\n");
	
	//Test for %p
	original = printf("%%p: %p\n", ptr);
	mine = ft_printf("%%p: %p\n", ptr);
	printf("%d, %d\n", original, mine);
	if (original != mine)
		printf("Error on %%p\n");
}*/