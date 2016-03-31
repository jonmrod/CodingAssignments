#include <stdio.h>
/*
Purpose: get comfortable with using pointers; Know difference between (&) and (*)
*/
int main() {
	//init variables
	int a;
	int b;

	//pointer variables
	int *pa;
	int *pb;
	int *pc;

	a = 12;
	b = 9;

	//assign pointers with a
	pa = &a;
	pb = pa;
	pc = pa;

	//print values pointed to a
	printf("&a assigned PA\n");
	printf("PA: %d, PB: %d, PC: %d\n", *pa, *pb, *pc);

	//print values pointed to b
	pa = &b;
	printf("&b assigned to PA\n");
	printf("PA: %d, PB: %d, PC: %d\n", *pa, *pb, *pc);

	//print out addresses
	printf("address values:\n");
	printf("PA: %p, PB: %p, PC: %p\n", pa, pb, pc);

	//print out value, address, and size of a
	printf("\n");
	printf("value of a: %d\n", a);
	printf("address of a: %p\n", &a);
	printf("size of a: %lu bytes\n", sizeof(a));
	
	
}