#pragma once

#include <string>

typedef unsigned char byte;

using namespace std;

class Image {
public:
	Image() : w(0), h(0), xPos(0), yPos(0), dx(0), dy(0), pixels(0){}
	~Image() { delete [] pixels; }
	void update(double dt);
	void draw() const;
	void load(const char * filename, int w, int h);
	void setX(double x) { xPos = x; }
	void setY(double y) { yPos = y; }
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
