#include <iostream>
#include <string>
#include <fstream>

/// <summary>
/// Advent of Code
/// 
/// Day 1
/// 
/// </summary>
/// <returns></returns>
int main()
{
    std::ifstream inFile1("inputs.txt");

    int addend1 = 0;
    int lineNum1 = 0;
    std::string input;

    while (std::getline(inFile1, input))
    {
        int addend2 = 0;
        int lineNum2 = 0;

        addend1 = std::stoi(input);
        std::ifstream inFile2("inputs.txt");

        while (std::getline(inFile2, input))
        {
            if (lineNum2 == lineNum1)
            {
                continue;
            }

            addend2 = std::stoi(input);
            int sum = addend1 + addend2;

            if (sum == 2020)
            {
                int product = addend1 * addend2;
                std::cout << product;
                return product;
            }
            lineNum2++;
        }
        lineNum1++;
    }
    return 0;
}