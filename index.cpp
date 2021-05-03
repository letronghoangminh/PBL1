#include <iostream>
#include <string>
#include "arrayio.cpp"
#include "methods.cpp"

using namespace std;

string selection = "0";
int isSelected = 0;

void index() {
	
	// Menu initalizing
	system("CLS"); 
	cout	<< "******************************************" << endl
			<< "*                                        *" << endl
			<< "*     Giai he phuong trinh tuyen tinh    *" << endl
			<< "*                                        *" << endl
			<< "*         1. Phuong phap Gauss           *" << endl
			<< "*         2. Phuong phap Krame           *" << endl
			<< "*         3. Thoat                       *" << endl
			<< "*                                        *" << endl
			<< "******************************************" << endl
			<< endl;
	
	//Selection Validation
	do {
		isSelected = 0;
		cout << "====> Nhap lua chon: ";
		cin >> selection;
		
		if(selection == "1" || selection == "2" || selection == "3")
			isSelected = 1;
			
	} while(!isSelected);
}

int main() {
	while(selection != "3") {
		index();
		
		if(selection == "1"){
			system("CLS");
			doGaussMethod();
		}
		
		if(selection == "2"){
			system("CLS");
			doKrameMethod();
		}
			
	}
	return 0;
}
