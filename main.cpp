#include <iostream>
#include <thread>
#include <chrono>
#include <limits.h>

void countFunc(int* ptrToInt, size_t times) {  	
   /*
    The thread t1 increments an integer n times
   */ 
   while(times > 0) {
   	*ptrToInt += 1;
    	times-- ;
   } 
}

int main() { 
   using namespace std::literals::chrono_literals;

   // Patameter n is tunable
   long long int n = 600000000;

   // number will be incremented from countFunc on thread t1
   int* number = new int();
   *number = 0;

   auto start = std::chrono::high_resolution_clock::now();
  
   std::thread t1(countFunc, number, n);

   // Seconds are tunable
   std::this_thread::sleep_for(1s);
   
   // Concurrency
   t1.join();
  
   auto end = std::chrono::high_resolution_clock::now();

   // Calculate time
   std::chrono::duration<float> duration = end - start;
   std::cout << duration.count() << "s " << std::endl;
   std::cout << "TM main counted " << *number; 
	std::cout << " times in " << duration.count() << " second\n";

   delete[] number;

	return 0;
}










