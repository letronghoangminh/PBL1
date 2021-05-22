#pragma once
#include <iostream>
#include <math.h>

/*
 * This file contain 2 main method that solve the problem
 */

//Declaring utilities functions
void findReverseExGauss(double ex[], int n, double arr[][200]);
double calcDetKrame(double arr[][200], int n);
void checkDetKrame(double det, int n, double arr[][200]);
void permutateTriangle(int n, double arr[][200]);
int checkEx(double ex[], int n);


//main functions
void doKrameMethod(double arr[][200], int n, double ex[]) {
	permutateTriangle(n, arr);
	double det = calcDetKrame(arr, n);
	checkDetKrame(det, n, arr);
}

void doGaussMethod(double arr[][200], int n, double ex[]){
	permutateTriangle(n, arr);
	findReverseExGauss(ex, n, arr);
}

//main functions

//Utilities function
void permutateTriangle(int n, double arr[][200]) {
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
//TODO check det
//TODO fill arr with each situation
//TODO create function to calc ex if det != 0
void checkDetKrame(double det, int n, double arr[][200]) {
	if (det == 0) {
		
	} else {

	}
}
//Utilities functions
