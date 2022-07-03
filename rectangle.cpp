#include "rectangle.hpp"

Rectangle::Rectangle(int xPos, int height, int yBound)
	: m_width(3), m_height(height), m_xPos(xPos), m_yPos(yBound - height), m_color(sf::Color::White) {}

int Rectangle::getWidth() const { return m_width; }

int Rectangle::getHeight() const { return m_height; }

int Rectangle::getXPos() const { return m_xPos; }

int Rectangle::getYPos() const { return m_yPos; }

const sf::Color& Rectangle::getColor() const { return m_color; }

void Rectangle::setHeight(int height) { m_height = height; }

void Rectangle::setYPos(int yPos) { m_yPos = yPos; }

void swap(Rectangle::RectanglePtr& lhs, Rectangle::RectanglePtr& rhs) {
	int tempHeight = lhs->getHeight();
	lhs->setHeight(rhs->getHeight());
	rhs->setHeight(tempHeight);

	int tempY = lhs->getYPos();
	lhs->setYPos(rhs->getYPos());
	rhs->setYPos(tempY);
}
