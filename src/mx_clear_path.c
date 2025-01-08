#include "pathfinder.h"

void mx_clear_path(t_path **head) {
	if (head != NULL && *head != NULL) {
		t_path *ptr = *head;

		while (ptr != NULL) {
			t_path *tmp = ptr->next;

			free(ptr);
			ptr = tmp;
		}
		*head = NULL;
	}
}

