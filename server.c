#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

int calculatepow(int i)
{
    int num;

    num = 1;
    if (i == 0)
        return (1);
    while (i)
    {
        num = num * 2;
        i--; 
    }
    return (num);
}

void printchar(int num)
{
    static int BIN[8];
    static int i;
    int tf;
    char asciicode;

    asciicode = 0;
    tf = 0;
    if (i <= 7)
        BIN[i++] = num - 30;
    if (i == 8)
    {    
        tf = 1;
        i = 0;
    }
    if (tf)
    {
        while (i <= 7)
        {   
            asciicode = asciicode + (BIN[i] * calculatepow(i));
            i++;
        }
        ft_printf("%c", asciicode);
        i = 0;
    }

} 

int main()
{
    printf("THE PID is : %d", getpid());
    printf("\n");
        signal(SIGUSR1, printchar);
        signal(SIGUSR2, printchar);
    while (1)
    {
        pause();
    }
}
