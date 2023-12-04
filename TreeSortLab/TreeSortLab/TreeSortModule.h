#pragma once

using DataType = int;

struct Tree
{
    Tree(Tree* right = nullptr, Tree* left = nullptr, DataType data = -1) : right(right), left(left), data(data) {}
    Tree* right, * left;
    DataType data;
};

void treeSort(Tree*& treePTR, DataType newData)
{
    if (treePTR == nullptr)
        treePTR = new Tree(nullptr, nullptr, newData);
    else
    {
        if (treePTR->data > newData)
            treeSort(treePTR->left, newData);
        else
            treeSort(treePTR->right, newData);
    }
}

void treeOutput(Tree*& treePTR)
{
    if (treePTR != nullptr)
    {
        treeOutput(treePTR->left);
        std::cout << treePTR->data << " ";
        treeOutput(treePTR->right);
    }
}

