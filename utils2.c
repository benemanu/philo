#include "philo.h"

long long current_timestamp(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void    join_thread(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->no_philos)
        pthread_join(data->tid[i], NULL);
}

int is_philo_dead(t_data *data)
{
    pthread_mutex_lock(&data->lock);
    if (data->dead == 0)
    {
        pthread_mutex_unlock(&data->lock);
        return (0);
    }
    else
    {
        pthread_mutex_unlock(&data->lock);
        return (1);
    }
}

int is_equal(t_data *data)
{
    pthread_mutex_lock(&data->lock);
    if (data->finished == data->no_philos)
    {
        pthread_mutex_unlock(&data->lock);
        return (0);
    }
    else
    {
        pthread_mutex_unlock(&data->lock);
        return (1);
    }
}

int finished_eating(t_data *data, int i)
{
    pthread_mutex_lock(&data->lock);
    pthread_mutex_lock(&data->philos->lock);
    if (data->philos[i - 1].eat_count == data->no_meals)
    {
        pthread_mutex_unlock(&data->lock);
        pthread_mutex_unlock(&data->philos->lock);
        return (0);
    }
    else
    {
        pthread_mutex_unlock(&data->lock);
        pthread_mutex_unlock(&data->philos->lock);
        return (1);
    }
}

int is_no_philos(t_data *data, int i)
{
    pthread_mutex_lock(&data->lock);
    if (i == data->no_philos - 1)
    {
        pthread_mutex_unlock(&data->lock);
        return (1);
    } 
    else
    {
        pthread_mutex_unlock(&data->lock);
        return (0);
    }
}