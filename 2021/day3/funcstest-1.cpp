#include <cassert>
#include "funcs-1.h"

#include <string>
#include <vector>

int main()
{
   std::vector<std::string> sample = {"00100", "11110", "10110", "10111", "10101", "01111", "00111", "11100", "10000", "11001", "00010", "01010"};

   assert(wordOfCommonBits(sample) == "10110");
   assert(binaryToDecimal("10110") == 22);
   assert(binaryToDecimal("01001") == 9);
   assert(invertBinary("10110") == "01001");
   assert(invertBinary("01001") == "10110");

   return 0;
}