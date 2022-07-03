#include <iostream>
#include <random>
#include "rectangle.hpp"
#include "sorting.hpp"
#define DEBUG 0

void createRectangles(std::vector<Rectangle::RectanglePtr>& vec, const sf::Image& image) {
	//FIXME: random number generation, use imt31 or smth 
	std::random_device rd;
	std::uniform_int_distribution<int> height(5, image.getSize().y - 50);
	int xOffset = 0;


	auto makeRectangle = [&]() {
		return std::make_unique<Rectangle>(xOffset, height(rd), image.getSize().y);
	};

	while (xOffset < image.getSize().x) {
		vec.push_back(makeRectangle());
		xOffset += 4;
	}
}

void displayRectangles(std::vector<Rectangle::RectanglePtr>& vec, sf::Image& image) {
	for (Rectangle::RectanglePtr& rectPtr : vec)
		for (size_t x = 0; x < rectPtr->getWidth(); ++x)
			for (size_t y = 0; y < rectPtr->getHeight(); ++y)
				image.setPixel(rectPtr->getXPos() + x, rectPtr->getYPos() + y, rectPtr->getColor());
}

int main() {
	int windowWidth = 1000;
	int windowHeight = 800;

	// create display window and window event
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorting Visualizer");
	sf::Event event;

	//create image to display on and set it's size to the window's size
	sf::Image image;
	image.create(windowWidth, windowHeight);

	// no idea 
	sf::Texture texture;
	texture.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	std::vector<Rectangle::RectanglePtr> vec;
	createRectangles(vec, image);
	displayRectangles(vec, image);
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	bool spacePressed = false;
	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			// close window if pressed close button
			if (event.type == sf::Event::Closed) window.close();
			// check if space bar was pressed and released
			if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::Space) spacePressed = true;
		}

		//display every frame
		//clear window then draw sprite then display it
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		window.clear();

		if (spacePressed) {
			//clearImage(image, windowWidth, windowHeight);
			sorting::insertionSort(vec, image, window, texture, sprite);

#if DEBUG
			for (auto rec : v)
				std::cout << rec->getHeight() << std::endl;
#endif // DEBUG


			//displayRectangles(vec, image);
			spacePressed = false;
		}
		window.draw(sprite);
		window.display();
	}

	return 0;
}