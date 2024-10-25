#include <stdio.h>
#include "compress.h"

void compress(int d_length, char * code) {
	const unsigned char A = 0b00;
	const unsigned char T = 0b01;
	const unsigned char C = 0b10;
	const unsigned char G = 0b11;

	unsigned char hold;
	unsigned char result = 0;

	int shift;

	for (int i = 0; i <= d_length; i++) {
		if (i % 4 == 0 || i == d_length) {
			if (i != 0) {
				printf("%hhu ", result);
			}
			result = 0;
			shift = 6;
		}
		//printf("%c %d %d\n", code[i], result, shift);
		switch (code[i]) {
		case 'A':
			hold = A;
			break;
		case 'T':
			hold = T;
			break;
		case 'C':
			hold = C;
			break;
		case 'G':
			hold = G;
			break;
		}
		result |= (hold<<shift);
		shift -= 2;
	}
	printf("\n");

}
