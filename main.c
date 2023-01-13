/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:13:19 by ubegona           #+#    #+#             */
/*   Updated: 2023/01/13 14:13:48 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	pthread_mutex_lock(&p->data->mutex[p->label]);
	p->fork = 1;
	pthread_mutex_lock(&p->data->mutex[(p->label + 1) % p->data->n_philo]);
	p -> last_eat = get_time(p);
	p->next_philo->fork = 1;
	if (p -> data -> finished)
		printf("%d --> %d jaten ari da\n", (get_time(p)), p -> label);
	ft_sleep(p -> data -> time_eat, p);
	pthread_mutex_unlock(&p->data->mutex[(p->label + 1) % p->data->n_philo]);
	pthread_mutex_unlock(&p->data->mutex[p->label]);
}

void	*philosopher(void *philo)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)philo;
	i = 0;
	while (i < p->data->amount_eat)
	{
		if (p->label % 2 == 0)
			usleep(50);
		take_fork(philo);
		p ->count_eat++;
		if (p -> data -> finished)
			printf("%d --> %d lotan dago\n", get_time(p), p -> label);
		ft_sleep(p -> data -> time_sleep, p);
		i++;
	}
	return (0);
}

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
			ft_sleep(20, philo);
			printf("%d --> %d hil da\n", get_time(philo), philo -> label);
			return (1);
		}
		philo = philo->next_philo;
		i++;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	t_data		*data;
	t_philo		*philo;
	int			i;

	if (check_erros(argc, argv))
		return (0);
	philo = malloc(sizeof(t_philo));
	data = malloc(sizeof(t_data));
	fill_up(philo, data, argc, argv);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		pthread_create(&data->t[i], NULL, &philosopher, philo);
		philo = philo->next_philo;
		i++;
	}
	i = 0;
	while (check_meals(philo))
	{
		if (check_deads(philo))
			return (0);
		i++;
	}
	return (0);
}
