/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:08:19 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/23 09:37:42 by gforns-s         ###   ########.fr       */
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