/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:28:11 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/16 13:00:00 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	load_data(char **av, t_data *data)
{
	if (check_input_valid(av) == true)
	{
		data->nb_philo = ft_atoi(av[1]);
		data->t_death = ft_atoi(av[2]);
		data->t_eat = ft_atoi(av[3]);
		data->t_sleep = ft_atoi(av[4]);
		data->nb_meal = -1;
		if (av[5])
			data->nb_meal = ft_atoi(av[5]);
		data->is_dead = false;
		data->philo->id = 0;
		data->philo->tid = data->nb_philo;
		//data->philo->r_fork = pthread_mutex_init(&data->philo->r_fork, NULL);
		//data->philo->l_fork = pthread_mutex_init(&data->philo->l_fork, NULL);
	}
	else
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	
	if (ac < 4 || ac > 5)
		return (printf("Invalid number of arguments\n"), 1);
	if	(load_data(av, &data) == -1)
		return (printf("Invalid argument/s\n"), 1);
	
	return (0);
}




/*
	pthread_mutex_init(&lock, NULL);
	pthread_create(&tid2, NULL, &routine, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock);

*/
/*
do check if num
do ft_atoi
Create a time calculator for u_int64_t !!!! ###### !!!!! #####
initialize all variables and allocate them.
prepare a free function for each malloc alocation


*/

/*		ARGS LIST
program
number philos
time philo must not eat to die
time it teaks each to eat
time it takes to sleep
times philo must eat to terminate program

if (ac != 6)
		return (printf("Invalid number of argumnts\n"));
*/

///	TESTING	///
/*
	int	x;
	x = 0;
	int rc;
	pthread_t thread_id[20];
	int tid;

	tid = pthread_self();

	while (x < 9)
	{
		x++;
		rc = pthread_create(&thread_id[x], NULL, test_print, (void *)x);
		if (rc)
		{
			printf("\n ERROR: return (code from pthread_create id %d \n", rc);
			break ;
		}
		printf("\nI am thread (%u). Created new thread (%u) in iterarion
			%d ...\n", tid, thread_id[x], x);
		if (x % 5 == 0)
			sleep(1);
	}
		pthread_exit(NULL);

*/