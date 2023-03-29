/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:54:37 by seonjo            #+#    #+#             */
/*   Updated: 2023/03/29 21:46:31 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	error_check(int all_len)
{
	if (all_len >= 0)
		return (all_len);
	else
		return (-1);
}

static void	ft_putstr(char *s, int *all_len)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			*all_len = INT_MIN;
		*all_len = *all_len + 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			if (write(1, &s[i], 1) == -1)
				*all_len = INT_MIN;
			i = i + 1;
		}
		*all_len = *all_len + i;
	}
}

static void	ft_putchar(char c, int *all_len)
{
	if (write(1, &c, 1) == -1)
		*all_len = INT_MIN;
	*all_len = *all_len + 1;
}

static int	ft_printf2(char c, va_list cp, int *all_len)
{
	if (c == 'c')
		ft_putchar((char)va_arg(cp, int), all_len);
	else if (c == 's')
		ft_putstr(va_arg(cp, char *), all_len);
	else if (c == 'p')
		ft_putptr(va_arg(cp, void *), all_len);
	else if (c == 'd' || c == 'i')
		ft_putnbr_d(va_arg(cp, int), all_len);
	else if (c == 'u')
		ft_putnbr_u(va_arg(cp, unsigned int), all_len);
	else if (c == 'x')
		ft_putnbr_16(va_arg(cp, unsigned int), 'x', all_len);
	else if (c == 'X')
		ft_putnbr_16(va_arg(cp, unsigned int), 'X', all_len);
	else if (c == '%')
		ft_putchar('%', all_len);
	if (c == 'p' || c == 's')
		return (2);
	else if (c == '%')
		return (0);
	else
		return (1);
}

int	ft_printf(const char *last, ...)
{
	va_list	ap;
	va_list	cp;
	int		all_len;
	size_t	i;
	size_t	tmp;

	va_start(ap, last);
	all_len = 0;
	i = 0;
	while (last[i] != '\0')
	{
		if (last[i++] == '%')
		{
			va_copy(cp, ap);
			tmp = ft_printf2(last[i++], cp, &all_len);
			if (tmp == 1)
				va_arg(ap, int);
			else if (tmp == 2)
				va_arg(ap, char *);
		}
		else
			ft_putchar(last[i - 1], &all_len);
	}
	va_end(ap);
	return (error_check(all_len));
}
