#include <assert.h>

#include <fstream>
#include <iostream>

#include "../commons/cpp/inputUtils.h"

// since each elf is up to a blank line,
// keep summing until the blank line is reached
// we only need the highest sum, so keep track of that+

// runtime: O(N), where N = number of lines in input file
// space: O(1), only tracker variables

int solve(std::string inputFilePath) {
  std::ifstream inputFile(inputFilePath);
  std::string inputLine;

  int max = 0;
  int sum = 0;

  // looping N times, where N is the number of lines in input file
  // each loop runs a constant number of operations
  while (std::getline(inputFile, inputLine)) {
    if (inputLine == "") {  // end of one elf
      if (sum > max) {
        max = sum;  // set new max
      }
      sum = 0;  // reset sum
    } else {    // same elf
      if (InputUtils::isInt(inputLine)) {
        sum += std::stoi(inputLine);
      }
    }
  }

  inputFile.close();
  return max;
}

int main(int argc, char** argv) {
  assert(solve("sampleInput.txt") == 24000);

  if (argc < 2) {
    std::cout << "provide path to input file" << std::endl;
    return 0;
  }

  std::cout << solve(argv[1]) << std::endl;

  return 0;
}