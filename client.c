#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "ft_printf/ft_printf.c"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long double	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		result = result * 10 + str[i++] - '0';
	result *= sign;
	if (!(result < 9223372036854775807))
		return (-1);
	else if (!(result >= -9223372036854775807))
		return (0);
	return (result);
}

int to_binary(int n) 
{
    int binary; 
    int base;

    binary = 0;
    base = 1;
    while (n > 0) 
    {
        binary += (n % 2) * base;
        n /= 2;
        base *= 10;
    }
    return (binary);
}

int ft_reverseInt(int num) 
{
    int reversed;
    int digit;
    
    reversed = 0;
    while (num) 
    {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return (reversed);
}

void ft_send(int pid, int number)
{
    int i;
    int count;

    count = 0;
    while (number)
    {
        i = number % 10;
        printf("SIGNAL BEING SENT = %d\n", i);
        if (i == 1)
            kill(pid, SIGUSR2);
        if (i == 0)
            kill(pid, SIGUSR1);
        number /= 10;
        count++;
        usleep(100);
    }
    while (count <= 7)
    {
        kill(pid, SIGUSR1);
        count++;
        usleep(100);
    }
}

void convert_send(int pid, char *str)
{
    int asciicode;
    int tens;
    int number;
    int i;

    i = 0;
    while (str[i])
    {
        tens = 1;
        asciicode = (int)str[i];
        number = to_binary(asciicode);
        ft_send(pid, number);
        usleep(500);
        i++;
    }

}

int main(int ac, char **av)
{
    if (ac == 3)
    {    
        if (ft_atoi(av[1]) >= 0)
            convert_send(ft_atoi(av[1]), av[2]);
        else
            ft_printf("Invalid PID!");
    }
    else
        ft_printf("Wrong argument count");
}
