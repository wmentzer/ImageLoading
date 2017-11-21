#include <iostream>
#include <cstdint>
#include "Frame.h"
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cstring>
#include <vector>

typedef unsigned char byte;

using namespace std;

void Frame::clear() {
	memset(pixels, 0, h * w * 3);
}

Frame::Frame(int w, int h)  { 
	this->w = w;
	this->h = h;
	pixels = new byte[w * h * 3]; 
}

void Frame::setPixel(int x, int y, byte r, byte g, byte b) {
	if(outside_frame(x,y)) { return; }	
	pixels[y * w * 3 + x * 3 + 0] = r;
	pixels[y * w * 3 + x * 3 + 1] = g;
	pixels[y * w * 3 + x * 3 + 2] = b;
}

bool Frame::outside_frame(int x, int y) {
	return x < 0 || x >= w || y < 0 || y >= h;
}

void Frame::write(FILE * file) {
	fwrite(pixels, 3, w * h, file);
}

