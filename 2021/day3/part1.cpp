#include <iostream>

#include "../commons/stdinToStringVector.h"
#include "funcs-1.h"

int main()
{
   std::vector<std::string> data = stdinToStringVector();
   std::string commonWord = wordOfCommonBits(data);

   std::cout << binaryToDecimal(commonWord) * binaryToDecimal(invertBinary(commonWord)) << std::endl;

   return 0;
}
