#include "philo.h"

void routine(void *arg)
{
    t_philo *philo;

    ft_printf("Hello from thread\n");
    take_fork(&philo);
    philo_eats(&philo);

}

void    take_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->lf);
    printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
    if (philo->info->no_philos == 1)
    {
        pthread_mutex_unlock(philo->lf);
        return ;
    }
    pthread_mutex_lock(philo->rf);
    printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
}

void    philo_eats(t_philo *philo)
{
    printf("%lld %d is eating\n", current_timestamp(), philo->id);
    pthread_mutex_lock(philo->info->m_eat);
    philo->last_eat = current_timestamp();
    philo->eat_count++;
    pthread_mutex_unlock(philo->info->m_eat);
    usleep(data->tt_eat);
    pthread_mutex_unlock(&data->philo->lf);
    pthread_mutex_unlock(data->philo->rf);
    printf("%lld %d is sleeping\n", current_timestamp(), data->philo->id);
    usleep(data->tt_sleep);
    printf("%lld %d is thinking\n", current_timestamp(), data->philo->id);

}