#ifndef SORTING_H
#define SORTING_H

#include "rectangle.hpp"
#include <vector>

namespace sorting {
	// update our display window
	void updateImage(sf::Image& image, sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite);
	// animate swaping two elements
	void animateSwap(Rectangle::RectanglePtr& lhs, Rectangle::RectanglePtr& rhs, sf::Image& image);

	// time: O(n^2), space: O(1) => BUBBLE each element to its correct position (from largest to smallest).
	void bubbleSort(std::vector<Rectangle::RectanglePtr>& arr, sf::Image& image, sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite);
	// time: O(n^2), space: O(1) => SELECT min element in sub-array and move it to the front
	void selectionSort(std::vector<Rectangle::RectanglePtr>& arr, sf::Image& image, sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite);
	// time: O(n^2), space: O(1) => INSERT each element in its correct position (from smallest to largest)
	void insertionSort(std::vector<Rectangle::RectanglePtr>& arr, sf::Image& image, sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite);
}

#endif