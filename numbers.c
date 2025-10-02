#include <stdio.h>

int main(void) {
    // Sets basic variables
    FILE *file;
    int number;
    int sum = 0;

    // Opens numbers.txt file
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Could not open numbers.txt\n");
        return 1;
    }

    // Scans numbers line by line and adds them up
    while (fscanf(file, "%d", &number) == 1) {
        sum += number;
    }

    fclose(file); // Closes file

    printf("The sum of all numbers is: %d\n", sum); // Prints sum of all numbers

    return 0;
}
