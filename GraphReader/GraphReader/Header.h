#include <vector>
#include <string>
#include <iostream>
#include <fstream>

std::string getNumbersFromString(std::string row) {
    int from, to, i = 0;
    int num = 0;
    char ch = ' ';
    if (row.length() > 1) {
        while (!((ch == '+') || (ch == '-') || (ch >= '0' and ch <= '9')) && i < row.length())
        {
            ch = row[i];
            i++;
        }
        from = i - 1;
        while (((ch == '+') || (ch == '-') || (ch >= '0' and ch <= '9')) && (i < row.length()))
        {
            ch = row[i];
            i++;
        }
        if (i == row.length())
            to = i;
        else
            to = i - 1;
        std::string substr = "";
        try
        {
            if (from < to && from < row.length()) {
                substr.append(row, from, to - from);
                return substr;
            }
            else {
                return "";
            }
        }
        catch (const std::exception&)
        {
            return "";
        }

    }
    else return "";
}



class GraphConvertor
{
public:
    void FillListFromFile(std::ifstream& file);
    void ListOutput();
    void FillMatrixFromFile(std::ifstream& file);
    void MatrixOutput();
    void ConvertListToMatrix();
    void ConvertMatrixToList();
    int GetCountOfVertices();
    int GetCountOfEdges();
private:
    void InitMatrix(int len);
    void InitList(int len);
    void SetCountOfEdges(std::string fileLine);
    void SetCountOfVertices(std::string fileLine);
    void SetCountOfEdgesAndVertices(std::string fileLine);
    struct ListOfEdgesType {
        ListOfEdgesType(int firstTop = 0, int secondTop = 0, int edgeSize = 0) : firstTop(firstTop), secondTop(secondTop), edgeSize(edgeSize) {}
        int firstTop, secondTop, edgeSize;
    };
    std::vector<ListOfEdgesType> ListofEdgesV;
    std::vector<std::vector<int>> AdjacencyMatrixV;
    int NumberOfVertices = 0;
    int NumberOfEdges = 0;
};

void GraphConvertor::InitList(int len) {
    ListofEdgesV.resize(len);
    for (int i = 0; i < len; i++) {
        ListofEdgesV[i].firstTop = 0;
        ListofEdgesV[i].secondTop = 0;
        ListofEdgesV[i].edgeSize = 0;
    }
}

int GraphConvertor::GetCountOfVertices() {
    return NumberOfVertices;
}

int GraphConvertor::GetCountOfEdges() {
    return NumberOfEdges;
}

void GraphConvertor::SetCountOfEdges(std::string fileLine) {
    try {
        std::string Edges = getNumbersFromString(fileLine);
        NumberOfEdges = std::stoi(Edges);
        std::cout << "\n" << NumberOfVertices << " " << NumberOfEdges << "\n";
    }
    catch (const std::exception&) {
        std::cout << "\n ERROR!!!! NORMALNIE DANNIE VVODI\n";
    }
}

void GraphConvertor::SetCountOfEdgesAndVertices(std::string fileLine) {
    try {
        std::string Str = fileLine;
        std::string Vertices = getNumbersFromString(Str);
        NumberOfVertices = std::stoi(Vertices);
        std::string copyLine = "";
        Str = copyLine.append(Str, Str.find_first_of(Vertices) + Vertices.length());
        std::string Edges = getNumbersFromString(Str);
        NumberOfEdges = std::stoi(Edges);
        std::cout << "\n" << NumberOfVertices << " " << NumberOfEdges << "\n";
    }
    catch (const std::exception&) {
        std::cout << "\n ERROR!!!! NORMALNIE DANNIE VVODI\n";
    }
}

void GraphConvertor::SetCountOfVertices(std::string fileLine) {
    try {
        std::string Vertices = getNumbersFromString(fileLine);
        NumberOfVertices = std::stoi(Vertices);
        std::cout << "\n" << NumberOfVertices << " " << NumberOfEdges << "\n";
    }
    catch (const std::exception&) {
        std::cout << "\n ERROR!!!! NORMALNIE DANNIE VVODI\n";
    }
}


void GraphConvertor::FillListFromFile(std::ifstream& inpFile) {
    std::string fileLine = "";
    int first, second, value = 0;
    if (!inpFile.eof()) {
        std::getline(inpFile, fileLine);
        SetCountOfEdgesAndVertices(fileLine);
    }
    int len = NumberOfEdges;
    for (int i = 0; i < len; i++)
    {
        if (!inpFile.eof()) {
            std::getline(inpFile, fileLine);
            ListOfEdgesType datas;
            std::string subNum1 = getNumbersFromString(fileLine);
            std::string copyLine = "";
            copyLine = copyLine.append(fileLine, fileLine.find_first_of(subNum1) + subNum1.length());
            fileLine = copyLine;
            std::string subNum2 = getNumbersFromString(fileLine);
            copyLine = "";
            copyLine = copyLine.append(fileLine, fileLine.find_first_of(subNum2) + subNum2.length());
            fileLine = copyLine;
            std::string subNum3 = getNumbersFromString(fileLine);
            try {
                first = std::stoi(subNum1);
                second = std::stoi(subNum2);
                value = std::stoi(subNum3);
                datas.firstTop = first;
                datas.secondTop = second;
                datas.edgeSize = value;
            }
            catch (const std::exception&) {
                std::cout << "\n ERROR!!!! NORMALNIE DANNIE VVODI\n";
            }

            ListofEdgesV.push_back(datas);
        }
    }
}

void GraphConvertor::ListOutput() {
    std::cout << "\nLIST: \n";
    for (int i = 0; i < ListofEdgesV.size(); i++) {
        std::cout << ListofEdgesV[i].firstTop << " " << ListofEdgesV[i].secondTop << " " << ListofEdgesV[i].edgeSize << "\n";
    }
    std::cout << "LIST END \n";
}

void GraphConvertor::ConvertListToMatrix() {
    int len = NumberOfVertices;
    InitMatrix(len);
    for (int i = 0; i < NumberOfEdges ; i++)
    {
        AdjacencyMatrixV[ListofEdgesV[i].firstTop - 1][ListofEdgesV[i].secondTop - 1] = ListofEdgesV[i].edgeSize;
        AdjacencyMatrixV[ListofEdgesV[i].secondTop - 1][ListofEdgesV[i].firstTop - 1] = ListofEdgesV[i].edgeSize;
    }
}

void GraphConvertor::InitMatrix(int len) {
    AdjacencyMatrixV.resize(len);
    for (int i = 0; i < len; i++) {
        AdjacencyMatrixV[i].resize(len);
        for (int j = 0; j < len; j++)
            AdjacencyMatrixV[i][j] = 0;
    }
}

void GraphConvertor::MatrixOutput() {
    int len = NumberOfVertices;

    std::cout << "\nMATRIX: " << "\n  ";
    for (int i = 0; i < len; i++) {
        std::cout << i + 1 << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < len; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < len; j++)
            std::cout << AdjacencyMatrixV[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "END MATRIX: \n";
}

void GraphConvertor::FillMatrixFromFile(std::ifstream& inpFile)
{
    std::string fileLine = "";
    std::getline(inpFile, fileLine);
    SetCountOfVertices(fileLine);
    int len = NumberOfVertices;
    InitMatrix(len);
    for (int i = 0; i < len; i++)
    {
        std::getline(inpFile, fileLine);
        for (int j = 0; j < len; j++)
        {
            std::string subNum = getNumbersFromString(fileLine);
            std::string copyLine = "";
            int pos = 0;
            if (fileLine.find(subNum) != std::string::npos)
            {
                pos = fileLine.find(subNum);
            }
            copyLine = copyLine.append(fileLine, pos + subNum.length());
            fileLine = copyLine;
            try
            {
                AdjacencyMatrixV[i][j] = std::stoi(subNum);
            }
            catch (const std::exception&)
            {
                std::cout << "\n ERROR!!!! NORMALNIE DANNIE VVODI\n";
            }
        }
    }
}

void GraphConvertor::ConvertMatrixToList() {
    int len = NumberOfVertices;
    InitList(NumberOfEdges);
    int edgeI = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (AdjacencyMatrixV[i][j] != 0) {
                ListofEdgesV[edgeI].firstTop = i + 1;
                ListofEdgesV[edgeI].secondTop = j + 1;
                ListofEdgesV[edgeI].edgeSize = AdjacencyMatrixV[i][j];
                edgeI++;
            }
        }
    }
}
#pragma once
