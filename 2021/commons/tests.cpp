#include "inputProcessing.h"
#include <cassert>

int main()
{
   std::vector<std::string> v = {"7", "4", "9", "5", "11", "17", "23", "2", "0", "14", "21", "24", "10", "16", "13", "6", "15", "25", "12", "22", "18", "20", "8", "19", "3", "26", "1"};
   assert(splitStringOnDelimiter("7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1", ",") == v);

   return 0;
}