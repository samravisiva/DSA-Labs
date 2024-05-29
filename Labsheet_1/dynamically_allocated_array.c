#include <stdio.h>
#include <stdlib.h>

int main(){
	float* p;

	p=(float*)malloc(10*sizeof(float));

	if (p==NULL){
		return 1;
	}

	for(int i=0; i<10; i++){
		p[i]= (float)i/10;
	}

	for(int i=0; i<10; i++){
		printf("%f\n", *(p+i));
	}
}