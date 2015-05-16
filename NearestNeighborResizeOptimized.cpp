/*
 * NearestNeigborResize.cpp
 *
 *  Created on: May 5, 2015
 *      Author: Matthew
 */

#include "NearestNeighborResizeOptimized.h"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <sys/time.h>

using namespace std;

NearestNeigborResize::NearestNeigborResize() {
	// TODO Auto-generated constructor stub

}

NearestNeigborResize::~NearestNeigborResize() {
	// TODO Auto-generated destructor stub
}

struct pixel {
	int r, g, b, a;
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

	pixel * temp = new pixel[w2 * h2];
	double x_ratio = w1/(double)w2;
	double y_ratio = h1/(double)h2;
	double px, py;
	for (int i=0;i<h2;i++) {
	        for (int j=0;j<w2;j++) {
	    		px = floor(j*x_ratio);
	    		py = floor(i*y_ratio);
	    		temp[(i*w2)+j] = pixels[(int)((py*w1)+px)];
		}
	}

	t = clock() - t;
	cout << t << endl;

	return temp;
}

int main() {
	int size = 10000;
	pixel * data = new pixel[size];
	for(int i = 0; i < size; i++) {
		pixel * p = new pixel();
		data[i] = *p;
	}
	//clock_t t;
	//t = clock();
	resizePixels(data, 100, 100, 601, 407);
	//t = clock() - t;
	//cout << t << endl;
	return 0;
}
