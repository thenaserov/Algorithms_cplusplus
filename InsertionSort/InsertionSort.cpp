#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename RandAccessContainer>
RandAccessContainer &InsertionSort(RandAccessContainer &input_vector)
{
	int key{};
	for (size_t j = 2; j < input_vector.size(); ++j)
	{
		// operator[] does not do range checking. Accessing element not presenting in vector silently leads to undefined behavior.
		// at() member function does range checking and throws an exception when you are trying to access nonexisting element
		key = input_vector.at(j);
		// I changed the location of i declaration and its type, so as j, to eliminate not-safe conversions between i and j
		// to signed types
		static size_t i{}; // I made i static of this for loop in order to prevent declaring it over and over again in each iteration, so preserving its value
		i = j - 1;
		while (i > 0 && input_vector.at(i) > key)
		{
			input_vector.at(i + 1) = input_vector.at(i);
			i = i - 1;
		}
		input_vector[i + 1] = key;
	}
	return input_vector;
}

int main()
{
	std::vector<int> unsorted = {1, 9, 8, 2, 3, 5, 7, 6, 4};
	auto sorted = InsertionSort<>(unsorted);

	// for(std::vector<int>::iterator iter = sorted.begin();iter < sorted.end(); iter ++) {
	// 	std::cout << *iter << std::endl;
	// }

	// The repo name addresses algorithm, I thought it would be nice if we made use of algorithms as much as possible
	// inorder to make it independent of the type on which unsorted and sorted has been intialized I used decltype,
	// although it is not that much neat!
	std::copy(std::begin(sorted), std::end(sorted), std::ostream_iterator<decltype(*sorted.begin())>{std::cout, ", "});
	std::cout << std::endl;
	return 0;
}
