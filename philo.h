#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct  s_philo
{
    int             id;
    long int        last_eat;
    bool			is_eating;
    int             eat_count;
    int             is_dead;
    struct t_info          *info;
    pthread_t		thread;
    pthread_mutex_t lf;
    pthread_mutex_t *rf;
}                   t_philo;

typedef struct s_info
{
    int             arg_c;
    int             no_philos;
    int             tt_die;
    int             tt_eat;
    int             tt_sleep;
    int             no_philos_eat;
    int             start_time;
    t_philo         *philo;
    pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
}                   t_info;

//main.c
int                 main (int argc, char **argv);

//init.c
int                 init_var(t_info *data, char **argv, int argc);
int                 init_philo(t_info *data);
long long           current_timestamp();

//philo.c
void                take_fork(t_philo *philo);
void                philo_eats(t_philo *philo);
void                routine(void *arg);

//utils.c
void                my_free(t_info *data);
int                 check_if_digits(char **argv);
int	                ft_isdigit(int c);

#endif