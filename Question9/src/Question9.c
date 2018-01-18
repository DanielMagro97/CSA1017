#include <stdio.h>
#include <stdlib.h>	// for exit function

long fibonacci(int term);

int main() {
	setbuf(stdout, NULL);

	// int which will hold how many terms of the Fibonacci Series the user wants to calculate
	int term;
	// ask the user how many terms he would like calculated
	printf("Till which term of the fibonacci sequence do you wish to calculate\n");
	// accept the number of terms as an input
	scanf("%d", &term);

	// output the sum of the terms up until the term requested by the user
	printf("The sum of the fibonacci series up to the %dth term is %ld\n", term, fibonacci(term));

	return 0;
}

long fibonacci(int term){

	// Special cases
	if (term <= 0){
		printf("The requested term is invalid (must be greater than or equal to 1)\n");
		exit(0);
	}
	else if(term > 45){
		printf("The following answers are invalid due to the capacity of the long data type\n");
		printf("Try calculating up to a term less than 46\n");
	}
	if(term == 1){
		return 0;
	}

	// General Method

	// create an array of ints with as many elements as terms were requested by the user
	// to hold each term of the fibonacci sequence
	long fibonacci[term];
	// set the first term of the fibonacci sequence to 0
	fibonacci[0] = 0;
	// set the second therm of the fibonacci sequence to 1
	fibonacci[1] = 1;
	// declare the int which will hold the sum of the terms entered so far
	// initialise it to the sum of the first and second term
	long sum = fibonacci[0] + fibonacci[1];

	// declare a counter for loops
	int i;
	// for loop which starts from the third term of the fibonacci sequence up until the term entered by the user
	for (i = 2; i < term; i++) {
		// set the value of the current term to the sum of the previous 2 terms
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		// add the current term to the sum of all the terms of the series
		sum += fibonacci[i];
	}

	// for loop which displays all the terms of the Fibonacci Sequence
	for (i = 0; i < term; i++) {
		printf("%ld\t", fibonacci[i]);
	}
	printf("\n");

	return sum;
}
