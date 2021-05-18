#include <iostream>
#include <string>
#include "nhap_xuat.cpp"
#include "methods.cpp"

using namespace std;

int soAn = 0;	
double arrHeSo[ARR_SIZE][ARR_SIZE];
double ex[ARR_SIZE];

string selection = "0";
int isSelected = 0;
int situation;
int inputSuccess = 1;

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
		cout << "====> Nhap lua chon cua ban: ";
		cin >> selection;
		
		if(selection == "1" || selection == "2" || selection == "3")
			isSelected = 1;
	} while(!isSelected);
}


int main() {
	
	while(selection != "3") {
		for(int i = 0; i < 200; i++) {
			ex[i] = 0;
		}	
		index();
		if(selection == "3") return 0;
		
		/* Da chon phuong thuc giai, tien hanh nhap input
		 * Input bao gom so an cua he phuong trinh (soAn) va cac he so cua he phuong trinh (arr)
		 */
		inputMenu();
		if(selectionInput == "1") {
			cout << "Nhap so an: ";
			cin >> soAn;
			cout << "Nhap cac he so:\n";
			doConsoleInput(arrHeSo, soAn);
		}
		else if(selectionInput == "2") {
			string fileName;
			cout << "Nhap ten file: "; 
			cin >> fileName;
			doFileInput(arrHeSo, fileName, &soAn, &inputSuccess);
			if(!inputSuccess) goto cant_open_file;
		}
		
		//Da nhap input, tien hanh giai he phuong trinh
		if(selection == "1") {
			doGaussMethod(arrHeSo, soAn, ex);
		}
		
		if(selection == "2") {
			doKrameMethod(arrHeSo, soAn, ex);
		}

    	// bien situation luu 3 gia tri: 2 la co nghiem, 1 la vo so nghiem, 0 la vo nghiem
    	situation = checkEx(ex, soAn);
    	
		//Giai xong he phuong trinh, tien hanh xuat nghiem ra man hinh (xuat ex[])
		doConsoleOutput(ex, soAn, situation);
		
		cant_open_file:; //neu khong the mo file de input thi chuong trinh se nhay den doan nay
		
		system("pause");
	}
	return 0;
}
