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
#include <fstream>

using namespace std;

NearestNeighborResizeOptimized::NearestNeighborResizeOptimized() {
	// TODO Auto-generated constructor stub

}

NearestNeighborResizeOptimized::~NearestNeighborResizeOptimized() {
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


	const int R_STRIDE = 32;
	const int C_STRIDE = 32;

	pixel * temp = new pixel[w2 * h2];
	double x_ratio = w1/(double)w2;
	double y_ratio = h1/(double)h2;
	double px, py;
	for (int R=0;R<h2;R+=R_STRIDE) {
	        for (int C=0;C<w2;C+=C_STRIDE) {
				for(int r=R; r<(R+R_STRIDE); r++) {
					for(int c=C; c<(C+C_STRIDE); c++) {
			    		px = floor(c*x_ratio);
			    		py = floor(r*y_ratio);
			    		temp[(r*C_STRIDE)+c] = pixels[(int)((py*w1)+px)];
					}
				}
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
	
	pixel * results = resizePixels(data, 100, 100, 6000, 6000);
	
	ofstream myfile;
	myfile.open ("results.txt");
	for(int i = 0; i < 36000000; i++) {
		myfile << "pixel " << i << " R: " << results->r << " G: " << results->g << " B: " << results->b << " A: " << results->a << "\n";
		//myfile << i;
		//myfile << results->r;
		//myfile << results->g;
		//myfile << results->b;
		//myfile << results->a;
		//myfile << "\n";
	}
	myfile.close();
	return 0;
}
