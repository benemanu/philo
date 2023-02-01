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
    t_info data;

    if (argc == 5 || argc == 6)
    {
        if (init_var(&data, argv) == 1)
            free(&data.philo);
        else
            init_philo(&data);
    }
    my_free(&data);

}
