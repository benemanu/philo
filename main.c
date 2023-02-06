/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:58:39 by bhielsch          #+#    #+#             */
/*   Updated: 2023/02/01 13:58:41 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int argc, char **argv)
{
    t_data data;

    if (argc < 5 || argc > 6)
        return (1);
    if (check_args(argv) == 1)
    {
        ft_printf("error: wrong arguments\n");
        return (1);
    }    
    if (init(&data, argv, argc) == 1)
        return (1);
    if (data.no_philos == 1)
        return (one_philo(&data));
    if (init_thread(&data) == 1)
        return (1);
    my_free(&data);
    return (0);
}