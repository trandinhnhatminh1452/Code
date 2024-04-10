#include <stdio.h>

#define N 9

int is_valid(int board[N][N], int row, int col, int num) {
    // Check if the number is already in the current row or column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }

    // Check if the number is already in the 3x3 sub-grid
    int start_row = 3 * (row / 3);
    int start_col = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[start_row + i][start_col + j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve_sudoku(board)) {
                            return 1;
                        }
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int count_sudoku_solutions(int board[N][N]) {
    int solution_count = 0;

    int row, col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                break;
            }
        }
        if (board[row][col] == 0) {
            break;
        }
    }

    if (row == N && col == N) {
        return 1;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            solution_count += count_sudoku_solutions(board);
            board[row][col] = 0;
        }
    }

    return solution_count;
}

int main() {
    int sudoku_board[N][N];

    printf("Enter the Sudoku board (9x9):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &sudoku_board[i][j]);
        }
    }

    if (solve_sudoku(sudoku_board)) {
        int solution_count = count_sudoku_solutions(sudoku_board);
        printf("Number of solutions: %d\n", solution_count);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
