/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:20:31 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/23 15:55:34 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->nb_philo)
	{
		// printf("Time: %llu\n", get_curr_time(data));
		// printf("Eat: %llu\n", eat_time(data->philo));
		// printf("Sleep: %llu\n", sleep_time(data->philo));
		// printf("Lst Meal: %llu\n", lst_meal_time(&data->philo[i]));
		// printf("Death: %llu\n", death_time(&data->philo[i]));
// 
		//printf("Cal : %llu\n", lst_meal_time(data->philo));
		
		if (get_time_ms() -  lst_meal_time(&data->philo[i]) >=
			death_time(&data->philo[i]))
		{
			pthread_mutex_lock(&data->lock);
			data->is_dead = true;
			pthread_mutex_unlock(&data->lock);
			return (data->philo[i].id);
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
		data->philo[i].meals = -1;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		data->philo[i].lst_meal = get_time_ms();
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
		usleep(50);
	}
	while (data->is_dead == false)
	{
		int	p;
		
		p = ft_is_dead(data);
		if (p > 0)
		{
			printf(C_RED "%llu Philo: %d  died\n"C_WHI, get_curr_time(data), p);
			i = -1;
			while (++i < data->nb_philo)
			{
				pthread_join(data->philo[i].tid, NULL);
				pthread_mutex_destroy(data->philo[i].r_fork);
			}
		}
	}
	// i = -1;
	// while (++i < data->nb_philo)
	// {
		// pthread_join(data->philo[i].tid, NULL);
	// }
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(data->philo[i].r_fork);
	return (0);
}
