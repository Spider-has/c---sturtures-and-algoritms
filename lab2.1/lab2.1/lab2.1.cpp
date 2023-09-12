#include <iostream>
#include <fstream>
#include <cmath>

const int size = 256;

int getNumber(std::ifstream& file)
{
    int num;
    file >> num;
    return num;
}

int getMiddle(int start, int end)
{
    float a = start, b = end;
    return std::floor(a / 2 + b / 2);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream numFile;

    numFile.open("Inp.txt");

    if (!numFile.is_open())
    {
        return EXIT_FAILURE;
    }

    int length = 0;
    int nums[size] = { -1 };
    for (int i = 0; i < size; i++)
        nums[i] = -1;
    while (!numFile.eof() && length < size)
    {
        nums[length] = getNumber(numFile);
        length++;
    }

    int step = std::floor(length / 2);
    int rightBorder = 0;
    if (step <= 0)
        step = 1;
    rightBorder = step - 1;
    int leftBorder = 0;
    bool found = false;
    while (!found && leftBorder < size)
    {
        int numsCount = 0;
        for (int i = 0; i < length; i++)
            if (nums[i] >= leftBorder && nums[i] <= rightBorder)
            {
                numsCount++;
            }
        if (numsCount < step) 
        {
            int missingNum = leftBorder;
            bool find = false;
            while (!find && missingNum <= rightBorder) 
            {
                int i = 0;

                while (missingNum != nums[i] && i < length) {
                    i++;
                }

                if (missingNum != nums[i - 1] && i >= length)
                {
                    find = true;
                    found = true;
                    std::cout << missingNum;
                }
                else
                  missingNum++;
            }
        }
        else
        {
            leftBorder = rightBorder + 1;
            rightBorder += step;
        }
    }
    
    numFile.close();

    return EXIT_SUCCESS;
}