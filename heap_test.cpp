#include "heap.h"
#include <iostream>

struct maxheapcomp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {

	Heap<int, maxheapcomp> max_heap(3);

	max_heap.push(10);
	max_heap.push(5);
	max_heap.push(20);
	max_heap.push(1);

	std::cout << "Top: " << max_heap.top() << std::endl;

	max_heap.pop();
	std::cout << "New top: " << max_heap.top() << std::endl;

	return 0;
}