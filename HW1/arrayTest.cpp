// arrayTestHW1.cpp
// Ryan Beggs, CISP 430
// 2/10/2019

#include <iostream>
#include <chrono>

using namespace std;

void greeting();

int main() {

	greeting();

  int *myArray = new int[1] {1};
  int runs = 100000;
  int count = 1;

  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; i < runs; i++) {

    int *tempArray = new int[count + 1];

    cout << "Current array: " << i + 1 << "\r";
  
    for (int j = 0; j < count; j++) {
      tempArray[j] = myArray[j];
    }

    tempArray[count] = 1;

    delete[] myArray;

    myArray = tempArray;

    count++;

  }

  auto end = chrono::high_resolution_clock::now();

  double elapsedTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  cout << "It took " << elapsedTime / 1000000000 << " seconds" << " to process " << runs << " elements" << endl;  

  return 0;
}

void greeting(){

	cout << "blah" << endl;

}

