/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:25:22 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 04:06:42 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_round(t_philo *philo)
{
	philo->round += 1;
	if (philo->round == philo->nb_meal)
		philo->full = true;
}

uint64_t	get_curr_time_clean(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->lock);
	time = get_time_ms() - data->t0;
	pthread_mutex_unlock(&data->lock);
	return (time);
}
uint64_t	get_curr_time_clean_u(t_data *data)
{
	uint64_t	time;

	time = get_time_ms() - data->t0;
	return (time);
}

void	set_lst_meal(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	pthread_mutex_lock(&data->philo->lock);
	data->philo->lst_meal = (get_time_ms() - data->t0);
	pthread_mutex_unlock(&data->philo->lock);
	pthread_mutex_unlock(&data->lock);
}

uint64_t	get_time_ms(void)
{
	struct timeval	time;
	uint64_t		t;

	gettimeofday(&time, NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t);
}
