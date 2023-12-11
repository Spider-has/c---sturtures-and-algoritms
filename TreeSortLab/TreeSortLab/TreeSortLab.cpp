import TreeSortModule2;

#include <iostream>
#include <fstream>

int main()
{
    Tree *node = nullptr;
    DataType data = 0;
    std::ifstream inp("input.txt");
    while (inp >> data)
    {
        addInTree(node, data);
    }
    treeOutput(node);
    std::cout << "\n";
    nodeOuput(node);
    deleteElement(node, 587);
    treeOutput(node);
    nodeOuput(node);
    deleteElement(node, 89);
    treeOutput(node);
    nodeOuput(node);
    deleteElement(node, 12);
    treeOutput(node);
    nodeOuput(node);
    deleteElement(node, 45);
    treeOutput(node);
    nodeOuput(node);
    deleteElement(node, 35);
    treeOutput(node);
    nodeOuput(node);
    deleteElement(node, 69);
    treeOutput(node);
    nodeOuput(node);
}
