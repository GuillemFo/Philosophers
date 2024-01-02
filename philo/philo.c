/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:28:11 by gforns-s          #+#    #+#             */
/*   Updated: 2024/01/02 12:27:21 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test_print(void *data)
{
	printf("Hello from new thread (%u) - I was created in  iteration %u\n", pthread_self(), data);
	pthread_exit(NULL);
}

int	main(int ac, char **av)
{
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
		printf("\nI am thread (%u). Created new thread (%u) in iterarion %d ...\n", tid, thread_id[x], x);
		if (x % 5 == 0)
			sleep(1);
	}
		pthread_exit(NULL);

	/*
	if (ac != 6)
		return (printf("Invalid number of argumnts\n"));
	*/
}