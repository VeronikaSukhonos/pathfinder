#include "pathfinder.h"

int mx_add_island(char **islands, char *line, int len,
				  int first_line, int *island_num) {
	char *island = NULL;
	int index = -1;

	if (first_line == 0) {
		(*island_num)++;
		return index;
	}
	island = mx_strndup(line, len);
	index = mx_search_island(islands, island);
	if (index == -1) {
		if (*island_num < first_line) {
			islands[*island_num] = island;
			index = *island_num;
		}
		else
			free(island);
		(*island_num)++;
	}
	else
		free(island);
	return index;
}

