#include <iostream>
#include <vector>

std::vector<int> InsertionSort(std::vector<int> input_vector) { 
	int key = 0, i = 0;
	for(int j = 2; j < input_vector.size(); ++j) {
		key = input_vector[j];
		i = j - 1;
		while (i > 0 && input_vector[i] > key) {
			input_vector[i + 1] = input_vector[i];
			i = i -1;
		}
		input_vector[i + 1] = key;
	}
	return input_vector;
}

int main() {
	std::vector<int> unsorted = {1, 9, 8, 2, 3, 5, 7, 6, 4};
	std::vector<int> sorted   = InsertionSort(unsorted);
	for(std::vector<int>::iterator iter = sorted.begin();iter < sorted.end(); iter ++) { 
		std::cout << *iter << std::endl;
	}
	return 0;
}
