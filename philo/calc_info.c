/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:25:22 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 00:58:07 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_round(t_philo *philo)
{
	philo->round += 1;
	if (philo->round == philo->nb_meal)
		philo->full = true;
}

unsigned long	lst_meal_time(t_philo *philo)
{
	unsigned long	i;
	i = philo->lst_meal;
	pthread_mutex_lock(&philo->data->lock);
	i = i - philo->data->t0;
	pthread_mutex_unlock(&philo->data->lock);
	return (i);
}

unsigned long	get_curr_time(t_data *data)
{
	unsigned long	time;

	time = get_time_ms();
	pthread_mutex_lock(&data->lock);
	time = time - data->t0;
	pthread_mutex_unlock(&data->lock);
	return (time);
}

unsigned long	get_curr_time_u(t_data *data)
{
	unsigned long	time;

	time = get_time_ms();
	time = time - data->t0;
	return (time);
}

unsigned long	get_time_ms(void)
{
	struct timeval	time;
	unsigned long		t;

	gettimeofday(&time, NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t);
}
