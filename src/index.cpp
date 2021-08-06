#include <iostream>
#include <string>
#include "input_output.cpp"
#include "methods.cpp"
#include "format.cpp"

using namespace std;

int numberOfUnknowns = 0;	
double factorArr[ARR_SIZE][ARR_SIZE]; // Mảng chứa hệ số
double rootArr[ARR_SIZE]; // Mảng chứa nghiệm
int situation; // biến chứa 3 trường hợp giải nghiệm

string selection = "0";
int isSelected = 0;
int inputSuccess = 1;

void welcomeScreen();
void index();


/******************************************************/


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
		
		// Đã chọn phương pháp giải, tiến hành nhập input
		// Input bao gồm số ẩn cua hệ phương trình (numberOfUnknowns) và các hệ số của hệ phương trình (factorArr)
		//
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
		
		// Đã nhập input
    // Tiến hành giải hệ phương trình bằng 2 phương pháp theo lựa chọn
		if(selection == "1") {
			doGaussJordanMethod(factorArr, numberOfUnknowns, rootArr);
		}
		
		if(selection == "2") {
			doCramerMethod(factorArr, numberOfUnknowns, rootArr);
		}

    // Biến situation lưu 3 giá trị: 2 là có nghiệm, 1 là vô số nghiệm, 0 là vô nghiệm
    situation = checkEx(rootArr, numberOfUnknowns);
    	
		//Giải xong hệ phương trình, xuất nghiệm ra Console
		doConsoleOutput(rootArr, numberOfUnknowns, situation);
		
		cant_open_file:; //neu khong the mo file de input thi chuong trinh se nhay den doan nay
		
		pause();
	}
	return 0;
}


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
	
	//Validate lựa chọn (isSelected chỉ có 3 giá trị "1", "2", "3") 
	do {
		isSelected = 0;
		cout << "====> Nhap lua chon cua ban: ";
		cin >> selection;
		
		if(selection == "1" || selection == "2" || selection == "3")
			isSelected = 1;
	} while(!isSelected);
}
