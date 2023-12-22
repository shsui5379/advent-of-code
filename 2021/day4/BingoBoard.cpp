#include "BingoBoard.h"
#include "BingoSpace.h"

/**
 * Construct a bingo board with the given numbers
 * 
 * @param board  25 ints to populate the board with
 * */
BingoBoard::BingoBoard(int data[25])
{
   for (int i = 0; i < 25; i++)
   {
      board[i / 5][i % 5] = {data[i], false};
   }
}

/**
 * Marks the given number on this board
 * 
 * @param number  The number to mark off
 * */
void BingoBoard::mark(int number)
{
   for (int row = 0; row < 5; row++)
   {
      for (int col = 0; col < 5; col++)
      {
         if (board[row][col].number == number)
         {
            board[row][col].marked = true;
            lastMarked = number;
            return;
         }
      }
   }
}

/**
 * Determines if this board has an entire row or entire column marked.
 * 
 * @returns  True if this board reached bingo
 * */
bool BingoBoard::hasBingo()
{
   //row
   for (int row = 0; row < 5; row++)
   {
      int counter = 0;

      for (int col = 0; col < 5; col++)
      {
         if (board[row][col].marked)
         {
            counter++;
         }
      }

      if (counter == 5)
      {
         return true;
      }
   }

   //column
   for (int col = 0; col < 5; col++)
   {
      int counter = 0;

      for (int row = 0; row < 5; row++)
      {
         if (board[row][col].marked)
         {
            counter++;
         }
      }

      if (counter == 5)
      {
         return true;
      }
   }

   return false;
}

/**
 * Computes this board's score, 
 * which is based on the sum of all unmarked numbers, 
 * times the last number to be marked
 * 
 * @returns  Score
 * */
int BingoBoard::getScore()
{
   int accumulator = 0;

   for (int row = 0; row < 5; row++)
   {
      for (int col = 0; col < 5; col++)
      {
         if (!board[row][col].marked)
         {
            accumulator += board[row][col].number;
         }
      }
   }

   return accumulator * lastMarked;
}