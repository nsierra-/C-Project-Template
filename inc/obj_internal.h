
#ifndef OBJ_INTERNAL
# define OBJ_INTERNAL

# include "obj.h"
# define TYPE_COUNT 5

static const char	*g_obj_tokens[] =
{
	"#",
	"v",
	"vt",
	"vn",
	"f",
	NULL
};

typedef enum	e_obj_type
{
	COMMENT,
	POSITION,
	COLOR,
	NORMAL,
	POLYGON
}				t_obj_type;

// typedef struct	s_type_match
// {
// 	const char	*token;
// 	int			(*f)(const char **, t_obj_data *);
// }				t_type_match;

// static const t_type_match	g_type_matches[] = {
// 	{
// 		.token = "#",
// 		.f = NULL,
// 	},
// 	{
// 		.token = "#",
// 		.f = NULL,
// 	},
// 	{
// 		.token = "#",
// 		.f = NULL,
// 	},
// 	{
// 		.token = "#",
// 		.f = NULL,
// 	},
// };

static int	(*g_extract[TYPE_COUNT])(const char **, t_obj_data *);

int			extract_vec3(const char **tokens, t_vec3 *vector);

int			extract_position(const char **tokens, t_obj_data *data);
int			extract_color(const char **tokens, t_obj_data *data);
int			extract_normal(const char **tokens, t_obj_data *data);
int			extract_polygon(const char **tokens, t_obj_data *data);

int			parse_line(char *line, t_obj_data *data);

#endif
