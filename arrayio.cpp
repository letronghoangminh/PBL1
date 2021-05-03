#pragma once
#include <iostream>
using namespace std;

/*
	Define: 
		h: arr/matrix height;
		w: arr/matrix width;
*/

void arrayInput(int arr[][200], int h, int w) {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}
}

void arrayOutput(int arr[][200], int h, int w) {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cout << arr[i][j];
		}
	}
}
