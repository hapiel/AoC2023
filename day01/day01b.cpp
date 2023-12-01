#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
  std::ifstream input("input.txt");

  std::vector<std::string> lines;
  std::vector<std::string> digits{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  std::string line;

  while(std::getline(input, line))
  {
    lines.push_back(line);
  }

  input.close();

  int sum = 0;
  int count = 0;

  for (const std::string& line : lines) {

    char firstDigit;
    size_t firstDigitIndex;
    char lastDigit;
    size_t lastDigitIndex;

    for (size_t i = 0; i < line.length(); i++) {
      if (std::isdigit(line[i])) {
        firstDigit = line[i];
        firstDigitIndex = i;
        break;
      }
    }

    for (size_t i = line.length(); i >= 0; i--) {
      if (std::isdigit(line[i])) {
        lastDigit = line[i];
        lastDigitIndex = i;
        std::cout << "i, LDI: " << i << " " << lastDigitIndex << std::endl;
        break;
      }
    }

    for (size_t i = 0; i < digits.size(); i++) {
      // check if the first digit is a word
      if (line.find(digits[i]) != std::string::npos) {
        if (line.find(digits[i]) < firstDigitIndex) {
          firstDigit = '0' + i + 1;
          firstDigitIndex = line.find(digits[i]);
        }
      }
      // check if the last digit is a word
      if (line.rfind(digits[i]) != std::string::npos) {
        if (line.rfind(digits[i]) > lastDigitIndex) {
          lastDigit = '0' + i + 1;
          lastDigitIndex = line.rfind(digits[i]);
        }
      }
    }

    std::string numberString = std::string(1, firstDigit) + lastDigit;
    int number = std::stoi(numberString);
    sum += number ;
    std::cout << count++ << " " << number << std::endl;
  }

  std::cout << sum << std::endl;

  return 0;
}