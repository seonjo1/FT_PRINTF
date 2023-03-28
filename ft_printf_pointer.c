/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:20:41 by seonjo            #+#    #+#             */
/*   Updated: 2023/03/28 22:25:54 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num_ptr(long long num, int count, char *base)
{
	char	c;

	if (num != 0)
	{
		count = print_num_ptr(num / 16, count, base);
		c = base[num % 16];
		write(1, &c, 1);
		count = count + 1;
	}
	return (count);
}

static int	putnbr_ptr(long long num, char opt)
{
	int		minus;
	int		count;
	char	*base;

	minus = 1;
	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		if (opt == 'X')
			base = "0123456789ABCDEF";
		else
			base = "0123456789abcdef";
		count = print_num_ptr(num, count, base);
	}
	return (count);
}

int	putptr(void *ptr)
{
	long long	p;

	write(1, "0x", 2);
	p = (long long)ptr;
	return (putnbr_ptr(p, 'x') + 2);
}
