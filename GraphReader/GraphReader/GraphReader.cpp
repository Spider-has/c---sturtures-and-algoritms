#include <iostream>
#include <fstream>
#include "Header.h"

int main()
{
    int data = 0;
    int length = 0;

    std::ifstream ListInp("ListOfEdges.txt");
    std::ifstream AdjacencyMatrInp("AdjacencyMatricesInput.txt");

    GraphConvertor Graph;
    Graph.FillMatrixFromFile(AdjacencyMatrInp);
    Graph.MatrixOutput();
    Graph.FillListFromFile(ListInp);
    Graph.ListOutput();
    Graph.ConvertListToMatrix();
    Graph.MatrixOutput();
    Graph.ConvertMatrixToList();
    Graph.ListOutput();
}

