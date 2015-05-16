/*
 * NearestNeigborResize.h
 *
 *  Created on: May 5, 2015
 *      Author: Matthew
 */

#ifndef NEARESTNEIGBORRESIZE_H_
#define NEARESTNEIGBORRESIZE_H_

class NearestNeigborResize {
public:
	NearestNeigborResize();
	virtual ~NearestNeigborResize();
	int* resizePixels(int * pixels, int w1, int h1, int w2, int h2);
};

#endif /* NEARESTNEIGBORRESIZE_H_ */
