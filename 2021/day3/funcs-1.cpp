#include "funcs-1.h"
#include <cmath>

/**
 * Produces a binary word, 
 * with each position having the most common bit 
 * found in the corresponding position 
 * of each binary word in the vector.
 * 
 * @param words  A vector of binary words as strings
 * @returns  The new binary word as a string
 * */
std::string wordOfCommonBits(std::vector<std::string> words)
{
   std::string output = "";
   int width = words[0].length();
   std::vector<int> tracker(width, 0);

   //sum corresponding positions
   for (std::string word : words)
   {
      for (int position = 0; position < width; position++)
      {
         tracker[position] += word[position] - '0';
      }
   }

   //finding common bit
   for (int position = 0; position < width; position++)
   {
      (tracker[position] / (double)words.size() >= 0.5) ? output += '1' : output += '0';
   }

   return output;
}

/**
 * Converts binary to decimal
 * 
 * @param binary  The binary as a string
 * @returns  The equivalent decimal
 * */
int binaryToDecimal(std::string binary)
{
   int accumulator = 0;

   for (int i = 0; i < binary.length(); i++)
   {
      accumulator += (binary[binary.length() - 1 - i] - '0') * pow(2, i);
   }

   return accumulator;
}

/**
 * Inverts a given binary
 * 
 * @param original  The original binary as a string
 * @returns  The inverted binary as a string
 * */
std::string invertBinary(std::string original)
{
   std::string output = "";

   for (int i = 0; i < original.length(); i++)
   {
      output += '0' + (original[i] - 1) % 2;
   }

   return output;
}