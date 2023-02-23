/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:13:19 by ubegona           #+#    #+#             */
/*   Updated: 2023/02/23 09:52:50 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	pthread_mutex_lock(&p->data->mutex[p->label]);
	filo_printf(get_time(p), p -> label, "has taken a fork", p);
	p->fork = 1;
	pthread_mutex_lock(&p->data->mutex[(p->label + 1) % p->data->n_philo]);
	p -> last_eat = get_time(p);
	p->next_philo->fork = 1;
	filo_printf(get_time(p), p -> label, "is eating", p);
	p ->count_eat++;
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
	if ((p->label + 1) % 2 == 0)
		usleep(p->data->time_eat);
	while (i != p->data->amount_eat)
	{
		take_fork(philo);
		filo_printf(get_time(p), p -> label, "is sleeping", p);
		ft_sleep(p -> data -> time_sleep, p);
		filo_printf(get_time(p), p -> label, "is thinking", p);
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
	fill_up_data(data, argc, argv);
	fill_up_philo(philo, data);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	pthread_mutex_init(&data->mutex_die, NULL);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		pthread_create(&data->t[i], NULL, &philosopher, philo);
		philo = philo->next_philo;
		i++;
	}
	checking_all(philo);
	exit(0);
}
