/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:09:17 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 14:31:53 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	lst_meal_time(t_philo *philo)
{
	uint64_t	tm;

	tm = philo->lst_meal;
	return (tm);
}

uint64_t	death_time(t_philo *philo)
{
	uint64_t	tm;

	tm = (philo->data->t_death);
	return (tm);
}

uint64_t	eat_time(t_philo *philo)
{
	uint64_t	tm;

	tm = (philo->data->t_eat);
	return (tm);
}

uint64_t	sleep_time(t_philo *philo)
{
	uint64_t	tm;

	tm = (philo->data->t_sleep);
	return (tm);
}

uint64_t	get_curr_time_f(t_data *data)
{
	uint64_t	tm;

	tm = get_time_ms();
	tm = tm - data->t0;
	return (tm);
}

uint64_t	get_curr_time(t_data *data)
{
	uint64_t	tm;

	tm = get_time_ms();
	tm = tm - data->t0;
	return (tm);
}

uint64_t	init_time(t_data *data)
{
	uint64_t	tm;

	tm = data->t0;
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
