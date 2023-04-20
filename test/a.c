#include <stdio.h>
#include <stdint.h>

// Define the size of the 2D array
#define ROWS 16
#define COLS 35

// Define the 2D array
char arr[ROWS][COLS] = {
    "1111111111111111111111111",
    "1000000000110000000000001",
    "1011000001110000000000001",
    "1001000000000000000000001",
    "11111111101100000111000001",
    "100000000011000001110111111111111",
    "11110111111111011100000010001",
    "11110111111111111101010010001",
    "1111111111111   11111111111111",
    "11111111111111111111111111111",
    "11000000110101011100000010001",
    "10000000000000001100000010001",
    "10000000000000001101010010001",
    "11000001110101011111011110N0111",
    "11110111 1110101 101111010001",
    "11111111 1111111 111111111111"
};

// Define a function to perform the flood fill algorithm
int floodFill(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return 0;
    }
    if (arr[x][y] == ' ') {
        return 1;
    }
    if (arr[x][y] == '0') {
        arr[x][y] = '#';
        return floodFill(x-1, y) || floodFill(x+1, y) || floodFill(x, y-1) || floodFill(x, y+1);
    }
    return 0;
}

// Define a function to check if all '0' characters are not touching the space
int isTouchingSpace() {
    // Find the position of the first '0' character
    int x, y;
    for (x = 0; x < ROWS; x++) {
        for (y = 0; y < COLS; y++) {
            if (arr[x][y] == '0') {
                break;
            }
        }
        if (y != COLS) {
            break;
        }
    }

    // Use the flood fill algorithm to check if there is a path to an empty space
    return floodFill(x, y);
}

// Define the main function
int main() {
    int touchingSpace = isTouchingSpace();
    printf("%s", touchingSpace ? "Some '0' characters are touching the space.\n" : "No '0' characters are touching the space.\n");
    return 0;
}
