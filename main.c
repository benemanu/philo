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

    data.arg_c = argc;
    if (argc == 5 || argc == 6)
    {
        if (init_var(&data, argv, argc) == 1)
        {
            //free(&data.philo);
            ft_printf("error: wrong arguments\n");
        }    
        else
            init_philo(&data);
    }
    else
        ft_printf("error: wrong number of arguments\n");
    my_free(&data);
    return (0);
}
