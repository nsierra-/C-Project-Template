
#ifndef OBJ_INTERNAL
# define OBJ_INTERNAL

# include "obj.h"
# include "obj_tokens.h"
# define TYPE_COUNT 5
# define DEFAULT_CODE -9

typedef struct				s_type_match
{
	const char				*token;
	int						(*f)(const char **, t_obj_data *);
}							t_type_match;

int							parse_vec3(const char **tokens, t_vec3 *vector);
int							parse_vec2(const char **tokens, t_vec3 *vector);

int							parse_comment(const char **tokens, t_obj_data *d);
int							parse_position(const char **tokens, t_obj_data *d);
int							parse_color(const char **tokens, t_obj_data *d);
int							parse_normal(const char **tokens, t_obj_data *d);
int							parse_polygon(const char **tokens, t_obj_data *d);

int							parse_line(char *line, t_obj_data *d);

void						parser_die(const char *msg);

static const t_type_match	g_type_matches[] = {
	{
		.token = COMMENT_TOKEN,
		.f = parse_comment,
	},
	{
		.token = POSITION_TOKEN,
		.f = parse_position,
	},
	{
		.token = COLOR_TOKEN,
		.f = parse_color,
	},
	{
		.token = NORMAL_TOKEN,
		.f = parse_normal,
	},
	{
		.token = POLYGON_TOKEN,
		.f = parse_polygon
	},
	{
		.token = NULL,
		.f = NULL
	}
};

unsigned int				g_current_line;
t_obj_data					*g_current_data;

#endif
