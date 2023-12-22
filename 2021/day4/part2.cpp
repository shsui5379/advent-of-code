#include <vector>
#include <iostream>

#include "../commons/inputProcessing.h"
#include "BingoBoard.h"

int main()
{
   std::string firstLine;
   getline(std::cin, firstLine);

   std::vector<std::string> calls = splitStringOnDelimiter(firstLine, ",");

   //making the bingo boards
   std::vector<BingoBoard *> boards;

   int first;

   while (std::cin >> first)
   {
      int num[25];
      num[0] = first;

      for (int i = 1; i < 25; i++)
      {
         std::cin >> num[i];
      }

      boards.push_back(new BingoBoard(num));
   }

   //play
   int round = 0;
   while (boards.size() > 1)
   {
      int num = std::stoi(calls[round]);

      for (int i = 0; i < boards.size(); i++)
      {
         boards[i]->mark(num);
         if (boards[i]->hasBingo())
         {
            delete boards[i];
            boards.erase(boards.begin() + i);
            i--;
         }
      }

      round++;
   }

   while (!boards[0]->hasBingo())
   {
      boards[0]->mark(std::stoi(calls[round]));
      round++;
   }

   std::cout << boards[0]->getScore() << std::endl;

   return 0;
}