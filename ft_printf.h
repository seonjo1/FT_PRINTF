/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:43:44 by seonjo            #+#    #+#             */
/*   Updated: 2023/03/28 22:23:07 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	putnbr_d(int n);
int	putnbr_u(unsigned int n);
int	putnbr_16(unsigned int num, char opt);
int	ft_printf(const char *last, ...);
int	putptr(void *ptr);

#endif