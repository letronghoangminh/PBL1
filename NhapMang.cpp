#include <iostream>

using namespace std;

void nhap(int rows, int cols, int matrix[][1001])
{
  cout << "Nhap cac hang so: " << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> matrix[i][j];
    }
  }
}

void xuat(int rows, int cols, int matrix[][1001])
{
  cout << "Cac hang so la: " << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  cout << "Nhap so an: " << endl;
  int n;
  cin >> n;
  int matrix[1001][1001];
  nhap(n, n + 1, matrix);
  xuat(n, n + 1, matrix);
}