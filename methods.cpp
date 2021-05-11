#pragma once
#include <iostream>
#include <math.h>

/*
 * This file contain 2 main method that solve the problem
 */

void doKrameMethod() {
	cout << "...doing krame method...";
	
	cout << endl;
	system("pause");
}

void doGaussMethod(double arr[][200], int n){
	cout << "...doing gauss method...";
	double ex[n]; //mang chua nghiem

	//bien doi ve ma tran tam giac
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double m = - (arr[j][i] / arr	[i][i]);
			for (int k = i; k < n + 1; k++) {
				arr[j][k] += arr[i][k] * m;
			}
		}
	}

	cout << "Sau khi bien doi tam giac" << endl;
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n + 1; j++) {
			cout << arr[i][j] << " ";
		}
	}

	//tim nghiem nguoc
	// for (int i = n - 1; i >= 0; i--) {
	// 	double s = arr[i][n];
	// 	for (int k = i + 1; k < n; k++) {
	// 		s -= arr[i][k] * ex[k];
	// 	}
	// 	ex[i] = s / arr[i][i];
	// }

	// // in nghiem
	// for (int i = 1; i <= n; i++) {
	// 	cout << ex[i] << " ";
	// }
	// cout << endl;
	system("pause");
}
