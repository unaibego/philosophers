/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:24:39 by ubegona           #+#    #+#             */
/*   Updated: 2023/01/13 14:26:56 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fill_up(t_philo *philo, t_data *data, int argc, char **argv)
{
	int		i;
	t_philo	*ds;

	i = 1;
	data->n_philo = ft_atoi(argv[1]);
	data->t = malloc(sizeof(pthread_t) * data->n_philo);
	philo -> data = data;
	philo -> fork = 0;
	philo -> label = 0;
	data->start_time = get_start();
	philo -> last_eat = get_time(philo);
	philo ->count_eat = 0;
	philo -> next_philo = NULL;
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->amount_eat = ft_atoi(argv[5]);
	else
		data->amount_eat = -5;
	data->finished = 1;
	while (i < data->n_philo)
	{
		addphilo(0, &philo, data, i);
		i++;
	}
	ds = philo;
	while (ds -> next_philo != NULL)
		ds = ds -> next_philo;
	ds -> next_philo = philo;
}

void	addphilo(int content, t_philo **anterior, t_data *data, int label)
{
	t_philo	*siguiente;
	t_philo	*ds;

	siguiente = (t_philo *)malloc(sizeof(t_philo));
	siguiente -> fork = content;
	siguiente -> label = label;
	siguiente -> data = data;
	siguiente -> next_philo = NULL;
	ds = (*anterior);
	while (ds -> next_philo != NULL)
	{
		ds = ds -> next_philo;
	}
	ds -> next_philo = siguiente;
}
