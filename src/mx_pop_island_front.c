#include "pathfinder.h"

t_island mx_pop_island_front(t_path **head) {
	t_island island = {0, 0};

	if (head != NULL && *head != NULL) {
		t_path *tmp = *head;

		island = tmp->island;
		*head = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	return island;
}

