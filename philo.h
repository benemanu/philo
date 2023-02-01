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

typedef struct s_philo
{
    
}               t_philo;


typedef struct s_info
{
    int no_philos;
    int tt_die;
    int tt_eat;
    int tt_sleep;
    int no_philos_eat;
    t_philo *philo;
}                 t_info;

#endif