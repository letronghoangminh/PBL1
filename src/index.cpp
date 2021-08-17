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
int inputSuccess = 1;

void welcomeScreen();

/******************************************************/


int main() {
  setUnicode();
  setColor(0, 15);
  clrscr();

  welcomeScreen();
  pause();
  
  clrscr();

	while(selection != "3") {
		
    for(int i = 0; i < 200; i++) {
			rootArr[i] = 0;
		}	

		selectMethodMenu(&selection);

		if(selection == "3") return 0;
		
		// Đã chọn phương pháp giải, tiến hành nhập input
		// Input bao gồm số ẩn cua hệ phương trình (numberOfUnknowns) và các hệ số của hệ phương trình (factorArr)
    // Nếu input bằng file, giá trị inputSuccess trả về 0 khi mở file thất bại. 
		inputMenu(factorArr, &numberOfUnknowns, &inputSuccess);

    //Trường hợp mở file thất bại, không thực hiện bước tính nghiệm và kết thúc phiên
    if(!inputSuccess) {
      setColor(0,4);
      cout << "Không thể mở file!" << endl;
      setColor(0,15);
      goto end_session;
    }
    
    clrscr();
    cout << "Dữ liệu đã nhập là hệ phương trình:  " << endl;
    printProblem(factorArr, numberOfUnknowns);
		
		
    // Tiến hành giải hệ phương trình bằng 2 phương pháp theo lựa chọn
    // Lưu nghiệm vào mảng rootArr[]
		if(selection == "1") {
			doGaussJordanMethod(factorArr, numberOfUnknowns, rootArr);
		}
		if(selection == "2") {
			doCramerMethod(factorArr, numberOfUnknowns, rootArr);
		}

    // Biến situation lưu 3 giá trị ứng với 3 trường hợp: 2 là có nghiệm, 1 là vô số nghiệm, 0 là vô nghiệm
    // Hàm checkRoot để kiểm tra trường hợp nghiệm
    situation = checkRoot(rootArr, numberOfUnknowns);
    	
		//Giải xong hệ phương trình, xuất nghiệm ra Console và file
		doConsoleOutput(rootArr, numberOfUnknowns, situation);
		doFileOutput(rootArr, numberOfUnknowns, situation);
		end_session:;
	
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