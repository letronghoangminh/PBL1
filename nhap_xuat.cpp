#pragma once
#include <fstream>
#include <iostream>
using namespace std;

string selectionInput = "0";
int isSelected2 = 0;

void inputMenu() {
	system("CLS"); 
	cout	<< "******************************************" << endl
			<< "*                                        *" << endl
			<< "*               Nhap du lieu             *" << endl
			<< "*                                        *" << endl
			<< "*             1. Nhap thu cong           *" << endl
			<< "*             2. Doc tu file             *" << endl
			<< "*                                        *" << endl
			<< "******************************************" << endl
			<< endl;
	
	//Selection Validation
	do {
		isSelected2 = 0;
		cout << "====> Nhap lua chon: ";
		cin >> selectionInput;
		
		if(selectionInput == "1" || selectionInput == "2")
			isSelected2 = 1;
			
	} while(!isSelected2);
}

void doFileInput(double arr[][200], int *soAn) {
	ifstream input(".\\input.txt");
	input >> *soAn; 
	int h, w;
	h = *soAn;
	w = *soAn + 1;
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			input >> arr[i][j];
		}
	}	
}


void doConsoleInput(double arr[][200], int soAn) {
	
	int h = soAn;
	int w = soAn + 1;
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}
}

void doConsoleOutput(double ex[], int soAn) {
	cout << "\nCac an cua he phuong trinh la:\n";
	for(int i = 0; i < soAn; i++) {
		cout << ex[i] << " ";
	}
	cout << endl;
}
