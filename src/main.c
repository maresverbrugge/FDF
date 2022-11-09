/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:25:57 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/09 17:44:50 by mverbrug      ########   odam.nl         */
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

int	count_rows(char *str)
{
	int		rows;
	char	**map_split_on_newline;

	map_split_on_newline = ft_split(str, '\n');
	if (!map_split_on_newline)
		exit(1);
	rows = 0;
	while (map_split_on_newline[rows])
		rows++;
	return (rows);
}

int	count_columns(char *str)
{
	int	columns;
	int	i;
	
	columns = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		// printf("str[i] = %c\n", str[i]);
		// !!!!!!~KLOPT NOG NIET~!!!!!!
		if (str[i] != ' ')
			columns++;
		i++;
	}
	return (columns);
}

void	parse_input(char *str)
{
	char	**data_points;

	data_points = ft_split(str, ' ');
	if (!data_points)
		exit(1);
	size_t i = 0;
	while (data_points[i])
	{
		printf("data_points[%zu] = %s\n", i, data_points[i]);
		i++;
	}
}

void	parse_map(void)
{
	int		map_fd;
	char	*str;

	map_fd = open("test_maps/pyramide.fdf", O_RDONLY);
	// map_fd = open("test_maps/elem2.fdf", O_RDONLY);
	// map_fd = open("test_maps/julia.fdf", O_RDONLY);
	// map_fd = open("test_maps/42.fdf", O_RDONLY);
	
	printf("map_fd = %d\n", map_fd);
	int ret = read_map(map_fd, &str);
	printf("ret = %d\n", ret);
	// printf("%s", str);
	// parse_input(str);
	printf ("rows = %d\n", count_rows(str));
	printf ("column = %d\n", count_columns(str));
}

int main()
{
	parse_map();
    return (0);
}
