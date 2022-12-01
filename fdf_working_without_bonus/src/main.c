/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:25:57 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/01 17:13:07 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	hook(void *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
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
		mlx = mlx_init(SCREEN_WIDTH, SCREEN_LENGTH, "Marès is koning", false);
		if (!mlx)
			errno_error();
		the_map = mlx_new_image(mlx, MAP_WIDTH, MAP_LENGTH);
		if (!the_map || mlx_image_to_window(mlx, the_map, 0, 0) < 0)
			errno_error();
		draw_grid(the_map, &map_data);
		mlx_loop_hook(mlx, &hook, mlx);
		mlx_loop(mlx);
		mlx_delete_image(mlx, the_map);
		mlx_terminate(mlx);
		free_all(&map_data);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	fdf(argc, argv);
	return (0);
}
