# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(){
	int m;
	printf("Enter size of string");
	scanf("%d", &m);
	char* string= (char*)malloc(m*sizeof(char));

	int n;
	printf("Enter the size of Array");
	scanf("%d", &n);
	char** arr= (char**)malloc(n*sizeof(string));

	if(arr==NULL){
		printf("Not able to allocate memory");
	}
	
	


	printf("Adding elements to the Array\n");
	printf("Enter strings(space separated)");
	for(int i=0; i<n; i++){
		scanf("%s", &arr[i]);
	}

	printf("The elements in the Array are ");
	for(int i=0; i<n; i++){
		printf("%s\n", &arr[i]);
	}
}