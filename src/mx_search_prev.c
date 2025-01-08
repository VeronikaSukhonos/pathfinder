#include "pathfinder.h"

bool mx_search_prev(t_path *head, t_island island) {
	t_path *ptr = head;

	while (ptr != NULL) {
		if (ptr->island.island == island.island
			&& ptr->island.dist_from == island.dist_from) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

