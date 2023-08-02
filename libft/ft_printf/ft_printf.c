/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:24:08 by cbernot           #+#    #+#             */
/*   Updated: 2023/02/15 12:28:19 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Call the correct function according to format specifier.
 */
static int	ft_handle_format(const char *str, int i, int *prt, va_list *args)
{
	int	len;

	len = 0;
	if (str[i + 1] == 'c')
		len = ft_print_char(va_arg(*args, int));
	else if (str[i + 1] == 's')
		len = ft_print_str(va_arg(*args, char *));
	else if (str[i + 1] == 'p')
		len = ft_print_ptr((long long)va_arg(*args, unsigned long long));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		len = ft_print_int(va_arg(*args, int));
	else if (str[i + 1] == 'u')
		len = ft_print_uint(va_arg(*args, unsigned int));
	else if (str[i + 1] == 'x')
		len = ft_print_int_base(va_arg(*args, int), "0123456789abcdef");
	else if (str[i + 1] == 'X')
		len = ft_print_int_base(va_arg(*args, int), "0123456789ABCDEF");
	else if (str[i + 1] == '%' && str[i] == '%')
		len = ft_print_char('%');
	else
		len = ft_print_char(str[i + 1]);
	if (len == -1)
		return (-1);
	return (*prt += len);
}

/**
 * @brief The same as libc. Handle %c (char), %s (char *), %p (void *), 
 * %d (double), %i (int), %u (unsigned int), %x (hex number with small 
 * caps), %X (hex number with capital letters) and %%(print %).
 * 
 * @param str String containing format specifiers
 * @param ... Values to print
 * @return int The number of characters printed or -1 if an error occured
 */
int	ft_printf(const char *str, ...)
{
	int		printed_lengh;
	size_t	i;
	va_list	args_list;

	va_start(args_list, str);
	i = -1;
	printed_lengh = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if (ft_handle_format(str, i++, &printed_lengh, &args_list) == -1)
				return (-1);
		}
		else if (i < ft_strlen(str))
		{
			if (ft_print_char((unsigned char)str[i]) == -1)
				return (-1);
			printed_lengh += 1;
		}
	}
	va_end(args_list);
	return (printed_lengh);
}
