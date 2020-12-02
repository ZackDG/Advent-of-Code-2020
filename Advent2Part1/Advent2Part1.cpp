#include <iostream>
#include <string>
#include <fstream>

bool IsValid(std::string line)
{
    int minLetter = 0;
    int maxLetter = 0;
    char letter;
    std::string password;

    minLetter = std::stoi(line.substr(0, line.find('-')));
    maxLetter = std::stoi(line.substr(line.find('-') + 1, line.find(' ')));
    letter = line.substr(line.find(' ') + 1, line.find(':'))[0];

    password = line.substr(line.find(':') + 2, password.npos);

    int letterCount = 0;
    for (int i = 0; i < password.size(); i++)
    {
        if (password[i] == letter)
            letterCount++;
    }

    if (letterCount >= minLetter && letterCount <= maxLetter)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::ifstream inFile("input.txt");
    std::string line;

    int correctPassCount = 0;
    while (std::getline(inFile, line))
    {
        if (IsValid(line))
        {
            correctPassCount++;
        }
    }

    std::cout << correctPassCount;
}
