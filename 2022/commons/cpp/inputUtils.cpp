#include "inputUtils.h"

bool InputUtils::isInt(std::string input) {
  try {
    long double converted = std::stold(input);
    return (converted == (int)converted);
  } catch (const std::exception &e) {
    return false;
  }
}
