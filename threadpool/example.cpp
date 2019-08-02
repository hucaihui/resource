#include <iostream>
#include <vector>
#include <chrono>

#include "ThreadPool.h"

int usefunction1(int a) {
	return a;
}

void baseUse1()
{
	// create thread pool with 4 worker threads
	ThreadPool pool(4);

	// enqueue and store future
	auto result = pool.enqueue([](int answer) { return answer; }, 42);
	auto result1 = pool.enqueue(usefunction1,222);
	// get result from future
	std::cout << result.get() << std::endl;
	std::cout << result1.get() << std::endl;
}

void baseUse2() {
	ThreadPool pool(4);
	std::vector< std::future<int> > results;

	for (int i = 0; i < 8; ++i) {
		results.emplace_back(
			pool.enqueue([i] {
			std::cout << "hello " << i << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "world " << i << std::endl;
			return i*i;
		})
		);
	}

	for (auto && result : results)
		std::cout << result.get() << ' ';
	std::cout << std::endl;
}

int main()
{
	baseUse1();
	baseUse2();
    
  
	system("pause");
	return 0;
}