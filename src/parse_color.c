#include <stdlib.h>
#include "ftlst.h"
#include "obj_internal.h"

int			parse_color(const char **tokens, t_obj_data *data)
{
	t_vec2	*new_color;

	new_color = NULL;
	if (!tokens[0] || !tokens[1])
		parser_die("A texture needs two arguments.");
	else if (!(new_color = malloc(sizeof(t_vec2))))
		return (0);
	new_color->x = atof(tokens[0]);
	new_color->y = atof(tokens[1]);
	lst_push_back(data->colors, new_color);
	return (1);
}
