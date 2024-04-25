/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:25:22 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 02:22:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_round(t_philo *philo)
{
	philo->round += 1;
	if (philo->round == philo->nb_meal)
		philo->full = true;
}

unsigned long long	get_curr_time_clean(t_data *data)
{
	unsigned long long	time;

	pthread_mutex_lock(&data->lock);
	time = get_time_ms() - data->t0;
	pthread_mutex_unlock(&data->lock);
	return (time);
}
unsigned long long	get_curr_time_clean_u(t_data *data)
{
	unsigned long long	time;

	time = get_time_ms() - data->t0;
	return (time);
}

void	set_lst_meal(t_data *data)
{
	pthread_mutex_lock(&data->philo->lock);
	data->philo->lst_meal = (get_time_ms());
	pthread_mutex_unlock(&data->philo->lock);

}

unsigned long long	get_time_ms(void)
{
	struct timeval	time;
	unsigned long long		t;

	gettimeofday(&time, NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t);
}
