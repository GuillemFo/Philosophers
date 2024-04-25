/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:25:22 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 01:50:46 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_round(t_philo *philo)
{
	philo->round += 1;
	if (philo->round == philo->nb_meal)
		philo->full = true;
}

long long	get_curr_time_clean(t_data *data)
{
	long long	time;

	time = get_time_ms();
	pthread_mutex_lock(&data->lock);
	time = time - data->t0;
	pthread_mutex_unlock(&data->lock);
	return (time);
}

long long	get_curr_time_clean_u(t_data *data)
{
	long long	time;

	time = get_time_ms();
	time = time - data->t0;
	return (time);
}

long long	get_time_ms(void)
{
	struct timeval	time;
	long long		t;

	gettimeofday(&time, NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t);
}
