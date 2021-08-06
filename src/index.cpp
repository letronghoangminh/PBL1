#include <iostream>
#include <string>
#include "input_output.cpp"
#include "methods.cpp"
#include "format.cpp"

using namespace std;
int numberOfUnknowns = 0;	
double factorArr[ARR_SIZE][ARR_SIZE]; //Mang chua he so
double rootArr[ARR_SIZE]; //Mang chua nghiem

string selection = "0";
int isSelected = 0;
int situation;
int inputSuccess = 1;

void welcomeScreen();
void index();

int main() {
    SetUnicode();
    SetColor(0, 15);
    clrscr();

    welcomeScreen();

    pause();
    clrscr();

	while(selection != "3") {
		
        for(int i = 0; i < 200; i++) {
			rootArr[i] = 0;
		}	

		index();

		if(selection == "3") return 0;
		
		/* Da chon phuong thuc giai, tien hanh nhap input
		 * Input bao gom so an cua he phuong trinh  numberOfUnknowns) va cac he so cua he phuong trinh (arr)
		 */
		inputMenu();
		if(selectionInput == "1") {
			cout << "====> Nhập số ẩn: ";
			cin >> numberOfUnknowns;
			cout << "====> Nhập các hệ số:\n";
			doConsoleInput(factorArr, numberOfUnknowns);
            cout << "Dữ liệu đã nhập là hệ phương trình:  " << endl;
            printProblem(factorArr, numberOfUnknowns);
		}
		else if(selectionInput == "2") {
			string fileName;
			cout << "\n====> Nhập tên file: "; 
			cin >> fileName;
			doFileInput(factorArr, fileName, &numberOfUnknowns, &inputSuccess);
			
            //truong hop mo file khong thanh cong, bo qua buoc tinh nghiem
            if(!inputSuccess) goto cant_open_file;

            //truong hop mo file thanh cong, in ra he phuong trinh 
            clrscr();
            cout << "Dữ liệu đã nhập là hệ phương trình:  " << endl;
            printProblem(factorArr, numberOfUnknowns);
		}
		
		//Da nhap input, tien hanh giai he phuong trinh
		if(selection == "1") {
			doGaussJordanMethod(factorArr, numberOfUnknowns, rootArr);
		}
		
		if(selection == "2") {
			doCramerMethod(factorArr, numberOfUnknowns, rootArr);
		}

    // bien situation luu 3 gia tri: 2 la co nghiem, 1 la vo so nghiem, 0 la vo nghiem
    situation = checkEx(rootArr, numberOfUnknowns);
    	
		//Giai xong he phuong trinh, tien hanh xuat nghiem ra man hinh (xuat rootArr[])
		doConsoleOutput(rootArr, numberOfUnknowns, situation);
		
		cant_open_file:; //neu khong the mo file de input thi chuong trinh se nhay den doan nay
		
		pause();
	}
	return 0;
}


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

void index() {
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
	
	//Validate lua chon 
	do {
		isSelected = 0;
		cout << "====> Nhap lua chon cua ban: ";
		cin >> selection;
		
		if(selection == "1" || selection == "2" || selection == "3")
			isSelected = 1;
	} while(!isSelected);
}
