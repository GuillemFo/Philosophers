/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:08:19 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 14:35:56 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(uint64_t time, t_philo *philo)
{
	uint64_t	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < time && check_philo_status(philo) == 0)
		usleep(50);

}

void	p_meals(t_philo *philo)
{
	philo->meals_cnt++;
}
