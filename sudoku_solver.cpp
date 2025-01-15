#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define EMPTY 0  
#define SIZE 9   

void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool canPlace(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num || 
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    bool foundEmpty = true;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == EMPTY) {
                foundEmpty = false;
                break;
            }
        }
        if (!foundEmpty) {
            break;
        }
    }

    if (foundEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (canPlace(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = EMPTY;
        }
    }

    return false;
}

int main() {
    int grid[SIZE][SIZE];

    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cin >> grid[row][col];
        }
    }

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "-1" << endl;

    }

    return 0;
}