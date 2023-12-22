#include <iostream>
#include <vector>

#include "../commons/stdinToStringVector.h"
#include "funcs-2.h"
#include "funcs-1.h"

int main()
{
   std::vector<std::string> data = stdinToStringVector();

   std::cout << binaryToDecimal(commonestWord(data)) * binaryToDecimal(leastCommonestWord(data)) << std::endl;

   return 0;
}