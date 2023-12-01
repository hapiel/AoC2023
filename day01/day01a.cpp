#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
  std::ifstream input("input.txt");

  std::vector<std::string> lines;
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
    char lastDigit;

    for (size_t i = 0; i < line.length(); i++) {
      if (std::isdigit(line[i])) {
        firstDigit = line[i];
        break;
      }
    }

    for (size_t i = line.length(); i >= 0; i--) {
      if (std::isdigit(line[i])) {
        lastDigit = line[i];
        break;
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