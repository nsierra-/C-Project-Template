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
/*
** A vertex here is a component of a face. It is made of a mandatory position,
** an optional color and optional normal.
*/
typedef struct	s_vertex
{
	t_vec3		position;
	t_vec2		uv;
	t_vec3		normal;
	t_vec3		color;
}				t_vertex;
/*
** This struct stands for Obj's 'v' type. It is made of a list of t_vertex.
*/
typedef struct	s_polygon
{
	t_lst		*vertices;
}				t_polygon;
/*
** Struct returned by parse_obj. It contains a list of everything in the file,
** where :
**	- positions correspond to 'v' ;
**	- uvs correspond to 'vt' ;
**	- normals correspond to 'vn' ;
**	- polygons correspond to 'f' ;
*/
typedef struct	s_obj_data
{
	t_lst		*positions;
	t_lst		*uvs;
	t_lst		*normals;
	t_lst		*polygons;
}				t_obj_data;

/*
** Use this function to retrieve data from a obj file path.
** Return values : the t_obj_data structure filled with everything the file
** contains or NULL if an error occured.
*/
t_obj_data		*obj_parse(const char *file_path);
/*
** Use this function to print all data. Very ugly.
*/
void			obj_print_data(const t_obj_data *data);
/*
** Use this function to free all space allocated by obj_parse.
*/
void			obj_delete_data(t_obj_data **data);
int				is_vec2_defined(t_vec2 *v);
int				is_vec3_defined(t_vec3 *v);

#endif
