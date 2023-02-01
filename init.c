#include "philo.h"

int init_var(t_info *data, char **argv, int argc)
{

    data->philo = malloc(sizeof(t_philo) * data->no_philos);
    if (!data->philo)
        return (-1);
    if (check_if_digits(argv) == 1)
    {
        data->no_philos = ft_atoi(argv[1]);
        data->tt_die = ft_atoi(argv[2]);
        data->tt_eat = ft_atoi(argv[3]);
        data->tt_sleep = ft_atoi(argv[4]);
        if (argc == 6)
            data->no_philos_eat = ft_atoi(argv[5]);
        else
            data->no_philos_eat = 0;
        if (data->no_philos_eat == 0)
            return (1);
        else
            return (0);
    }
    else
    {
        ft_printf("Error: Invalid amount of arguments!");
        return (1);
    }
    
}

void    init_philo(t_info *data)
{

}