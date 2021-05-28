#include <iostream>
#include <string>
#include "nhap_xuat.cpp"
#include "methods.cpp"

using namespace std;

int so_an = 0;	
double arr_heso[ARR_SIZE][ARR_SIZE]; //Mang chua he so
double ex[ARR_SIZE]; //Mang chua nghiem

string selection = "0";
int isSelected = 0;
int situation;
int inputSuccess = 1;

void index() {
	// Menu
	system("CLS"); 
	cout	<< "+----------------------------------------+" << endl
			<< "|     Giai he phuong trinh tuyen tinh    |" << endl
			<< "+----------------------------------------+" << endl
			<< "|                                        |" << endl
			<< "|         1. Phuong phap Gauss           |" << endl
			<< "|         2. Phuong phap Krame           |" << endl
			<< "|         3. Thoat                       |" << endl
			<< "|                                        |" << endl
			<< "+----------------------------------------+" << endl
			<< endl;
	
	//Validate lua chon 
	do {
		isSelected = 0;
		cout << "====> Nhap lua chon cua ban: ";
		cin >> selection;
		
		if(selection == "1" || selection == "2" || selection == "3")
			isSelected = 1;
	} while(!isSelected);
}


int main() {
	cout	<< "+----------------------------------------------+" << endl
			<< "|     DO AN LAP TRINH TINH TOAN  PBL1 20.16    |" << endl
			<< "+----------------------------------------------+" << endl
			<< "|                                              |" << endl
			<< "|   DE TAI: GIAI HE PHUONG TRINH TUYEN TINH    |" << endl
			<< "|       BANG PHUONG PHAP GAUSS VA KRAME        |" << endl
			<< "|                                              |" << endl
			<< "|            Sinh vien thuc hien:              |" << endl
            << "|          1. Le Trong Hoang Minh              |" << endl 
            << "|          2. Nguyen Van Hoang Nhan            |" << endl
            << "|                                              |" << endl
 			<< "+----------------------------------------------+" << endl
			<< endl << endl;
    system("pause");
    system("CLS");

	while(selection != "3") {
		
        for(int i = 0; i < 200; i++) {
			ex[i] = 0;
		}	

		index();

		if(selection == "3") return 0;
		
		/* Da chon phuong thuc giai, tien hanh nhap input
		 * Input bao gom so an cua he phuong trinh (so_an) va cac he so cua he phuong trinh (arr)
		 */
		inputMenu();
		if(selectionInput == "1") {
			cout << "====> Nhap so an: ";
			cin >> so_an;
			cout << "====> Nhap cac he so:\n";
			doConsoleInput(arr_heso, so_an);
		}
		else if(selectionInput == "2") {
			string fileName;
			cout << "\n====> Nhap ten file: "; 
			cin >> fileName;
			doFileInput(arr_heso, fileName, &so_an, &inputSuccess);
			
            //truong hop mo file khong thanh cong, bo qua buoc tinh nghiem
            if(!inputSuccess) goto cant_open_file;

            //truong hop mo file thanh cong, in ra he phuong trinh 
            system("CLS");
            cout << "Du lieu da nhap tu file la he phuong trinh:  " << endl;
            printProblem(arr_heso, so_an);
		}
		
		//Da nhap input, tien hanh giai he phuong trinh
		if(selection == "1") {
			doGaussMethod(arr_heso, so_an, ex);
		}
		
		if(selection == "2") {
			doKrameMethod(arr_heso, so_an, ex);
		}

    	// bien situation luu 3 gia tri: 2 la co nghiem, 1 la vo so nghiem, 0 la vo nghiem
    	situation = checkEx(ex, so_an);
    	
		//Giai xong he phuong trinh, tien hanh xuat nghiem ra man hinh (xuat ex[])
		doConsoleOutput(ex, so_an, situation);
		
		cant_open_file:; //neu khong the mo file de input thi chuong trinh se nhay den doan nay
		
		system("pause");
	}
	return 0;
}
