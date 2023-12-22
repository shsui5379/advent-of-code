#include <assert.h>

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#include "../commons/cpp/inputUtils.h"

// taking part 1 as base
// but now we want to the the sum of the top 3 elves
// efficient data structure for tracking that would be a min heap of size 3
// if the new sum we want to test is < than findMin, deleteMin and insert the
// new sum

// alt approach: 3 int vars for tracking the top 3
// if > first, replace first
// else if > second, replace second
// else if > third, replace third

// runtime comparison:
// using a minheap, identifying a new record only takes one operation at worst
// case but with 3 vars, worst case takes three operations using a minheap,
// replacing the new record: removing an existing record will only take one
// operation, since size 3 heap will have a height of 2 inserting the new record
// worst case takes two operations, due to height of 2 using 3 vars, the
// replacement is just an one operation move overall, the minheap worst case
// takes 3 moves, mainly used for DS operations, while using 3 vars worst case
// takes 4 moves, mainly used to do var comparisons
// the minheap approach has a minuscule edge in runtime

// space comparison:
// we're mainly storing 3 ints here,
// but the STL implementation of a minheap uses a vector under the hood,
// which adds additional space overhead
// the 3 vars approach has a minuscule edge in space

// runtime: O(N), where N = number of lines in input file
// space: O(1), only tracker variables

int solve(std::string inputFilePath) {
  std::ifstream inputFile(inputFilePath);
  std::string inputLine;

  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  q.push(0);
  q.push(0);
  q.push(0);

  int sum = 0;

  // looping N times, where N is the number of lines in input file
  // each loop runs a constant number of operations
  while (std::getline(inputFile, inputLine)) {
    if (inputLine == "") {   // end of one elf
      if (sum >= q.top()) {  // new record
        q.pop();
        q.push(sum);
      }
      sum = 0;  // reset sum
    } else {    // same elf
      if (InputUtils::isInt(inputLine)) {
        sum += std::stoi(inputLine);
      }
    }
  }

  if (sum >= q.top()) {  // new record
    q.pop();
    q.push(sum);
  }

  inputFile.close();

  int output = 0;
  for (int i = 0; i < 3; i++) {
    output += q.top();
    q.pop();
  }

  return output;
}

int main(int argc, char** argv) {
  assert(solve("sampleInput.txt") == 45000);

  if (argc < 2) {
    std::cout << "provide path to input file" << std::endl;
    return 0;
  }

  std::cout << solve(argv[1]) << std::endl;

  return 0;
}