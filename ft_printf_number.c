/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:42:39 by seonjo            #+#    #+#             */
/*   Updated: 2023/03/23 16:49:20 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num(long long num, int fd, int count)
{
	char	c;

	if (num != 0)
	{
		count = print_num(num / 10, fd, count);
		c = num % 10 + '0';
		write(fd, &c, 1);
		count = count + 1;
	}
	return (count);
}

int	putnbr_d(int n, int fd)
{
	long long	num;
	int			minus;
	int			count;

	num = n;
	minus = 1;
	count = 0;
	if (num == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else
	{
		if (num < 0)
		{
			write(fd, "-", 1);
			count = count + 1;
			num = -num;
		}
		count = print_num(num, fd, count);
	}
	return (count);
}

int	putnbr_u(unsigned int n, int fd)
{
	long long	num;
	int			minus;
	int			count;

	num = n;
	minus = 1;
	count = 0;
	if (num == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else
	{
		count = print_num(num, fd, count);
	}
	return (count);
}

static int	print_num16(unsigned int num, int fd, int count, char *base)
{
	char	c;

	if (num != 0)
	{
		count = print_num16(num / 16, fd, count, base);
		c = base[num % 16];
		write(fd, &c, 1);
		count = count + 1;
	}
	return (count);
}

int	putnbr_16(unsigned int num, int fd, char opt)
{
	int		minus;
	int		count;
	char	*base;

	minus = 1;
	count = 0;
	if (num == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else
	{
		if (opt == 'X')
			base = "0123456789ABCDEF";
		else if (opt == 'x')
			base = "0123456789abcdef";
		count = print_num16(num, fd, count, base);
	}
	return (count);
}
