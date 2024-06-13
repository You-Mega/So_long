/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:01:03 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/13 22:28:38 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void char_free(char **arr)
{
    int j = 0;
    while (arr[j])
    {
        free(arr[j]);
        j++;
    }
    free(arr);
}

void free_texture(t_long *data)
{
	mlx_delete_texture(data->e_texture);
	mlx_delete_texture(data->p_texture);
	mlx_delete_texture(data->c_texture);
	mlx_delete_texture(data->w_texture);
	mlx_delete_texture(data->b_texture);
}
void	map_image(t_long *data)
{
	int i = 0;
	int j = 0;
	while (data->read[0][i])
		i++;
	while (data->read[j])
		j++;
	if (((i * 64) > 2560 || (j * 64) > 1440))
		{
			char_free(data->read);
			exit(write(2, "ERROR\ninvalid\n", 15));
		}
	data->game = mlx_init(i * 64, j *64, "so_long", true);
	data->e_texture = mlx_load_png("./textur/E.png");
	data->p_texture = mlx_load_png("./textur/P.png");
	data->c_texture = mlx_load_png("./textur/C.png");
	data->w_texture = mlx_load_png("./textur/1.png");
	data->b_texture = mlx_load_png("./textur/0.png");
	if (!data->e_texture || !data->p_texture || !data->c_texture || !data->w_texture || !data->b_texture)
		exit(write(2,"ERROR\n", 6));
	data->e_image = mlx_texture_to_image(data->game, data->e_texture);
	data->p_image = mlx_texture_to_image(data->game, data->p_texture);
	data->c_image = mlx_texture_to_image(data->game, data->c_texture);
	data->w_image = mlx_texture_to_image(data->game, data->w_texture);
	data->b_image = mlx_texture_to_image(data->game, data->b_texture);
	free_texture(data);
}

void	img_to_window(t_long *data)
{
	int i;
	int j = 0;
	data->exit_i = 0;
	data->exit_j = 0;
	if (!data->w_image || !data->b_image || !data->e_image || !data->c_image)
		exit(write(2, "ERROR\nerror", 11));
	
	while (data->read[j])
	{
		i = 0;
		while (data->read[j][i])
		{
			if (data->read[j][i] == '1')
				mlx_image_to_window(data->game, data->w_image, i * 64, j * 64);
			else if (data->read[j][i] == '0')
				mlx_image_to_window(data->game, data->b_image, i * 64, j * 64);
			else if (data->read[j][i] == 'C')
				mlx_image_to_window(data->game, data->c_image, i * 64, j * 64);
			else if (data->read[j][i] == 'P')
				mlx_image_to_window(data->game, data->b_image, i * 64, j * 64);
			else if (data->read[j][i] == 'E')
			{
				mlx_image_to_window(data->game, data->e_image, i * 64, j * 64);
				data->exit_i = i * 64;
				data->exit_j = j * 64;
			}
			i++;
		}
		ft_printf("%d %d\n", data->exit_i, data->exit_j);
		j++;
	}
	mlx_image_to_window(data->game, data->p_image, data->x * 64, data->y * 64);
}

void free_struct(void *data)
{
	t_long *tmp = data;
	if (tmp->game)
	{
		mlx_close_window(tmp->game);
		// mlx_terminate(tmp->game);
	}
	free (tmp);
	char_free(tmp->read);
	exit(0);
}

void fix_key_hook(mlx_key_data_t keycode, void* param)
{
	t_long *data = (t_long *)param;
	if (keycode.key == MLX_KEY_ESCAPE || keycode.key == MLX_KEY_Q)
		free_struct(data);
	
    else if ((keycode.key == MLX_KEY_LEFT || keycode.key == MLX_KEY_A) && (keycode.action == MLX_PRESS|| keycode.action == MLX_REPEAT))
    {
        move_left(data);
    }
    else if ((keycode.key == MLX_KEY_RIGHT || keycode.key == MLX_KEY_D) && (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
    {
        move_right(data);
    }
    else if ((keycode.key == MLX_KEY_UP || keycode.key == MLX_KEY_W) && (keycode.action == MLX_PRESS|| keycode.action == MLX_REPEAT))
    {
        move_up(data);
    }
    else if (keycode.key == MLX_KEY_DOWN || keycode.key == MLX_KEY_S)
    {
        move_dawn(data);
    }
}