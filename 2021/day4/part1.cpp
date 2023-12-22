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
   for (std::string call : calls)
   {
      int num = std::stoi(call);

      for (BingoBoard *board : boards)
      {
         board->mark(num);
         if (board->hasBingo())
         {
            std::cout << board->getScore() << std::endl;
            return 0;
         }
      }
   }

   return 0;
}