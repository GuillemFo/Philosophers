/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:49:45 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 12:57:50 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_curr_time(t_data *data)
{
	unsigned long long	tm;

	tm = get_time_ms();
	pthread_mutex_lock(&data->lock);
	tm = tm - data->t0;
	pthread_mutex_unlock(&data->lock);
	return (tm);
}

unsigned long long	get_curr_time_f(t_data *data)
{
	unsigned long long	tm;

	tm = get_time_ms();
	tm = tm - data->t0;
	return (tm);
}

unsigned long long	init_time(t_data *data)
{
	unsigned long long	tm;

	pthread_mutex_lock(&data->lock);
	tm = data->t0;
	pthread_mutex_unlock(&data->lock);
	return (tm);
}

unsigned long long	get_time_ms(void)
{
	struct timeval		time;
	unsigned long long	t;

	gettimeofday(&time, NULL);
	t = (unsigned long long)(time.tv_sec * 1000)
		+ (unsigned long long)(time.tv_usec / 1000);
	return (t);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_p(philo, get_curr_time(philo->data), philo->id, "is sleeping");
	ft_usleep(philo->t_sleep);
}
