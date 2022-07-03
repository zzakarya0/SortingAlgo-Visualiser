#include <vector>
#include "rectangle.hpp"


void bubbleSort(std::vector<Rectangle::RectanglePtr>& arr) {
	for (size_t i = 0; i < arr.size() - 1; ++i) {
		for (size_t j = 0; j < arr.size() - 1 - i; ++j)
			if (arr[j]->getHeight() > arr[j + 1]->getHeight()) swap(arr[j], arr[j + 1]);
		//std::cout << arr << std::endl;
	}

}
