/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:54:37 by seonjo            #+#    #+#             */
/*   Updated: 2023/03/23 17:15:53 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr(char *s)
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

int	putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int putptr(void *ptr)
{
	
	
}

int	ft_printf(const char *last, ...)
{
	size_t	i;
	size_t	all_len;
	va_list	ap;
	int		tmp;

	va_start(ap, last);
	i = 0;
	while (last[i] != '\0')
	{
		if (last[i] != '%')
			all_len = all_len + putchar(&last[i]);
		else
		{
			i = i + 1;
			if (last[i] == 'c')
				all_len = all_len + putchar(va_arg(ap, char));
			else if (last[i] == 's')
			{
				tmp = putstr(va_arg(ap, char));
				all_len = all_len + tmp;
				if (tmp != 0)
					while (va_arg(ap, char) != '\0')
						;
			}
			else if (last[i] == 'p') //포인터 
				all_len = all_len + putptr(va_arg(ap, void *));
			else if (last[i] == 'd' || last[i] == 'i') // 부호가 있는 십진 정수
				all_len = all_len + putnbr_d(va_arg(ap, int), 1);
			else if (last[i] == 'u') // unsigned int
				all_len = all_len + putnbr_u(va_arg(ap, unsigned int), 1);
			else if (last[i] == 'x') // abcdef를 사용한 부호가 없는 16진 정수
				all_len = all_len + putnbr_16(va_arg(ap, unsigned int), 1, 'x');
			else if (last[i] == 'X') // ABCDEF를 사용한 부호가 없는 16진 정수
				all_len = all_len + putnbr_16(va_arg(ap, unsigned int), 1, 'X');
			else if (last[i] == '%')
				all_len = all_len + putchar('%');
		}
		i = i + 1;
	}
	va_end(ap);
	return (all_len);
}
