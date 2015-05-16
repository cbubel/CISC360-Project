all:
	g++-4.7 -std=c++11 NearestNeighborResizeOptimized.cpp -o optimized
	g++-4.7 -std=c++11 NearestNeighborResizeOptimized.cpp -o optimized.exe

clean:
	rm -rf *o optimized.exe optimized
