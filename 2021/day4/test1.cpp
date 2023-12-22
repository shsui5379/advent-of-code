#include <cassert>

#include "BingoBoard.h"

int main()
{
   int sample[25] = {14, 21, 17, 24, 4, 10, 16, 15, 9, 19, 18, 8, 23, 26, 20, 22, 11, 13, 6, 5, 2, 0, 12, 3, 7};
   int calls[] = {7, 4, 9, 5, 11, 17, 23, 2, 0, 14, 21, 24, 10, 16, 13, 6, 15, 25, 12, 22, 18, 20, 8, 19, 3, 26, 1};

   BingoBoard b(sample);

   int pos = 0;

   while (!b.hasBingo())
   {
      b.mark(calls[pos]);
      pos++;
   }

   assert(b.getScore() == 4512);

   return 0;
}