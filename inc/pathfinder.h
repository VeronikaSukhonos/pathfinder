#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_island {
	int island;
	int dist_from;
}			   t_island;

typedef struct s_path {
	t_island island;
	struct s_path *next;
}			   t_path;

typedef struct s_answer {
	unsigned int dist;
	t_path *prev;
}			   t_answer;

int mx_file_to_graph(char *filename, char ***islands, int ***graph);
char **mx_str_to_lines(char *s);
int mx_search_island(char **islands, char *name);
int mx_add_island(char **islands, char *line, int len,
				  int first_line, int *island_num);
void mx_print_line_error(int line_num, char ***lines, char ***islands,
						 int ***graph, int size);
void mx_del_graph(int ***graph, int size);

t_list *mx_get_shortest_paths(int **graph, int island_num);
t_answer *mx_find_paths_from_island(int **graph, int src,
									bool *visited, int island_num);
int mx_min_dist_island(t_answer *answer, bool *visited, int island_num);
void mx_restore_paths_from_island(t_list **paths, t_answer *answer,
								  int src, int island_num);

t_path *mx_create_island(t_island island);
void mx_push_island_front(t_path **head, t_island island);
void mx_push_island_back(t_path **head, t_island island);
t_island mx_pop_island_front(t_path **head);
void mx_clear_path(t_path **head);
t_path *mx_dup_path(t_path *head);
bool mx_search_prev(t_path *head, t_island island);
bool mx_cmp_paths(void *a, void *b);
int mx_get_dst(t_path *head);

void mx_print_paths(t_list *paths, char **islands);

#endif

