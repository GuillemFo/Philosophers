/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:20:31 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/18 13:02:54 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->nb_philo)
	{
		printf("Time: %llu\n", get_curr_time(data));
		printf("Eat: %llu\n", eat_time(data->philo));
		printf("Sleep: %llu\n", sleep_time(data->philo));
		printf("Lst Meal: %llu\n", lst_meal_time(&data->philo[i]));
		printf("Death: %llu\n", death_time(&data->philo[i]));

		printf("Cal : %llu\n", (get_curr_time(data) - lst_meal_time(data->philo)));
		
		if (get_curr_time(data) - lst_meal_time(data->philo) >=
			death_time(&data->philo[i]))
		{
			pthread_mutex_lock(&data->lock);
			data->is_dead = true;
			pthread_mutex_unlock(&data->lock);
			return (-1);
		}
		usleep(10);
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
		data->philo[i].lst_meal = data->t0;
		printf("%llu\n", data->t0);
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
		usleep(250);
	}
	i = 0;
	while (data->is_dead == false)
	{
		if (ft_is_dead(data) == -1)
			printf(C_RED "%llu Philo: %d  died\n"C_WHITE, get_curr_time(data),
				data->philo->id);
	}
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}
	return (0);
}
