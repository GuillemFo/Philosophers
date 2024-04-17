/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:09:17 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/17 13:33:02 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	eat_time(t_philo *philo)
{
	uint64_t	tm;

	pthread_mutex_lock(&philo->data->lock);
	tm = (philo->data->t_eat * 1000);
	pthread_mutex_unlock(&philo->data->lock);
	return (tm);
}

uint64_t	sleep_time(t_philo *philo)
{
	uint64_t	tm;

	pthread_mutex_lock(&philo->data->lock);
	tm = (philo->data->t_sleep * 1000);
	pthread_mutex_unlock(&philo->data->lock);
	return (tm);
}

uint64_t	get_curr_time(t_data *data)
{
	uint64_t	tm;

	tm = get_time_ms();
	pthread_mutex_lock(&data->lock);
	tm = tm - data->t0;
	pthread_mutex_unlock(&data->lock);
	return (tm);
}

uint64_t	get_time_ms(void)
{
	struct timeval	time;
	uint64_t		t;

	gettimeofday(&time, NULL);
	t = (uint64_t)(time.tv_sec * 1000) + (uint64_t)(time.tv_usec / 1000);
	return (t);
}
