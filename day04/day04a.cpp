#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

int main()
{
  std::ifstream input("input.txt");

  std::string line;

  std::vector<std::vector<std::vector<size_t>>> cards;

  while (std::getline(input, line))
  {

    // split line at '|'
    std::vector<std::string> parts;
    std::string part;
    std::istringstream iss(line.substr(8));
    while (std::getline(iss, part, '|'))
    {

      parts.push_back(part);
    }

    // split parts at ' '
    std::vector<size_t> winningNumbers;
    std::istringstream issWinning(parts[0]);
    std::string numWinning;

    while (std::getline(issWinning, numWinning, ' '))
    {
      if (std::isdigit(numWinning[0]))
      {
        winningNumbers.push_back(std::stoi(numWinning));
      }
    }

    std::vector<size_t> myNumbers;
    std::istringstream issMyNumbers(parts[1]);
    std::string numMyNumbers;

    while (std::getline(issMyNumbers, numMyNumbers, ' '))
    {
      if (std::isdigit(numMyNumbers[0]))
      {
        myNumbers.push_back(std::stoi(numMyNumbers));
      }
    }

    std::vector<std::vector<size_t>> card;

    card.push_back(winningNumbers);
    card.push_back(myNumbers);

    cards.push_back(card);
  }

  // END PARSING
  size_t totalPoints = 0;

  for (std::vector<std::vector<size_t>> card : cards)
  {
    size_t cardScore = 0;

    for (size_t winningNumber : card[0])
    {
      for (size_t myNumber : card[1])
      {
        if (winningNumber == myNumber)
        {
          cardScore++;
        }
      }
    }

    size_t cardPoints = std::pow(2, cardScore - 1);
    totalPoints += cardPoints;

  }

  std::cout << totalPoints << std::endl;

  return 0;
}