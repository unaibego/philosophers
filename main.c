/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:13:19 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/27 17:32:40 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void*	philosopher(int **i)
{
	printf(" %d filosofoa naiz eta jaten nago\n", **i);
	return(0);
}

int main()
{
	pthread_t	t1[5];
	int			i;
	int			*p;
	int 		male;

	i = 0;
	p = &i;
	while (i < 5)
	{
		pthread_create(&t1[i], NULL, &philosopher, &p);
		i++;
	}
	pthread_join(t1[0], NULL);
	pthread_join(t1[1], NULL);
	pthread_join(t1[2], NULL);
	pthread_join(t1[3], NULL);
	pthread_join(t1[4], NULL);

	return(0);
}
