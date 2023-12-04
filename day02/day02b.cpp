#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
  std::ifstream input("input.txt");

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(input, line))
  {
    lines.push_back(line);
  }

  std::vector<std::vector<std::vector<int>>> games;

  for (const std::string &line : lines)
  {

    std::vector<std::vector<int>> game;

    std::vector<int> red;
    std::vector<int> green;
    std::vector<int> blue;

    size_t linePos = 0;

    while (line.find("red", linePos) != std::string::npos)
    {
      linePos = line.find("red", linePos);
      linePos++;

      size_t digitPos = line.find_first_of("0123456789", linePos - 4);
      size_t digitLength = 1;

      while (line.find_first_of("0123456789", digitPos + digitLength) == digitPos + digitLength)
      {
        digitLength++;
      }

      red.push_back(std::stoi(line.substr(digitPos, digitLength)));
    }

    linePos = 0;

    while (line.find("green", linePos) != std::string::npos)
    {
      linePos = line.find("green", linePos);
      linePos++;

      size_t digitPos = line.find_first_of("0123456789", linePos - 4);
      size_t digitLength = 1;

      while (line.find_first_of("0123456789", digitPos + digitLength) == digitPos + digitLength)
      {
        digitLength++;
      }

      green.push_back(std::stoi(line.substr(digitPos, digitLength)));
    }

    linePos = 0;

    while (line.find("blue", linePos) != std::string::npos)
    {
      linePos = line.find("blue", linePos);
      linePos++;

      size_t digitPos = line.find_first_of("0123456789", linePos - 4);
      size_t digitLength = 1;

      while (line.find_first_of("0123456789", digitPos + digitLength) == digitPos + digitLength)
      {
        digitLength++;
      }

      blue.push_back(std::stoi(line.substr(digitPos, digitLength)));
    }

    game.push_back(red);
    game.push_back(green);
    game.push_back(blue);

    games.push_back(game);
  }



  size_t powerSum = 0;

  for (size_t i = 0; i < games.size(); ++i)
  {

    size_t maxRed = 0;
    size_t maxGreen = 0;
    size_t maxBlue = 0;

    for (size_t j = 0; j < games[i].size(); ++j)
    {
      for (size_t k = 0; k < games[i][j].size(); ++k)
      {

        // red
        if (j == 0)
        {
          if (games[i][j][k] > maxRed)
          {
            maxRed = games[i][j][k];
          }
        }
        // green
        if (j == 1)
        {
          if (games[i][j][k] > maxGreen)
          {
            maxGreen = games[i][j][k];
          }
        }
        // blue
        if (j == 2)
        {
          if (games[i][j][k] > maxBlue)
          {
            maxBlue = games[i][j][k];
          }
        }

      }

      
    }

    size_t gamePower = maxRed * maxGreen * maxBlue;
    powerSum += gamePower;

  }

  std::cout << "answer: " << powerSum << std::endl;

  return 0;
}