#include <iostream>
#include <vector>
#include <fstream>
#include <string>

bool isAsterix(char ch)
{
  std::string symbols = "!@#$%^&*+=-[]\\\';,/{}|\":<>?~_";
  return symbols.find(ch) != std::string::npos;
}

int main()
{
  std::ifstream input("input.txt");

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(input, line))
  {
    lines.push_back(line);
  }

  size_t partSum = 0;

  for (size_t i = 0; i < lines.size(); i++)
  {
    size_t linePos = 0;
    while (lines[i].find_first_of("0123456789", linePos) != std::string::npos)
    {
      linePos = lines[i].find_first_of("0123456789", linePos); // beginning of the new number
      bool isPartNumber = false;
      size_t numberLength = 1;
      while (lines[i].find_first_of("0123456789", linePos + numberLength) == linePos + numberLength)
      {
        numberLength++;
      }

      // search above
      if (i > 0)
      {
        // search left
        if (linePos > 0)
        {
          isPartNumber = isPartNumber || isAsterix(lines[i - 1][linePos - 1]); // left above
        }

        if (linePos + numberLength < lines[i].size())
        {
          isPartNumber = isPartNumber || isAsterix(lines[i - 1][linePos + numberLength]); // right above
        }

        for (size_t j = 0; j < numberLength; j++)
        {
          isPartNumber = isPartNumber || isAsterix(lines[i - 1][linePos + j]); // above
        }
      }

      // search below
      if (i < lines.size() - 1)
      {
        if (i < lines.size() - 1)
        {
          isPartNumber = isPartNumber || isAsterix(lines[i + 1][linePos - 1]); // left below
        }

        if (linePos + numberLength < lines[i].size())
        {
          isPartNumber = isPartNumber || isAsterix(lines[i + 1][linePos + numberLength]); // right below
        }

        for (size_t j = 0; j < numberLength; j++)
        {
          isPartNumber = isPartNumber || isAsterix(lines[i + 1][linePos + j]); // below
        }
      }

      if (i < lines.size() - 1)
      {
        isPartNumber = isPartNumber || isAsterix(lines[i][linePos - 1]); // left
      }
      if (linePos + numberLength < lines[i].size())

      {
        isPartNumber = isPartNumber || isAsterix(lines[i][linePos + numberLength]); // right
      }

      if (isPartNumber)
      {

        partSum += std::stoi(lines[i].substr(linePos, numberLength));

        // std::cout << lines[i].substr(linePos, numberLength) << std::endl;
      }

      linePos += numberLength;
    }
  }

  std::cout << partSum << std::endl;

  return 0;
}