#include <stdio.h>
#include <stdlib.h>
#include "decompress.h"

void decompress(int argc, char * argv[]) {
	char code[64] = {0};
	int start = 63 - atoi(argv[2]);
	unsigned char num = 0;
	int left = 0;
	for (int i = 3; i < argc; i++) {
		num = (unsigned char) atoi(argv[i]);
		left = 0;
		for (int j = 0; j < 4 && start < 64; j++) {
			unsigned char shiftleft = num << left;
			unsigned char shiftright = shiftleft >> 6;
			switch (shiftright) {
			case 0:
				code[start++] = 'A';
				break;
			case 1:
				code[start++] = 'T';
				break;
			case 2:
				code[start++] = 'C';
				break;
			case 3:
				code[start++] = 'G';
				break;
			default:
				printf("Error\n");
				break;
			}
			left += 2;
		}
	}
	start = 63 - atoi(argv[2]);
	if (code[63] == 'A') {
		code[63] = '\0';
	}
	printf("%s\n", code + start);
}
