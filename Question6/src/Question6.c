#include <stdio.h>
#include <stdlib.h>	// for rand function
#include <time.h>	// for time

// setting the number of elements in a row/column of the square matrices
#define SIZE 32

// setting the range of the random numbers [1 , range]
#define RANGE 999

int main() {
	setbuf(stdout, NULL);
	// setting the seed for random numbers to time
	srand(time(NULL));

	// declaring the 2D arrays of floats which will be used as matrices
	double matrixA[SIZE][SIZE];
	double matrixB[SIZE][SIZE];
	double matrixMULT[SIZE][SIZE];

	// counters for the for-loop to fill the matrices with random values, and to carry out the multiplication
	int i, j, k;

	// filling the matrices A&B with random Real Numbers
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			matrixA[i][j] = (double) rand() / (double) (RAND_MAX/RANGE);
			matrixB[i][j] = (double) rand() / (double) (RAND_MAX/RANGE);
		}
	}

	// displaying the matrices
	printf("Matrix A:\n");
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			printf("%f", matrixA[i][j]);
			// after every column insert a tab space for spacing
			printf("\t");
		}
		// after every row start a new line for spacing
		printf("\n");
	}
	printf("\nMatrix B:\n");
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			printf("%f", matrixB[i][j]);
			printf("\t");
		}
		printf("\n");
	}

	// carrying out the multiplication
	double sum = 0;
	// first two nested 'for's which go through every element in the final array
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			// setting the current element of the matrix holding the result of the multiplication to 0
			matrixMULT[i][j] = 0;

			// in this for loop, the program moves through the first array column by column,
			// and the second array row by row, each time working the product, and calculating
			// the value of the current element as a sum of each product
			for(k=0; k<SIZE; k++){
				sum += matrixA[i][k] * matrixB[k][j];
			}
			// setting the value of the current element in the matrix to the calculated sum
			matrixMULT[i][j] = sum;

			// resetting the sum
			sum = 0;
		}
	}

	// Displaying the result of the multiplication
	printf("\nResult of Multiplication:\n");
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			printf("%f", matrixMULT[i][j]);
			printf("\t");
		}
		printf("\n");
	}

	return 0;
}
