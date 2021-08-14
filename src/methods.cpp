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
void eliminateGaussJordan(int n, double arr[][200], double cloneArray[][200]);
void findRootGaussJordan(double rootArr[], int n, double arr[][200]);


double calcDetCramer(double arr[][200], int n);
void checkDetCramer(double rootArr[],double det, int n, double arr[][200]);
void calcRootCramer(double rootArr[], double arr[][200], double det, int n);

void permutateTriangle(int n, double arr[][200], double cloneArray[][200]);
int checkRoot(double rootArr[], int n);
void copyArray(double arr[][200], double cloneArray[][200], int n);
void swapColunm(double arr[][200], int col, int n);
void handleFloatErrors(double arr[][200], int n);
void swapArrayElement(double arr[][200], int firstRow, int secondRow, int column);


/******************************************************/


//main functions
void doCramerMethod(double arr[][200], int n, double rootArr[]) {
	double cloneArray[200][200];
	permutateTriangle(n, arr, cloneArray);

	cout << "Sau khi biến đổi ma trận về ma trận tam giác: " << endl;
	printProblem(cloneArray, n);

	double det = calcDetCramer(cloneArray, n);
	cout << "Định thức của ma trận vuông A là: " << det << endl;

	checkDetCramer(rootArr, det, n, arr);
}


void doGaussJordanMethod(double arr[][200], int n, double rootArr[]){
	double cloneArray[200][200];
	cout << "Sau khi biến đổi ma trận bằng phương pháp khử Gauss-Jordan: " << endl;

	eliminateGaussJordan(n, arr, cloneArray);
	findRootGaussJordan(rootArr, n, cloneArray);
}

//main functions



//Utilities function

void eliminateGaussJordan(int n, double arr[][200], double cloneArray[][200]) {
	copyArray(arr, cloneArray, n);

	for (int i = 0; i < n; i++) {
		// Check if arr[i][i] = 0 then handle ending program situations
    if (cloneArray[i][i] == 0.0) {
			printProblem(cloneArray, n);
      if (cloneArray[i][n] == 0.0) {
				// Setting this for checking infinite roots
				cloneArray[i][n] = NAN;
			} else {
				// Setting this for checking no roots
				cloneArray[i][n] = INFINITY;
			}
      return;
    }

		// Doing Gauss-Jordan elimination
    for (int j = 0; j < n; j++) {
      if (i != j) {
        double ratio = cloneArray[j][i] / cloneArray[i][i];

        for (int k = 0; k < n + 1; k++)
        {
          cloneArray[j][k] = cloneArray[j][k] - ratio * cloneArray[i][k];
        }
      }
    }
  }

	printProblem(cloneArray, n);
}


void permutateTriangle(int n, double arr[][200], double cloneArray[][200]) {
	copyArray(arr, cloneArray, n);

	for (int i = 0; i < n - 1; i++) {
		// Check if arr[i][i] = 0 then swap rows
		if (abs(cloneArray[i][i]) < 0.001) {
			for (int j = i + 1; j < n; j++) {
				if (abs(cloneArray[j][i]) > 0.01) {
					for (int k = 0; k < n + 1; k++) {
						swapArrayElement(i, j, k);
					}
				}
				break;
			}
		}

		// Doing Gauss elimination
		for (int j = i + 1; j < n; j++) {
			double m = - (cloneArray[j][i] / cloneArray	[i][i]);
			
			for (int k = i; k < n + 1; k++) {
				cloneArray[j][k] += cloneArray[i][k] * m;
			}
		}
	}

	handleFloatErrors(cloneArray, n);
}


void findRootGaussJordan(double rootArr[], int n, double arr[][200]) {
	for (int i = 0; i < n; i++) {
    rootArr[i] = arr[i][n] / arr[i][i];
  }
}


int checkRoot(double rootArr[], int n) {
	for (int i = 0; i < n; i++) {
		if (rootArr[i] == INFINITY || rootArr[i] == -INFINITY) {
			// No roots
			return 0;
		}
		if (isnan(rootArr[i])) {
			// Infinite root
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
				// Setting this for checking no roots
				rootArr[0] = INFINITY;
				return;
			}
		}

		// Setting this for checking infinite roots
		rootArr[0] = NAN;
	} else {
		calcRootCramer(rootArr, arr, det, n);	
	}
}


void calcRootCramer(double rootArr[], double arr[][200], double det, int n) {
	for (int i = 0; i < n; i++) {
		double tempArr[200][200];

		copyArray(arr, tempArr, n);

		// Making Ai array
		swapColunm(tempArr, i, n);
		
		cout << "Ma trận A" << i + 1 << " là: " << endl;
		printProblem(tempArr, n);

		// Turn matrix to triangle matrix
		permutateTriangle(n, tempArr, tempArr);
		cout << "Ma trận A" << i + 1 << " sau khi biến đổi về ma trận tam giác: " << endl;
		printProblem(tempArr, n);
		
		double detI = calcDetCramer(tempArr, n);
		cout << "Định thức của ma trận vuông A" << i + 1 << ": " << detI << endl;

		rootArr[i] = detI / det;
	}
}


void copyArray(double arr[][200], double cloneArray[][200], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cloneArray[i][j] = arr[i][j];
		}
	}
}


void swapColunm(double arr[][200], int col, int n) {
	for (int i = 0; i < n; i++) {
			double temp = arr[i][col];
			arr[i][col] = arr[i][n];
			arr[i][n] = temp;
	}
}


void handleFloatErrors(double arr[][200], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (abs(arr[i][j]) < 0.001) arr[i][j] = 0;
		}
	}
}

void swapArrayElement(double arr[][200], int firstRow, int secondRow, int column) {
	double temp = cloneArray[firstRow][column];
	cloneArray[firstRow][column] = cloneArray[secondRow][column];
	cloneArray[secondRow][column] = temp;
}


//Utilities functions
