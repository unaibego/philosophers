/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:33:56 by ubegona           #+#    #+#             */
/*   Updated: 2023/02/23 13:18:52 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_meals(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		philo = philo->next_philo;
		if (philo -> count_eat != philo->data->amount_eat)
			return (1);
		i++;
	}
	return (0);
}

int	check_deads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		if ((get_time(philo) - philo->last_eat) > philo -> data -> time_die)
		{
			pthread_mutex_lock(&philo->data->mutex_die);
			printf("%d-->%d %s\n", get_time(philo), philo -> label, "is dead");
			usleep(200000);
			free_all(philo);
			exit(0);
			return (1);
		}
		philo = philo->next_philo;
		i++;
	}
	return (0);
}

void	checking_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (check_meals(philo))
	{
		check_deads(philo);
		i++;
	}
}
