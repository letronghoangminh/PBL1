#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const int ARR_SIZE = 200;
string selectionInput = "0";
int isSelected2 = 0;

void inputMenu();
void doFileInput(double arr[][ARR_SIZE], string file_name, int *so_an, int *success);
void printProblem(double arr[][ARR_SIZE], int so_an);
void doConsoleInput(double arr[][ARR_SIZE], int so_an);
void doConsoleInput(double arr[][ARR_SIZE], int so_an);
void doConsoleOutput(double ex[], int so_an, int situation);

void inputMenu() {
	system("CLS"); 
	cout    << "+----------------------------------------+" << endl
		    << "|               Nhập dữ liệu             |" << endl
			<< "+----------------------------------------+" << endl
			<< "|                                        |" << endl
			<< "|             1. Nhập thủ công           |" << endl
			<< "|             2. Đọc từ file             |" << endl
			<< "|                                        |" << endl
			<< "+----------------------------------------+" << endl
			<< endl;
	
	//Selection Validation
	isSelected2 = 0;
	do {
		cout << "====> Nhập lựa chọn của bạn: ";
		cin >> selectionInput;
		if(selectionInput == "1" || selectionInput == "2")
			isSelected2 = 1;
	} while(!isSelected2);
}

void doFileInput(double arr[][ARR_SIZE], string file_name, int *so_an, int *success) {
	
	
	ifstream infile;
	infile.open(file_name.c_str());
	
	if( infile.is_open() ) {
		infile >> *so_an; 
		int n;
		n = *so_an;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n+1; j++) {
				infile >> arr[i][j];
			}
		}
		infile.close();
	}
	else {
		cout << "Không thể mở file!" << endl;
		*success = 0;
	}
	
}

void printProblem(double arr[][ARR_SIZE], int so_an) {
    cout << "+--------------------------------------------+" << endl;
    for(int i = 0; i < so_an; i++) {
        for(int j = 0; j < so_an - 1; j++) {
            printf("%7.2lfx%d + ",arr[i][j], j+1);
        }
        printf("%7.2lfx%d = %7.2lf\n", arr[i][so_an-1], so_an, arr[i][so_an]);
    }
    cout << "+--------------------------------------------+" << endl;


}


void doConsoleInput(double arr[][ARR_SIZE], int so_an) {
	
	int h = so_an;
	int w = so_an + 1;
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}
}

void doConsoleOutput(double ex[], int so_an, int situation) {
	
	if(situation == 1) {
		cout << "\n====> Hệ phương trình vô số nghiệm.";
	}
	
	if(situation == 2) {
		cout << "\n====> Các ẩn của hệ phương trình là: " << endl;
        printf("            +---------+--------------------+\n");
        printf("            |   STT   |       Giá trị      |\n");
        printf("            +---------+--------------------+\n");
		for(int i = 0; i < so_an; i++) {
            printf("            |   x%-3d  |     %-10.3lf     |\n", i+1, ex[i]); 
		}	
        printf("            +---------+--------------------+\n");
	}
	
	if(situation == 0) {
		cout << "\n====> Hệ phương trình vô nghiệm.";
	}
	
	cout << endl << endl;
}
