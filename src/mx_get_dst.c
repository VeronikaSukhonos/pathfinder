#include "pathfinder.h"

int mx_get_dst(t_path *head) {
	t_path *ptr = head;
	int dst = 0;

	while (ptr != NULL) {
		dst = ptr->island.island;
		ptr = ptr->next;
	}
	return dst;
}

