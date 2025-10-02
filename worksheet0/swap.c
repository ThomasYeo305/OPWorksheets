#include <stdio.h>

// Function to swaap the two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 5, y = 10; // Sets two values to swap

    printf("Before: x = %d, y = %d\n", x, y); // Prints the numbers order before the swap

    swap(&x, &y); // Swaps numbers using the swap function

    printf("After:  x = %d, y = %d\n", x, y); // Shows the numbers order after the swap

    return 0;
}
