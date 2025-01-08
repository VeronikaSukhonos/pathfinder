#include "pathfinder.h"

void mx_push_island_front(t_path **head, t_island island) {
	if (head != NULL) {
		t_path *front = mx_create_island(island);

		if (front != NULL) {
			front->next = *head;
			*head = front;
		}
	}
}

