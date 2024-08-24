#include <iostream>
#define N 4
using namespace std;

int steps = 0; // Global variable to count steps

void printSolution(int board[N][N]) {
  for (int i = 0; i < N; i++, cout << endl)
    for (int j = 0; j < N; j++) {
      cout << (board[i][j] ? "Q " : ". ");
    }
}

bool isSafe(int board[N][N], int row, int col) {
  for (int i = 0; i < col; i++) {
    if (board[row][i]) {
      steps++;
      return false;
    }
    steps += 4;
  }

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      steps++;
      return false;
    }

    steps += 6;
  }

  for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
    if (board[i][j]) {
      steps++;
      return false;
    }
    steps += 6;
  }

  return true;
}

bool solveNQUtil(int board[N][N], int col) {
  if (col >= N) {
    steps++;
    return true;
  }

  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;
      steps++; // Increment step count
      if (solveNQUtil(board, col + 1)) {
        steps++;
        return true;
      }
      board[i][col] = 0;
    }
  }
  return false;
}

bool solveNQ() {

  int board[N][N] = {0};
  if (!solveNQUtil(board, 0)) {
    cout << "Solution does not exist" << endl;
    return false;
  }
  printSolution(board);
  return true;
}

int main() {
  solveNQ();
  cout << "No. of required steps: " << steps << endl;
  return 0;
}