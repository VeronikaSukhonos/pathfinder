#include "pathfinder.h"

t_answer *mx_find_paths_from_island(int **graph, int src,
									bool *visited, int island_num) {
	t_answer *answer = malloc(sizeof(t_answer) * island_num);

	for (int i = 0; i < island_num; i++) {
		answer[i].dist = UINT_MAX;
		answer[i].prev = NULL;
		visited[i] = false;
	}
	answer[src].dist = 0;
	for (int i = 0; i < island_num - 1; i++) {
		int min = mx_min_dist_island(answer, visited, island_num);

		visited[min] = true;
		for (int j = 0; j < island_num; j++) {
			if (!visited[j] && graph[min][j] != 0
				&& answer[min].dist != UINT_MAX) {
				unsigned int new_dist = answer[min].dist + graph[min][j];
				t_island island = {min, graph[min][j]};

				if (answer[j].dist > new_dist) {
					answer[j].dist = new_dist;
					mx_clear_path(&answer[j].prev);
					mx_push_island_front(&answer[j].prev, island);
				}
				else if (answer[j].dist == new_dist)
					mx_push_island_front(&answer[j].prev, island);
			}
		}
	}
	return answer;
}

