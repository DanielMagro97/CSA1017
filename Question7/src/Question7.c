#include <stdio.h>

int getMax(int array[], int i, int max);

int main(){
	setbuf(stdout, NULL);

	int size;

	/*
    printf("Enter the size of the array: ");
    scanf("%d",&size);

	int array[size];

    printf("Enter %d elements of an array: ", size);
    for(i=0;i<size;i++)
      scanf("%d",&arr[i]);

    */

	int array[] = {-7, -68, -95, 0};
	size = sizeof(array)/sizeof(array[0]);

    int max = getMax(array, 0, size-1);

    printf("Largest element of the array is: %d", max);

    return 0;
}

// recursive function to find the largest element in a list
// parameters of this function are a pointer to the array, the start of the array, and the end of it
int getMax(int array[], int start, int end){
	// int which will store the largest element found
	int max;
	// if there is only one element being considered, then it is the largest one
	if(start == end){
		return array[end];
	}
	// calling the recursive function and starting from the next element
	max = getMax(array, start+1, end);
	// if the first element being considered is greater than the max, return it
    if(array[start] > max){
    	return array[start];
    }
    // else return the current max
    else{
    	return max;
    }
}
