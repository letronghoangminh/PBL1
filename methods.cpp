#pragma once
#include <iostream>
#include <math.h>

/*
 * This file contain 2 main method that solve the problem
 */

//Declaring utilities functions
void permutateTriangle(double ex[], int n, double arr[][200]);
void findReverseEx(double ex[], int n, double arr[][200]);
int checkEx(double ex[], int n);


//main functions
void doKrameMethod(double arr[][200], int n, double ex[]) {
	
}

int doGaussMethod(double arr[][200], int n, double ex[]){
	permutateTriangle(ex, n, arr);
	findReverseEx(ex, n, arr);
	int situation = checkEx(ex, n);
	return situation;
}

//main functions

//Utilities function
void permutateTriangle(double ex[], int n, double arr[][200]) {
	for (int i = 0; i < n - 1; i++) {
		if (abs(arr[i][i]) < 0.001) {
			for (int j = i + 1; j < n; j++) {
				if (abs(arr[j][i]) > 0.01) {
					for (int k = 0; k < n + 1; k++) {
						double temp = arr[i][k];
						arr[i][k] = arr[j][k];
						arr[j][k] = temp;
					}
				}
				break;
			}
		}
		for (int j = i + 1; j < n; j++) {
			double m = - (arr[j][i] / arr	[i][i]);
			for (int k = i; k < n + 1; k++) {
				arr[j][k] += arr[i][k] * m;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (abs(arr[i][j]) < 0.001) arr[i][j] = 0;
		}
	}
}

void findReverseEx(double ex[], int n, double arr[][200]) {
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
//Utilities functions
