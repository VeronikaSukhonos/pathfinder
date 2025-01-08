#include "pathfinder.h"

t_path *mx_dup_path(t_path *head) {
	t_path *new_head = NULL;
	t_path *ptr = head;

	while (ptr != NULL) {
		t_island island = ptr->island;

		mx_push_island_back(&new_head, island);
		ptr = ptr->next;
	}
	return new_head;
}

