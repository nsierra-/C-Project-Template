#include <string.h>
#include "obj_internal.h"
#include "libft.h"

static int	determine_line_type(const char *input)
{
	int		i;

	i = 0;
	if (!strcmp(input, "\n"))
		return (0);
	while (g_obj_tokens[i])
	{
		if (!strcmp(g_obj_tokens[i], input))
			return (i);
		++i;
	}
	return (-1);
}

int			parse_line(char *line, t_obj_data *data)
{
	char	**tokens;
	int		type;

	if (!(tokens = ft_split(line, " \t")))
		return (0);
	type = determine_line_type(tokens[0]);
	if (type < 0)
	{
		ft_free_tab(tokens);
		return (0);
	}
	if (g_extract[type])
		(*g_extract[type])((const char **)(tokens + 1), data);
	ft_free_tab(tokens);
	return (1);
}
