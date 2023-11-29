#include <unistd.h>

int	ft_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int	is_valid_base(char *base)
{
    int i;
    int j;

    if (ft_strlen(base) < 2)
        return 0;
    i = 0;
    while (base[i++])
    {
        if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
            return 0;

        j = i + 1;
        while (base[j++])
        {
            if (base[i] == base[j])
                return 0;
        }
    }
    return 1;
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr_base(int nbr, char *base)
{
    long nb = nbr;
    long a;

    if (!is_valid_base(base))
        return;

    a = ft_strlen(base);

    if (nb < 0)
    {
        nb = -nb;
        ft_putchar('-');
    }

    if (nb >= a)
    {
        ft_putnbr_base(nb / a, base);
        ft_putnbr_base(nb % a, base);
    }
    else
        ft_putchar(base[nb]);
}

int main(int ac, char **av)
{
    long lon;
    if(ac > 1)
        lon = atoi(av[1]);
        ft_putnbr_base(lon, av[2]);

    return (0);
}