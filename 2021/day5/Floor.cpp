#include "Floor.h"

/**
 * Initializes a Floor with given dimensions
 * 
 * @param r  Number of rows
 * @param c  Number of columns
 * */
Floor::Floor(int r, int c)
{
   numRow = r;
   numCol = c;
   array = new int *[r];

   for (int i = 0; i < numRow; i++)
   {
      array[i] = new int[c];

      for (int j = 0; j < numCol; j++)
      {
         array[i][j] = 0;
      }
   }
}

/**
 * Destructs this Floor
 * */
Floor::~Floor()
{
   for (int i = 0; i < numCol; i++)
   {
      delete[] array[i];
      array[i] = nullptr;
   }

   delete[] array;
   array = nullptr;
}

/**
 * Increment the mark count of all points 
 * contained in a line with endpoints 
 * (x1, y1) and (x2, y2)
 * 
 * @param x1  X coordinate of the first endpoint
 * @param y1  y coordinate of the first endpoint
 * @param x2  X coordinate of the second endpoint
 * @param y2  Y coordinate of the second endpoint
 * */
void Floor::mark(int x1, int y1, int x2, int y2)
{
   //horizontal: y's are the same
   if (y1 == y2)
   {
      if (x2 > x1)
      {
         for (int x = x1; x <= x2; x++)
         {
            array[y1][x]++;
         }
      }
      else
      {
         for (int x = x2; x <= x1; x++)
         {
            array[y1][x]++;
         }
      }
   }
   //vertical: x's are the same
   else if (x1 == x2)
   {
      if (y2 > y1)
      {
         for (int y = y1; y <= y2; y++)
         {
            array[y][x1]++;
         }
      }
      else
      {
         for (int y = y2; y <= y1; y++)
         {
            array[y][x1]++;
         }
      }
   }
   //diagonal @ 45deg
   else
   {
      if (x1 > x2)
      {
         if (y1 > y2)
         {
            for (int x = x1; x >= x2; x--)
            {
               array[y1][x]++;
               y1--;
            }
         }
         else
         {
            for (int x = x1; x >= x2; x--)
            {
               array[y1][x]++;
               y1++;
            }
         }
      }
      else
      {
         if (y1 > y2)
         {
            for (int x = x1; x <= x2; x++)
            {
               array[y1][x]++;
               y1--;
            }
         }
         else
         {
            for (int x = x1; x <= x2; x++)
            {
               array[y1][x]++;
               y1++;
            }
         }
      }
   }
}

/**
 * Counts the number of points on this Floor 
 * that is marked at least `threshold` times
 * 
 * @param threshold  The mark threshold
 * @returns  The number of points marked at least threshold times
 * */
int Floor::pointsIntersect(int threshold)
{
   int counter = 0;
   for (int r = 0; r < numRow; r++)
   {
      for (int c = 0; c < numCol; c++)
      {
         if (array[r][c] >= threshold)
         {
            counter++;
         }
      }
   }
   return counter;
}