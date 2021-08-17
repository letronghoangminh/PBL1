#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include "format.cpp"

using namespace std;

const int ARR_SIZE = 200;
string selectionInput = "0";
int isSelected2 = 0;


void welcomeScreen();
void selectMethodMenu(string *selection);
void inputMenu(double factorArr[][ARR_SIZE], int *numberOfUnknowns, int *inputSuccess);
void doFileInput(double arr[][ARR_SIZE], string fileName, int *numberOfUnknowns, int *success);
void doFileOutput(double ex[], int numberOfUnknowns, int situation);
void printProblem(double arr[][ARR_SIZE], int numberOfUnknowns);
void doConsoleInput(double arr[][ARR_SIZE], int *numberOfUnknowns);
void doConsoleOutput(double ex[], int numberOfUnknowns, int situation);


/******************************************************/

void welcomeScreen() {
    cout	<< "+----------------------------------------------+" << endl
          << "|     ĐỒ ÁN LẬP TRÌNH TÍNH TOÁN  PBL1 20.16    |" << endl
          << "+----------------------------------------------+" << endl
          << "|                                              |" << endl
          << "|   ĐỀ TÀI: GIẢI HỆ PHƯƠNG TRÌNH TUYẾN TÍNH    |" << endl
          << "|         BẰNG PHƯƠNG PHÁP Gauss-Jordan/Cramer |" << endl
          << "|                                              |" << endl
          << "|            Sinh viên thực hiện:              |" << endl
          << "|          1. Lê Trọng Hoàng Minh              |" << endl 
          << "|          2. Nguyễn Văn Hoàng Nhân            |" << endl
          << "|                                              |" << endl
          << "+----------------------------------------------+" << endl
          << endl << endl;
}

void selectMethodMenu(string *selection) {
	// Menu
	clrscr(); 
	cout	<< "+----------------------------------------+" << endl
        << "|     Giải hệ phương trình tuyến tính    |" << endl
        << "+----------------------------------------+" << endl
        << "|                                        |" << endl
        << "|         1. Phương pháp Gauss-Jordan    |" << endl
        << "|         2. Phương pháp Cramer          |" << endl
        << "|         3. Thoát                       |" << endl
        << "|                                        |" << endl
        << "+----------------------------------------+" << endl
        << endl;
	
	//Validate choices (isSelected has 3 values "1", "2", "3")
  int isSelected = 0; 
	do {
		isSelected = 0;
		cout << "====> Nhập lựa chọn của bạn: ";
		cin >> *selection;
		
		if(*selection == "1" || *selection == "2" || *selection == "3")
			isSelected = 1;
	} while(!isSelected);
}

void inputMenu(double factorArr[][ARR_SIZE], int *numberOfUnknowns, int *inputSuccess) {
	clrscr();
  
	cout  << "+----------------------------------------+" << endl
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

  if(selectionInput == "1") {
			doConsoleInput(factorArr, numberOfUnknowns);
		}
		else if(selectionInput == "2") {
			string fileName;
			cout << "\n====> Nhập tên file: "; 
			cin >> fileName;
			doFileInput(factorArr, fileName, numberOfUnknowns, inputSuccess);
		}

}

void doFileInput(double arr[][ARR_SIZE], string fileName, int *numberOfUnknowns, int *success) {
	ifstream infile;
  fileName = "data/" + fileName;
	infile.open(fileName.c_str());
	if( infile.is_open() ) {
		infile >> *numberOfUnknowns; 
		int n;
		n = *numberOfUnknowns;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n+1; j++) {
				infile >> arr[i][j];
			}
		}
		infile.close();
    return;
	}
	
	*success = 0;	
}

void doConsoleInput(double arr[][ARR_SIZE], int *numberOfUnknowns) {
	
	cout << "====> Nhập số ẩn: ";
	cin >> *numberOfUnknowns;
	cout << "====> Nhập các hệ số:\n";

  int h = *numberOfUnknowns;
	int w = *numberOfUnknowns + 1;
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}
}

void printProblem(double arr[][ARR_SIZE], int numberOfUnknowns) {
    cout << "+--------------------------------------------+" << endl;
    for(int i = 0; i < numberOfUnknowns; i++) {
        for(int j = 0; j < numberOfUnknowns - 1; j++) {
            printf("%7.2lfx%d + ",arr[i][j], j+1);
        }
        printf("%7.2lfx%d = %7.2lf\n", arr[i][numberOfUnknowns-1], numberOfUnknowns, arr[i][numberOfUnknowns]);
    }
    cout << "+--------------------------------------------+" << endl << endl;
}

void doConsoleOutput(double ex[], int numberOfUnknowns, int situation) {
	
	if(situation == 1) {
		cout << "\n====> Hệ phương trình vô số nghiệm.";
	}
	
	if(situation == 2) {
        printf("            +---------+--------------------+\n");
        printf("            |   STT   |       Giá trị      |\n");
        printf("            +---------+--------------------+\n");
		for(int i = 0; i < numberOfUnknowns; i++) {
            printf("            |   x%-3d  |     %-10.3lf     |\n", i+1, ex[i]); 
		}	
        printf("            +---------+--------------------+\n");
	}
	
	if(situation == 0) {
		cout << "\n====> Hệ phương trình vô nghiệm.";
	}
	
	cout << endl << endl;
}

void doFileOutput(double ex[], int numberOfUnknowns, int situation) {

  FILE *outfile;
	outfile = fopen("data/result.out", "w");

  if(situation == 1) {
		fprintf(outfile,"\n====> Hệ phương trình vô số nghiệm.");
	}
	
	if(situation == 2) {
		fprintf(outfile,"\n====> Các ẩn của hệ phương trình là: \n");
    fprintf(outfile,"+---------+--------------------+\n");
    fprintf(outfile,"|   STT   |       Giá trị      |\n");
    fprintf(outfile,"+---------+--------------------+\n");
		for(int i = 0; i < numberOfUnknowns; i++) {
      fprintf(outfile,"|   x%-3d  |     %-10.3lf     |\n", i+1, ex[i]); 
		}	
      fprintf(outfile,"+---------+--------------------+\n");
	}
	
	if(situation == 0) {
		fprintf(outfile,"\n====> Hệ phương trình vô nghiệm.");
	}
  fclose(outfile);
}