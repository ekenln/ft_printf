/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 15:24:25 by elleneklund   #+#    #+#                 */
/*   Updated: 2023/11/10 13:40:29 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(long nbr, char *base)
{
	int		digit;
	long	left;
	size_t	count;
	int		base_len;

	count = 0;
	base_len = ft_strlen(base);
	digit = nbr % base_len;
	left = nbr / base_len;
	if (nbr < 0)
	{
		ft_putchar('-');
		count++;
		digit = -digit;
		left = -left;
	}
	if (left > 0)
		count += ft_putnbr_base(left, base);
	ft_putchar(base[digit]);
	count++;
	return (count);
}

size_t	put_vptr(void *vptr)
{
	long	value;
	size_t	count;

	value = (long)vptr;
	if (!vptr)
		return (write(1, "(nil)", 5));
	ft_putstr("0x");
	count = ft_put_address(value, "0123456789abcdef");
	count += 2;
	return (count);
}

size_t	ft_put_address(unsigned long nbr, char *base)
{
	int		digit;
	long	left;
	size_t	count;
	int		base_len;	

	count = 0;
	base_len = ft_strlen(base);
	digit = nbr % base_len;
	left = nbr / base_len;
	if (left > 0)
		count += ft_put_address(left, base);
	ft_putchar(base[digit]);
	count++;
	return (count);
}

size_t	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
