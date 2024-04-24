/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:51:45 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 18:02:52 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	check_philo_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if ((philo->data->is_dead) == true)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (-99);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

void	ft_think(t_philo *philo)
{
	// if (check_philo_status(philo) == -99)
	// 	return ;
	
	ft_print_p(philo, get_curr_time_f(philo->data), philo->id, "is thinking");
	
}

void	ft_eat(t_philo *philo)
{
	// if (check_philo_status(philo) == -99)
	// 	return ;
	pthread_mutex_lock(philo->r_fork);
	ft_print_p(philo, get_curr_time_f(philo->data), philo->id, "has taken a fork");

	// if (check_philo_status(philo) == -99)
	// {
	// 	pthread_mutex_unlock(philo->r_fork);
	// 	return ;
	// }
	pthread_mutex_lock(philo->l_fork);
	ft_print_p(philo, get_curr_time_f(philo->data), philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->lock);
	philo->lst_meal = get_time_ms();
	pthread_mutex_unlock(&philo->lock);
	p_meals(philo);
	// if (check_philo_status(philo) == -99)
	// {
	// 	pthread_mutex_unlock(philo->r_fork);
	// 	pthread_mutex_unlock(philo->l_fork);
	// 	return ;
	// }
	
	ft_print_p(philo, get_curr_time_f(philo->data), philo->id, "is eating");
	
	ft_usleep(eat_time(philo), philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_sleep(t_philo *philo)
{
	// if (check_philo_status(philo) == -99)
	// 	return ;
	
	ft_print_p(philo, get_curr_time_f(philo->data), philo->id, "is sleeping");
	
	ft_usleep(sleep_time(philo), philo);
}

void	*routine(void *aux)
{
	t_philo	*philo;

	philo = aux;
	while (check_philo_status(philo) == 0)
	{
		// if (check_philo_status(philo) == -99)
		// 	return (NULL);
		ft_eat(philo);
		// if (check_philo_status(philo) == -99)
		// 	return (NULL);
		ft_sleep(philo);
		// if (check_philo_status(philo) == -99)
		// 	return (NULL);
		ft_think(philo);
	}
	return (NULL);
}
