#include <stdio.h>
#include <math.h>	// for pow function
#include <stdlib.h>

// declaring the constant PI
#define PI 3.14159265359

float sin_cos(char fn, float input, int terms);
long factorial(int n);	// factorial function

int main(void) {
	setbuf(stdout, NULL);

	// char which holds whether the user wants to determine the sin or cos of a number
	char trig_fn;
	// float which holds the number on which trig function will be evaluated
	float input;
	// int which holds how many terms of the series expansion the user wants evaluated
	int terms;
	// float which holds the final answer of the calculation
	float answer;

	// determining whether the user wants to evaluate a sin or a cos
	printf("Please enter whether you want to evaluate a sin or cos (s for sin or c for cos).\n");
	scanf("%c", &trig_fn);

	// determining on what value the user wants to compute the trig fn.
	printf("Please enter the number you would like to compute the trig. fn. of. (in radians)\n");
	scanf("%f", &input);
	// calculating the modulus of the input to get it in the range of -2pi<input<2pi
	input = fmod(input, 2*PI);
	printf("%f\n", input);

	// determining how many terms of the series expansion the user wants considered
	printf("How many terms of the series expansion of the trigonometric function would you like to be evaluated?\n");
	scanf("%d", &terms);

	// calling the method sin_cos and passing whether the fn. is a sin or cos,
	// the input, and the number of terms requested as arguments.
	answer = sin_cos(trig_fn, input, terms);

	if(trig_fn == 's'){
		printf("sin(%f) = %f (up to %d terms)", input, answer, terms);
	}
	else if(trig_fn == 'c'){
		printf("cos(%f) = %f (up to %d terms)", input, answer, terms);
	}

	return 0;
}

float sin_cos(char fn, float input, int terms) {

	// float which will store the answer of the input
	float ans = 0.0;

	// counter for loop for series
	int i;

	// if the user wants a sin function evaluated
	if (fn == 's') {
		for (i = 0; i < terms; i++) {
			ans += pow(-1, i) * pow(input, (2*i + 1)) / factorial(2*i + 1);
		}
	} else if (fn == 'c') {
		for (i = 0; i < terms; i++) {
			ans += pow(-1, i) * pow(input, (2*i)) / factorial(2*i);
		}
	}

	return ans;
}

// function to evaluate factorials
long factorial(int n) {
	if (n == 0)
		return 1;
	else
		return (n * factorial(n - 1));
}
