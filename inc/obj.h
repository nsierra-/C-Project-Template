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
	t_vec2		color;
	t_vec3		normal;
	t_vec2		uv;
}				t_vertex;

typedef struct	s_polygon
{
	t_lst		*vertices;
}				t_polygon;

typedef struct	s_obj_data
{
	t_lst		*positions;
	t_lst		*colors;
	t_lst		*normals;
	t_lst		*polygons;
}				t_obj_data;

t_obj_data	*obj_parse(const char *file_path);
void		obj_print_data(const t_obj_data *data);
void		obj_delete_data(t_obj_data **data);

#endif
