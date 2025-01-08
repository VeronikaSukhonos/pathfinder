#include "pathfinder.h"

bool mx_cmp_paths(void *a, void *b) {
	t_path *ptr_a = (t_path *)a;
	t_path *ptr_b = (t_path *)b;
	int src_a = ptr_a->island.island;
	int src_b = ptr_b->island.island;
	int dst_a = mx_get_dst(ptr_a);
	int dst_b = mx_get_dst(ptr_b);

	if (src_a > src_b)
		return true;
	if (src_a < src_b)
		return false;

	if (dst_a > dst_b)
		return true;
	if (dst_a < dst_b)
		return false;

	while (ptr_a != NULL && ptr_b != NULL) {
		if (ptr_a->island.island > ptr_b->island.island)
			return true;
		if (ptr_a->island.island < ptr_b->island.island)
			return false;
		ptr_a = ptr_a->next;
		ptr_b = ptr_b->next;
	}
	return false;
}

