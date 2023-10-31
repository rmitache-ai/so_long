/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:43:40 by rmitache          #+#    #+#             */
/*   Updated: 2023/05/15 16:09:37 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_format(const char *f, va_list args, int *return_value)
{
	if (*f == 'c')
		ft_printf_c(va_arg(args, int), return_value);
	else if (*f == 's')
		ft_printf_str(va_arg(args, char *), return_value);
	else if (*f == 'p')
		ft_printf_p(va_arg(args, void *), return_value);
	else if (*f == 'd' || *f == 'i')
		ft_printf_d(va_arg(args, int), return_value);
	else if (*f == 'u' || *f == 'x' || *f == 'X')
		ft_printf_u(va_arg(args, unsigned int), return_value, *f);
	else if (*f == '%')
	{
		ft_putchar_fd('%', 1);
		(*return_value)++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		return_value;
	va_list	args;

	va_start(args, format);
	return_value = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_handle_format(format, args, &return_value);
		}
		else
			ft_printf_nosign(*format, &return_value);
		format++;
	}
	va_end(args);
	return (return_value);
}
