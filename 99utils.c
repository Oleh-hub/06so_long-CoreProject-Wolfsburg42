/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:53:34 by oruban            #+#    #+#             */
/*   Updated: 2024/03/20 11:33:15 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// closes open mam file and fees memory allocated by gnl, 
// if fd > 0 and str != NULL 
void	error_exit(const char *message, int fd, char *line1, char *line2)
{
	if (fd > 0)
		close (fd);
	if (!line1)
		free (line1);
	if (!line2)
		free (line2);
	write (2, message, ft_strlen(message));
	exit (1);
}
