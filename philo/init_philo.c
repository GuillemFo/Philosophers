/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:20:31 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/17 17:02:14 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (get_curr_time(data) - lst_meal_time(&data->philo[i]) <
			death_time(&data->philo[i]))
		{
			pthread_mutex_lock(&data->lock);
			data->is_dead = true;
			pthread_mutex_unlock(&data->lock);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		data->philo[i].lst_meal = -1;
		data->philo[i].r_fork = &data->fork[i];
		if (i < data->nb_philo - 1)
			data->philo[i].l_fork = &data->fork[i + 1];
		else
			data->philo[i].l_fork = &data->fork[0];
		i++;
	}
	return (0);
}

int	create_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo[i].tid, NULL, routine, &data->philo[i]);
		i++;
	}
	i = 0;
	if (ft_is_dead(data) == -1)
		printf("%llu Philo: %d  died\n", get_curr_time(data),
			data->philo->id);
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}
	return (0);
}
