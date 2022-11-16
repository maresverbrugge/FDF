/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:25:57 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/16 16:48:55 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	hook(void *mlx)
{
	// Close the window when pressing escape key
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	// Modify the x & y position of an already existing instance:
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
	// 	the_map->instances[0].y -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// 	the_map->instances[0].y += 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	// 	the_map->instances[0].x -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	// 	the_map->instances[0].x += 5;
}

void free_all(t_map *map_data)
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
		// printf("map_data.rows = %d\n", map_data.rows);
		// printf("map_data.columns = %d\n", map_data.columns);
		// printf("map_data.amount_of_points = %d\n", map_data.amount_of_points);
		// printf("map_data.map_as_str = \n%s\n", map_data.map_as_str);
		// int i = 0;
		// while (map_data.str_split[i])
		// {
		// 	printf("map_data.str_split[%d] = %s\n", i, map_data.str_split[i]);
		// 	i++;
		// }
		mlx = mlx_init(WIDTH, HEIGHT, "Marès is koning", true);
		if (!mlx)
			exit(EXIT_FAILURE);
		// Creates a whole new image:
		the_map = mlx_new_image(mlx, 128, 128);
		// Set every pixel to white:
		memset(the_map->pixels, 255, the_map->width * the_map->height * sizeof(int));
		// Creates a new instance/copy of an already existing image:
		mlx_image_to_window(mlx, the_map, 0, 0);
		mlx_loop_hook(mlx, &hook, mlx);
		mlx_loop(mlx);
		// Deletes an image and removes it from the render queue:
		mlx_delete_image(mlx, the_map);
		mlx_terminate(mlx);
		free_all(&map_data);
	}
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	fdf(argc, argv);
	// system("leaks fdf");
    return (0);
}
