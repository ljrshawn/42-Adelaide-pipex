/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:04:56 by jlyu              #+#    #+#             */
/*   Updated: 2023/07/25 10:43:14 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_chr(int c);
int	ft_print_str(char *str);
int	ft_print_point(unsigned long long pointer);
int	ft_print_dec(int number);
int	ft_print_undec(unsigned int number);
int	print_hexa(unsigned long long pointer);
int	print_long_hexa(unsigned int pointer, char flag);

#endif