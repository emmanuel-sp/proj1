#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "compress.h"
#include "decompress.h"

int main(int argc, char * argv[]) {
	char * flag = argv[1];
	int d_length = strlen(argv[2]);
	if (flag[1] == 'd') {
		decompress(argc, argv);
	} else if (flag[1] == 'c') {
		printf("%d ", d_length);
		compress(d_length, argv[2]);
	}
	return 0;
}
