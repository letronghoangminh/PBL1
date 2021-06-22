#include <iostream>
#include <string>
#include "nhap_xuat.cpp"
#include "methods.cpp"
#include "format.cpp"

using namespace std;

int so_an = 0;	
double arr_heso[ARR_SIZE][ARR_SIZE]; //Mang chua he so
double ex[ARR_SIZE]; //Mang chua nghiem

string selection = "0";
int isSelected = 0;
int situation;
int inputSuccess = 1;

void introduce() {
    cout	<< "+----------------------------------------------+" << endl
			<< "|     ĐỒ ÁN LẬP TRÌNH TÍNH TOÁN  PBL1 20.16    |" << endl
			<< "+----------------------------------------------+" << endl
			<< "|                                              |" << endl
			<< "|   ĐỀ TÀI: GIẢI HỆ PHƯƠNG TRÌNH TUYẾN TÍNH    |" << endl
			<< "|         BẰNG PHƯƠNG PHÁP GAUSS/KRAME         |" << endl
			<< "|                                              |" << endl
			<< "|            Sinh viên thực hiện:              |" << endl
            << "|          1. Lê Trọng Hoàng Minh              |" << endl 
            << "|          2. Nguyễn Văn Hoàng Nhân            |" << endl
            << "|                                              |" << endl
 			<< "+----------------------------------------------+" << endl
			<< endl << endl;
}

void index() {
	// Menu
	clrscr(); 
	cout	<< "+----------------------------------------+" << endl
			<< "|     Giải hệ phương trình tuyến tính    |" << endl
			<< "+----------------------------------------+" << endl
			<< "|                                        |" << endl
			<< "|         1. Phương pháp Gauss           |" << endl
			<< "|         2. Phương pháp Krame           |" << endl
			<< "|         3. Thoát                       |" << endl
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
    SetUnicode();
    SetColor(0, 15);
    clrscr();

    introduce();

    pause();
    clrscr();

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
			cout << "====> Nhập số ẩn: ";
			cin >> so_an;
			cout << "====> Nhập các hệ số:\n";
			doConsoleInput(arr_heso, so_an);
            cout << "Dữ liệu đã nhập là hệ phương trình:  " << endl;
            printProblem(arr_heso, so_an);
		}
		else if(selectionInput == "2") {
			string fileName;
			cout << "\n====> Nhập tên file: "; 
			cin >> fileName;
			doFileInput(arr_heso, fileName, &so_an, &inputSuccess);
			
            //truong hop mo file khong thanh cong, bo qua buoc tinh nghiem
            if(!inputSuccess) goto cant_open_file;

            //truong hop mo file thanh cong, in ra he phuong trinh 
            clrscr();
            cout << "Dữ liệu đã nhập là hệ phương trình:  " << endl;
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
		
		pause();
	}
	return 0;
}
