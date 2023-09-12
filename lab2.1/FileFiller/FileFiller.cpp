#include <iostream>
#include <fstream>
#include <cmath>

const int size = 256;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::fstream numFile;

    numFile.open("Inp.txt");

    if (!numFile.is_open())
    {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < size; i++)
    {
        numFile << i;
        if(i < size - 1)
            numFile << " ";
    }

    numFile.close();

    return EXIT_SUCCESS;
}