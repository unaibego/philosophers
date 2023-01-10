/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:13:19 by ubegona           #+#    #+#             */
/*   Updated: 2023/01/10 14:06:17 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	resul;
	int	minus;

	i = 0;
	resul = 0;
	minus = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		i++;
		minus = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			resul = resul * 10 + str[i] - '0';
		i++;
	}
	return (resul * minus);
}

void	*philosopher(void *data)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)data;
	i = 0;
	while (i < 10000000)
	{
		pthread_mutex_lock(&p->data->mutex);
		pthread_mutex_unlock(&p->data->mutex);
		i++;
	}
	printf(" filosofoa naiz eta jaten nago hau da nire forka %d\n", p->fork);
	usleep(3);
	return (0);
}

void	addphilo(int content, t_philo **anterior)
{
	t_philo	*siguiente;
	t_philo	*ds;

	siguiente = (t_philo *)malloc(sizeof(t_philo));
	siguiente -> fork = content;
	siguiente -> next_philo = NULL;
	ds = (*anterior);
	while (ds -> next_philo != NULL)
	{
		ds = ds -> next_philo;
	}
	ds -> next_philo = siguiente;
}

t_data	fill_up(t_philo *philo, t_data data, int argc, char **argv)
{
	int	i;

	i = 1;
	data.n_philo = ft_atoi(argv[1]);
	data.t = malloc(sizeof(pthread_t) * data.n_philo);
	philo = malloc(sizeof(t_philo));
	philo -> fork = 0;
	philo -> next_philo = NULL;
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	data.amount_eat = ft_atoi(argv[5]);
	while (i < data.n_philo)
	{
		addphilo(0, &philo);
		i++;
	}
	return (data);
}

int	main(int argc, char	**argv)
{
	t_data		data;
	t_philo		*philo;
	int			i;

	data = fill_up(philo, data, argc, argv);
	printf("a ver zer den ha %d\n" ,philo -> fork);
	pthread_mutex_init(&data.mutex, NULL);
	i = 0;
	while (i < data.n_philo)
	{
		pthread_create(&data.t[i], NULL, &philosopher, &philo);
		i++;
	}
	i = 0;
	while (i < data.n_philo)
	{
		pthread_join(data.t[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&data.mutex);
	return (0);
}
