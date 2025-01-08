#include "pathfinder.h"

t_list *mx_get_shortest_paths(int **graph, int island_num) {
	t_list *paths = NULL;
	t_answer *answer = NULL;
	bool *visited = malloc(sizeof(bool) * island_num);

	for (int i = 0; i < island_num - 1; i++) {
		answer = mx_find_paths_from_island(graph, i, visited, island_num);
		mx_restore_paths_from_island(&paths, answer, i, island_num);
		for (int j = 0; j < island_num; j++)
			mx_clear_path(&answer[j].prev);
		free(answer);
	}
	free(visited);
	paths = mx_sort_list(paths, mx_cmp_paths);
	return paths;
}

