#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	char ch;
	char *file_name = argv[1];

	//printf("%s", file_name);
        fp = fopen(file_name, "r");

	while((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}
}
