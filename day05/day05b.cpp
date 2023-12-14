#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> 

int main()
{
  std::ifstream input("input.txt");

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(input, line))
  {
    lines.push_back(line);
  }

  std::vector<long long> seeds;

  std::istringstream seedStream(lines[0]);
  std::string seed;

  while (std::getline(seedStream, seed, ' '))
  {
    if (std::isdigit(seed[0]))
    {
      seeds.push_back(std::stoll(seed));
    }
  }

  std::vector<long long> newSeeds;

  for (int i = 0; i < seeds.size(); i++)
  {
    if (i % 2 == 1)
    {
      for (long long j = 0; j < seeds[i]; j++)
      {
        newSeeds.push_back(seeds[i-1] + j);
      }
    }
    std::cout << "seed " << i << " done. count: " << newSeeds.size() << std::endl;
  }

  std::cout << "All seeds done. count: " << newSeeds.size() << std::endl;

  std::vector<std::vector<std::vector<long long>>> maps;

  int mapCount = -1;

  for (size_t i = 2; i < lines.size(); i++)
  {
    if (lines[i].find("map") != std::string::npos)
    {
      mapCount++;
      std::vector<std::vector<long long>> map;
      maps.push_back(map);
    }
    if (isdigit(lines[i][0]))
    {
      std::istringstream iss(lines[i]);
      std::string number;
      std::vector<long long> range;
      while (std::getline(iss, number, ' '))
      {
        range.push_back(std::stoll(number));
      }
      maps[mapCount].push_back(range);
    }
  }

  // parsing done

  std::vector<long long> locations;

  for (long long seed : newSeeds)
  {
    long long location = seed;
    for (std::vector<std::vector<long long>> map : maps)
    {
      for (std::vector<long long> range : map)
      {
        if (location >= range[1] && location < range[1] + range[2]){
          location = range[0] + (location - range[1]);
          break;
        }
      }
    }
    locations.push_back(location);
  }

  auto nearestLocation = std::min_element(locations.begin(), locations.end());

  std::cout << *nearestLocation << std::endl;

  return 0;
}