#include "philo.h"

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    philo->time_to_die = philo->data->tt_die + current_timestamp();
    while (is_philo_dead(philo->data) == 0)
    {
        if (finished_eating(philo->data, philo->id) == 0)
        {
            if (is_philo_dead(philo->data) == 0)
            {
                pthread_mutex_lock(&philo->data->lock);
                philo->data->finished++;
                pthread_mutex_unlock(&philo->data->lock);
            }
        }
        if (is_equal(philo->data) == 0)
            my_free(philo->data);
        if(take_fork(philo) == 0)
        {
            pthread_mutex_lock(&philo->lock);
            philo->time_to_die = current_timestamp() + philo->data->tt_die;
            pthread_mutex_unlock(&philo->lock);
            philo_eats(philo);    
        }
    }
    return ((void*)0);
}

int    take_fork(t_philo *philo)
{
    int ind;

    ind = 1;
    if (is_philo_dead(philo->data) == 0)
    {
        if (philo->id % 2 == 0)
            pthread_mutex_lock(philo->rf);
        else
            pthread_mutex_lock(philo->lf);
        print(philo->data, "has taken a fork\n", philo->id);
        ind = 0;
    }
    if (is_philo_dead(philo->data) == 0)
    {
        if (philo->id % 2 == 0)
            pthread_mutex_lock(philo->lf);
        else
            pthread_mutex_lock(philo->rf);
        print(philo->data, "has taken a fork\n", philo->id);
    }
    else
    {
        if (philo->id % 2 == 0)
            pthread_mutex_unlock(philo->rf);
        else
            pthread_mutex_unlock(philo->lf);
        ind = 1;
    }
    return (ind);
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
    return (0);
}