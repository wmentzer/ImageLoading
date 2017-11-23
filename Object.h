#pragma once

class Object {
public:
	virtual void draw() const = 0;
	virtual void update(double dt) = 0;
	virtual void setX(double newX) = 0;
	virtual void setY(double newY) = 0;

private:
	double yPos;
	double xPos;
};
