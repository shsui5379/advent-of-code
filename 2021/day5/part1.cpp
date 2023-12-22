#include <vector>
#include <iostream>

#include "../commons/inputProcessing.h"
#include "Floor.h"

int main()
{
   Floor floor(999, 999);

   std::string first, second, third;
   while (std::cin >> first >> second >> third)
   {
      std::vector<std::string> coord1 = splitStringOnDelimiter(first, ",");
      std::vector<std::string> coord2 = splitStringOnDelimiter(third, ",");

      floor.mark(std::stoi(coord1[0]), std::stoi(coord1[1]), std::stoi(coord2[0]), std::stoi(coord2[1]));
   }

   std::cout << floor.pointsIntersect(2) << std::endl;

   return 0;
}