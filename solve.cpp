/**
 * Sudoku Solver Implemented in C++
 * Copyright 2018, Ajith Ramachandran, ajithar204@gmail.com
 *
 * This software is released under the terms of the
 * GNU LGPL license. See http://www.gnu.org/licenses/lgpl.html
 * for more information.
 *
 * */

#include<iostream>

#define N 9
#define UNASSIGNED 0

extern "C" {
    bool isSafe(int grid[N][N], int row, int col, int num);
    bool findUnassignedLocation(int grid[N][N], int &row, int &col);

    bool solveSudoku(int grid[N][N]) {
        /*
        function to solve sudoku puzzle recursively
        */
        int row, col, num;
        if(!findUnassignedLocation(grid, row, col))
            return true;
        
        for(num=1; num<=9; num++) {
            // checks if the number can be added to the location
            if(isSafe(grid, row, col, num)) {
                grid[row][col] = num;
                // calls solve sudoku recursively until the puzzle is solved
                if(solveSudoku(grid))
                    return true;

                grid[row][col] = UNASSIGNED;
            }
        }
        // No soultion exists for the puzzle
        return false;
    }

    bool findUnassignedLocation(int grid[N][N], int &row, int &col) {
        /*
        returns true if the grid contains unassigned columns
        sets value for the variables row and col
        */
        for(row=0; row<N; row++) {
            for(col=0; col<N; col++) {
                if(grid[row][col]==UNASSIGNED)
                    return true;
            }
        }
        return false;
    }

    bool usedInRow(int grid[N][N], int row, int num) {
        /*
        checks if the number is present in the same row
        */
        for(int col=0; col<N; col++) {
            if(grid[row][col]==num)
                return true;
        }
        return false;
    }

    bool usedInColumn(int grid[N][N], int col, int num) {
        /*
        checks if the number is present in the same column
        */
        for(int row=0; row<N; row++) {
            if(grid[row][col]==num)
                return true;
        }
        return false;
    }

    bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
        /*
        checks if the number is present in the same box
        */
        for(int row=0; row<3; row++) {
            for(int col=0; col<3; col++) {
                if(grid[row+boxStartRow][col+boxStartCol]==num)
                    return true;
            }
        }
        return false;
    }

    bool isSafe(int grid[N][N], int row, int col, int num) {
        /*
        checks if number is used is same row column and box
        */
        int boxStartRow = row-row%3; // set value for the starting row
        int boxStartCol = col-col%3; // and colummn of the current box
        if(!usedInRow(grid, row, num) && !usedInColumn(grid, col, num) && !usedInBox(grid, boxStartRow, boxStartCol, num))
            return true;
        return false;
    }

    void printGrid(int grid[N][N]) {
        /*
        prints the puzzle
        */
        for (int row=0; row<N; row++) { 
        for (int col=0; col<N; col++)
                std::cout<<grid[row][col]<<' ';
            std::cout<<("\n"); 
        } 
    }

    int main() {
        int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
        if (solveSudoku(grid) == true)
            printGrid(grid);
        else
            printf("No solution exists");
        return 0;
    }
}
