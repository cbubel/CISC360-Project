all:
	g++ -std=c++11 -O2 NearestNeighborResizeOptimized.cpp -o optimized
	g++ -std=c++11 -O2 NearestNeighborResizeOptimized.cpp -o optimized.exe

clean:
	git clean -f
