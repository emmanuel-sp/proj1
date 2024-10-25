CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: proj1.out

proj1.out: proj1.o compress.o decompress.o
	$(CC) $(LFLAGS) -o proj1.out proj1.o compress.o decompress.o

proj1.o: proj1.c compress.h decompress.h
	$(CC) $(CFLAGS) proj1.c

compress.o: compress.c compress.h decompress.h
	$(CC) $(CFLAGS) compress.c

decompress.o: decompress.c compress.h decompress.h
	$(CC) $(CFLAGS) decompress.c

run: proj1.out
	./proj1.out -c ATTCGG

	./proj1.out -c CAT

	./proj1.out -c AGTCCCAGATTTCCC

	./proj1.out -c GTTAACCGGTTAGGCCTCCTC

	./proj1.out -c CCCCTAGAGAGAGAGAGCCGAGTTCAAAGTCAAAACCCATTCTCTCTCCTCG

	./proj1.out -d 6 22 240

	./proj1.out -d 3 132

	./proj1.out -d 15 54 163 21 168

	./proj1.out -d 21 212 43 212 250 105 128

	./proj1.out -d 52 170 76 204 204 235 53 128 216 2 161 102 102 155

	./proj1.out -c AGGGAA

	./proj1.out -d 6 63 0

clean:
	rm *.o
	rm proj1.out
