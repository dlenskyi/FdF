/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:24:46 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/12 14:38:07 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define FLAGS " .#0-+*Ljthlz123456789"
# define BASE "BOXbox"

typedef	enum	e_mod
{
	arg_reset = 0,
	arg_hh,
	arg_h,
	arg_l,
	arg_ll,
	arg_L,
	arg_z,
	arg_j,
	arg_t
}				t_mod;

typedef	struct	s_flg
{
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		prec;
	int		negative;
}				t_flg;

typedef	struct	s_gen
{
	va_list		ap;
	t_mod		mod;
	t_flg		flg;
	int			i;
	int			back;
	char		*result;
}				t_gen;

/*
**				ft_printf main func
*/

int				ft_printf(const char *format, ...);
void			run_project(const char *s, t_gen *g);
void			set_flgs(t_flg *flg);
void			parse_str(const char *s, t_gen *g);

/*
**				setting_color
*/

void			check_if_color(const char *s, t_gen *g);
void			set_effect(const char *s, t_gen *g);
void			set_basic_color(const char *s, t_gen *g);
void			set_light_color(const char *s, t_gen *g);
void			set_background_color(const char *s, t_gen *g);

/*
**				validate_params
*/

void			validate_mods(const char *s, t_gen *g);
void			validate_flgs(const char *s, t_gen *g);
void			validate_width(t_gen *g);
void			validate_precision(const char *s, t_gen *g);
void			check_params(t_gen *g);

/*
**				managing specificators
*/

void			manage_box(t_gen *g, char var);
void			manage_di(t_gen *g);
void			manage_u(t_gen *g, char var);
void			manage_cs(t_gen *g, char var);
void			manage_f(t_gen *g, char var);
void			manage_p(t_gen *g, char var);
void			manage_n(t_gen *g);
void			manage_percent(t_gen *g);

/*
**				printing di
*/

void			if_sign_udi(t_gen *g);
void			print_width_udi(t_gen *g);
void			print_sign_udi(t_gen *g);
void			if_precision_udi(t_gen *g);
void			print_udi(t_gen *g);

/*
**				printing cs
*/

void			print_width_cs(t_gen *g, char c);
void			if_null_s(t_gen *g, int len);
void			print_null_cs(t_gen *g, char c);
void			print_c(t_gen *g, char c, char var);
void			print_s(t_gen *g, char c);

/*
**				printing box
*/

void			print_width_box(t_gen *g, char var);
void			if_precision_box(t_gen *g, char var);
void			print_hash_box(t_gen *g, char var, long nb);
void			print_box(t_gen *g, char var, long nb);

/*
**				printing p
*/

void			print_width_p(t_gen *g);
void			if_precision_p(t_gen *g);
void			print_p(t_gen *g, char var);

/*
**				printing non valid specificators
*/

void			print_nonvalid(t_gen *g, char c);
void			print_width_nonvalid(t_gen *g);

/*
**				printing f
*/

void			print_width_f(t_gen *g);
char			*get_precision_f(char *precision, int prec, long double *nb,
				char *str);
void			if_precision_f(t_gen *g, long double nb);
void			check_prec_f(t_gen *g, char *buf, char *precision);
void			print_float(t_gen *g, long double nb);
char			*if_zero_minus(double n);

/*
**				       EFFECT				 COLORS
**				{OFF}		 OFF EFFECT	 BLK		BLACK
**				{SET:BO}	 BOLD		 RED		RED
**				{SET:FT}	 FAINT		 GRN		GREEN
**				{SET:IT}	 ITALIC	 	 YEL		YELLOW
**				{SET:UL}	 UNDERLINE	 BLU		BLUE
**				{SET:RE}	 REVERSE	 MGT		MAGENTA
**				{SET:BL}	 BLINK	 	 CYN		CYAN
**										 WHT		WHITE
**
**				{BGC:***}	BACKGROUND COLOR
**				{LT:***}	LIGHT COLOR
*/

#endif
