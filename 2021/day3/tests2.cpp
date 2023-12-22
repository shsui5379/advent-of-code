#include <cassert>

#include "funcs-2.h"

int main()
{
   std::vector<std::string> sample = {"00100", "11110", "10110", "10111", "10101", "01111", "00111", "11100", "10000", "11001", "00010", "01010"};

   assert(commonestWord(sample) == "10111");
   assert(leastCommonestWord(sample) == "01010");

   return 0;
}