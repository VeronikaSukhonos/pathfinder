#include "pathfinder.h"

void mx_push_island_back(t_path **head, t_island island) {
	if (head != NULL) {
		t_path *back = mx_create_island(island);

		if (back != NULL) {
			if (*head == NULL)
				*head = back;
			else {
				t_path *ptr = *head;

				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = back;
			}
		}
	}
}

