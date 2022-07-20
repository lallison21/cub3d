/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:08:01 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:08:03 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"

# define W_UP_KEY 13
# define A_LEFT_KEY 0
# define S_DOWN_KEY 1
# define D_RIGHT_KEY 2
# define ESC_KEY 53
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define S_WIDTH 1920
# define S_HEIGHT 1080

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*north_wall;
	void	*south_wall;
	void	*east_wall;
	void	*west_wall;
	int		*north_data;
	int		*south_data;
	int		*east_data;
	int		*west_data;
	int		floor_data;
	int		ceiling_data;
}	t_data;

typedef struct s_assets
{
	char	*floor;
	char	*ceiling;
	char	*north_wall;
	char	*south_wall;
	char	*east_wall;
	char	*west_wall;
}	t_assets;

typedef struct s_raycaster
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		x;
	int		y;
	int		w;
	int		h;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheigt;
	int		drawstart;
	int		drawend;
	int		color;
	double	frametime;
	double	movespeed;
	double	rotspeed;
	double	olddir_x;
	double	oldplane_x;
	int		texwidht;
	int		texheight;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	texpos;
	int		**buffer;
}	t_ray;

typedef struct s_vars
{
	t_data		img;
	t_assets	assets;
	t_ray		ray;
	void		*mlx;
	void		*win;
	char		**map;
	int			x;
	int			y;
}	t_vars;

int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_next_line(int fd, char **str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	check_file(int argc, char **argv, t_vars *vars);
void	check_contents(int fd, t_vars *vars);
int		check_line(char *str);
void	read_check(int check, char *buf);
void	smol_map_check(t_vars *vars);
void	create_map(t_vars *vars, char *str, int fd);
void	map_check(t_vars *vars);
char	*find_asset(char *str);
void	get_img_data(t_data *img, t_assets *assets);
void	raycaster(t_vars *vars);
int		commands(int keycode, t_vars *vars);
int		closed_win(void);
void	check_movements_left_right(int keycode, t_vars *vars);
void	check_movements_up_down(int keycode, t_vars *vars);
void	check_rotation_left(int keycode, t_vars *vars);
void	check_rotation_right(int keycode, t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render_window(t_vars *vars);
void	render_floor_ceilinig(t_vars *vars);
void	get_initial_values(t_vars *vars);
void	dda_algorithm(t_vars *vars);
void	draw_line_calculations(t_vars *vars);
void	texturing_calculations(t_vars *vars);
void	choose_wall_texture(t_vars *vars);
void	render_walls(t_vars *vars);
void	ft_perror(char *err);

#endif
