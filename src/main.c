/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:25:57 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/14 12:37:00 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// mlx_image_t	*g_img;

// void	hook(void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		g_img->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		g_img->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		g_img->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		g_img->instances[0].x += 5;
// }

// int32_t	main(void)
// {
// 	mlx_t	*mlx;

// 	mlx = mlx_init(WIDTH, HEIGHT, "Marès is koning", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	g_img = mlx_new_image(mlx, 128, 128);
// 	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
// 	mlx_image_to_window(mlx, g_img, 0, 0);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

void	fdf(int argc, char **argv)
{
	t_map   	map_data;
	// t_data_point data_point;

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
		free(map_data.data_points);
		free(map_data.int_array);
		free_2d_array(map_data.str_split);
	}
}

int main(int argc, char **argv)
{
	fdf(argc, argv);
	// system("leaks fdf");
    return (0);
}
