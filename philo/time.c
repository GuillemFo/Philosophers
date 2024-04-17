/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:09:17 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/17 12:33:41 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
