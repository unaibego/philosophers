/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:11 by ubegona           #+#    #+#             */
/*   Updated: 2023/01/12 13:15:56 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "pthread.h"

// ********************************* estruktura ********************************

typedef struct s_data
{
	int				n_philo;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				amount_eat;
	pthread_t		*t;
	pthread_mutex_t	*mutex;
}				t_data;

typedef struct s_philo
{
	int				label;
	int				fork;
	struct s_data	*data;
	struct s_philo	*next_philo;	
}				t_philo;

// ********************************* make_move.c ***************************


#endif
