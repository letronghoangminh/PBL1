#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const int ARR_SIZE = 200;
string selectionInput = "0";
int isSelected2 = 0;

void inputMenu() {
	system("CLS"); 
	cout	<< "******************************************" << endl
			<< "*                                    	 *" << endl
			<< "*               Nhap du lieu             *" << endl
			<< "*                                        *" << endl
			<< "*             1. Nhap thu cong           *" << endl
			<< "*             2. Doc tu file             *" << endl
			<< "*                                        *" << endl
			<< "******************************************" << endl
			<< endl;
	
	//Selection Validation
	isSelected2 = 0;
	do {
		cout << "====> Nhap lua chon cua ban: ";
		cin >> selectionInput;
		if(selectionInput == "1" || selectionInput == "2")
			isSelected2 = 1;
	} while(!isSelected2);
}

void doFileInput(double arr[][ARR_SIZE], string fileName, int *soAn, int *success) {
	
	
	ifstream infile;
	infile.open(fileName.c_str());
	
	if( infile.is_open() ) {
		infile >> *soAn; 
		int n;
		n = *soAn;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n+1; j++) {
				infile >> arr[i][j];
			}
		}
		infile.close();
	}
	else {
		cout << "Khong the mo file input!" << endl;
		*success = 0;
	}
	
}


void doConsoleInput(double arr[][ARR_SIZE], int soAn) {
	
	int h = soAn;
	int w = soAn + 1;
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}
}

void doConsoleOutput(double ex[], int soAn, int situation) {
	
	if(situation == 1) {
		cout << "\n==>He phuong trinh vo so nghiem";
	}
	
	if(situation == 2) {
		cout << "\n==>Cac an cua he phuong trinh la:";
		for(int i = 0; i < soAn; i++) {
			cout << setprecision(4) << ex[i] <<  " ";
		}	
	}
	
	if(situation == 0) {
		cout << "\n==>He phuong trinh vo nghiem";
	}
	
	cout << endl << endl;
}
