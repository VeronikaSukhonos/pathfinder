#include "pathfinder.h"

int mx_min_dist_island(t_answer *answer, bool *visited, int island_num) {
	unsigned int min = UINT_MAX;
	int mindex = 0;

	for (int i = 0; i < island_num; i++) {
		if (!visited[i] && answer[i].dist < min) {
			min = answer[i].dist;
			mindex = i;
		}
	}
	return mindex;
}

