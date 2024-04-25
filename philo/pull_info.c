/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:24:40 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 02:14:52 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_death_time(t_data *data)
{
	long long	i;
	pthread_mutex_lock(&data->dead);
	i = data->t_death;
	pthread_mutex_unlock(&data->dead);
	return (i);

}

long long	get_lst_meal(t_philo *philo)
{
	long long	i;
	pthread_mutex_lock(&philo->lock);
	i =  philo->lst_meal;
	pthread_mutex_unlock(&philo->lock);
	return (i);
}
