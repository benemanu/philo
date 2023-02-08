/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:58:39 by bhielsch          #+#    #+#             */
/*   Updated: 2023/02/08 16:17:18 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (argc < 5 || argc > 6 || check_args(argv) == 1)
		my_exit();
	if (init(&data, argv, argc) == 1)
		return (1);
	if (data.no_philos == 1)
		return (one_philo(&data));
	if (init_thread(&data) == 1)
		return (1);
	while (is_philo_dead(&data) == 0)
	{
		i = 0;
		while (is_no_philos(&data, i) == 0 && is_philo_dead(&data) == 0)
		{
			pthread_mutex_lock(&data.philos[i].lock);
			if (current_timestamp() >= data.philos[i].time_to_die)
				print(&data, "died\n", data.philos[i].id);
			pthread_mutex_unlock(&data.philos[i++].lock);
		}
	}
	join_thread(&data);
	my_free(&data);
}

void	my_exit(void)
{
	ft_printf("error: wrong arguments\n");
	exit(1);
}
