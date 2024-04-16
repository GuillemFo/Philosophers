/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:20:31 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/16 16:59:28 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].data = data;
		printf("Data access is_dead: %d\n", data->philo[i].data->is_dead);
		data->philo[i].id = i + 1;
		data->philo[i].r_fork = &data->fork[i];
		if (i < data->nb_philo - 1)
			data->philo[i].l_fork = &data->fork[i + 1];
		else
			data->philo[i].l_fork = &data->fork[0];
		printf("Philo_id:%d r_fork:%p\n", data->philo[i].id, data->philo[i].r_fork);
		printf("Philo_id:%d l_fork:%p\n", data->philo[i].id, data->philo[i].l_fork);
		i++;
	}
	return (0);
}
