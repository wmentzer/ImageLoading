#include "Rectangle.h"
#include "Frame.h"

typedef unsigned char byte;

extern Frame frame;

void Rectangle::setX(double newX) {
	xPos = newX;
}

void Rectangle::setY(double newY) {
	yPos = newY;
}

void Rectangle::update(double dt) {
	xPos = xPos + dt * dx;
	yPos = yPos + dt * dy;

}

void Rectangle::setVelocity(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}

void Rectangle::draw() const {
	for(int i = 0; i < w; ++i) {
		for(int j = 0; j < h; ++j) {
			frame.setPixel(xPos + 0.5 + i, yPos + 0.5 + j, r, g, b);
		}
	}

}

void Rectangle::setColor(byte red, byte green, byte blue) {
	r = red;
	g = green;
	b = blue;
}
