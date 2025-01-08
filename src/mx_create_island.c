#include "pathfinder.h"

t_path *mx_create_island(t_island island) {
	t_path *new = malloc(sizeof(t_path));

	if (new != NULL) {
		new->island = island;
		new->next = NULL;
	}
	return new;
}

