/**
 * This problem involves extracting numbers from a string, and adding to an
 * accumulator
 *
 * For each row, treat it as one unit
 * Traverse with 2 pointers,
 * one from start, one from end
 * to get the first numeral it encounters
 * Worst case scenario of having to process all n characters
 *
 * Runtime: O(m * n) for m rows of n characters, as each row may need every
 * character processed Space: O(1) for a running accumulator variable
 */

#include <cassert>
#include <fstream>
#include <iostream>

int getNumber(std::string input) {  // O(n) possibly processing all n characters
  int number = 0;

  // get first digit
  for (int i = 0; i < input.length(); i++) {
    if (input[i] >= '0' && input[i] <= '9') {
      number += (input[i] - '0') * 10;
      break;
    }
  }

  // get second digit
  for (int i = input.length() - 1; i > -1; i--) {
    if (input[i] >= '0' && input[i] <= '9') {
      number += input[i] - '0';
      break;
    }
  }

  return number;
}

int solve(std::string inputFilePath) {
  std::ifstream inputFile(inputFilePath);
  std::string inputLine;

  int sum = 0;

  while (
      std::getline(inputFile, inputLine)) {  // O(m) going through all m lines
    sum += getNumber(inputLine);
  }

  inputFile.close();
  return sum;
}

int main(int argc, char** argv) {
  assert(getNumber("1abc2") == 12);
  assert(getNumber("pqr3stu8vwx") == 38);
  assert(getNumber("a1b2c3d4e5f") == 15);
  assert(getNumber("treb7uchet") == 77);
  assert(solve("sampleInput.txt") == 142);

  if (argc < 2) {
    std::cout << "provide path to input file" << std::endl;
    return 1;
  }

  std::cout << solve(argv[1]) << std::endl;

  return 0;
}