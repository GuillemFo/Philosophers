/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:08:19 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/23 13:02:10 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(uint64_t time)
{
	uint64_t	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < time)
		usleep(150);
	return (1);
}

void	p_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->meals++;
	pthread_mutex_unlock(&philo->lock);
}
