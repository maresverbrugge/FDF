/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:20:47 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/08 15:44:44 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h" // for libft
# include "printf/printf.h" // for my own written printf

# include <stdlib.h> // for malloc, free, exit
# include <unistd.h> // for write, read

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdio.h> // for PRINTF!!!

typedef struct s_data_points
{
	int x;
    int y;
    int z;
}	t_data_points;

typedef struct s_data
{
	int axis;
    int ordinate;
    int altitude;
}	t_data;

#endif