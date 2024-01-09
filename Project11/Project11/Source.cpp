#include <iostream>
using namespace std;

const int N = 9;

bool is_valid(int board[N][N], int row, int col, int num) {
	// Check if the number is not in the same row or column
	for (int i = 0; i < N; i++) {
		if (board[row][i] == num || board[i][col] == num) {
			return false;
		}
	}

	// Check if the number is not in the 3x3 grid
	int start_row = 3 * (row / 3);
	int start_col = 3 * (col / 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[start_row + i][start_col + j] == num) {
				return false;
			}
		}
	}

	return true;
}

bool find_empty_cell(int board[N][N], int& row, int& col) {
	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if (board[row][col] == 0) {
				return true;
			}
		}
	}
	return false;
}

bool solve_sudoku(int board[N][N]) {
	int row, col;

	if (!find_empty_cell(board, row, col)) {
		return true;  // Puzzle solved
	}

	for (int num = 1; num <= 9; num++) {
		if (is_valid(board, row, col, num)) {
			board[row][col] = num;

			if (solve_sudoku(board)) {
				return true;  // Move to the next empty cell
			}

			board[row][col] = 0;  // Backtrack if the current arrangement doesn't lead to a solution
		}
	}

	return false;  // No solution found
}

int main() {
	int sudoku_board[N][N];

	cout << "Enter the Sudoku puzzle (0 for empty cells):\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sudoku_board[i][j];
		}
	}

	if (solve_sudoku(sudoku_board)) {
		// Display the solved Sudoku
		cout << "\nSolved Sudoku:\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << sudoku_board[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "No solution exists." << endl;
	}


	return 0;
}