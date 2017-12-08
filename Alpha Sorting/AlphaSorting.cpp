#include <iostream>
#include <string>
#include <random>

int swap = 0;


void swapItem(std::string  &firstItem, std::string  &secondItem) {

	std::string  temp = firstItem;
	firstItem = secondItem;
	secondItem = temp;

}

void sortString(std::string string[], int sizeOfString) {
	for (int i = 1; i < sizeOfString; i++) {
		int j = i;
		while (j > 0 && string[j - 1][0] >= string[j][0]) {
			swapItem(string[j], string[j - 1]);
			for (int k = 0; k < string[j - 1].length(); k++) {
				if (string[j - 1][k] > string[j][k]) {
					swapItem(string[j], string[j - 1]);
					break;
				}
				else if (string[j - 1][k] != string[j][k]) {
					break;
				}
			}
			j--;
		}
	}
}

int main() {
	const int arraySize = 50;
	std::random_device rando;
	std::string test[] = { " ","A","B" };
	std::string strings[arraySize];
	for (int i = 0; i < arraySize; i++) {
		std::string namerandom;
		for (int i = 0; i < 7; i++) {
			namerandom += test[rando() % 3];
		}
		strings[i] += namerandom;
	}

	sortString(strings, arraySize);
	for (int i = 0; i < arraySize; i++) {
		std::cout << strings[i] << std::endl;
	}
	std::cout << "Swap: " << swap << std::endl;
	return 0;
}