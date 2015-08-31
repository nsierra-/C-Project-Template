#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "obj_internal.h"

static void		fill_vertex_position(const char **tokens, t_vertex *vertex, t_obj_data *data)
{
	int			index;
	t_lst		*positions;
	t_vec3		*pos;

	index = atoi(tokens[0]);
	positions = data->positions;
	pos = lst_data_at(positions, index);
	if (pos)
	{
		vertex->position.x = pos->x;
		vertex->position.y = pos->y;
		vertex->position.z = pos->z;
	}
	else
	{
		vertex->position.x = 0;
		vertex->position.y = 0;
		vertex->position.z = 0;
	}
}

static void		fill_vertex_color(const char **tokens, t_vertex *vertex, int no_texture, t_obj_data *data)
{
	int			index;
	t_lst		*colors;
	t_vec2		*color;

	colors = data->colors;
	index = tokens[1] && !no_texture ? atoi(tokens[1]) : -1;
	color = index > 0 ? lst_data_at(colors, index) : NULL;
	if (color)
	{
		vertex->color.x = color->x;
		vertex->color.y = color->y;
	}
	else
	{
		vertex->color.x = 0;
		vertex->color.y = 0;
	}
}

static void		fill_vertex_normal(const char **tokens, t_vertex *vertex, t_obj_data *data)
{
	int			index;
	t_lst		*normals;
	t_vec3		*normal;

	normals = data->normals;
	index = tokens[1] && tokens[2] ? atoi(tokens[2]) : -1;
	normal = lst_data_at(normals, index);
	if (normal)
	{
		vertex->position.x = normal->x;
		vertex->position.y = normal->y;
		vertex->position.z = normal->z;
	}
	else
	{
		vertex->position.x = 0;
		vertex->position.y = 0;
		vertex->position.z = 0;
	}
}

static int		add_vertex(const char **tokens, int no_texture, t_obj_data *data)
{
	t_vertex	*new_vertex;

	if (!tokens[0] || !(new_vertex = malloc(sizeof(t_vertex))))
		return (0);
	fill_vertex_position(tokens, new_vertex, data);
	fill_vertex_color(tokens, new_vertex, no_texture, data);
	fill_vertex_normal(tokens, new_vertex, data);
	return (1);
}

int				extract_polygon(const char **tokens, t_obj_data *data)
{
	int			i;
	int			no_texture;

	i = 0;
	if (!tokens[0] || !tokens[1] || !tokens[2])
		return (0);
	while (tokens[i])
	{
		no_texture = strstr(tokens[i], "//") ? 0 : 1;
		if (!add_vertex((const char **)ft_split(tokens[i], "/"), no_texture, data))
			return (0);
	}
	return (1);
}
