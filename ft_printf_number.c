/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:42:39 by seonjo            #+#    #+#             */
/*   Updated: 2023/03/29 21:30:56 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_num(long long num, int count, int *all_len)
{
	char	c;

	if (num != 0)
	{
		count = ft_print_num(num / 10, count, all_len);
		c = num % 10 + '0';
		if (write(1, &c, 1) == -1)
			*all_len = *all_len + INT_MIN;
		count = count + 1;
	}
	return (count);
}

void	ft_putnbr_d(int n, int *all_len)
{
	long long	num;
	int			minus;
	int			count;

	num = n;
	minus = 1;
	count = 0;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			*all_len = *all_len + INT_MIN;
		*all_len = *all_len + 1;
	}
	else
	{
		if (num < 0)
		{
			if (write(1, "-", 1) == -1)
				*all_len = *all_len + INT_MIN;
			count = count + 1;
			num = -num;
		}
		count = ft_print_num(num, count, all_len);
		*all_len = *all_len + count;
	}
}

void	ft_putnbr_u(unsigned int n, int *all_len)
{
	long long	num;
	int			minus;
	int			count;

	num = n;
	minus = 1;
	count = 0;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			*all_len = *all_len + INT_MIN;
		*all_len = *all_len + 1;
	}
	else
	{
		count = ft_print_num(num, count, all_len);
		*all_len = *all_len + count;
	}
}

static int	ft_print_16(unsigned int num, int count, char *base, int *all_len)
{
	char	c;

	if (num != 0)
	{
		count = ft_print_16(num / 16, count, base, all_len);
		c = base[num % 16];
		if (write(1, &c, 1) == -1)
			*all_len = *all_len + INT_MIN;
		count = count + 1;
	}
	return (count);
}

void	ft_putnbr_16(unsigned int num, char opt, int *all_len)
{
	int		minus;
	int		count;
	char	*base;

	minus = 1;
	count = 0;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			*all_len = *all_len + INT_MIN;
		*all_len = *all_len + 1;
	}
	else
	{
		if (opt == 'X')
			base = "0123456789ABCDEF";
		else
			base = "0123456789abcdef";
		count = ft_print_16(num, count, base, all_len);
		*all_len = *all_len + count;
	}
}
