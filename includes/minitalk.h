/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:11:09 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/09 14:06:13 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_message
{
	char	tmp_char;
	int		counter;
}				t_message;

#endif