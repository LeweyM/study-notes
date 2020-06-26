# include <stdlib.h>
# include <stdio.h>

int main(int argc, char *argv[]) {
	int* data = malloc(sizeof(int) * 100);
	free(data + 50);
	printf("%i", data[1]);
	return 0;
}
