#include <stdio.h>

int main(){
	int var = 20;
	int *p;
	p = &var;
	printf("The address var is stored in is %x\n", &var);
	printf("The pointer p points tp %x\n", p );
	printf("The value stored in the pointer p is %d\n", *p);
}