#include "philo.h"

// void *routine(void *arg)
// {
//     t_philo *philo;

//     philo = (t_philo *)arg;
//     take_fork(philo);
//     philo_eats(philo);
// }

// void    take_fork(t_philo *philo)
// {
//     pthread_mutex_lock(&philo->lf);
//     printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
//     pthread_mutex_lock((philo->rf));
//     printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
// }

// void    philo_eats(t_philo *philo)
// {
//     printf("%lld %d is eating\n", current_timestamp(), philo->id);
//     pthread_mutex_unlock(&philo->lf);
//     pthread_mutex_unlock(philo->rf);
//     printf("%lld %d is sleeping\n", current_timestamp(), philo->id);
//     printf("%lld %d is thinking\n", current_timestamp(), philo->id);
// }

int    one_philo(t_data *data)
{
    print(data, "has taken a fork\n", 1);
    ft_usleep(data->tt_die);
    print(data, "died\n", 1);
    pthread_mutex_destroy(&data->write);
    pthread_mutex_destroy(&data->lock);
    exit(0);
}

int init_thread(t_data * data)
{
    data->start_time = current_timestamp();
}