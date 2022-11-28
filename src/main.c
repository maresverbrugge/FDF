/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:25:57 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/28 14:40:12 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error(void)
{
	ft_putendl_fd(strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

void	hook(void *mlx)
{
	// Close the window when pressing escape key
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
	// 	the_map->instances[0].y -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// 	the_map->instances[0].y += 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	// 	the_map->instances[0].x -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	// 	the_map->instances[0].x += 5;
}

void	free_all(t_map *map_data)
{
	free(map_data->data_points);
	free(map_data->int_array);
	free_2d_array(map_data->str_split);
}

int	fdf(int argc, char **argv)
{
	t_map		map_data;
	mlx_t		*mlx;
	mlx_image_t	*the_map;

	if (argc > 1)
	{
		parse_map(argv, &map_data);
		edit_data_points(&map_data);
		// mlx_set_setting(MLX_MAXIMIZED, true);
		// Start mlx:
		mlx = mlx_init(SCREEN_WIDTH, SCREEN_LENGTH, "Marès is koning", true);
		// mlx = NULL;
		if (!mlx)
			error();
		// Create a new image:
		the_map = mlx_new_image(mlx, MAP_WIDTH, MAP_LENGTH);
		//  Display instance of image:
		if (!the_map || mlx_image_to_window(mlx, the_map, 0, 0) < 0)
			error();
		// Draw data points on image:
		draw_grid(the_map, &map_data);
		// Creates a new instance/copy of an already existing image:
		mlx_loop_hook(mlx, &hook, mlx);
		mlx_loop(mlx);
		// Deletes an image and removes it from the render queue:
		mlx_delete_image(mlx, the_map);
		mlx_terminate(mlx);
		free_all(&map_data);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	fdf(argc, argv);
	// system("leaks fdf");
	return (0);
}
