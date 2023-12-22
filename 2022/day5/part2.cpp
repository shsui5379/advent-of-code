// simulation through stack operations
// like part 1, but not moving one by one
// hold in a temp stack before moving to new stack

#include <cassert>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

std::string solve(std::string inputPath) {
  std::ifstream inputFile(inputPath);
  std::string currentLine;

  std::vector<std::stack<char>> stacks;

  // parsing stacks
  std::list<std::vector<char>> stackData;

  while (std::getline(inputFile, currentLine)) {
    if (stacks.size() == 0) {
      for (int i = 0; i < (currentLine.length() + 1) / 4; i++) {
        std::stack<char> s;
        stacks.push_back(s);
      }
    }

    if (currentLine[1] == '1') {
      break;
    }

    std::vector<char> rowData;

    for (int i = 1; i < currentLine.length(); i += 4) {
      rowData.push_back(currentLine[i]);
    }

    stackData.insert(stackData.end(), rowData);
  }

  // building stacks
  for (auto itr = stackData.rbegin(); itr != stackData.rend(); itr++) {
    std::vector<char> rowData = *itr;

    for (int i = 0; i < rowData.size(); i++) {
      if (rowData[i] != ' ') {
        stacks[i].push(rowData[i]);
      }
    }
  }

  // discarding garbage data
  std::getline(inputFile, currentLine);

  // performing operations
  while (std::getline(inputFile, currentLine)) {
    // index 0 is count
    // index 1 is source
    // index 2 is destination
    int data[3];
    int idx = 0;

    std::string builder = "";
    for (char c : currentLine) {
      if (c >= '0' && c <= '9') {
        builder += c;
      } else {
        if (builder != "") {
          data[idx] = std::stoi(builder);
          idx++;
          builder = "";
        }
      }
    }

    if (builder != "") {
      data[idx] = std::stoi(builder);
      idx++;
      builder = "";
    }

    std::stack<char> temp;
    for (int i = 0; i < data[0]; i++) {
      if (!stacks[data[1] - 1].empty()) {
        temp.push(stacks[data[1] - 1].top());
        stacks[data[1] - 1].pop();
      }
    }
    while (!temp.empty()) {
      stacks[data[2] - 1].push(temp.top());
      temp.pop();
    }
  }

  // building solution
  std::string builder = "";
  for (std::stack<char> stack : stacks) {
    if (!stack.empty()) {
      builder += stack.top();
    }
  }
  return builder;
}

int main(int argc, char** argv) {
  assert(solve("sample.txt") == "MCD");

  if (argc < 2) {
    std::cout << "provide path to input file" << std::endl;
    return 0;
  }

  std::cout << solve(argv[1]) << std::endl;

  return 0;
}