#pragma once
#include <iostream>
#include <math.h>
#include "nhap_xuat.cpp"

/*
 * This file contain 2 main method that solve the problem
 */

//Declaring utilities functions
void findReverseExGauss(double ex[], int n, double arr[][200]);
double calcDetKrame(double arr[][200], int n);
void checkDetKrame(double ex[],double det, int n, double arr[][200]);
void calcExKrame(double ex[], double arr[][200], double det, int n);
void permutateTriangle(int n, double arr[][200], double resultArr[][200]);
int checkEx(double ex[], int n);


//main functions
void doKrameMethod(double arr[][200], int n, double ex[]) {
	double resultArr[200][200];
	permutateTriangle(n, arr, resultArr);
	double det = calcDetKrame(resultArr, n);
	checkDetKrame(ex, det, n, arr);
}

void doGaussMethod(double arr[][200], int n, double ex[]){
	double resultArr[200][200];
	permutateTriangle(n, arr, resultArr);
	findReverseExGauss(ex, n, resultArr);
}

//main functions

//Utilities function
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

void findReverseExGauss(double ex[], int n, double arr[][200]) {
	for (int i = n - 1; i >= 0; i--) {
		double s = arr[i][n];

		for (int k = i + 1; k < n; k++) {
			s -= arr[i][k] * ex[k];
		}

		ex[i] = s / arr[i][i];
	}
}

int checkEx(double ex[], int n) {
	for (int i = 0; i < n; i++) {
		if (ex[i] == INFINITY || ex[i] == -INFINITY) {
			return 0;
		}
		if (isnan(ex[i])) {
			return 1;
		}
	}

	return 2;
}

double calcDetKrame(double arr[][200], int n) {
	double det = 1;

	for (int i = 0; i < n; i++) {
		det *= arr[i][i];
	}

	return det;
}


//TODO create function to calc ex if det != 0
void checkDetKrame(double ex[], double det, int n, double arr[][200]) {
	if (det == 0) {
		for (int i = 1; i < n; i++) {
			if (arr[i][n] != arr[i - 1][n]) {
				ex[0] = INFINITY;
				return;
			}
		}

		ex[0] = NAN;
	} else {
		calcExKrame(ex, arr, det, n);	
	}
}

void calcExKrame(double ex[], double arr[][200], double det, int n) {
	for (int i = 0; i < n; i++) {
		double tempArr[200][200];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n + 1; j++) {
				tempArr[i][j] = arr[i][j];
			}
		}

		for (int j = 0; j < n; j++) {
			double temp = tempArr[j][i];
			tempArr[j][i] = tempArr[j][n];
			tempArr[j][n] = temp;
		}

		permutateTriangle(n, tempArr, tempArr);
		double detI = calcDetKrame(tempArr, n);
		ex[i] = detI / det;
	}
}

//Utilities functions
