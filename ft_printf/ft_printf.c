#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_putstr(char *str)
{
	int counter = 0;
	if (!str)
		return write(1, "(null)", 6);
	while (*str)
		counter += write(1, str++, 1);
	return counter;
}

int ft_putchar(int c)
{
	return write(1, &c, 1);
}

int ft_putnbr(int nb)
{
	int counter = 0;
	if (nb == -2147483648)
		return write(1, "-2147483648", 11);
	if (nb < 0)
	{
		counter += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		counter += ft_putchar(nb + '0');
	else
	{
		counter += ft_putnbr(nb / 10);
		counter += ft_putnbr(nb % 10);
	}
	return counter;
}

int print_hex(unsigned int n)
{
	int counter = 0;
	char hexa[] = "0123456789abcdef";

	if (n >= 16)
		counter += print_hex(n / 16);
	counter += ft_putchar(hexa[n % 16]);
	return counter;
}


int ft_printf(const char *str, ... )
{
	int counter = 0, i = 0;
	va_list ap;
	va_start(ap, str);

	for (; str[i]; i++)
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				counter += ft_putstr(va_arg(ap, char *));
			if (str[i] == 'd' || str[i] == 'i')
				counter += ft_putnbr(va_arg(ap, int));
			if (str[i] == 'x')
				counter += print_hex(va_arg(ap, unsigned int));
		}
		else
			counter += ft_putchar(str[i]);
	}
	va_end(ap);
	return counter;
}
