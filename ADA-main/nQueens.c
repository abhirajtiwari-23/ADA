#include <stdio.h>

#define N 4

int board[N][N];

// Function to check whether position is safe
int isSafe(int row, int col)
{
    int i, j;

    // Check left side row
    for(i = 0; i < col; i++)
    {
        if(board[row][i] == 1)
            return 0;
    }

    // Check upper-left diagonal
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return 0;
    }

    // Check lower-left diagonal
    for(i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

// Backtracking function
int solveNQueens(int col)
{
    int row;

    // Base case
    if(col >= N)
        return 1;

    // Try each row
    for(row = 0; row < N; row++)
    {
        if(isSafe(row, col))
        {
            // Place queen
            board[row][col] = 1;

            // Recur for next column
            if(solveNQueens(col + 1))
                return 1;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return 0;
}

// Function to print solution
void printBoard()
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    int i, j;

    // Initialize board with 0
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if(solveNQueens(0))
    {
        printf("Solution Exists:\n");
        printBoard();
    }
    else
    {
        printf("No Solution Exists");
    }

    return 0;
}
