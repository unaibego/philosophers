/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:33:56 by ubegona           #+#    #+#             */
/*   Updated: 2023/02/23 09:34:41 by ubegona          ###   ########.fr       */
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
			philo->data->finished = 0;
			ft_sleep(1, philo);
			filo_printf(get_time(philo), philo -> label, "is dead", philo);
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
		if (check_deads(philo))
		{
			free_all(philo);
			exit(0);
		}
		i++;
	}
}
