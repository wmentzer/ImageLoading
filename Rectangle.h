#pragma once

#include "Object.h"

using namespace std;

typedef unsigned char byte;

class Rectangle : public Object {
public:
	Rectangle(int height, int width) : h(height), w(width){}
	~Rectangle() {}

	virtual void setX(double newX);
	virtual void setY(double newY);
	virtual void draw() const;
	virtual void update(double dt);
	void setVelocity(double dx, double dy);
	void setColor(byte red, byte green, byte blue);

private:
	int h, w;
	byte r;
	byte g;
	byte b;
	double dx, dy;
	int xPos, yPos;
};
