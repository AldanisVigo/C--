/*
	Concurrent Programming Models
	
	1. Multiprocessing - Each process has only one thread running and 
	all processes communicate through files, pipes, message queues.
	
	2. Multithreading - One process contains two or more threads, and all 
	threads communicate using shared memory.

*/
//Multithreading provides better performance that multiprocessing.
//Multithreading is more difficult to program

#include <iostream>
#include <thread>
using namespace std;

void function_1(){
	std::cout << "Beauty is only skin deep" << std::endl;
}
int main(){
	std::thread t1(function_1); //t1 starts running
	//t1.join();	//main thread waits for t1 to finish
	t1.detach(); //t1 will run freely on it's own, independent of main - daemon process
	
	//Checking if thread is joinable
	if(t1.joinable())
		t1.join();
	return 0;
}
