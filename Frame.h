#pragma once

#include "Image.h"
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cstring>
#include <vector>

typedef unsigned char byte;

class Frame {
public:
	Frame(int w, int h);
	~Frame() { delete [] pixels; }
	void clear();
	void setPixel(int x, int y, byte r, byte g, byte b);
	bool outside_frame(int x, int y);
	void write(FILE * file);

private:
	int h;
	int w;

	byte * pixels;
};

