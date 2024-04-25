/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:09:17 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 12:53:24 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	lst_meal_time(t_philo *philo)
{
	unsigned long long	tm;

	pthread_mutex_lock(&philo->lock);
	tm = philo->lst_meal;
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

unsigned long long	death_time(t_philo *philo)
{
	unsigned long long	tm;

	pthread_mutex_lock(&philo->lock);
	tm = (philo->t_death);
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

unsigned long long	eat_time(t_philo *philo)
{
	unsigned long long	tm;

	pthread_mutex_lock(&philo->lock);
	tm = (philo->t_eat);
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

int	get_data_meal(t_data *data)
{
	int	i;

	i = (data->nb_meal);
	return (i);
}

unsigned long long	sleep_time(t_philo *philo)
{
	unsigned long long	tm;

	pthread_mutex_lock(&philo->lock);
	tm = (philo->t_sleep);
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}
