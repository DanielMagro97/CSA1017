#include <stdio.h>
#include <stdbool.h>	// for boolean data type
#include <math.h>		// for sqrt function

bool is_prime(int number);
int sieve_of_Eratosthenes(int limit);

int main() {
	setbuf(stdout, NULL);

	int number;
	printf("Which number do you want to know is prime?\n");
	scanf("%d", &number);

	if(is_prime(number) == 1){
		printf("%d is a prime number\n", number);
	} else{
		printf("%d is not a prime number\n", number);
	}

	printf("Up till which number would you like to know is prime?\n");
	printf("Using the Sieve of Eratosthenes algorithm.\n");
	int limit;
	scanf("%d", &limit);
	sieve_of_Eratosthenes(limit);

	return 0;
}

bool is_prime(int number) {

	// if the number is 1, then it is not a prime number
	if(number == 1){
		return false;
	}
	// else, if the number is 2, then it is a prime number
	else if(number == 2){
		return true;
	}
	// else, if the number is even, then it is not a prime number
	else if(number%2 == 0){
		return false;
	}
	// else, check if the number is divisible by any odd number between 3 and the square root of the number
	else{
		int i;
		for(i=3; i<=sqrt(number); i+=2){
			if(number%i == 0){
				return false;
			}
		}
		return true;
	}
}

int sieve_of_Eratosthenes(int limit){

	// a boolean array which holds whether the corresponding number is a prime or not
	// for simplicity the array will store from 0-limit
	bool primes[limit+1];

	// setting the number one as a non-prime
	primes[1] = false;
	// setting all the elements of the array of primes (2 - limit) to true
	int i,j;	// counters used for loops
	for(i=2; i<(limit+1); i++){
		primes[i] = true;
	}

	// go through all the numbers
	for(i=2; i<(limit+1); i++){
		// if the number is so far considered a prime
		if(primes[i] == 1){
			// start from twice the current number (since it is surely not a prime), and mark it and every successive
			// (with the number itself as an interval) number
			// Eg: If we are on number 5, then start from (2*5) 10 and mark it as non-prime, as well as every other 5th number.
			for(j=2*i; j<(limit+1); j+=i){
				primes[j] = false;
			}
		}
	}

	// printing the prime numbers
	for(i=1; i<(limit+1); i++){
		if(primes[i] == 1){
			printf("%d\t", i);
		}
	}
	printf("\n");

	return 0;
}

