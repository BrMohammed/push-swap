# include "push_swap.h"

static long	loop(const char *str, int i, int n)
{
	long	result;
	long	help;

	result = 0;
	help = 0;
	if(str[n] >= '0' && str[n] <= '9')
	{
		while (str[n] >= '0' && str[n] <= '9')
		{
			help = 10 * help + (str[n] - '0');
			if ((help / 10 != result) && (i == -1))
				return (0);
			if ((help / 10 != result) && (i == 1))
				return (-1);
			result = 10 * result + (str[n] - '0');
			n++;
		}
	}
	else
		return(-405);
	return (result * i);
}

int	ft_atoi(char *str)
{
	long	result;
	int		i;
	int		n;

	result = 0;
	i = 1;
	n = 0;
	while (str[n] == '\f' || str[n] == '\n' || str[n] == 32
		|| str[n] == '\r' || str[n] == '\v' || str[n] == '\t')
		n++;
	if (str[n] == '-')
	{
		i *= -1;
		n++;
	}
	else if (str[n] == '+')
		n++;
	result = loop(str, i, n);
	return (result);
}
