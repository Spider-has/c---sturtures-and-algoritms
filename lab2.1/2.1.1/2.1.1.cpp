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

int getNumsCount(int arr[], int minNum, int maxNum)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] >= minNum && arr[i] <= maxNum)
            count++;
    return count;
}

int getMissedNum(int arr[], int length)
{
    int numNow = 0, rightBorder = size, leftBorder = 0;
    numNow = getMiddle(leftBorder, rightBorder);
    bool found = false;
    int rightNumsCount = 0, leftNumsCount = 0;
    while (!found && numNow < size)
    {
        if (std::floor((rightBorder - leftBorder) / 2) == 0  || leftBorder == size - 1 || rightBorder == 1)
            found = true;
        rightNumsCount = getNumsCount(arr, numNow, rightBorder);
        leftNumsCount = getNumsCount(arr, leftBorder, numNow - 1);
        if (rightNumsCount > leftNumsCount) {
            rightBorder = getMiddle(leftBorder, rightBorder);
            numNow = getMiddle(leftBorder, rightBorder);
        }
        else
        {
            leftBorder = getMiddle(leftBorder, rightBorder);
            numNow = getMiddle(leftBorder, rightBorder);
        }
    }
    
    return numNow;
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

   
    int num = getMissedNum(nums, length);
    std::cout << num;
    numFile.close();

    return EXIT_SUCCESS;
}