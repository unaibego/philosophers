/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:13:19 by ubegona           #+#    #+#             */
/*   Updated: 2023/01/12 13:52:16 by ubegona          ###   ########.fr       */
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

void	take_fork(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	printf("zenbat da hau %d eta hau %d\n", p->label, p->data->n_philo);
	pthread_mutex_lock(&p->data->mutex[p->label]);
	p->fork = 1;
	printf("jaixo\n");
	pthread_mutex_lock(&p->data->mutex[(p->label + 1) % p->data->n_philo]);
	p->next_philo->fork = 1;
	printf(" %d filosofoa jaten ari da", p -> label);
	pthread_mutex_unlock(&p->data->mutex[(p->label + 1) % p->data->n_philo]);
	pthread_mutex_unlock(&p->data->mutex[p->label]);
}

void	*philosopher(void *philo)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)philo;
	i = 0;
	if (p->label % 2 == 0)
		usleep(50);
	printf("data konprobatzen %d\n", p->data->n_philo);
	take_fork(philo);
	// printf("a ver zer den ha %s\n" ,p -> data);
	while (i < 10000000)
	{
		pthread_mutex_unlock(&p->data->mutex);
		i++;
	}
	printf(" filosofoa naiz eta jaten nago hau da nire forka %d\n", p->label);
	usleep(3);
	return (0);
}

void	addphilo(int content, t_philo **anterior, t_data data, int label)
{
	t_philo	*siguiente;
	t_philo	*ds;

	siguiente = (t_philo *)malloc(sizeof(t_philo));
	siguiente -> fork = content;
	siguiente -> label = label;
	siguiente -> data = &data;
	siguiente -> next_philo = NULL;
	ds = (*anterior);
	while (ds -> next_philo != NULL)
	{
		ds = ds -> next_philo;
	}
	ds -> next_philo = siguiente;
	// siguiente -> next_philo = (*anterior);
}

t_data	fill_up(t_philo *philo, t_data data, int argc, char **argv)
{
	int		i;
	t_philo	*ds;

	i = 1;
	data.n_philo = ft_atoi(argv[1]);
	data.t = malloc(sizeof(pthread_t) * data.n_philo);
	philo -> data = &data;
	philo -> fork = 0;
	philo -> label = 0;
	philo -> next_philo = NULL;
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	data.amount_eat = ft_atoi(argv[5]);
	while (i < data.n_philo)
	{
		addphilo(0, &philo, data, i);
		i++;
	}
	ds = philo;
	while (ds -> next_philo != NULL)
	{
		ds = ds -> next_philo;
	}
	ds -> next_philo = philo;
	return (data);
}

int	main(int argc, char	**argv)
{
	t_data		data;
	t_philo		*philo;
	int			i;

	philo = malloc(sizeof(t_philo));
	data = fill_up(philo, data, argc, argv);
	data.mutex = malloc(sizeof(pthread_mutex_t) * data.n_philo);
	i = 0;
	while (i < data.n_philo)
	{
		pthread_mutex_init(&data.mutex[i], NULL);
		pthread_create(&data.t[i], NULL, &philosopher, philo);
		philo = philo->next_philo;
		i++;
	}
	i = 0;
	while (i < data.n_philo)
	{
		// pthread_mutex_destroy(&data.mutex[i]);
		pthread_join(data.t[i], NULL);
		i++;
	}
	
	return (0);
}
