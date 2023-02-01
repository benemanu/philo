#include "philo.h"

void    free(t_info *data)
{
    //Free everything here and exit
}

int check_if_digits(char **argv)
{
    int i;
    int j;

    i = 0;
    while(argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 0)
                return (0);
            j++;
        }
    }
    return (1);
}