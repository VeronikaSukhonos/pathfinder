#include "pathfinder.h"

void mx_restore_paths_from_island(t_list **paths, t_answer *answer,
								  int src, int island_num) {
	for (int i = src + 1; i < island_num; i++) {
		t_path *stack = NULL;
		t_path *tmp = NULL;
		t_island dst = {i, answer[i].dist};

		if (answer[i].dist != UINT_MAX) {
			mx_push_island_front(&stack, dst);
			while (stack != NULL) {
				t_island island = mx_pop_island_front(&stack);

				mx_push_island_front(&tmp, island);
				if (island.island == src) {
					t_path *path = mx_dup_path(tmp);
					t_path *dup = NULL;

					if (stack != NULL)
						dup = mx_dup_path(tmp);

					mx_clear_path(&tmp);
					mx_push_back(paths, path);
					while (true) {
						mx_pop_island_front(&dup);
						if (dup == NULL || stack == NULL)
							break;
						if (answer[dup->island.island].prev->next != NULL
							&& mx_search_prev(answer[dup->island.island].prev,
											  stack->island) == true) {
							break;
						}
					}
					tmp = dup;
				}
				else {
					t_path *ptr = answer[island.island].prev;

					while (ptr != NULL) {
						mx_push_island_front(&stack, ptr->island);
						ptr = ptr->next;
					}
				}
			}
		}
	}
}

