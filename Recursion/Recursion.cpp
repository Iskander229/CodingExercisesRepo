#include <iostream>


void myLoop(int i) {              //simple recursive loop (1-15)
	std::cout << i << std::endl;
	if (i < 15) {
		myLoop(i + 1);
	}
}

void myBackLoop(int i) {          //reversed recursive loop (15-1)
	if (i < 15) {
		myBackLoop(i + 1);
	}
	std::cout << i << std::endl;
}


int main() {
	int input;
	std::cout << "simle or backwards? 1/2" << std::endl;
	std::cin >> input;
	
	if (input == 1) {
		myLoop(1);
	}
	else if (input == 2) {
		myBackLoop(1);
	}
}