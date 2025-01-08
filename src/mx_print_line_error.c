#include "pathfinder.h"

void mx_print_line_error(int line_num, char ***lines, char ***islands,
						 int ***graph, int size) {
	char *invalid_line = mx_itoa(line_num + 1);

    mx_printerr("error: line ");
	mx_printerr(invalid_line);
	mx_printerr(" is not valid\n");
	mx_strdel(&invalid_line);
	mx_del_strarr(lines);
	mx_del_strarr(islands);
	mx_del_graph(graph, size);
	exit(1);
}

