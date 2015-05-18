/*
 * NearestNeigborResize.cpp
 *
 *  Created on: May 5, 2015
 *      Author: Matthew
 */

#include "NearestNeighborResizeOptimized.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <sys/time.h>
#include <fstream>

using namespace std;

NearestNeighborResizeOptimized::NearestNeighborResizeOptimized() {
	// TODO Auto-generated constructor stub

}

NearestNeighborResizeOptimized::~NearestNeighborResizeOptimized() {
	// TODO Auto-generated destructor stub
}

struct pixel {
	unsigned char r, g, b, a;
	pixel() {
		r = 0, g = 0, b = 0, a = 0;
	}
};

/*
* pixels = array
* w1 = original width
* h1 = original height
* w2 = new width
* h2 = new height
*/
pixel * resizePixels(pixel * pixels, int w1, int h1, int w2, int h2) {
	clock_t t;
	t = clock();

	#define R_STRIDE 32
	#define C_STRIDE 32

	pixel * temp = new pixel[w2 * h2];
	double x_ratio = w1/(double)w2;
	double y_ratio = h1/(double)h2;
	double px, py;
	for (int R=0;R<h2;R+=R_STRIDE) {
	        for (int C=0;C<w2;C+=C_STRIDE) {
				for(int r=R; r<std::min(R+R_STRIDE, h2); r++) {
					for(int c=C; c<std::min(C+C_STRIDE, w2); c++) {
			    		px = floor(c*x_ratio);
			    		py = floor(r*y_ratio);
			    		temp[(r*w2)+c] = pixels[(int)((py*w1)+px)];
					}
				}
		}
	}

	t = clock() - t;
	cout << t << endl;

	return temp;
}

int main(int ac, char** av) {
	srand(atoi(av[1]));
	int oldWidth = atoi(av[2]);
	int oldHeight = atoi(av[3]);
	int newWidth = atoi(av[4]);
	int newHeight = atoi(av[5]);
	
	pixel * data = new pixel[oldWidth * oldHeight];
	for(int i = 0; i < oldWidth * oldHeight; i++) {
		pixel p;
		p.r = rand() % 256;
		p.g = rand() % 256;
		p.b = rand() % 256;
		p.a = rand() % 256;
		data[i] = p;
	}
	
	pixel * results = resizePixels(data, oldWidth, oldHeight, newWidth, newHeight);
	
	ofstream myfile;
	myfile.open ("results.txt", std::ofstream::binary);
	for(int i = 0; i < newWidth * newHeight; i++) {
		myfile << results[i].r << results[i].g << results[i].b << results[i].a;
		//myfile << i;
		//myfile << results->r;
		//myfile << results->g;
		//myfile << results->b;
		//myfile << results->a;
		//myfile << "\n";
	}
	myfile.close();
	delete[] data;
	delete[] results;
	return 0;
}
