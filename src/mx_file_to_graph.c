#include "pathfinder.h"

int mx_file_to_graph(char *filename, char ***islands, int ***graph) {
	char *file = mx_file_to_str(filename);
	char **lines = mx_str_to_lines(file);
	int first_line = 0;
	int island_num = 0;
	int bridge_sum = 0;
	bool duplicate = false;

	if (file == NULL || lines == NULL) {
		mx_printerr("error: file ");
		mx_printerr(filename);
		mx_printerr(" is empty\n");
		exit(1);
	}
	mx_strdel(&file);

	if (lines[0] == NULL)
		mx_print_line_error(0, &lines, islands, graph, first_line);
	for (int i = 0; lines[0][i] != '\0'; i++) {
		if (!mx_isdigit(lines[0][i]))
			mx_print_line_error(0, &lines, islands, graph, first_line);
	}
	first_line = mx_atoi(lines[0]);
	if (first_line == 0)
		mx_print_line_error(0, &lines, islands, graph, first_line);
	else if (first_line == -1)
		first_line = 0;

	*islands = malloc(sizeof(char *) * (first_line + 1));
	for (int i = 0; i < first_line + 1; i++)
		(*islands)[i] = NULL;

	*graph = malloc(sizeof(int *) * first_line);
	for (int i = 0; i < first_line; i++) {
		(*graph)[i] = malloc(sizeof(int) * first_line);
		for (int j = 0; j < first_line; j++)
			(*graph)[i][j] = 0;
	}

	for (int j = 1; lines[j] != NULL; j++) {
		int len = mx_strlen(lines[j]);
		int hyphen = mx_get_char_index(lines[j], '-');
		int comma = mx_get_char_index(lines[j], ',');
		int weight = 0;
		int index1 = -1;
		int index2 = -1;

		if (len < 5 || hyphen < 1
			|| comma < hyphen + 2 || comma == len - 1) {
			mx_print_line_error(j, &lines, islands, graph, first_line);
		}
		for (int i = 0; i < hyphen; i++) {
			if (!mx_isalpha(lines[j][i]))
				mx_print_line_error(j, &lines, islands, graph, first_line);
		}
		for (int i = hyphen + 1; i < comma; i++) {
			if (!mx_isalpha(lines[j][i]))
				mx_print_line_error(j, &lines, islands, graph, first_line);
		}
		if (hyphen == comma - hyphen - 1
			&& mx_strncmp(lines[j], lines[j] + hyphen + 1, hyphen) == 0) {
			mx_print_line_error(j, &lines, islands, graph, first_line);
		}
		for (int i = comma + 1; i < len; i++) {
			if (!mx_isdigit(lines[j][i]))
				mx_print_line_error(j, &lines, islands, graph, first_line);
		}
		weight = mx_atoi(lines[j] + comma + 1);
		if (weight == 0)
			mx_print_line_error(j, &lines, islands, graph, first_line);
		else if (weight == -1)
			bridge_sum = -1;

		index1 = mx_add_island(*islands, lines[j],
							   hyphen, first_line, &island_num);
		index2 = mx_add_island(*islands, lines[j] + hyphen + 1,
							   comma - hyphen - 1, first_line, &island_num);
		if (island_num <= first_line && (*graph)[index1][index2] == 0) {
			(*graph)[index1][index2] = weight;
			(*graph)[index2][index1] = weight;
		}
		else
			duplicate = true;
		if (bridge_sum != -1 && INT_MAX - bridge_sum >= weight)
			bridge_sum += weight;
		else
			bridge_sum = -1;
	}
	mx_del_strarr(&lines);

	if (island_num != first_line) {
		mx_printerr("error: invalid number of islands\n");
		mx_del_strarr(islands);
		mx_del_graph(graph, first_line);
		exit(1);
	}
	if (duplicate == true) {
		mx_printerr("error: duplicate bridges\n");
		mx_del_strarr(islands);
		mx_del_graph(graph, first_line);
		exit(1);
	}
	if (bridge_sum == -1) {
		mx_printerr("error: sum of bridges lengths is too big\n");
		mx_del_strarr(islands);
		mx_del_graph(graph, first_line);
		exit(1);
	}
	return first_line;
}

