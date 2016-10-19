#include <iostream>



int main() {
	int n = 0;
	double sum = 0;
	double hjelper;
	std::cout << "hello, vi skal vi regne gjennomsnitt av noen tall? skriv inn; ";
	
	while (std::cin >> hjelper) {
		if (hjelper < 0) {
			std::cout << "under 0" << std::endl;
			break;
		}
		sum = sum + hjelper;
		n++;

		hjelper = sum / n;
		std::cout << hjelper << std::endl;
		std::cout << std::endl;

	}
	
}

 
