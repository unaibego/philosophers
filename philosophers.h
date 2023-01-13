/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:11 by ubegona           #+#    #+#             */
/*   Updated: 2023/01/13 13:33:43 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "pthread.h"
# include "sys/time.h"

// ********************************* estruktura ********************************

typedef struct s_data
{
	int				n_philo;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				finished;
	int				amount_eat;
	int				start_time;
	pthread_t		*t;
	pthread_mutex_t	*mutex;
}				t_data;

typedef struct s_philo
{
	int				label;
	int				fork;
	int				count_eat;
	int				last_eat;
	struct s_data	*data;
	struct s_philo	*next_philo;	
}				t_philo;

// ********************************* libft.c ***************************
int		ft_atoi(const char *str);
// ********************************* fill_up.c ***************************
void	fill_up(t_philo *philo, t_data *data, int argc, char **argv);
void	addphilo(int content, t_philo **anterior, t_data *data, int label);
// ********************************* main.c ***************************
int		main(int argc, char	**argv);
void	*philosopher(void *philo);
void	take_fork(void *philo);
// ********************************* errors.c ***************************
int		check_erros(int argc, char **argv);
// ********************************* time.c ***************************
int		get_time(t_philo *philo);
int		get_start(void);
void	ft_sleep(int time, t_philo *philo);
#endif
