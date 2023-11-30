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
int get_len(int n)
{
    int i;

    i = 0;
    if (n < 0)
    {
        i++;
        n *= -1;
    }
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_putnbr_base(int nbr, char *base)
{
    long a;
    int i;

    i = 0;
    if (!is_valid_base(base))
        return;
    a = ft_strlen(base);
    if (nbr < 0)
    {
        nbr = -nbr;
        ft_putchar('-');
        i++;
    }
    if (nbr >= a)
    {
        ft_putnbr_base(nbr / a, base);
        ft_putnbr_base(nbr % a, base);
    }
    else
    {
        ft_putchar(base[nbr]);
        i++;
    }
    return();
}

int main(int ac, char **av)
{
    long lon;
    if(ac > 1)
        lon = atoi(av[1]);
        ft_putnbr_base(lon, av[2]);

    return (0);
}