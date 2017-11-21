#include "Image.h"
#include "Frame.h"
#include <cstring>
#include <sstream>
#include <iostream>
#include <stdio.h>

extern Frame frame;

void Image::load(const char * filename, int w, int h) {
	this->w = w;
	this->h = h;
	pixels = new byte[w * h * 3];

	std::stringstream ss;

	ss << "ffmpeg -i " << filename <<
	" -f rawvideo -pix_fmt rgb24 " <<
	"-vf scale=" << w << ":" << h <<
	" - ";

	FILE * pipe = popen(ss.str().c_str(), "r");

	fread(pixels, 3, w * h, pipe);
	fclose(pipe);
}

void Image::draw() const {
	for(int i = 0; i < w; ++i) {
		for(int j = 0; j < h; ++j) {
			byte r = pixels[j * w * 3 + i * 3 + 0];
			byte g = pixels[j * w * 3 + i * 3 + 1];
			byte b = pixels[j * w * 3 + i * 3 + 2];
			frame.setPixel(xPos + 0.5 + i, yPos + 0.5 + j, r, g, b);
		}
	}
}

void Image::setVelocity(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}

void Image::update(double dt) {
	xPos = xPos + dt * dx;
	yPos = yPos + dt * dy;
}
