/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:59:57 by fishaq            #+#    #+#             */
/*   Updated: 2023/09/16 19:01:03 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(ap, int));
	else if (format == 's')
		count += print_str(va_arg(ap, char *));
	else if (format == 'p')
		count += print_pointer(va_arg(ap, unsigned long long int));
	else if (format == 'd' || format == 'i')
		count += print_number(va_arg(ap, int));
	else if (format == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x')
		count += print_hexasmall(va_arg(ap, unsigned int));
	else if (format == 'X')
		count += print_hexacap(va_arg(ap, unsigned int));
	else if (format == '%')
		count += write(1, &format, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += print_format(ap, str[i + 1]);
			i++;
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
// int main()
// {
//     int count;
//     int f;

//     count = 0;

//     count = ft_printf("hello : %c\n",'l');
//     f = printf("hello : %c\n",'l');

//     ft_printf("count %d\n" , count);
//     printf("count %d\n",f);
//     return(0);
// }
// int main() {
//     unsigned int num = 255;
//     int count = ft_printf("%x\n",num);
//     printf("%x\n",num);
//     //printf("Hexadecimal representation: ");
//     ft_printf("%d\n",count);
//     printf("\n");
//     return (0);
// }