#pragma once

#include "BingoSpace.h"

class BingoBoard
{
private:
   BingoSpace board[5][5];
   int lastMarked;

public:
   BingoBoard(int data[25]);
   void mark(int number);
   bool hasBingo();
   int getScore();
};