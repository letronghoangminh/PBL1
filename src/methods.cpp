#pragma once
#include <iostream>
#include <math.h>
#include "input_output.cpp"
#include <stdlib.h>

using namespace std;

/*
 * This file contain 2 main method that solve the problem
 */

//Declaring utilities functions
void eliminateGaussJordan(int n, double arr[][200], double resultArr[][200]);

void findRootGaussJordan(double rootArr[], int n, double arr[][200]);

double calcDetCramer(double arr[][200], int n);

void checkDetCramer(double rootArr[],double det, int n, double arr[][200]);

void calcExCramer(double rootArr[], double arr[][200], double det, int n);

void permutateTriangle(int n, double arr[][200], double resultArr[][200]);

int checkEx(double rootArr[], int n);



//main functions
void doCramerMethod(double arr[][200], int n, double rootArr[]) {
	double resultArr[200][200];
	permutateTriangle(n, arr, resultArr);
	cout << "Sau khi biến đổi ma trận về ma trận tam giác: " << endl;
	printProblem(resultArr, n);
	double det = calcDetCramer(resultArr, n);
	cout << "Định thức của ma trận vuông A là: " << det << endl;
	checkDetCramer(rootArr, det, n, arr);
}


void doGaussJordanMethod(double arr[][200], int n, double rootArr[]){
	double resultArr[200][200];
	cout << "Sau khi biến đổi ma trận bằng phương pháp khử Gauss-Jordan: " << endl;
	eliminateGaussJordan(n, arr, resultArr);
	findRootGaussJordan(rootArr, n, resultArr);
}

//main functions



//Utilities function
void eliminateGaussJordan(int n, double arr[][200], double resultArr[][200]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			resultArr[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
    if (resultArr[i][i] == 0.0) {
			printProblem(resultArr, n);
      if (resultArr[i][n] == 0.0) {
				resultArr[i][n] = NAN;
			} else {
				resultArr[i][n] = INFINITY;
			}
      return;
    }

    for (int j = 0; j < n; j++) {
      if (i != j) {
        double ratio = resultArr[j][i] / resultArr[i][i];

        for (int k = 0; k < n + 1; k++)
        {
          resultArr[j][k] = resultArr[j][k] - ratio * resultArr[i][k];
        }
      }
    }
  }

	printProblem(resultArr, n);
}


void permutateTriangle(int n, double arr[][200], double resultArr[][200]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			resultArr[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (abs(resultArr[i][i]) < 0.001) {
			for (int j = i + 1; j < n; j++) {
				if (abs(resultArr[j][i]) > 0.01) {
					for (int k = 0; k < n + 1; k++) {
						double temp = resultArr[i][k];
						resultArr[i][k] = resultArr[j][k];
						resultArr[j][k] = temp;
					}
				}
				break;
			}
		}

		for (int j = i + 1; j < n; j++) {
			double m = - (resultArr[j][i] / resultArr	[i][i]);
			
			for (int k = i; k < n + 1; k++) {
				resultArr[j][k] += resultArr[i][k] * m;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (abs(resultArr[i][j]) < 0.001) resultArr[i][j] = 0;
		}
	}
}


void findRootGaussJordan(double rootArr[], int n, double arr[][200]) {
	for (int i = 0; i < n; i++) {
    rootArr[i] = arr[i][n] / arr[i][i];
  }
}


int checkEx(double rootArr[], int n) {
	for (int i = 0; i < n; i++) {
		if (rootArr[i] == INFINITY || rootArr[i] == -INFINITY) {
			return 0;
		}
		if (isnan(rootArr[i])) {
			return 1;
		}
	}

	return 2;
}


double calcDetCramer(double arr[][200], int n) {
	double det = 1;

	for (int i = 0; i < n; i++) {
		det *= arr[i][i];
	}

	return det;
}


void checkDetCramer(double rootArr[], double det, int n, double arr[][200]) {
	if (det == 0) {
		for (int i = 1; i < n; i++) {
			if (arr[i][n] != arr[i - 1][n]) {
				rootArr[0] = INFINITY;
				return;
			}
		}

		rootArr[0] = NAN;
	} else {
		calcExCramer(rootArr, arr, det, n);	
	}
}


void calcExCramer(double rootArr[], double arr[][200], double det, int n) {
	for (int i = 0; i < n; i++) {
		double tempArr[200][200];

		for (int k = 0; k < n; k++) {
			for (int j = 0; j < n + 1; j++) {
				tempArr[k][j] = arr[k][j];
			}
		}

		for (int j = 0; j < n; j++) {
			double temp = tempArr[j][i];
			tempArr[j][i] = tempArr[j][n];
			tempArr[j][n] = temp;
		}
		
		cout << "Ma trận A" << i + 1 << " là: " << endl;
		printProblem(tempArr, n);
		permutateTriangle(n, tempArr, tempArr);
		cout << "Ma trận A" << i + 1 << " sau khi biến đổi về ma trận tam giác: " << endl;
		printProblem(tempArr, n);
		double detI = calcDetCramer(tempArr, n);
		cout << "Định thức của ma trận vuông A" << i + 1 << ": " << detI << endl;
		rootArr[i] = detI / det;
	}
}

//Utilities functions
