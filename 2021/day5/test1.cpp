#include "Floor.h"
#include <cassert>

int main()
{
   Floor f(10, 10);

   f.mark(0, 9, 5, 9);
   f.mark(9, 4, 3, 4);
   f.mark(2, 2, 2, 1);
   f.mark(7, 0, 7, 4);
   f.mark(0, 9, 2, 9);
   f.mark(3, 4, 1, 4);
   f.mark(8, 0, 0, 8);
   f.mark(6, 4, 2, 0);
   f.mark(0, 0, 8, 8);
   f.mark(5, 5, 8, 2);

   assert(f.pointsIntersect(2) == 12);

   return 0;
}