/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 11:07:03 by eeklund       #+#    #+#                 */
/*   Updated: 2023/11/30 13:12:47 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_master(char c, va_list ap)
{
	int	total;

	total = 0;
	if (c == 's')
		total += ft_putstr(va_arg(ap, char *));
	else if (c == 'c')
		total += ft_putchar(va_arg(ap, int));
	else if (c == 'd' || c == 'i')
		total += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (c == 'u')
		total += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		total += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		total += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		total += put_vptr(va_arg(ap, void *));
	else if (!ft_strchr("cspdiuxX%%", c))
	{
		total += ft_putchar('%');
		total += ft_putchar(c);
	}
	else
		total += ft_putchar(c);
	return (total);
}

int	ft_printf(const char *format, ...)
{
	int		total;
	int		i;
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			total += ft_putchar(format[i]);
		else if (!format[++i])
			return (-1);
		else
			total += put_master(format[i], ap);
		i++;
	}
	va_end (ap);
	return (total);
}

// int main(void)
// {
//  	// int	age = 21;
//  	//void *vptr = NULL;
// 	//char *name = "Ellen";
//  	// char c = 'c';
//  	// unsigned int u = 345;
//  	// int hexa = -1234;
//  	//to see return value:
// //  	printf("%i\n", ft_printf("name: %s im %i years old\nhexa: %x,
// // unsigned: %u int: %i\naddress of name: %p\ndouble%%",
// // name, 21, -1, -23, 2147483647, LONG_MIN));

// //  	printf("%i\n", printf("name: %s im %i years old\nhexa: %x,
// // unsigned: %u int:%i\naddress of name: %p\ndouble",
// // name, 21, -1, -23, 2147483647, LONG_MIN));

// 	ft_printf("%i\n", (ft_printf("%p\n", NULL)));
// 	printf("%i\n", (printf("%p\n", NULL)));
// //printf("%%åore\0ite%%\0", NULL);
// //ft_printf("%%åore\0ite%%\0", NULL);
// } 
