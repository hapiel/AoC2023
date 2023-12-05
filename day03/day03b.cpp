#include <iostream>
#include <vector>
#include <fstream>
#include <string>

bool isAsterix(char ch)
{
  std::string symbols = "*";
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

  // three dimensional vector
  std::vector<std::vector<std::vector<int>>> asterixGrid(lines.size(), std::vector<std::vector<int>>(lines[0].size()));

  for (size_t i = 0; i < lines.size(); i++)
  {
    size_t linePos = 0;
    while (lines[i].find_first_of("0123456789", linePos) != std::string::npos)
    {
      linePos = lines[i].find_first_of("0123456789", linePos); // beginning of the new number
      int asterX = -1;
      int asterY = -1;
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
          if (isAsterix(lines[i - 1][linePos - 1]))
          {
            asterX = linePos - 1;
            asterY = i - 1;
            isPartNumber = true;
          }; // left above
        }

        if (linePos + numberLength < lines[i].size())
        {
          if (isAsterix(lines[i - 1][linePos + numberLength]))
          {
            asterX = linePos + numberLength;
            asterY = i - 1;

            isPartNumber = true;
          }; // right above
        }

        for (size_t j = 0; j < numberLength; j++)
        {
          if (isAsterix(lines[i - 1][linePos + j]))
          {
            asterX = linePos + j;
            asterY = i - 1;
            isPartNumber = true;
          }; // above
        }
      }

      // search below
      if (i < lines.size() - 1)
      {
        if (i < lines.size() - 1)
        {
          if (isAsterix(lines[i + 1][linePos - 1]))
          {
            asterX = linePos - 1;
            asterY = i + 1;
            isPartNumber = true;
          }
        } // left below

        if (linePos + numberLength < lines[i].size())
        {
          if (isAsterix(lines[i + 1][linePos + numberLength]))
          {
            asterX = linePos + numberLength;
            asterY = i + 1;
            isPartNumber = true;
          }
        } // right below

        for (size_t j = 0; j < numberLength; j++)
        {
          if (isAsterix(lines[i + 1][linePos + j]))
          {
            asterX = linePos + j;
            asterY = i + 1;
            isPartNumber = true;
          }

        } // below
      }

      if (i < lines.size() - 1)
      {
        if (isAsterix(lines[i][linePos - 1]))
        {
          asterX = linePos - 1;
          asterY = i;
          isPartNumber = true;
        }
      } // left

      if (linePos + numberLength < lines[i].size())

      {
        if (isAsterix(lines[i][linePos + numberLength]))
        {
          asterX = linePos + numberLength;
          asterY = i;
          isPartNumber = true;

        } // right
      }

      if (isPartNumber)
      {

        asterixGrid[asterY][asterX].push_back(std::stoi(lines[i].substr(linePos, numberLength)));
      }

      linePos += numberLength;
    }
  }

  size_t partSum = 0;

  for (size_t i = 0; i < asterixGrid.size(); i++)
  {
    for (size_t j = 0; j < asterixGrid[i].size(); j++)
    {
      if (asterixGrid[i][j].size() == 2)
      {
        partSum += asterixGrid[i][j][0] * asterixGrid[i][j][1];
        std::cout << asterixGrid[i][j][0] << " " << asterixGrid[i][j][1] << std::endl;
      }
    }
  }

  std::cout << partSum << std::endl;

  return 0;
}