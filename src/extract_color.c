#include <stdlib.h>
#include "ftlst.h"
#include "obj_internal.h"

int			extract_color(const char **tokens, t_obj_data *data)
{
	t_vec2	*t;

	if (!tokens[0] || !tokens[1] || !(t = malloc(sizeof(t_vec2))))
		return (0);
	t->x = atof(tokens[0]);
	t->y = atof(tokens[1]);
	lst_push_back(data->colors, t);
	return (1);
}
