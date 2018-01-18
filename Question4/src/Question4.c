#include <stdio.h>
#include <stdlib.h>		// for exit function
#include <time.h>
#include <stdbool.h>	// for boolean data type
#include <math.h>		// for ceil function

#define SIZE 16384	// Setting the size of the array to 16384
#define RANGE 99999	// Range of random numbers (1 - range)

void swap(int * u, int * v);	// Generic swap method
void shellSort(int array[]);

int main(){
	setbuf(stdout, NULL);

	// declaring an array of 16384 integers
	int array[SIZE];

	// filling the array with random number
	srand(time(NULL));	// The seed of the random numbers will be based on time
	int i;	// counter for loops
	for(i=0; i<SIZE; i++){
		array[i] = (rand() % RANGE) + 1;
	}

	// displaying the unsorted list
	for(i=0; i<SIZE; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	// calling the optimised shell sort method
	shellSort(array);

	// displaying the sorted list
	for(i=0; i<SIZE; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	// Testing if the array was successfully sorted
	for (i = 1; i < SIZE; i++) {
		// if the preceding element is larger than the next one, then the program will output that the list wasn't
		// successfully sorted and exit the program
		if (array[i - 1] > array[i]) {	// each element is compared to the one before it
			printf("The list was not successfully sorted\n");
			exit(1);
		}
	}
	printf("The list was successfully sorted\n");

	return 0;
}

void shellSort(int array[]){
	// int which holds the gap which will be used to sort smaller 'sublists'
	int gap;
	// int which will be used as counters for loops
	int i;
	// boolean value which will indicate whether a swap has occurred or not
	bool flag;

	// setting the value of the gap/interval to half of the size of the array
	gap = SIZE/2;

	// do the following, until no swaps have occurred and the gap has become 1
	do{
		// set the flag to false
		flag = false;
		// bubble sort, but instead of comparing adjacent elements, elements have the gap in between
		for(i=0; i<(SIZE-gap); i++){
			if(array[i] > array[i+gap]){
				swap(&array[i], &array[i+gap]);
				// set the flag to true to indicate that a swap has occurred
				flag = true;
			}
		}
		// if the gap is still greater than 1
		if(gap > 1){
			// then divide it by 2 and round up
			gap = ceil(gap/2);
			// set the flag to true to indicate that the gap is not yet 1
			flag = true;
		}
	}while(flag != false);
}

// Generic swap method
void swap(int *u, int *v) {
	int temp;

	temp = *u;
	*u = *v;
	*v = temp;
}
