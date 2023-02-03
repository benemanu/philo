#include "philo.h"

// void    my_free(t_data *data)
// {
//     // pthread_mutex_destroy(data->philo->lf);
//     // pthread_mutex_destroy(data->philo->rf);
//     // free(data->philo);
//     ft_printf("freeing memory\n");
// }

int check_if_digits(char **argv)
{
    int i;
    int j;

    i = 1;
    while(argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int check_args(char **argv)
{
    int i;

    i = 1;
    if (check_if_digits(argv) == 0)
        return (1);
    while (argv[i])
    {
        if( ft_atoi(argv[i]) < 0)
            return (1);
        i++;
    }
    if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) >= 200)
        return (1);
    return (0);
}

void    print(t_data *data, char *str, int id)
{
    long long time;
    
    time = current_timestamp() - data->start_time;
    printf("%lld %d %s", time, id, str);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = current_timestamp();
	while (current_timestamp() - time < ms)
		usleep(ms / 10);
}