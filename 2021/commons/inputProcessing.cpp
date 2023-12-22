#include "inputProcessing.h"
#include <iostream>

/**
 * Takes input from stdin, 
 * and put each "word" as an element 
 * in a vector
 * 
 * @returns  The vector of string lines
 * */
std::vector<std::string> stdinToStringVector()
{
   std::vector<std::string> output;
   std::string current;

   while (std::cin >> current)
   {
      output.push_back(current);
   }

   return output;
}

/**
 * Splits a string on a deliminter
 * 
 * @param string  The string to split
 * @param delimiter  The delimiter
 * @returns  A vector of the substrings
 * */
std::vector<std::string> splitStringOnDelimiter(std::string string, std::string delimiter)
{
   std::vector<std::string> output;

   while (string.find(delimiter) != std::string::npos)
   {
      output.push_back(string.substr(0, string.find(delimiter)));
      string = string.substr(string.find(delimiter) + 1);
   }

   output.push_back(string);

   return output;
}