/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:39:06 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/12 16:39:09 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "mlx.h"
# include <math.h>

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define HEIGHT			1000
# define WIDTH			2000
# define MENU_SIZE		300
# define COLOR_STR		0xFFFFFF
# define COLOR_BACKGR	0x000000
# define COLOR_MENU_BG	0x545354
# define ESC			53
# define KB_W			13
# define KB_A			0
# define KB_S			1
# define KB_D			2
# define KB_1			18
# define KB_2			19
# define KB_3			20
# define KB_4			21
# define KB_5			22
# define KB_6			23
# define KB_PLUS		24
# define KB_MINUS		27
# define KB_I			34
# define KB_P			35
# define KB_Z			6
# define KB_X			7
# define ARR_UP			126
# define ARR_DOWN		125
# define ARR_LEFT		123
# define ARR_RIGHT		124
# define NUM_1			83
# define NUM_2			84
# define NUM_3			85
# define NUM_4			86
# define NUM_5			87
# define NUM_6			88
# define NUM_PLUS		69
# define NUM_MINUS		78
# define LEFT_BUTTON	1
# define SCROLL_UP		4
# define SCROLL_DOWN	5

typedef	struct				s_fdf_pos
{
	int						x;
	int						y;
	int						z;
	int						color;
}							t_fdf_pos;

typedef struct				s_fdf_val_pos
{
	int						z;
	int						color;
	struct s_fdf_val_pos	*next;
}							t_fdf_val_pos;

typedef struct				s_fdf_size
{
	int						min_z;
	int						max_z;
	int						length_y;
	int						length_x;
	int						*arrof_color;
	int						*arrof_struct;
}							t_fdf_size;

typedef struct				s_fdf_rotation
{
	int						offset_y;
	int						offset_x;
	double					alpha;
	double					beta;
	double					gamma;
	double					division;
	int						zoom;
}							t_fdf_rotation;

typedef struct				s_fdf_click
{
	int						y;
	int						prev_y;
	int						x;
	int						prev_x;
	char					latm;
}							t_fdf_click;

typedef	struct				s_fdf_gen
{
	t_fdf_size				*size;
	t_fdf_rotation			*rotation;
	t_fdf_click				*click;
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	char					*data_addr;
	int						iso;
	int						parallel;
	int						bpp;
	int						line_size;
	int						end;
}							t_fdf_gen;

/*
**							Start of project + initialization of structures
*/

t_fdf_size					*init_size(void);
t_fdf_gen					*init_gen(t_fdf_size *size);
t_fdf_rotation				*init_rotation(t_fdf_gen *g);
void						quit(char *s);

/*
**							parsing and validating map
*/

int							parse_map(int fd, t_fdf_size *size,
							t_fdf_val_pos **val_pos);
t_fdf_val_pos				*remove_elem(t_fdf_val_pos **val_pos);
void						add_elem(t_fdf_val_pos **val_pos,
							t_fdf_val_pos *elem);

/*
**							initializing array of structures
*/

void						init_arr_of_struct(t_fdf_val_pos **val_pos,
							t_fdf_size *size);

/*
**							drawing magic
*/

void						magic(t_fdf_size *size, t_fdf_gen *g);

/*
**							managing colors and gradient
*/

int							set_color(t_fdf_pos current, t_fdf_pos end,
							t_fdf_pos start, t_fdf_pos delta);
int							manage_gradient(int start, int end, double percent);
int							set_default_color(t_fdf_size *size, int z);
double						percentage(int start, int end, int current);
t_fdf_pos					curr_pos(int x, int y, t_fdf_size *size);

/*
**							rotating axis
*/

t_fdf_pos					projection(t_fdf_pos pos, t_fdf_gen *g);

/*
**							mouse_board controls
*/

int							key_press(int keycode, void *param);
void						init_buttons(t_fdf_gen *g);
int							finish(void *param);
void						zoom_map(int keycode, t_fdf_gen *g);
void						rotate_map(int keycode, t_fdf_gen *g);
void						change_projection(int keycode, t_fdf_gen *g);
void						smooth_map(int keycode, t_fdf_gen *g);
void						move_map(int keycode, t_fdf_gen *g);
int							press_mouse(int button, int x, int y, void *param);
int							release_mouse(int button, int x,
							int y, void *param);
int							move_mouse(int x, int y, void *param);

#endif
