/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_q.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:31:03 by hgranule          #+#    #+#             */
/*   Updated: 2020/12/24 02:44:22 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_Q_H
# define LOG_Q_H

# include <stdbool.h>
# include <pthread.h>
# include "timer.h"

# define LOG_QUEUE_CAPACITY 1024

typedef struct s_log_queue	t_log_q;
typedef struct s_log_item	t_log_item;

struct						s_log_item
{
	int						philo_id;
	t_time_ms				time;
	const char				*message;
};

struct						s_log_queue
{
	t_log_item				*data;
	unsigned				h;
	unsigned				t;
	unsigned				len;
	unsigned				size;
};

void						log_q_push(t_log_q *q, struct s_log_item li);
const t_log_item			*log_q_head(t_log_q *q);
void						log_q_pop(t_log_q *q);
bool						log_q_isempty(t_log_q *q);
bool						log_q_isfull(t_log_q *q);

extern pthread_mutex_t		g_atomic;

#endif
