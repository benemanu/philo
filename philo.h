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
	struct s_data	*data;
	pthread_t       t1;
	int             id;
	int             eat_count;
	int             status;
	int             eating;
	long long		last_eaten;
	long long       time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*rf;
	pthread_mutex_t	*lf;
} t_philo;

typedef struct s_data
{
	pthread_t       *tid;
	int             no_philos;
	int             no_meals;
	int             dead;
	int             finished;
	t_philo         *philos;
	int       tt_die;
	int       tt_eat;
	int       tt_sleep;
	long long start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t	printf;
} t_data;

//main.c
int                 main (int argc, char **argv);

//init.c
int 				init(t_data *data, char **argv, int argc);
int 				init_var(t_data *data, char **argv, int argc);
int 				init_philos(t_data *data);
int 				alloc(t_data *data);
int 				init_forks(t_data *data);


//philo.c
int    				take_fork(t_philo *philo);
void                philo_eats(t_philo *philo);
void                *routine(void *arg);
int	    			one_philo(t_data *data);
int 				init_thread(t_data * data);
void				check_death(t_philo *philo);

//utils.c
void                my_free(t_data *data);
int                 check_if_digits(char **argv);
int	                ft_isdigit(int c);
int 				check_args(char **argv);
void    			print(t_data *data, char *str, int id);
void				ft_usleep(int ms);

//utils2.c
long long 			current_timestamp(void);
void    			action(void *arg);
int 				is_philo_dead(t_data *data);
int 				is_equal(t_data *data);
int					finished_eating(t_data *data, int i);
int 				is_no_philos(t_data *data, int i);
void    			join_thread(t_data *data);

#endif