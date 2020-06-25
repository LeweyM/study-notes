#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 01234
// hello

int matches_from_here(char* line, char* search_term, int search_term_length, int i, int depth) {
	printf("pop");
	if (depth == search_term_length) {
		printf("\nboop:%c\nbrap:%c\n", *(line+i), *(search_term+i));
		return 1;
	}
	if (*(line + i) == *(search_term + i)){
		return matches_from_here(line, search_term, search_term_length, i+1, depth+1);
	}
	return 0;
}

int matches(char* line, char* search_term, int line_len) {
	int search_term_len = strlen(search_term)-1;
	for (int i = 0; i < line_len; i++) {
		if (i + search_term_len >= line_len) {
			return 0;
		} else {
			int c = matches_from_here(line, search_term, search_term_len, i, 0);
			if (c == 1) return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	char *line;
	char *file_name = argv[1];

	char *search_term = argv[2];

	printf("grepping for: %s\n", search_term);
        fp = fopen(file_name, "r");

	size_t linecap = 0;
	ssize_t linelen;
	while((linelen = getline(&line, &linecap, fp)) > 0) {
		int contains = matches(line, search_term, linelen);
		printf("line: %sresult: %i\n", line, contains);
	}
	fclose(fp);
}
