#include "philo.h"

long long current_timestamp(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void check_death(t_philo *philo)
{
    if (philo->last_eaten - philo->data->start_time - philo->data->tt_die < 0)
    {
        philo->status = 0;
        print(philo->data, "died\n", philo->id);
        my_free(philo->data);
    }
}

void    *action(void *arg)
{
    t_philo *philo;

    philo = (t_philo *) arg;
    while (philo->data->dead == 0)
    {
        pthread_mutex_lock(&philo->lock);
        if (current_timestamp() >= philo->time_to_die && philo->eating == 0)
            print(philo->data, "died\n", philo->id);
        if (philo->eat_count == philo->data->no_meals)
        {
            pthread_mutex_lock(&philo->data->lock);
            philo->data->finished++;
            philo->eat_count++;
            pthread_mutex_unlock(&philo->data->lock);
        }
        pthread_mutex_unlock(&philo->lock);
    }
    return ((void *)0);
}