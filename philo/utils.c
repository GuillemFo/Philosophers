/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:48:35 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 12:54:10 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_and_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philo[i].lock);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
}

int	get_nb_philo(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->lock);
	i = (data->nb_philo);
	pthread_mutex_unlock(&data->lock);
	return (i);
}

void	p_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->meals = philo->meals + 1;
	pthread_mutex_unlock(&philo->lock);
}
