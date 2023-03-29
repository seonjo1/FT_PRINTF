/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:20:41 by seonjo            #+#    #+#             */
/*   Updated: 2023/03/29 21:23:04 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_num_ptr(size_t num, int count, char *base, int *all_len)
{
	char	c;

	if (num != 0)
	{
		count = ft_print_num_ptr(num / 16, count, base, all_len);
		c = base[num % 16];
		if (write(1, &c, 1) == -1)
			*all_len = INT_MIN;
		count = count + 1;
	}
	return (count);
}

static int	ft_putnbr_ptr(size_t num, char opt, int *all_len)
{
	int		minus;
	int		count;
	char	*base;

	minus = 1;
	count = 0;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			*all_len = INT_MIN;
		return (1);
	}
	else
	{
		if (opt == 'X')
			base = "0123456789ABCDEF";
		else
			base = "0123456789abcdef";
		count = ft_print_num_ptr(num, count, base, all_len);
	}
	return (count);
}

void	ft_putptr(void *ptr, int *all_len)
{
	size_t	p;

	if (write(1, "0x", 2) == -1)
		*all_len = INT_MIN;
	p = (size_t)ptr;
	*all_len = *all_len + ft_putnbr_ptr(p, 'x', all_len) + 2;
}
