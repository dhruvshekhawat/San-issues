/*There should not be a race condition in this case as data is just being read. With gcc thread sanitizer detects a false race condition
but with clang it works fine.*/
#include <thread>
#include <iostream>
#include <string>

std::string func()
{
	static std::string msg("Inside func");
	return msg;
}

int main()
{
	std::thread t1([]() { std::cout << func() << "\n"; });
	std::thread t2([]() { std::cout << func() << "\n"; });

	t1.join();
	t2.join();
}
