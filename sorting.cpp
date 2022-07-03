#include "sorting.hpp"
#include  <iostream>

namespace sorting {
	void resetColor(Rectangle::RectanglePtr& ptr1, Rectangle::RectanglePtr& ptr2, sf::Image& image) {
		for (int x = 0; x < ptr1->getWidth(); x++)
			for (int y = 0; y < ptr1->getHeight(); y++)
				image.setPixel(ptr1->getXPos() + x, ptr1->getYPos() + y, sf::Color::White);

		for (int x = 0; x < ptr2->getWidth(); x++)
			for (int y = 0; y < ptr2->getHeight(); y++)
				image.setPixel(ptr2->getXPos() + x, ptr2->getYPos() + y, sf::Color::White);
	}

	void updateMin(Rectangle::RectanglePtr& newMin, Rectangle::RectanglePtr& oldMin ,sf::Image& image) {
		for (size_t x = 0; x < newMin->getWidth(); ++x)
			for (size_t y = 0; y < newMin->getHeight(); ++y)
				image.setPixel(newMin->getXPos() + x, newMin->getYPos() + y, sf::Color::Blue);
		
		for (size_t x = 0; x < oldMin->getWidth(); ++x)
			for (size_t y = 0; y < oldMin->getHeight(); ++y)
				image.setPixel(oldMin->getXPos() + x, oldMin->getYPos() + y, sf::Color::White);		
	}

	void updateImage(sf::Image& image, sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite) {
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		window.draw(sprite);
		window.display();
	}

	void animateSwap(Rectangle::RectanglePtr& lhs, Rectangle::RectanglePtr& rhs, sf::Image& image) {
		for (int x = 0; x < lhs->getWidth(); x++)
			for (int y = 0; y < lhs->getHeight(); y++)
				image.setPixel(rhs->getXPos() + x, lhs->getYPos() + y, sf::Color::Red);

		for (int x = 0; x < lhs->getWidth(); x++)
			for (int y = 0; y < lhs->getHeight(); y++)
				image.setPixel(lhs->getXPos() + x, lhs->getYPos() + y, sf::Color::Black);

		for (int x = 0; x < rhs->getWidth(); x++)
			for (int y = 0; y < rhs->getHeight(); y++)
				image.setPixel(lhs->getXPos() + x, rhs->getYPos() + y, sf::Color::Red);
	}

	void bubbleSort(std::vector<Rectangle::RectanglePtr>& arr, sf::Image& image, sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite) {
		for (size_t i = 0; i < arr.size() - 1; ++i) {
			bool performedSwap = false;
			for (size_t j = 0; j < arr.size() - 1 - i; ++j)
				if (arr[j]->getHeight() > arr[j + 1]->getHeight()) {
					performedSwap = true;
					window.clear();

					animateSwap(arr[j], arr[j + 1], image);
					swap(arr[j], arr[j + 1]);
					updateImage(image, window, texture, sprite);

					resetColor(arr[j], arr[j + 1], image);
					updateImage(image, window, texture, sprite);
				}
			if (!performedSwap) return;
		}
	}

	void selectionSort(std::vector<Rectangle::RectanglePtr>& arr, sf::Image& image, sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite) {
		Rectangle::RectanglePtr curMin(nullptr);

		for (size_t i = 0; i < arr.size() - 1; ++i) {
			curMin = arr[i];

			for (size_t x = 0; x < curMin->getWidth(); ++x)
				for (size_t y = 0; y < curMin->getHeight(); ++y)
					image.setPixel(curMin->getXPos() + x, curMin->getYPos() + y, sf::Color::Green);

			for (size_t j = i + 1; j < arr.size(); ++j) {
				if (arr[j]->getHeight() < curMin->getHeight()) {
					window.clear();

					if (curMin != arr[i]) updateMin(arr[j], curMin, image);
					curMin = arr[j];
					updateImage(image, window, texture, sprite);
				}
			}

			animateSwap(arr[i], curMin, image);
			swap(arr[i], curMin);
			updateImage(image, window, texture, sprite);

			resetColor(arr[i], curMin, image);
			updateImage(image, window, texture, sprite);
		}
	}

	void insertionSort(std::vector<Rectangle::RectanglePtr>& arr, sf::Image& image, sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite) {
		for (size_t i = 1; i < arr.size(); ++i)
			for (size_t j = i; j > 0; --j) {
				if (arr[j - 1]->getHeight() > arr[j]->getHeight()) {
					window.clear();

					animateSwap(arr[j - 1], arr[j], image);
					swap(arr[j - 1], arr[j]);
					updateImage(image, window, texture, sprite);

					resetColor(arr[j - 1], arr[j], image);
					updateImage(image, window, texture, sprite);
				}
				else break;
			}
	}
}