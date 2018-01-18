#include <stdio.h>
#include <stdlib.h>	// for exit function
#include <string.h>	// for strcat function

void convertRoman(int number);

int main() {
	setbuf(stdout, NULL);

	// variable which will store the number entered by the user that is to be represented in Roman Numerals
	int number;
	// prompt the user to enter a number between 1 and 1024 to be represented in Roman Numerals
	printf("Please enter the number (1-1024) you wish to be represented in Roman Numerals\n");
	// Accept the input from the user
	scanf("%d", &number);
	// Check if the user's input is greater than 1 and less than 1024
	if (number >= 1 && number <= 1024) {
		// if so call the method which will represent it as a roman numeral
		convertRoman(number);
	} else {
		// if not notify the user and exit the program
		printf("Only numbers between 1 and 1024 are accepted as input.\n");
		exit(0);
	}
	return 0;
}

void convertRoman(int number) {

	printf("The number %d will be represented in Roman Numerals.\n", number);

	// an array of the symbols of the numbers used in the Roman Numerals system
	char romanNumerals[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	// an array of the values of the numbers used in the Roman Numerals system
	int numerals[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	// array of chars that holds the resulting Roman Numeral
	char roman[15];
	roman[0] = '\0';
	// variable which indicates which Roman Numeral is currently being considered
	int i = 0;
	// variable which holds how many more numbers need to be converted
	int r = number;

	// while there are still numbers to be converted to Roman Numerals
	while(r != 0){
		// if the Roman Numeral currently being considered were to be deducted from the remaining value, and the value would
		// remain greater than or equal to zero, than the calculation is carried out, and the Roman Numeral is stored in
		// the resulting array
		if( (r-numerals[i]) >= 0){
			r -= numerals[i];
			strcat(roman, romanNumerals[i]);
		}
		// else consider the next Roman Numeral in the array
		else{
			i++;
		}
	}

	// print the result
	printf("The inputted number in Roman Numerals is: %s\n", roman);
}
