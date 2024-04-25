/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:24:40 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 02:24:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_death_status(t_philo *philo)
{
	bool	i;
	
	pthread_mutex_lock(&philo->data->dead);
	i = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->dead);
	return (i);
}
unsigned long long	get_death_time(t_data *data)
{
	unsigned long long	i;
	
	pthread_mutex_lock(&data->dead);
	i = data->t_death;
	pthread_mutex_unlock(&data->dead);
	return (i);
}

unsigned long long	get_lst_meal(t_philo *philo)
{
	unsigned long long	i;

	pthread_mutex_lock(&philo->lock);
	i =  philo->lst_meal;
	pthread_mutex_unlock(&philo->lock);
	return (i);
}
