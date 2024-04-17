/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:51:45 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/17 17:18:13 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int			check_philo_status()	//add this function before any philo move like take a fork, think or sleep and close the thread with return. create a cleaner to destroy all threads and mutex
{
	
}

void	ft_think(t_philo *philo)
{
	printf("%llu Philo: %d is thinking\n", get_curr_time(philo->data),
		philo->id);
}

void	ft_eat(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(philo->r_fork);
	printf("%llu Philo: %d  has taken a fork\n", get_curr_time(philo->data),
		philo->id);
	pthread_mutex_lock(philo->l_fork);
	printf("%llu Philo: %d  has taken a fork\n", get_curr_time(philo->data),
		philo->id);
	pthread_mutex_lock(&philo->lock);
	philo->lst_meal = get_curr_time(philo->data);
	pthread_mutex_unlock(&philo->lock);
	printf("%llu Philo: %d is eating\n", philo->lst_meal, philo->id);
	time = eat_time(philo);
	usleep(time);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_sleep(t_philo *philo)
{
	uint64_t	time;

	time = get_curr_time(philo->data);
	printf("%llu Philo: %d is sleeping\n", time, philo->id);
	time = sleep_time(philo);
	usleep(time);
}

void	*routine(void *aux)
{
	t_philo	*philo;

	philo = aux;
	ft_eat(philo);
	ft_sleep(philo);
	ft_think(philo);
	return (NULL);
}
