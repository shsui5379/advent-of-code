/**
 * Takes part 1 as base, but numbers spelled out in alphabet need to be
 * processed too
 *
 * sliding window esque technique to scan for spelled numbers
 *
 * Runtime: O(m * 100n) for m words of n length
 * Space: constant, just predefined data and sum variables
 */

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>

int getNumber(std::string input) {  // O(100n) : 2 * O(50n) loops
  int output = 0;

  const std::pair<std::string, int> NUMBERS[] = {
      {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
      {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

  // get first digit
  for (int i = 0; i < input.length(); i++) {
    if (input[i] >= '0' && input[i] <= '9') {  // found a numeral character
      output += 10 * (input[i] - '0');
      break;
    } else {  // find spelled number - loops 10 times, worse case scenario each
              // of the n characters will be processed by the sliding window 5
              // times - O(50n)
      bool found = false;

      for (std::pair<std::string, int> number : NUMBERS) {
        int length = number.first.length();

        if (i < input.length() - length &&
            input.substr(i, length) == number.first) {
          output += 10 * number.second;
          found = true;
          break;
        }
      }

      if (found) break;
    }
  }

  // get second digit
  for (int i = input.length() - 1; i > -1; i--) {
    if (input[i] >= '0' && input[i] <= '9') {  // found numeral character
      output += input[i] - '0';
      break;
    } else {  // find spelled number
      bool found = false;

      for (std::pair<std::string, int> number : NUMBERS) {
        int length = number.first.length();

        if (i - length > -1 &&
            input.substr(i - length + 1, length) == number.first) {
          output += number.second;
          found = true;
          break;
        }
      }

      if (found) break;
    }
  }

  return output;
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
  assert(getNumber("two1nine") == 29);
  assert(getNumber("eightwothree") == 83);
  assert(getNumber("abcone2threexyz") == 13);
  assert(getNumber("xtwone3four") == 24);
  assert(getNumber("4nineeightseven2") == 42);
  assert(getNumber("zoneight234") == 14);
  assert(getNumber("7pqrstsixteen") == 76);

  assert(solve("sampleInput.txt") == 142);
  assert(solve("sampleInput2.txt") == 281);

  if (argc < 2) {
    std::cout << "provide path to input file" << std::endl;
    return 1;
  }

  std::cout << solve(argv[1]) << std::endl;

  return 0;
}