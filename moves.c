/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:46:28 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/13 22:29:40 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_left(t_long *data)
{
    if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64) - 1] != '1')
    {
        if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] == 'E' && data->c == 0)
            free_struct(data);
        else if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] == 'C')
        {
            data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] = '0';
            data->c--;
        }
        mlx_image_to_window(data->game, data->b_image, data->p_image->instances->x, data->p_image->instances->y);
        data->p_image->instances->x -= 64;
        mlx_image_to_window(data->game, data->p_image, data->p_image->instances->x, data->p_image->instances->y);
        mlx_image_to_window(data->game, data->e_image, data->exit_i, data->exit_j);
        ft_printf("number move = %d\n", data->count++);
    }
}

void move_right(t_long *data)
{
    if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64) + 1] != '1')
    {
        if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] == 'E' && data->c == 0)
            free_struct(data);
        else if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] == 'C')
        {
            data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] = '0';
            data->c--;
        }
            mlx_image_to_window(data->game, data->b_image, data->p_image->instances->x, data->p_image->instances->y);
        data->p_image->instances->x += 64;
        mlx_image_to_window(data->game, data->p_image, data->p_image->instances->x, data->p_image->instances->y);
        mlx_image_to_window(data->game, data->e_image, data->exit_i, data->exit_j);
        ft_printf("number move = %d\n", data->count++);
    }
}

void move_up(t_long *data)
{
    if (data->read[(data->p_image->instances->y / 64) - 1][(data->p_image->instances->x / 64)] != '1')
    {
        if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] == 'E' && data->c == 0)
            free_struct(data);
        else if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] == 'C')
        {
            data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] = '0';
            data->c--;
        }
        mlx_image_to_window(data->game, data->b_image, data->p_image->instances->x, data->p_image->instances->y);
        data->p_image->instances->y -= 64;
        mlx_image_to_window(data->game, data->p_image, data->p_image->instances->x, data->p_image->instances->y);
        mlx_image_to_window(data->game, data->e_image, data->exit_i, data->exit_j);
        ft_printf("number move = %d\n", data->count++);
    }
}
void move_dawn(t_long *data)
{
    if (data->read[(data->p_image->instances->y / 64) + 1][(data->p_image->instances->x / 64)] != '1')
    {
        if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] == 'E' && data->c == 0)
            free_struct(data);
        else if (data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] == 'C')
        {
            data->read[(data->p_image->instances->y / 64)][(data->p_image->instances->x / 64)] = '0';
            data->c--;
        }
        mlx_image_to_window(data->game, data->b_image, data->p_image->instances->x, data->p_image->instances->y);
        data->p_image->instances->y += 64;
        mlx_image_to_window(data->game, data->p_image, data->p_image->instances->x, data->p_image->instances->y);
        mlx_image_to_window(data->game, data->e_image, data->exit_i, data->exit_j);
        ft_printf("number move = %d\n", data->count++);
    }
}