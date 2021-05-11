#include <iostream>
#include <string>
#include "nhap_xuat.cpp"
#include "methods.cpp"

using namespace std;

const int ARR_SIZE = 201;

int soAn = 0;
double arrHeSo[ARR_SIZE][ARR_SIZE];
double ex[ARR_SIZE];

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
		
		/* Da chon phuong thuc giai, tien hanh nhap input
		 * Input bao gom so an cua he phuong trinh (variableNumber) va bang he so cua he phuong trinh (arr)
		 *
		 */
		inputMenu();
		if(selectionInput == "1") {
			cout << "Nhap so an: ";
			cin >> soAn;
			doConsoleInput(arrHeSo, soAn);
		}
		else if(selection == "2") {
			doFileInput(arrHeSo, &soAn);

		}
		
		//Da nhap input, tien hanh giai he phuong trinh
		if(selection == "1"){
			system("CLS");
			doGaussMethod(arrHeSo, soAn, ex);
		}
		
		if(selection == "2"){
			system("CLS");
			doKrameMethod(arrHeSo, soAn, ex);
		}
		//Giai xong he phuong trinh, tien hanh xuat nghiem ra man hinh (xuat ex[])
		doConsoleOutput(ex, soAn);
		system("pause");
	}
	return 0;
}
