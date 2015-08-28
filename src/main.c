/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 04:25:01 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 04:25:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "ftlst.h"
#include "obj.h"

int			extract_vertex(char **tokens, t_obj_infos *infos)
{
	puts("extract_vertex");
	t_vec3	*v;

	if (!tokens[0] || !tokens[1] || !tokens[2] || !(v = malloc(sizeof(t_vec3))))
		return (0);
	v->x = atof(tokens[0]);
	v->y = atof(tokens[1]);
	v->z = atof(tokens[2]);
	lst_push_back(infos->v, v);
	return (1);
}

int			extract_texture(char **tokens, t_obj_infos *infos)
{
	puts("extract_texture");
	t_vec2	*t;

	if (!tokens[0] || !tokens[1] || !(t = malloc(sizeof(t_vec2))))
		return (0);
	t->x = atof(tokens[0]);
	t->y = atof(tokens[1]);
	lst_push_back(infos->t, t);
	return (1);
}

int			extract_face(char **tokens, t_obj_infos *infos)
{
	puts("extract_face");
	(void)tokens;
	(void)infos;

	if (!tokens[0] || !tokens[1] || !tokens[2])
		return (0);
	return (1);
}

int			free_tab(char **tab, int ret)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (ret);
}

int			determine_line_type(const char *input)
{
	int		i;

	i = 0;
	if (!strcmp(input, "\n"))
		return (0);
	while (g_types_tokens[i])
	{
		if (!strcmp(g_types_tokens[i], input))
			return (i);
		++i;
	}
	return (-1);
}

int			parse_obj_line(char *line, t_obj_infos *infos)
{
	char	**tokens;
	int		type;

	if (!(tokens = ft_split(line, " \t")))
		return (0);
	type = determine_line_type(tokens[0]);
	if (type < 0)
		return (free_tab(tokens, 0));
	if (g_extract[type])
		(*g_extract[type])(tokens + 1, infos);
	return (free_tab(tokens, 1));
}

int			init_parser(t_obj_infos *infos, t_lst *v, t_lst *t, t_lst *f)
{
	g_extract[COMMENT] = NULL;
	g_extract[VERTEX] = extract_vertex;
	g_extract[TEXTURE] = extract_texture;
	g_extract[FACE] = extract_face;
	infos->v = v;
	infos->t = t;
	infos->f = f;
	return (1);
}

int			parse_obj(const char *file_path, t_lst *v, t_lst *t, t_lst *f)
{
	FILE	*fp;
	char	line[BUFF_SIZE];
	t_obj_infos	infos;

	if (!(fp = fopen(file_path, "r")) || !init_parser(&infos, v, t, f))
		return (0);
	while (fgets(line, BUFF_SIZE, fp) != NULL)
	{
		if (!parse_obj_line(line, &infos))
			return (0);
	}
	fclose(fp);
	return (1);
}

int			main(void)
{
	t_lst	*vertices = new_lst();
	t_lst	*textures = new_lst();
	t_lst	*faces = new_lst();

	parse_obj("test.test", vertices, textures, faces);
	return EXIT_SUCCESS;
}
