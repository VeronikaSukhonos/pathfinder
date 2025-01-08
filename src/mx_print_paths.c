#include "pathfinder.h"

void mx_print_paths(t_list *paths, char **islands) {
	t_list *path = paths;

	while (path != NULL) {
		t_path *ptr = path->data;
		int src = ptr->island.island;
		int dst = mx_get_dst(ptr);

		for (int j = 0; j < 40; j++)
			mx_printchar('=');
		mx_printchar('\n');

		mx_printstr("Path: ");
		mx_printstr(islands[src]);
		mx_printstr(" -> ");
		mx_printstr(islands[dst]);
		mx_printchar('\n');

		ptr = path->data;
		mx_printstr("Route: ");
		while (ptr != NULL) {
			mx_printstr(islands[ptr->island.island]);
			if (ptr->next != NULL)
				mx_printstr(" -> ");
			ptr = ptr->next;
		}
		mx_printchar('\n');

		ptr = path->data;
		mx_printstr("Distance: ");
		while (ptr != NULL) {
			if (ptr->island.island == src
				&& ptr->next->island.island == dst) {
				mx_printint(ptr->next->island.dist_from);
				break;
			}
			mx_printint(ptr->island.dist_from);
			if (ptr->next->island.island == dst) {
				mx_printstr(" = ");
				mx_printint(ptr->next->island.dist_from);
				break;
			}
			else
				mx_printstr(" + ");			
			ptr = ptr->next;
		}
		mx_printchar('\n');

		for (int j = 0; j < 40; j++)
			mx_printchar('=');
		mx_printchar('\n');

		ptr = path->data;
		mx_clear_path(&ptr);
		path = path->next;
	}
}

