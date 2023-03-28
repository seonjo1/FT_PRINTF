/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:54:37 by seonjo            #+#    #+#             */
/*   Updated: 2023/03/28 22:22:17 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i = i + 1;
	}
	return (i);
}

static int	putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_printf2(char c, va_list cp, size_t *all_len, int tmp)
{
	if (c == 'c')
		*all_len = *all_len + putchar(va_arg(cp, int));
	else if (c == 's')
	{
		tmp = putstr(va_arg(cp, char *));
		*all_len = *all_len + tmp;
		return (2);
	}
	else if (c == 'p')
		*all_len = *all_len + putptr(va_arg(cp, void *));
	else if (c == 'd' || c == 'i')
		*all_len = *all_len + putnbr_d(va_arg(cp, int));
	else if (c == 'u')
		*all_len = *all_len + putnbr_u(va_arg(cp, unsigned int));
	else if (c == 'x')
		*all_len = *all_len + putnbr_16(va_arg(cp, unsigned int), 'x');
	else if (c == 'X')
		*all_len = *all_len + putnbr_16(va_arg(cp, unsigned int), 'X');
	else if (c == '%')
		*all_len = *all_len + putchar('%');
	if (c == '%')
		return (0);
	else
		return (1);
}

int	ft_printf(const char *last, ...)
{
	size_t	tmp;
	size_t	i;
	size_t	all_len;
	va_list	ap;
	va_list	cp;

	va_start(ap, last);
	i = 0;
	while (last[i] != '\0')
	{
		if (last[i] == '%')
		{
			i = i + 1;
			va_copy(cp, ap);
			tmp = ft_printf2(last[i], cp, &all_len, 0);
			while (tmp--)
				va_arg(ap, int);
		}
		else
			all_len = all_len + putchar(last[i]);
		i = i + 1;
	}
	va_end(ap);
	return (all_len);
}
