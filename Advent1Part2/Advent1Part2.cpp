#include <iostream>
#include <string>
#include <fstream>

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
                lineNum2++;
                continue;
            }
            addend2 = std::stoi(input);


            int lineNum3 = 0;
            int addend3 = 0;
            std::ifstream inFile3("inputs.txt");

            while (std::getline(inFile3, input))
            {
                if (lineNum3 == lineNum2 || lineNum3 == lineNum1)
                {
                    lineNum3++;
                    continue;
                }

                addend3 = std::stoi(input);
                int sum = addend1 + addend2 + addend3;

                if (sum == 2020)
                {
                    int product = addend1 * addend2 * addend3;
                    std::cout << product;
                    return product;
                }
                lineNum3++;
            }
            lineNum2++;

        }
        lineNum1++;
    }
    return 0;
}