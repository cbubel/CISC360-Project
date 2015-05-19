all:
	g++-4.7 -std=c++11 NearestNeighborResizeOptimized.cpp -o optimized
#	g++-4.7 -std=c++11 -O2 NearestNeighborResizeOptimized.cpp -o optimized.exe

clean:
	git clean -f
