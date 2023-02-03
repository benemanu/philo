#include "philo.h"

int init(t_data *data, int argc, char **argv)
{
    if (init_var(data, argv, argc) == 1)
        return (1);
    if (alloc(data) == 1)
        return (1);
    if (init_forks(data) == 1)
        return (1);
    init_philos(data);
    return (0);
}

int init_var(t_data *data, int argc, char **argv)
{
    data->no_philos = ft_atoi(argv[1]);
    data->tt_die = ft_atoi(argv[2]);
    data->tt_eat = ft_atoi(argv[3]);
    data->tt_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->no_meals = ft_atoi(argv[5]);
    else
        data->no_meals = -1;
    data->dead = 0;
    data->finished = 0;
    data->start_time = current_timestamp();
    pthread_mutex_init(&data->write, NULL);
    pthread_mutex_init(&data->lock, NULL);
    return (0);
}

int init_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->no_philos)
    {
        data->philos[i].data = data;
        data->philos[i].id = i + 1;
        data->philos[i].eat_cont = 0;
        data->philos[i].status = 0;
        data->philos[i].eating = 0;
        data->philos[i].time_to_die = data->tt_die;
        pthread_mutex_init(&data->philos[i].lock, NULL);
        i++;
    }
    return (0);
}

int init_forks(t_data *data)
{
    int i;

    i = 0;
    while (i < data->no_philos)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    data->philos->lf = &data->forks[0];
    data->philos->rf = &data->forks[data->no_philos - 1];
    i = 1;
    while (i < data->no_philos)
    {
        data->philos[i].lf = &data->forks[i];
        data->philos[i].rf = &data->forks[i - 1];
        i++;
    }
    return (0);
}

int alloc(t_data *data)
{
    data->tid = malloc(sizeof(pthread_t) * data->no_philos);
	if (!data->tid)
		return (ft_printf("Error: malloc failed\n"));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->no_philos);
	if (!data->forks)
		return (ft_printf("Error: malloc failed\n"));
	data->philos = malloc(sizeof(t_philo) * data->no_philos);
	if (!data->philos)
		return (ft_printf("Error: malloc failed\n"));
	return (0);
}