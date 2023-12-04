export module TreeSortModule; // module declaration

//import <iostream>;        // import declaration

import <iostream>;

using DataType = int;

struct Tree
{
    Tree(Tree* right = nullptr, Tree* left = nullptr, DataType data = -1) : right(right), left(left), data(data) {}
    Tree* right, * left;
    DataType data;
};


export void addInTree(Tree*& treePTR, DataType newData)
{
    if (treePTR == nullptr)
        treePTR = new Tree(nullptr, nullptr, newData);
    else
    {
        if (treePTR->data > newData)
            addInTree(treePTR->left, newData);
        else
            addInTree(treePTR->right, newData);
    }
}

export void treeOutput(Tree*& treePTR)
{
    if (treePTR != nullptr)
    {
        treeOutput(treePTR->left);
        std::cout << treePTR->data << " ";
        treeOutput(treePTR->right);
    }
}



