#pragma once

class Floor
{
private:
   int **array;
   int numRow;
   int numCol;

public:
   Floor(int r, int c);
   ~Floor();
   void mark(int x1, int y1, int x2, int y2);
   int pointsIntersect(int threshold);
};