#include <iostream>
#include <fstream>
#include <cmath>

const long int size = 100000;

int getNumber(std::fstream& file)
{
    int num;
    file >> num;
    return num;
}

int getMiddle(int start, int end)
{
    return std::floor((start + end) / 2);
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
            std::cout << posNow;
        }
        else if ((posNow == 0) || (posNow == length - 1) || (posNow == oldPos))
        {
            isFound = true;
            std::cout << -1;
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
    std::fstream fileNum;

    fileNum.open("Inp.txt");

    if (!fileNum.is_open())
    {
        return EXIT_FAILURE;
    }

    int fileNums[size] = {0};
    int i = 0;

    while (!fileNum.eof())
    {
        fileNums[i] = getNumber(fileNum);
        i++;
    }

    int num = 0;

    do
    {
        std::cout << "\nВведите число для поиска: ";
        std::cin >> num;
        if (num < INT_MAX)
            binarySearch(fileNums, i, num);
        else
        {
            std::cout << "\nнет, соси ";
            break;
        }
           
        
    } while (1);

    return EXIT_SUCCESS;
}