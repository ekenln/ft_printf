/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elleneklund <elleneklund@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:07:15 by eeklund           #+#    #+#             */
/*   Updated: 2023/11/10 13:05:32 by elleneklund      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
size_t	ft_put_address(unsigned long nbr, char *base);
size_t	ft_putnbr_base(long nbr, char *base);
size_t	ft_putstr(char *s);
size_t	ft_putchar(char c);
size_t	put_vptr(void *vptr);

#endif