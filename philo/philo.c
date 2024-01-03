/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:28:11 by gforns-s          #+#    #+#             */
/*   Updated: 2024/01/04 00:39:42 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int				cont = 0;
pthread_mutex_t	lock;

void	*routine(void)
{
	int	i;

	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&lock);
		cont++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}
int	main(int ac, char **av)
{
	pthread_t tid1, tid2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&tid1, NULL, &routine, NULL);
	pthread_create(&tid2, NULL, &routine, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock);
	printf("cont: %d\n", cont);
}

/*
do check if num
do ft_atoi
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