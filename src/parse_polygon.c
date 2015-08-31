#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "obj_internal.h"

static int		parse_polygon_components(
					const char **tokens,
					t_polygon *new_polygon)
{
	int			i;
	int			nt;
	char		**ctokens;

	i = 0;
	if (!tokens_are_enough(tokens, 3))
		parser_die("A face must declare at least three vertices.");
	while (tokens[i])
	{
		nt = 0;
		if (strstr(tokens[i], "//"))
			nt = 1;
		ctokens = ft_split(tokens[i], "/\n");
		if (!add_vertex((const char **)ctokens, nt, new_polygon->vertices))
			return (0);
		++i;
	}
	return (1);
}

int				parse_polygon(const char **tokens)
{
	t_polygon	*new_polygon;

	if (!(new_polygon = malloc(sizeof(t_polygon))))
		return (0);
	new_polygon->vertices = new_lst();
	if (!parse_polygon_components(tokens, new_polygon))
	{
		free(new_polygon);
		return (0);
	}
	lst_push_back(g_current_data->polygons, new_polygon);
	return (1);
}

