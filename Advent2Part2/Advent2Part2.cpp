#include <iostream>
#include <string>
#include <fstream>

bool IsValid(std::string line)
{
    int position1 = 0;
    int position2 = 0;
    char letter;

    std::string password;

    position1 = std::stoi(line.substr(0, line.find('-')));
    position2 = std::stoi(line.substr(line.find('-') + 1, line.find(' ')));
    letter = line.substr(line.find(' ') + 1, line.find(':'))[0];

    password = line.substr(line.find(':') + 2, password.npos);
    
    int letterCount = 0;
    if (password[position1 - 1] == letter)
        letterCount++;
    
    if (password[position2 - 1] == letter)
        letterCount++;
    
    if (letterCount == 1)
        return true;
    
    else
        return false;   
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
