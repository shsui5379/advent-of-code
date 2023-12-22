#include <cassert>
#include <iostream>

int countIncreases(int data[], int length);
int *slidingWindowSums(int data[], int length);

int main() {
  int sample[] = {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};
  assert(countIncreases(sample, 10) == 7);

  int *slidingSample = slidingWindowSums(sample, 10);
  int sampleSlideSolution[] = {607, 618, 618, 617, 647, 716, 769, 792};

  for (int i = 0; i < 8; i++) {
    assert(sampleSlideSolution[i] == slidingSample[i]);
  }

  assert(countIncreases(slidingSample, 8) == 5);

  delete[] slidingSample;

  //--------------------------------------------------------------------------------

  int data[] = {};

  int dataLength = sizeof(data) / sizeof(data[0]);

  std::cout << countIncreases(data, dataLength) << std::endl;

  int *slidingData = slidingWindowSums(data, dataLength);

  std::cout << countIncreases(slidingData, dataLength - 2) << std::endl;

  delete[] slidingData;

  return 0;
}

/**
 * Count how many times the numbers in the data set increased
 *
 * @param data  The data set
 * @param length  The length of the data set
 * @returns  The count of increases
 * */
int countIncreases(int data[], int length) {
  int counter = 0;

  for (int i = 1; i < length; i++) {
    if (data[i] > data[i - 1]) {
      counter++;
    }
  }

  return counter;
}

/**
 * Creates an array of sums,
 * created by a 3-elements-long sliding window.
 *
 * @param data  The data to process
 * @param length  The length of the data to process
 * @returns  Pointer to the output array
 * */
int *slidingWindowSums(int data[], int length) {
  int *output = new int[length - 2];

  for (int i = 0; i < length - 2; i++) {
    output[i] = data[i] + data[i + 1] + data[i + 2];
  }

  return output;
}