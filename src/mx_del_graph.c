#include "pathfinder.h"

void mx_del_graph(int ***graph, int size) {
	if (graph != NULL && *graph != NULL) {
		for (int i = 0; i < size; i++) {
			free((*graph)[i]);
			(*graph)[i] = NULL;
		}
		free(*graph);
		*graph = NULL;
	}
}

