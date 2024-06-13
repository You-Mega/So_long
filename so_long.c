/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:55:11 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/13 11:43:56 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_player(t_long *data)
{
	size_t x = 0;
	int p = 0;
	int i = 0;
	int e = 0;
	data->c = 0;
	while (data->map[x])
	{
		i = 0;
		while (data->map[x][i])
		{
			if (data->map[x][i] == 'P')
				p++;
			else if (data->map[x][i] == 'E')
				e++;
			else if (data->map[x][i] == 'C')
				data->c++;
			i++;
		}
		x++;
	}
	printf("p = %d, e = %d, c= %d\n",p ,e, data->c);
	if(!(p == 1 && e == 1 && data->c >= 1))
		exit(write(2, "ERROR\nTHERE IS NO PLAYER OR EXIT DOOR\n", 32));
}
void	check_lenth_map(char **map, size_t len)
{
	int x = 0;
	
	while(map[x])
	{
		if (ft_strlen(map[x]) != len)
			exit(write(2, "ERROR\nLINES HAS DEFERETNS LENTH\n", 25));
		x++;
	}
}
void check_map(t_long *data)
{
	int  i = 0;
	int x = 0;
	size_t y;
	int count = 0;
	y = ft_strlen(data->map[x]);
	check_lenth_map(data->map, y);
	while (data->map[count])
		count++;
	while (x < count)
	{
		i = 0;
		while (data->map[x][i])
		{
			if (data->map[x][i] != '1' && (x == 0 || x == count - 1))
				exit(write(2, "ERROR\nMAP NOT VALID!!\n", 22));
			else if (data->map[x][0] != '1' || data->map[x][y - 1] != '1')
				exit(write(2, "ERROR\nMAP NOT VALID xH and xL!!\n", 25));
			else if(data->map[x][i] != '0' && data->map[x][i] != '1' && data->map[x][i] != 'E' && data->map[x][i] != 'C' && data->map[x][i] != 'P')
				exit(write(2, "ERROR\nINVALID CHARCTRER FOR MAPS\n", 27));
			i++;
		}
		x++;
	}
	check_player(data);
}
char	**ft_read_map(char *name)
{
	int fd = open(name, O_RDONLY);
	char *line = NULL;
	char *tmp;
	char **map;
	while(1)
	{
		tmp = get_next_line(fd);
		if(!tmp)
			break ;
		line = ft_strjoin(line, tmp);
		free(tmp);
		// tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	return (map);
}

void ols(void)
{
	system("leaks so_long");
}
int main(int ac, char **av)
{
	t_long *data;
	atexit(ols);
	if (ac > 2 || !av[1])
		return (write(2, "ERROR\n xxxxx", 12));
	data = malloc(sizeof(t_long));
	if(!(map_name(av[1])))
		return (write (2, "ERROR\nMap error\n", 16));
	data->count = 1;
	data->map = ft_read_map(av[1]);
	data->read = ft_read_map(av[1]);
	if(!data->map)
		return (write(2, "ERROR\nMAP IS EMTHY\n", 19));
	check_map(data);
	printf("-*-*-*-*-*-*-*-*-*\n");
	player_place(data->map, data);
	printf("-*-*-*-*-*-*-*-*-*\n");
	the_path(data);
	char_free(data->map);
	printf("-*-*-*-*-*-*-*-*-*\n");
	map_image(data);
	img_to_window(data);
	mlx_key_hook(data->game, fix_key_hook, data);
	mlx_close_hook(data->game, &free_struct, data);
	mlx_loop(data->game);
	return 0;
}
