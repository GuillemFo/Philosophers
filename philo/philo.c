/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:28:11 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/15 13:08:07 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	load_data(char **av, t_data *data)
{
	data->tid = (pthread_t *)malloc (data->philo_nb * sizeof(pthread_t));
	data->philo_nb = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	data->meals_nb = ft_atoi(av[5]);
	data->philo = (t_philo *) malloc (data->philo_nb * sizeof(t_philo));
	data->dead = 0;
	data->finished = 0;
	

}

void	*routine(t_philo *philo)
{
	printf("Time: (%llu) Philo (%d)\n", philo->id);
	
	pthread_mutex_lock(&philo->lock);
	pthread_mutex_unlock(&philo->lock);
	pthread_exit(NULL);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		data;
	int			i;
	i = 0;
	load_data(av, &data);
	pthread_mutex_init(&data.write, NULL);
	while (i < data.philo_nb)
	{
		pthread_mutex_init(&data.philo[i].lock, NULL);
		//pthread_mutex_lock(&data.write);
		data.philo[i].id = i;
		pthread_create(&data.tid[i], NULL, &routine, (void *)&data.philo[i]);
		i++;
	}
	i = 0;
	while (i < data.philo_nb)
	{
		pthread_join(data.tid[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&data.write);
	printf("philos: %d\n", i);
	pthread_exit(NULL);
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
			exit(1);
		}
		printf("\nI am thread (%u). Created new thread (%u) in iterarion
			%d ...\n", tid, thread_id[x], x);
		if (x % 5 == 0)
			sleep(1);
	}
		pthread_exit(NULL);

*/