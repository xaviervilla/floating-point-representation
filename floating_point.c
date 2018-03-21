#include <stdio.h>

void print_from_memory(float* num){

	int fsize = 8*sizeof(*num);
	unsigned int ptr = *((unsigned int*)num);
	printf("\n======================================================================================\n");
	printf("The size of our floating point is %d bits.\n", fsize);
	printf("\nOur floating point number is %f in decimal, stored at memory address %x.\n", *num, ptr);
	printf("\nIf we read each bit from memory, it looks like this (after we write it backwards):\n");
	printf("\n");
	printf("Sign	Exponent		Significand\n");

	ptr >> 31 & 1;
	for( int i = 0; i < 32; i++){
		if (i == 1 || i == 9){
			printf("	");
		}
	    printf("%d ", ptr >> (-i-1) & 1);
	}

	printf("\n=====================================================================================\n\n");

	}

int main(){

	float num = 0.0;

	printf("Enter a float, or 0 to stop.\n");
	scanf("%f", &num);
	print_from_memory(&num); 

	while (num != 0.0){

		printf("Enter another float, or 0.0 to stop.\n");
		scanf("%f", &num);
		print_from_memory(&num);

	}
	
	return 0;

}