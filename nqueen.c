#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int board[20], count = 0;

void printSolution(int n) {
    printf("\nSolution %d:\n", ++count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j) printf("Q ");
            else printf(". ");
        }
        printf("\n");
    }
}

bool place(int row, int column) {
    for (int i = 1; i <= row - 1; i++) {
        // Check column and diagonal clashes
        if (board[i] == column || abs(board[i] - column) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void queen(int row, int n) {
    for (int column = 1; column <= n; column++) {
        if (place(row, column)) {
            board[row] = column;
            if (row == n) printSolution(n);
            else queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter number of Queens: ");
    scanf("%d", &n);
    queen(1, n);
    if (count == 0) printf("No solutions exist.\n");
    return 0;
}