#include <iostream>

using namespace std;

void nhap(int rows, int cols, int matrix[][1001]) {
  cout << "Nhap cac hang so: " << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }
}

void swapRow(arr[][1001], n, row1, ro22) {
	for(int j = 0; j <= n; j++) {
		tg = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tg;
	}
}

void gauss(int matrix[][1001], int n)
{
  for (int i = 1; i < n; i++) {
    if (matrix[i][i] == 0) {
      for (int j = i + 1; j <= n; j++) {
        if (matrix[j][i] != 0) {
          swapRow(matrix, n, i, j);
          break;
        }
        if (j > n) {
          cout << "HPT vo so nghiem";
          return;
        }
      }
    }
  }
}

int main() {
  cout << "Nhap so an: " << endl;
  int n;
  cin >> n;
  int matrix[1001][1001];
  nhap(n, n + 1, matrix);
}
