/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:11 by ubegona           #+#    #+#             */
/*   Updated: 2023/02/23 09:35:18 by ubegona          ###   ########.fr       */
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
	pthread_mutex_t	mutex_die;
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
size_t	ft_strlen(const char *str);
// ********************************* fill_up.c ***************************
void	fill_up_philo(t_philo *philo, t_data *data);
void	addphilo(int content, t_philo **anterior, t_data *data, int label);
void	fill_up_data(t_data *data, int argc, char **argv);
// ********************************* main.c ***************************
int		main(int argc, char	**argv);
void	*philosopher(void *philo);
// ********************************* checking_all.c ***************************
void	take_fork(void *philo);
int		check_meals(t_philo *philo);
void	checking_all(t_philo *philo);
// ********************************* print_philo.c ***************************
void	filo_printf(int time, int philo, char *string, t_philo	*p);
// ********************************* errors.c ***************************
int		check_erros(int argc, char **argv);
// ********************************* time.c ***************************
int		get_time(t_philo *philo);
int		get_start(void);
void	ft_sleep(int time, t_philo *philo);
// ********************************* free_all.c ***************************
void	free_all(t_philo *philo);
void	free_list(t_philo *philo);
#endif
