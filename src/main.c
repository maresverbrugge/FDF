/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:25:57 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/17 15:37:19 by mverbrug      ########   odam.nl         */
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

void	draw_test_line(mlx_image_t *the_map, t_map *map_data)
{
	int start_x = map_data->data_points[0].x;
	int end_x = map_data->data_points[1].x;
	int y = map_data->data_points[0].y;
	while(end_x > start_x)
	{
		mlx_put_pixel(the_map, end_x, y, 0xFFFFFFFF);
		end_x--;
	}
	int start_y = map_data->data_points[0].y;
	int end_y = map_data->data_points[19].y;
	int x = 0;
	while(end_y > start_y)
	{
		mlx_put_pixel(the_map, x, end_y, 0xFFFFFFFF);
		end_y--;
	}
}

void	draw_grid(mlx_image_t *the_map, t_map *map_data)
{
	int i;
	
	i = 0;
	while(i < map_data->amount_of_points)
	{
		map_data->data_points[i].x = map_data->data_points[i].x * 42;
		map_data->data_points[i].y = map_data->data_points[i].y * 70;
		mlx_put_pixel(the_map, map_data->data_points[i].x, map_data->data_points[i].y, 0x00F400FF);
		// printf("i = %d\n", i);
		i++;
		// map_data->data_points[i].x += 10;
		// map_data->data_points[i].y += 10;
	}
	draw_test_line(the_map, map_data);
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
		mlx = mlx_init(1000, 1000, "Marès is koning", true);
		if (!mlx)
			exit(EXIT_FAILURE);
		// Creates a whole new image:
		the_map = mlx_new_image(mlx, 2000, 2000);
		// Draw data points on image:
		draw_grid(the_map, &map_data);
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
