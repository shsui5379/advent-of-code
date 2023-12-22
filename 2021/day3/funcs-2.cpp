#include <vector>
#include <string>

#include "funcs-2.h"
#include "funcs-1.h"

/**
 * First, make a word out of the common bits. 
 * Then, eliminate all words that don't share the same first bit 
 * with that new word. 
 * 
 * Second, make another word out of the common bits 
 * using the remaining words. 
 * Then, eliminate all words that don't share the same second bit 
 * with that new word. 
 * 
 * Third, repeat with the third bit, and so on. 
 * 
 * Until the vector of words have only one word left. 
 * Return that.
 * 
 * @param words  The vector of words
 * @returns  The "commenest" word from the vector
 * */
std::string commonestWord(std::vector<std::string> words)
{
   int position = 0;
   while (words.size() > 1)
   {
      std::string commonWord = wordOfCommonBits(words);
      words = filterByBit(words, commonWord[position], position);
      position++;
   }
   return words[0];
}

/**
 * Filter out words that don't have a given bit in a given position
 * 
 * @param words  Vector of words to filter
 * @param bit  The bit being expected at position
 * @param position  The position to check for the bit
 * @returns  The filtered vector
 * */
std::vector<std::string> filterByBit(std::vector<std::string> words, char bit, int position)
{
   for (int i = 0; i < words.size(); i++)
   {
      if (words[i][position] != bit)
      {
         words.erase(words.begin() + i);
         i--;
      }
   }
   return words;
}

/**
 * Just like commonestWord, but based on the least common bits
 * 
 * @param words  The vector of words
 * @returns  The least "commonest" word
 * */
std::string leastCommonestWord(std::vector<std::string> words)
{
   int position = 0;
   while (words.size() > 1)
   {
      std::string leastCommonWord = invertBinary(wordOfCommonBits(words));
      words = filterByBit(words, leastCommonWord[position], position);
      position++;
   }
   return words[0];
}