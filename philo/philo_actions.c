/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:51:45 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/23 13:39:58 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	check_philo_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if ((philo->data->is_dead) == true)
	{
		//pthread_mutex_unlock(&philo->data->lock);
		return (-99);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

void	ft_think(t_philo *philo)
{
	if (check_philo_status(philo) == -99)
		return ;
	printf("%llu Philo: %d is thinking\n", get_curr_time(philo->data),
		philo->id);
}

void	ft_eat(t_philo *philo)
{
	if (check_philo_status(philo) == -99)
		return ;
	printf("gdshj\n");
	pthread_mutex_lock(philo->r_fork);
	printf("%llu Philo: %d  has taken a fork\n", get_curr_time(philo->data),
		philo->id);
	if (check_philo_status(philo) == -99)
		return ;
	pthread_mutex_lock(philo->l_fork);
	printf("%llu Philo: %d  has taken a fork\n", get_curr_time(philo->data),
		philo->id);
	if (check_philo_status(philo) == -99)
		return ;
	pthread_mutex_lock(&philo->lock);
	philo->lst_meal = get_time_ms();
	pthread_mutex_unlock(&philo->lock);
	p_meals(philo);
	printf("%llu Philo: %d is eating\n", get_curr_time(philo->data), philo->id);
	ft_usleep(eat_time(philo));
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_sleep(t_philo *philo)
{
	uint64_t	time;

	if (check_philo_status(philo) == -99)
		return ;
	time = get_curr_time(philo->data);
	printf("%llu Philo: %d is sleeping\n", time, philo->id);
	time = sleep_time(philo);
	ft_usleep(time);
}

void	*routine(void *aux)
{
	t_philo	*philo;

	philo = aux;
	while (philo->data->is_dead == false)
	{	
		ft_eat(philo);;
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
