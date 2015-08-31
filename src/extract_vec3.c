#include <stdlib.h>
#include "obj_internal.h"

int		extract_vec3(const char **tokens, t_vec3 *vector)
{
	if (!tokens[0] || !tokens[1] || !tokens[2])
		return (0);
	vector->x = atof(tokens[0]);
	vector->y = atof(tokens[1]);
	vector->z = atof(tokens[2]);
	return (1);
}
