all:
	g++ -std=c++11 NearestNeighborResizeOptimized.cpp -o optimized
	g++ -std=c++11 NearestNeighborResizeOptimized.cpp -o optimized.exe

clean:
	git clean -f
