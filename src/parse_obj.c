#include <stdlib.h>
#include <stdio.h>
#include "ftlst.h"
#include "obj_internal.h"

static int		init_parser(t_obj_data *data)
{
	g_extract[COMMENT] = NULL;
	g_extract[POSITION] = extract_position;
	g_extract[COLOR] = extract_color;
	g_extract[NORMAL] = extract_normal;
	g_extract[POLYGON] = extract_polygon;
	data->positions = new_lst();
	data->colors = new_lst();
	data->normals = new_lst();
	data->polygons = new_lst();
	return (1);
}

t_obj_data		*parse_obj(const char *file_path)
{
	FILE		*fp;
	char		line[BUFF_SIZE];
	t_obj_data	*data;

	if (!(fp = fopen(file_path, "r"))
		|| !(data = malloc(sizeof(t_obj_data)))
		|| !init_parser(data))
		return (NULL);
	while (fgets(line, BUFF_SIZE, fp) != NULL)
	{
		if (!parse_line(line, data))
			return (NULL);
	}
	fclose(fp);
	return (data);
}
