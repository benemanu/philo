#include "philo.h"

int init_var(t_info *data, char **argv, int argc)
{
    // pthread_mutex_init(&data->philo->lf, NULL);
    // pthread_mutex_init(&data->philo->rf, NULL);

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
            data->no_philos_eat = -1;
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

int    init_philo(t_info *data)
{
    int i;

    i = 0;
    data->start_time = current_timestamp();
    while (i < data->no_philos)
    {
        data->philo[i].id = i + 1;
        data->philo[i].last_eat = 0;
        data->philo[i].eat_count = 0;
        data->philo[i].is_dead = 0;
        data->philo[i].rf = NULL;
        // pthread_mutex_init(&data->philo[i].lf, NULL);
        // if (i == data->no_philos - 1)
        //     data->philo[i].rf = &data->philo[0].lf;
        // else
        //     data->philo[i].rf = &data->philo[i + 1].lf;
        pthread_create(&data->philo[i].thread, NULL, (void *)routine, (void *)&data->philo[i]);
        pthread_join(data->philo[i].thread, NULL);
        i++;
    }
}

long long current_timestamp()
{
    struct timeval te;
    gettimeofday(&te, NULL); 
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000;
    return milliseconds;
}