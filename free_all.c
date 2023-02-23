/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:44:30 by ubegona           #+#    #+#             */
/*   Updated: 2023/02/23 09:28:35 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philo *philo)
{
	free(philo->data->mutex);
	free(philo->data->t);
	free_list(philo);
}

void	free_list(t_philo *philo)
{
	t_philo	*ds;
	int		i;

	i = philo->data->n_philo;
	free((philo)->data);
	while (0 < i)
	{
		ds = philo-> next_philo;
		free(philo);
		philo = ds;
		i--;
	}
}
