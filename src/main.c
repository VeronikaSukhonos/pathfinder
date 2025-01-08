#include "pathfinder.h"

int main(int argc, char *argv[]) {
	char **islands = NULL;
	int **graph = NULL;
	t_list *paths = NULL;
	int island_num = 0;
	int fd = -1;

	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		mx_printerr("error: file ");
		mx_printerr(argv[1]);
		mx_printerr(" does not exist\n");
		exit(1);
	}
	close(fd);

	island_num = mx_file_to_graph(argv[1], &islands, &graph);

	paths = mx_get_shortest_paths(graph, island_num);
	mx_del_graph(&graph, island_num);

	mx_print_paths(paths, islands);

	mx_clear_list(&paths);
	mx_del_strarr(&islands);
}

