#include <string.h>
#include "obj_internal.h"
#include "libft.h"

static int	(*get_parse_function(const char *input))(const char **, t_obj_data *)
{
	int		i;

	i = 0;
	while (g_type_matches[i].token && g_type_matches[i].f)
	{
		if (!strcmp(g_type_matches[i].token, input))
			return (g_type_matches[i].f);
		++i;
	}
	return (NULL);
}

int			parse_line(char *line, t_obj_data *data)
{
	char	**tokens;
	int		(*parse_function)(const char **, t_obj_data *);

	if (!(tokens = ft_split(line, " \t")))
		return (0);
	parse_function = get_parse_function(tokens[0]);
	if (!parse_function)
	{
		ft_free_tab(tokens);
		parser_die("Unknown data type.");
	}
	(*parse_function)((const char **)(tokens + 1), data);
	ft_free_tab(tokens);
	return (1);
}
