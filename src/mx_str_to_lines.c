#include "pathfinder.h"

char **mx_str_to_lines(char *s) {
	if (s != NULL) {
		char **arr = NULL;
		char *ptr = s;
		int lines = 0;
		int linenum = 0;
		int len = 0;

		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] == '\n' && s[i + 1] != '\0')
				lines++;
		}
		lines++;
		arr = malloc(sizeof(char *) * (lines + 1));
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] == '\n' || s[i + 1] == '\0') {
				if (s[i] != '\n' && s[i + 1] == '\0')
					len++;
				arr[linenum] = mx_strndup(ptr, len);
				ptr = s + i + 1;
				linenum++;
				len = 0;
			}
			else
				len++;
		}
		arr[lines] = NULL;
		return arr;
	}
	return NULL;
}

