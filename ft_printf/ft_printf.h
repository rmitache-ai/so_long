/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:47:18 by rmitache          #+#    #+#             */
/*   Updated: 2023/07/24 17:57:12 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_printf_c(char c, int *return_value);
void	ft_printf_str(char *str, int *return_value);
void	ft_printf_nosign(char c, int *return_value);
void	ft_printf_p(void *p, int *return_value);
int		ft_printf_count(long p);
void	ft_printf_d(int input, int *return_value);
void	ft_putnbr_long(long n, int fd);
void	ft_printf_u(unsigned int input, int *return_value, char format);
void	ft_printf_hex(unsigned int input, int *return_value, char format);

#endif