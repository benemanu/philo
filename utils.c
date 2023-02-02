#include "philo.h"

void    my_free(t_info *data)
{
    // pthread_mutex_destroy(data->philo->lf);
    // pthread_mutex_destroy(data->philo->rf);
    // free(data->philo);
    ft_printf("freeing memory\n");
}

int check_if_digits(char **argv)
{
    int i;
    int j;

    i = 1;
    while(argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}