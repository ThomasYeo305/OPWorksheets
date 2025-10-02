#include <stdio.h>

// Function to print 2D array
void print2DArray(int *arr, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            
            // Accesses element at row i and column j
            printf("%d ", *(arr + i * width + j));
        }
        printf("\n");
    }
}

int main(void) {
    int width = 3, height = 2; // Sets 3x2 width and height

    // Puts example 2D array in memory
    int data[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("2D Array:\n");
    print2DArray(&data[0][0], width, height); // Prints the 2D array

    return 0;
}
