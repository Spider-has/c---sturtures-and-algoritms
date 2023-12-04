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
    deleteElement(node, 7);
    treeOutput(node);
    nodeOuput(node);
}
