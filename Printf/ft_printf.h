/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loosorio <loosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:30:56 by loosorio          #+#    #+#             */
/*   Updated: 2023/11/27 19:49:38 by loosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_params_c(char c);
int	ft_params_s(char *s);
int	ft_params_d_i(int n);
int	ft_params_u(unsigned int n);
int	ft_params_x(unsigned int n, char c);
int	ft_params_p(unsigned long n, int i);

#endif
