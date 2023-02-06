#include "philo.h"

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    philo->time_to_die = philo->data->tt_die + current_timestamp();
    if (pthread_create(&philo->t1, NULL, &action, (void *)philo))
        return ((void *)1);
    while (philo->data->dead == 0)
    {
        if (philo->eat_count == philo->data->no_meals)
            philo->data->finished++;
        if (philo->data->finished == philo->data->no_philos)
            my_free(philo->data);
        take_fork(philo);
        philo->time_to_die = current_timestamp() + philo->data->tt_die;
        philo_eats(philo);
        
    }
    if (pthread_join(philo->t1, NULL))
        return ((void *)1);
    return ((void*)0);
}

void    take_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->rf);
    print(philo->data, "has taken a fork\n", philo->id);
    pthread_mutex_lock(philo->lf);
    print(philo->data, "has taken a fork\n", philo->id);
}

void    philo_eats(t_philo *philo)
{   
    print(philo->data, "is eating\n", philo->id);
    philo->eat_count++;
    ft_usleep(philo->data->tt_eat);
    pthread_mutex_unlock(philo->lf);
    pthread_mutex_unlock(philo->rf);
    print(philo->data, "is sleeping\n", philo->id);
    ft_usleep(philo->data->tt_sleep);
    print(philo->data, "is thinking\n", philo->id);
}

int    one_philo(t_data *data)
{
    print(data, "has taken a fork\n", 1);
    ft_usleep(data->tt_die);
    print(data, "died\n", 1);
    pthread_mutex_destroy(&data->lock);
    exit(0);
}

int init_thread(t_data * data)
{
    int i;

    i = -1;
    data->start_time = current_timestamp();
    while(++i < data->no_philos)
    {
        if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
            return (1);
        ft_usleep(1);
    }
    i = -1;
    while (++i < data->no_philos)
    {
        if(pthread_join(data->tid[i], NULL))
            return (1);
    }
    return (0);
}