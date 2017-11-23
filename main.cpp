#include <iostream>
#include "Image.h"
#include "Rectangle.h"
#include "Object.h"
#include "Frame.h"
#include <stdio.h>
#include <fstream>

using namespace std;

typedef unsigned char byte;

const double frames_per_second = 30;
const int duration_in_seconds = 4;

Frame frame(720,480);

int main(int argc, char * argv[]) {

	const char * cmd =
	"ffmpeg              "
	"-y                  "
	"-hide_banner        "
	"-f rawvideo         " // input to be raw video data
	"-pixel_format rgb24 "
	"-video_size 720x480 "
	"-r 60               " // frames per second
	"-i -                " // read data from the standard input stream
	"-pix_fmt yuv420p    " // to render with Quicktime
	"-vcodec mpeg4       "
	"-an                 " // no audio
	"-q:v 5              " // quality level; 1 <= q <= 32
	"output.mp4          ";


	FILE * pipe = popen(cmd, "w");
	if (pipe == 0) {
		cout << "error: " << strerror(errno) << endl;
		return 1;
	}

	Rectangle rec(10, 20);
	Image image1;
	Image image2;
	rec.setX(0.0);
	rec.setY(300.0);
	image2.setX(300.0);
	image2.setY(150.0);
	rec.setVelocity(100, -100);
	image1.setVelocity(100, 100);
	image2.setVelocity(0,-100);
	rec.setColor(0xFF, 0x00, 0x00);
	image2.load("duck.bmp", 150, 150);
	image1.load("newBaseball.bmp", 100, 100);

	// Write video frames into the pipe.
	int num_frames = duration_in_seconds * frames_per_second;
	for (int i = 0; i < num_frames; ++i) {
		double dt = 1.0 / frames_per_second;
		frame.clear();
		rec.draw();
		image1.draw();
		image2.draw();
		rec.update(dt);
		image1.update(dt);
		image2.update(dt);
	
		frame.write(pipe);
	}

	fflush(pipe);
	pclose(pipe);

	cout << "num_frames: " << num_frames << endl;
	cout << "Done." << endl;

	return 0;
}
