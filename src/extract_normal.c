#include <stdlib.h>
#include "ftlst.h"
#include "obj_internal.h"

int			extract_normal(const char **tokens, t_obj_data *data)
{
	t_vec3	*new_normal;

	if (!(new_normal = malloc(sizeof(t_vec3))))
		return (0);
	else if (!extract_vec3(tokens, new_normal))
	{
		free(new_normal);
		return (0);
	}
	lst_push_back(data->normals, new_normal);
	return (1);
}
