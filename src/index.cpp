#include <iostream>
#include <string>
#include "input_output.cpp"
#include "methods.cpp"
#include "format.cpp"

using namespace std;

int numberOfUnknowns = 0;	
double factorArr[ARR_SIZE][ARR_SIZE]; // Array of coefficients
double rootArr[ARR_SIZE]; // Array of roots
int situation; // 3 situations of root

string selection = "0";
int inputSuccess = 1;

/******************************************************/


int main() {
  setUnicode();
  setColor(0, 15);
  clrscr();

  welcomeScreen();
  pause();
  
  clrscr();

	while(selection != "3") { 
		
    inputSuccess = 1;

    for(int i = 0; i < 200; i++) {
			rootArr[i] = 0;
		}	

		selectMethodMenu(&selection);

		if(selection == "3") return 0;
		
		// Method is chosen.
		// Input contains of numberOfUnknowns and coefficients
    // If input by file return inputSuccess = 0 khi when failing to open file 
		inputMenu(factorArr, &numberOfUnknowns, &inputSuccess);

    // If faling to open file, end session
    if(!inputSuccess) {
      setColor(0,4);
      cout << "Không thể mở file!" << endl;
      setColor(0,15);
      goto end_session;
    }
    
    clrscr();
    cout << "Dữ liệu đã nhập là hệ phương trình:  " << endl;
    printProblem(factorArr, numberOfUnknowns);
		
		
    // Find roots with chosen method
    // Store roots in rootArr
		if(selection == "1") {
			doGaussJordanMethod(factorArr, numberOfUnknowns, rootArr);
		}
		if(selection == "2") {
			doCramerMethod(factorArr, numberOfUnknowns, rootArr);
		}

    // situation variable: 2 means normal roots, 1 means infinte roots, 0 means no root
    // checkRoot function to check the situation of roots
    situation = checkRoot(rootArr, numberOfUnknowns);
    	
		// After finishing solving the problem, output to console and file
		doConsoleOutput(rootArr, numberOfUnknowns, situation);
		doFileOutput(rootArr, numberOfUnknowns, situation);
		
    end_session:;
		pause();
	}

	return 0;
}


/******************************************************/

