#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "obj_internal.h"

static int		int_from_token(const char **tokens, int index)
{
	int			j;
	int			ret;

	j = 0;
	while (j <= index)
	{
		if (!tokens[j++])
			return DEFAULT_CODE;
	}
	ret = atoi(tokens[index]) - 1;
	if (ret < 0)
		parser_die("A face index can't be negative.");
	return (ret);
}

static void		fill_vertex_position(const char **tokens,
	t_vertex *vertex,
	t_obj_data *data)
{
	int			index;
	t_lst		*positions;
	t_vec3		*pos;

	index = int_from_token(tokens, 0);
	positions = data->positions;
	pos = lst_data_at(positions, index);
	if (pos)
	{
		vertex->position.x = pos->x;
		vertex->position.y = pos->y;
		vertex->position.z = pos->z;
	}
	else if (index >= 0 && lst_get_size(positions) > (size_t)index)
	{
		vertex->position.x = 0;
		vertex->position.y = 0;
		vertex->position.z = 0;
	}
	else
		parser_die("Invalid index for a position.");
}

static void		fill_vertex_color(const char **tokens,
	t_vertex *vertex,
	int no_texture,
	t_obj_data *data)
{
	int			i;
	t_lst		*colors;
	t_vec2		*color;

	colors = data->colors;
	i = DEFAULT_CODE;
	if (!no_texture)
		i = int_from_token(tokens, 1);
	color = lst_data_at(colors, i);
	if (color)
	{
		vertex->color.x = color->x;
		vertex->color.y = color->y;
	}
	else if (i == DEFAULT_CODE || (i >= 0 && lst_get_size(colors) > (size_t)i))
	{
		vertex->color.x = 0;
		vertex->color.y = 0;
	}
	else
		parser_die("Invalid index for color.");
}

static void		fill_vertex_normal(const char **tokens,
	t_vertex *vertex,
	int no_texture,
	t_obj_data *data)
{
	int			i;
	t_lst		*normals;
	t_vec3		*normal;

	normals = data->normals;
	i = int_from_token(tokens, 2);
	if (no_texture)
		i = int_from_token(tokens, 1);
	normal = lst_data_at(normals, i);
	if (normal)
	{
		vertex->normal.x = normal->x;
		vertex->normal.y = normal->y;
		vertex->normal.z = normal->z;
	}
	else if (i == -9 || (i >= 0 && lst_get_size(normals) > (size_t)i))
	{
		vertex->normal.x = 0;
		vertex->normal.y = 0;
		vertex->normal.z = 0;
	}
	else
		parser_die("Invalid index for normal.");
}

static int		add_vertex(const char **tokens,
	int no_texture,
	t_lst *vertices,
	t_obj_data *data)
{
	t_vertex	*new_vertex;

	new_vertex = NULL;
	if (!tokens[0])
		parser_die("A face component can't be empty.");
	else if (!(new_vertex = malloc(sizeof(t_vertex))))
		return (0);
	fill_vertex_position(tokens, new_vertex, data);
	fill_vertex_color(tokens, new_vertex, no_texture, data);
	fill_vertex_normal(tokens, new_vertex, no_texture, data);
	lst_push_back(vertices, new_vertex);
	return (1);
}

int				parse_polygon_components(const char **tokens,
	t_polygon *new_polygon,
	t_obj_data *data)
{
	int			i;
	int			no_texture;
	char		**component_tokens;

	i = 0;
	if (!tokens[0] || !tokens[1] || !tokens[2])
		parser_die("A face must declare at least three vertices.");
	while (tokens[i])
	{
		no_texture = 0;
		if (strstr(tokens[i], "//"))
			no_texture = 1;
		component_tokens = ft_split(tokens[i], "/\n");
		if (!add_vertex((const char **)component_tokens, no_texture, new_polygon->vertices, data))
			return (0);
		++i;
	}
	return (1);
}

int				parse_polygon(const char **tokens, t_obj_data *data)
{
	t_polygon	*new_polygon;

	if (!(new_polygon = malloc(sizeof(t_polygon))))
		return (0);
	new_polygon->vertices = new_lst();
	if (!parse_polygon_components(tokens, new_polygon, data))
	{
		free(new_polygon);
		return (0);
	}
	lst_push_back(data->polygons, new_polygon);
	return (1);
}

