/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:58:25 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/14 11:15:51 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/ft_printf/include/ft_printf.h"
# include "../../libft/get_next_line/includes/get_next_line.h"
# include "../../minilibx/mlx.h"
# include "struct.h"

/* ***************************** MAGIC_MALLOC ****************************** */

void		*mcgic(void *p, size_t size, int rule);
void		del(void *content);
int			ft_check(void *data, void *data_ref);
void		ft_list_remove(t_list **begin_list, t_list **lst, t_list **prev);
void		ft_list_remove_if(t_list **begin_list, void *p, int (*cmp)());

/* ******************************** PARSING ******************************** */

void		ft_get_textures(t_cub *cub, char *av);
short int	ft_get_type_info(char *line, int *j);
int			ft_count_letter(char *line, int j);
void		ft_cpy_color(t_cub *cub, char *line, t_color *color);
int			ft_rstrncmp(const char *s1, const char *s2, int n);
bool		ft_isspace_nonewline(char c);
char		**ft_split_mcgic(char const *s, char c);
bool		get_map(t_cub *cub, int fd);
bool		check_borders(t_cub *cub, int len_x, int len_y, int i);
bool		check_x_borders(char **str, int last);
bool		check_y_borders(char **str, int last_x, int last_y);
char		**check_limits(t_cub *cub);

/* ******************************** WINDOW ********************************* */

void		ft_open_window(t_cub *cub);
int			ft_handle_cross(t_cub *cub);
void		ft_exit(t_cub *cub, char *err);
int			ft_handle_keys_press(int keycode, t_cub *cub);
int			ft_handle_keys_release(int keycode, t_cub *cub);
int			ft_handle_no_event(t_cub *cub);
bool		ft_stop(t_cub *cub, double y, double x);
void		ft_move_front(t_cub *cub);
void		ft_move_behind(t_cub *cub);
void		ft_move_left(t_cub *cub);
void		ft_move_right(t_cub *cub);
void		ft_rotate_right(t_cub *cub);
void		ft_rotate_left(t_cub *cub);

/* ********************************* DRAW ********************************** */

void		ft_draw_vertical_line(t_pt pt, int color, t_cub *cub);
void		ft_set_pt(t_pt *pt, int x, int yo, int ye);
void		ft_img_pix_put(t_img *img, int x, int y, int color);
void		ft_put_textcol_to_img(t_cub *cub, t_ray ray, int x);

/* ******************************* RAYCASTING ****************************** */

void		ft_draw_img(t_cub *cub);
void		ft_calcul_ray_hwall(t_cub *cub, double a);
void		ft_calcul_ray_vwall(t_cub *cub, double a);
bool		ft_hit_wall(t_cub *cub, int x, int y);
void		ft_set_dist(t_ray *ray);
void		ft_set_ray(t_ray *ray);
void		ft_cpy_ray(t_ray ray_src, t_ray *ray_dst);
bool		ft_equald(double to_check, double to_cmp);
double		ft_deg_to_rad(double a);
double		ft_abs_gap(double a, double b);
int			ft_sign(int n);

#endif