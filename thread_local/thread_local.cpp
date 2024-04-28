#include <thread>

thread_local int a = 1;

int func() {
	thread_local int b = 2;
	return b;
}

int main() {
	std::thread t1(func);
	std::thread t2(func);
	
	t1.join();
	t2.join();
	
    return 0;
}


