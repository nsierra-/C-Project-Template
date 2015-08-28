/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 04:25:01 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 04:25:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "ftlst.h"
# define BUFF_SIZE 512

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_vertex
{
	t_vec3		position;
	t_vec2		texture;
	t_vec3		normal;
}				t_vertex;

typedef struct	s_face
{
	t_lst		*composition;
}				t_face;

static const char *g_types_tokens[] =
{
	"#",
	"v",
	"vt",
	"f",
	NULL
};

enum	e_obj_type
{
	COMMENT,
	VERTEX,
	TEXTURE,
	FACE
};

typedef struct	s_obj_infos
{
	t_lst		*v;
	t_lst		*t;
	t_lst		*f;
}				t_obj_infos;

int	(*g_extract[4])(char **, t_obj_infos *);

#endif
