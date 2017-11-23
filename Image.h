#pragma once

#include "Object.h"
#include <string>

typedef unsigned char byte;

using namespace std;

class Image : public Object {
public:
	Image() : w(0), h(0), xPos(0), yPos(0), dx(0), dy(0), pixels(nullptr){}
	~Image() { delete [] pixels;}

	virtual void update(double dt);
	virtual void draw() const;
	void load(const char * filename, int w, int h);
	virtual void setX(double newX);
	virtual void setY(double newY);
	void setVelocity(double dx, double dy);
	
private:
	byte * pixels;

	int w;
	int h;
	double dx;
	double dy;
	double xPos;
	double yPos;
};
