/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:20:47 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/08 14:26:58 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h" // for libft

# include <stdlib.h> // for malloc, free, exit
# include <unistd.h> // for write, read

# include <stdio.h> // for PRINTF!!!

typedef struct s_data_points
{
	int x;
    int y;
    int z;
}	t_data_points;

#endif