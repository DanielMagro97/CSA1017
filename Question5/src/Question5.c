#include <stdio.h>
#include <math.h>	// for fabs funtion

// defining to what point of accuracy the Newton Raphson method will run
#define ACCURACY 0.001

int main(){
	setbuf(stdout, NULL);

	// float which stores the user's input
	float input;
	// asking the user for an input
	printf("What number would you like to compute the square root of\n");
	// accepting the user's input
	scanf("%f", &input);

	// Declare three floats which will store:
	// x0 - what the previous approximation was
	// x1 - a more accurate approximation (current approximation)
	// error - a measure of how much the result has changed from the last iteration
	float x0, x1, error;

	// First Guess
	x1 = input/2;
	do{
		// what was the most recent approximation is set to the previous approximation
		x0 = x1;
		// Newton Raphson Algorithm
		x1 = (0.5)*(x0 + input/x0);
		// computing the magnitude of how much the approximation has changed from the previous iteration
		error = fabs(x1-x0);
		// do this until the error is less than the specified amount
	}while(error > ACCURACY);

	printf("The exact square root of %f is %f\n", input, sqrt(input));
	printf("The square root of %f is approximately %f (to the nearest %f)\n", input, x1, ACCURACY);

	return 0;
}
