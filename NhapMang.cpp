#include <iostream>

using namespace std;

void nhap(int rows, int cols, float matrix[][101]) {
  cout << "Nhap cac hang so: " << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }
}

void swapRow(arr[][101], n, row1, ro22) {
	for(int j = 0; j <= n; j++) {
		temp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = temp;
	}
}

void gauss(float matrix[][101], int n)
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

void giaiNghiem(float matrix[][101], int n) {
//	float s;
//	for(int i = n; i > 0; i--) {
//		s = 0;
//		for(int j = i + 1; j <= n; j++) {
//			s = s + a[i][j]*x[]
//		} 
//	}
}



int main() {
  cout << "Nhap so an: " << endl;
  int n;
  cin >> n;
  int nghiem[101];
  float matrix[101][101];
  nhap(n, n + 1, matrix);
  gauss(matrix, n);
  giaiNghiem(matrix, n);
  
}
