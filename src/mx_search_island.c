#include "pathfinder.h"

int mx_search_island(char **islands, char *name) {
	for (int i = 0; islands[i] != NULL; i++) {
		if (mx_strcmp(islands[i], name) == 0)
			return i;
	}
	return -1;
}

