#include <iostream>

int main()
{
   int horizontal = 0;
   int vertical = 0;
   int aim = 0;

   std::string direction;
   int steps;

   //part 1
   /*while (std::cin >> direction >> steps)
   {
      if (direction == "forward")
         horizontal += steps;
      else if (direction == "up")
         vertical -= steps;
      else if (direction == "down")
         vertical += steps;
   }*/

   //part 2
   while (std::cin >> direction >> steps)
   {
      if (direction == "forward")
      {
         horizontal += steps;
         vertical += aim * steps;
      }
      else if (direction == "up")
      {
         aim -= steps;
      }
      else if (direction == "down")
      {
         aim += steps;
      }
   }

   std::cout << horizontal * vertical << std::endl;

   return 0;
}