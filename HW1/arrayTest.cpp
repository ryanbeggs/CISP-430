// arrayTestHW1.cpp
// Ryan Beggs, CISP 430
// 2/10/2019

#include <iostream>
#include <chrono>

using namespace std;

//Function Prototype
void greeting();

int main() {

	greeting();

  int *myArray = nullptr;       // initialize pointer to null
  int size = 1;                 // array size
  myArray = new int[size] {1};  // build new array on the heap, initialize to 1
  int runs = 10000;             // size of final array

  auto start = chrono::high_resolution_clock::now();  // start time

  for (int i = 0; i < runs; i++) {

    int *tempArray = nullptr;                         // initialize pointer to null
    tempArray = new int[size + 1];                    // build new array on the heap

    cout << "Current array: " << i + 1 << "\r";       // display progress
  
    for (int j = 0; j < size; j++) {                  // copy original array to temp array
      tempArray[j] = myArray[j];
    }

    tempArray[size] = 1;                              // add int to new temp array
    delete[] myArray;                                 // free memory
    myArray = tempArray;                              // swap pointers
    tempArray = nullptr;                              // null tempArray
    size++;                                           // increment size
  }

  auto end = chrono::high_resolution_clock::now();    // end time

  // calculate elapsed time in nanoseconds
  double elapsedTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  // display elapsed time in seconds
  cout << "It took " << elapsedTime / 1000000000 << " seconds to process " << runs << " elements" << endl;  

  return 0;
}

//Program Greeting
void greeting(){

  cout << "**************************************************" << endl;
	cout << "* This program calculates how long it takes to   *" << endl;
  cout << "* repeatedly resize an array and add one element *" << endl;
  cout << "* to the end of the array each time              *" << endl;
  cout << "**************************************************" << endl;
}

/* Results
Average of 3 runs without -O3 optimization

     1,000 - 0.007219 Seconds
    10,000 - 0.132090 Seconds
   100,000 - 15.03343 Seconds
 1,000,000 - 1693.866 Seconds
10,000,000 - Too long, unable to complete

Average of 3 runs with -O3 optimization 

     1,000 - 0.006465 Seconds
    10,000 - 0.068023 Seconds
   100,000 - 9.205700 Seconds
 1,000,000 - 1152.800 Seconds
10,000,000 - Too long, unable to complete
*/