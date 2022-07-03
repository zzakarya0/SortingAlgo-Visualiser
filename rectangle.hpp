#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <memory>

struct Rectangle {
private:
	int m_width;
	int m_height;
	int m_xPos, m_yPos;
	sf::Color m_color;

public:
	typedef std::shared_ptr<Rectangle> RectanglePtr;
	Rectangle(int xPos, int height, int yBound);
	int getWidth() const;
	int getHeight() const;
	int getXPos() const;
	int getYPos() const;
	const sf::Color& getColor() const;

	void setHeight(int height);
	void setYPos(int yPos);
	friend void swap(RectanglePtr& lhs, RectanglePtr& rhs);
};


#endif
