/*
 * NearestNeigborResize.h
 *
 *  Created on: May 5, 2015
 *      Author: Matthew
 */

#ifndef NEARESTNEIHGBORRESIZEOPTIMIZED_H_
#define NEARESTNEIHGBORRESIZEOPTIMIZED_H_

class NearestNeighborResizeOptimized {
public:
	NearestNeighborResizeOptimized();
	virtual ~NearestNeighborResizeOptimized();
	int* resizePixels(int * pixels, int w1, int h1, int w2, int h2);
};

#endif /* NEARESTNEIGHBORRESIZEOPTIMIZED_H_ */
