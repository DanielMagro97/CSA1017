#include <stdio.h>
#include <stdlib.h>	// for atof function
#include <string.h>	// for strlen function
#include <ctype.h>	// for isdigit function

#define SIZE 100	// size of the array which will be used as the stack

void push(float stack[], int * stackPointer, float si);	// si is stack input
float pop(float stack[], int * stackPointer);

int main() {
	setbuf(stdout, NULL);

	// declaring the array which will be used as a stack
	// and a pointer to the stack (stackPointer) which points to the last character pushed onto the stack.
	float stack[SIZE];
	int stackPointer = -1;

	// declaring an array of 'char's which will hold the postfix expression to be evaluated
	char postfix[SIZE];
	// ask the user to input the expression to be converted
	printf("Enter the RPN expression you would like evaluated (include a space between operands and operators) \n");
	// store the user's inputted expression in the array 'expression'
	gets(postfix);

	// Evaluating postfix expressions using the stack
	int i = 0;
	float op1;				// float that will hold one operand popped from the stack
	float op2;				// float that will hold one operand popped from the stack
	float result;			// float that will temporarily hold the result of an operation
	char stringOperand[10];	// array will be used to convert strings to numbers
	int operandIndex;		// index for the array of the operand as a char
	float floatOperand;		// float that will hold converted strings

	while(postfix[i] != '\0'){

		// if the current character is an operand
		if(isdigit(postfix[i])){
			// reset the index for the array containing the operand as a string to -1
			operandIndex = -1;
			// append the current character (digit) to the array storing the operand as a string
			stringOperand[++operandIndex] = postfix[i];
			// while the next character isn't a whitespace (implies it is part of the same number)
			while(postfix[i+1] != ' '){
				stringOperand[++operandIndex] = postfix[++i];
			}
			// indicate the end of the string
			stringOperand[++operandIndex] = '\0';

			// convert the string containing the operand to a float
			floatOperand = atof(stringOperand);
			// push the float to the stack
			push(stack, &stackPointer, floatOperand);
		}
		// if the current character is an operator
		else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
			switch (postfix[i]){

			// if the operator is a + (addition)
			case '+':
				// set the second operand to whatever is at the top of the stack
				op2 = pop(stack, &stackPointer);
				// set the first operand to whatever is at the top of the stack
				op1 = pop(stack, &stackPointer);
				// compute the result
				result = op1 + op2;
				// push the result to the top of the stack
				push(stack, &stackPointer, result);
				break;
			case '-':
				op2 = pop(stack, &stackPointer);
				op1 = pop(stack, &stackPointer);
				result = op1 - op2;
				push(stack, &stackPointer, result);
				break;
			case '*':
				op2 = pop(stack, &stackPointer);
				op1 = pop(stack, &stackPointer);
				result = op1 * op2;
				push(stack, &stackPointer, result);
				break;
			case '/':
				op2 = pop(stack, &stackPointer);
				op1 = pop(stack, &stackPointer);
				result = op1 / op2;
				push(stack, &stackPointer, result);
				break;
			}
		}
		i++;
	}

	printf("The result of the expression (rounded to 4 decimal places) is %.4f\n", pop(stack, &stackPointer));

	return 0;
}

// method to push onto the stack
void push(float stack[], int * stackPointer, float si) {
	// if the stack pointer points to the last element, then the stack is full
	if (*stackPointer == (SIZE - 1)) {
		printf("The stack is full\n");
	} else {
		(*stackPointer)++;			// increment the stack pointer to point to an empty element
		stack[*stackPointer] = si;	// stores the input in the element indicated by the stack pointer
	}

	// Displaying the contents of the stack, the element which is displayed first is the one at the bottom of the stack
	int i = 0;
	while(i <= *stackPointer){
		printf("%f", stack[i]);
		printf("\t");
		i++;
	}
	printf("\n");
}

// method to pop from the top of the stack
float pop(float stack[], int * stackPointer) {
	// if the stack pointer points to element '-1', then the stack is empty
	if (*stackPointer == -1) {
		printf("The stack is empty\n");
		return '\0';	// return a null character
	} else {
		// return whatever is at the top of the stack (pointed to by the stack pointer)
		// then decrement the stack pointer to point to the previous element (accomplished with a postfix decrement)
		return stack[(*stackPointer)--];
	}
}
