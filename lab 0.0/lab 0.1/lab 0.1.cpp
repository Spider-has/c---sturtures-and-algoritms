#include <iostream>
#include <fstream>
#include <cmath>

const int size = 100000;

int pos = -2;

int getNumber(std::fstream& file)
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

void binarySearch(int arr[], int length, int number)
{
    int posNow = 0, oldPos = 0;
    bool isFound = false;
    posNow = getMiddle(0, length);
    while (!isFound) {
        if (arr[posNow] == number)
        {
            isFound = true;
            pos = posNow;
        }
        else if ((posNow == 0) || (posNow == length - 1) || (posNow == oldPos))
        {
            isFound = true;
            pos = -1;
        }

        if (number > arr[posNow]) {
            oldPos = posNow;
            posNow = getMiddle(posNow, length);
        }
        else
            posNow = getMiddle(oldPos, posNow);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::fstream numFile;

    numFile.open("Inp.txt");

    if (!numFile.is_open())
    {
        return EXIT_FAILURE;
    }

    int userNumber = 0;
    int tryNum = -1;


    std::cout << "\nВведите число для поиска: ";
    std::cin >> userNumber;

    while (!numFile.eof() && pos < 0) {

        int nums[size] = { 0 };
        int i = 0;

        while (!numFile.eof() && i < size)
        {
            nums[i] = getNumber(numFile);
            i++;
        }

        if (userNumber < INT_MAX)
        {
            binarySearch(nums, i, userNumber);
            tryNum++;
        }
        else
        {
            std::cout << "\nнет, такие числа нельзя ";
        }
    }
    if (pos >= 0)
        std::cout << pos + tryNum * size;
    else
        std::cout << pos;
    numFile.close();

    return EXIT_SUCCESS;
}