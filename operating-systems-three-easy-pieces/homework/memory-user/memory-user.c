#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int bytes = atoi(argv[1]);
	printf("%s", "working...\n");
	printf("%ld\n", (long)getpid());
	
	
	bool *ptr;
	ptr = (bool*) malloc(bytes);

	while(true) {
		for (int i = 0; i < bytes; i++) {
			ptr[i] = !ptr[i];
		}
	}
}
