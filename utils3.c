/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:51:56 by bhielsch          #+#    #+#             */
/*   Updated: 2023/02/08 16:17:27 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int ms)
{
	long int	time;

	time = current_timestamp();
	while (current_timestamp() - time < ms)
		usleep(ms / 10);
}

int	is_no_philos(t_data *data, int i)
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

void	data_plus(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	data->finished++;
	pthread_mutex_unlock(&data->lock);
}

void	lock_forks1(t_data *data, int i)
{
	if (i % 2 == 0)
		pthread_mutex_lock(data->philos[i - 1].rf);
	else
		pthread_mutex_lock(data->philos[i - 1].lf);
	print(data, "has taken a fork\n", i);
}

void	lock_forks2(t_data *data, int i)
{
	if (i % 2 == 0)
		pthread_mutex_lock(data->philos[i - 1].lf);
	else
		pthread_mutex_lock(data->philos[i - 1].rf);
	print(data, "has taken a fork\n", i);
}
