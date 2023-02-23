/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:43:21 by ubegona           #+#    #+#             */
/*   Updated: 2023/02/22 10:20:05 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	filo_printf(int time, int philo, char *string, t_philo	*p)
{
	pthread_mutex_lock(&p->data->mutex_die);
	printf("%d-->%d %s\n", time, philo, string);
	if (check_meals(p))
		pthread_mutex_unlock(&p->data->mutex_die);
	else
	{
		free_all(p);
		exit (0);
	}
}
