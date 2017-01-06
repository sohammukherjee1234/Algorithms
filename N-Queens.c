#include <stdio.h>
#include <math.h>
#define n 4

int board[n][n]; // 1 means Queen is placed, else not

int check(int r, int c) {
	int i, j;
	for (i = 0; i < c; i++) // same row
		if (board[r][i])
			return 0;
	for (i = r, j = c; i >= 0 && j >= 0; i--, j--) // upper left diagonal
		if (board[i][j])
			return 0;
	for (i = r, j = c; i < n && j >= 0; i++, j--) // lower left diagonal
		if (board[i][j])
			return 0;
	return 1;
}

int solve(int col) { // places 1 queen in each column first
	int i, j;
	if (col >= n) return 1;
	for (i = 0; i < n; i++) {
		if (check(i, col)) {
			board[i][col] = 1;
			if (solve(col+1))
				return 1;
			board[i][col] = 0;
		}
	}
	return 0;
}

int main() {
	int i, j;
	solve(0);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}