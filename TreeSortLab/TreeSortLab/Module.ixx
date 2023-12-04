export module TreeSortModule2;

import <iostream>;

export using DataType = int;

export struct Tree
{
    Tree(Tree* right = nullptr, Tree* left = nullptr, DataType data = -1, bool red = true) : right(right), 
        left(left), data(data), red(red) {}
    Tree* right, * left;
    DataType data;
    bool red;
};

void treeElementDataOutput(Tree*& treePTR)
{
    std::cout << "\nelement: " << treePTR->data << "-";
    if (treePTR->red)
        std::cout << "red \n";
    else
        std::cout << "black \n";
}

export void nodeOuput(Tree*& treePTR)
{
    if(treePTR)
        std::cout << "\nnode: " << treePTR->data << " red: " << treePTR->red;
    if (treePTR->left)
    {
        std::cout << "\nleft: " << treePTR->left->data << " red: " << treePTR->left->red;
        if (treePTR->left->left)
            std::cout << "\nleft left: " << treePTR->left->left->data << " red: " << treePTR->left->left->red;
        if (treePTR->left->right)
            std::cout << "\nleft rigth: " << treePTR->left->right->data << " red: " << treePTR->left->right->red;
    }

    if (treePTR->right)
    {
        std::cout << "\nright: " << treePTR->right->data << " red: " << treePTR->right->red;
        if (treePTR->right->left)
            std::cout << "\nright left: " << treePTR->right->left->data << " red: " << treePTR->right->left->red;
        if (treePTR->right->right)
            std::cout << "\nright rigth: " << treePTR->right->right->data << " red: " << treePTR->right->right->red;
    }
    std::cout << "\n";
}


void doCheckDadAndUncle(Tree*& treePTR)
{
    if ((treePTR->left && treePTR->left->red) && (treePTR->right && treePTR->right->red)
        && (((treePTR->left->left && treePTR->left->left->red)
            || (treePTR->left->right && treePTR->left->right->red))
            || ((treePTR->right->left && treePTR->right->left->red)
                || (treePTR->right->right && treePTR->right->right->red))))
    {
        treePTR->left->red = false;
        treePTR->right->red = false;
        treePTR->red = !treePTR->red;
        std::cout << "\nreverse start!\n";
        nodeOuput(treePTR);
        std::cout << "\nreverse done!\n";
    }
}


void doRightHandRotateCheck(Tree*& treePTR)
{
    if ((treePTR->left && treePTR->left->red)
        && ((treePTR->right && !treePTR->right->red) || !treePTR->right)
        && (treePTR->left->left && treePTR->left->left->red))
    {
        nodeOuput(treePTR);
        Tree* treeCopy = treePTR;
        treePTR = treePTR->left;
        treeCopy->left = treePTR->right;
        treePTR->right = treeCopy;
        treePTR->red = false;
        treePTR->left->red = true;
        treePTR->right->red = true;
        std::cout << "\nright hand rotate done!\n";
        nodeOuput(treePTR);
    }
}

void doLeftHandRotateCheck(Tree*& treePTR)
{
    if ((treePTR->right && treePTR->right->red)
        && ((treePTR->left && !treePTR->left->red) || !treePTR->left)
        && (treePTR->right->right && treePTR->right->right->red))
    {
        nodeOuput(treePTR);
        Tree* treeCopy = treePTR;
        treePTR = treePTR->right;
        treeCopy->right = treePTR->left;
        treePTR->left = treeCopy;
        treePTR->red = false;
        treePTR->left->red = true;
        treePTR->right->red = true;
        std::cout << "\nleft hand rotate done!\n";
        nodeOuput(treePTR);
    }
}

void doLeftRightRedCheck(Tree*& treePTR)
{
    if ((treePTR->left && treePTR->left->red)
        && (treePTR->left->right && treePTR->left->right->red)
        && (!treePTR->left->left))
    {
        nodeOuput(treePTR);
        Tree* treeCopy = treePTR->left;
        treePTR->left = treePTR->left->right;
        treePTR->left->left = treeCopy;
        treeCopy->right = nullptr;
        std::cout << "\nleft right red check done!\n";
        nodeOuput(treePTR);
    }
}

void doRightLeftRedCheck(Tree*& treePTR)
{
    if ((treePTR->right && treePTR->right->red)
        && (treePTR->right->left && treePTR->right->left->red)
        && (!treePTR->right->right))
    {
        nodeOuput(treePTR);
        Tree* treeCopy = treePTR->right;
        treePTR->right = treePTR->right->left;
        treePTR->right->right = treeCopy;
        treeCopy->left = nullptr;
        std::cout << "\nright left red check done!\n";
        nodeOuput(treePTR);
    }
}

void deleteElementWithoutChildren(Tree*& treePTR)
{
    delete(treePTR);
    treePTR = nullptr;
}

void deleteElementWithOneChildren(Tree*& treePTR)
{
    Tree* treePTRCopy = treePTR;
    if (treePTR->left)
    {
        treePTR = treePTR->left;
    }
    else
    {
        treePTR = treePTR->right;
    }
    delete(treePTRCopy);
    treePTRCopy = nullptr;
}

void deleteElementWithTwoChildren(Tree*& treePTR)
{
    Tree* treePTRRightLeft = treePTR->right;
    Tree* treePTRCopy = treePTR;
    Tree* treePTRRightLeftCopy = treePTRRightLeft;
    while (treePTRRightLeft->left)
    {
        treePTRRightLeftCopy = treePTRRightLeft;
        treePTRRightLeft = treePTRRightLeft->left;
    }
    if(treePTRRightLeftCopy->left)
        treePTRRightLeftCopy->left = nullptr; // отчислил указатель

    if (treePTRRightLeft != treePTR->right)
    {
        treePTR = treePTRRightLeft;
        treePTR->right = treePTRCopy->right;
        
    }
    else
    {
        treePTR = treePTRRightLeft;
        treePTR->right = nullptr;
    }
    treePTR->red = treePTRCopy->red;
    treePTR->left = treePTRCopy->left;

    delete(treePTRCopy);
    treePTRCopy = nullptr;
}


void colorCheckLeftChildAfterDelete(Tree*& treePTR)
{
    if ((treePTR->left && treePTR->right) &&
        (treePTR->right->right && treePTR->right->left))
    {
        if (!treePTR->right->right->red && !treePTR->right->left->red)
        {
            treePTR->right->red = true;
            treePTR->red = false;
            std::cout << "\n First case fix delete 1\n";
        }
        else
        {
            if (!treePTR->right->right->red && treePTR->right->left->red)
            {
                treePTR->right->red = true;
                treePTR->right->left->red = false;
                Tree* treePTRCopy = treePTR->right;
                treePTR->right = treePTR->right->left;
                treePTR->right->right = treePTRCopy;
                treePTRCopy->left = nullptr;
                std::cout << "\n Second case fix delete 1\n";
            }
            if (treePTR->right->right->red)
            {
                treePTR->right->red = treePTR->red;
                treePTR->red = false;
                treePTR->right->right->red = false;
                Tree* treePTRCopy = treePTR;
                treePTR = treePTR->right;
                treePTRCopy->right = treePTR->left;
                treePTR->left = treePTRCopy;
            }
        }
    }
}


void colorCheckRightChildAfterDelete(Tree*& treePTR)
{
    if ((treePTR->left && treePTR->right) &&
        (treePTR->left->right && treePTR->left->left))
    {
        if (!treePTR->left->right->red && !treePTR->left->left->red)
        {
            treePTR->left->red = true;
            treePTR->red = false;
            std::cout << "\n First case fix delete 2\n";
        }
        else
        {
            if (!treePTR->left->right->red && treePTR->left->left->red)
            {
                treePTR->left->red = true;
                treePTR->left->left->red = false;
                Tree* treePTRCopy = treePTR->left;
                treePTR->left = treePTR->left->left;
                treePTR->left->right = treePTRCopy;
                treePTRCopy->left = nullptr;
                std::cout << "\n Second case fix delete 2\n";
            }
            if (treePTR->left->right->red)
            {
                treePTR->left->red = treePTR->red;
                treePTR->red = false;
                treePTR->left->right->red = false;
                Tree* treePTRCopy = treePTR;
                treePTR = treePTR->left;
                treePTRCopy->left = treePTR->right;
                treePTR->right = treePTRCopy;
            }
        }
    }
}

void fixElementDelete(Tree*& treePTR)
{
    if ((treePTR->left && !treePTR->left->red) && (treePTR->right && treePTR->right->red))
    {
        Tree* treePTRCopy = treePTR;
        treePTR = treePTR->right;
        treePTRCopy->right = treePTR->left;
        treePTR->left = treePTRCopy;
        treePTR->red = false;
        treePTRCopy->red = true;
    }
    else
        if ((treePTR->left && treePTR->left->red) && (treePTR->right && !treePTR->right->red))
        {
            Tree* treePTRCopy = treePTR;
            treePTR = treePTR->left;
            treePTRCopy->left = treePTR->right;
            treePTR->right = treePTRCopy;
            treePTR->red = false;
            treePTRCopy->red = true;
        }
    colorCheckLeftChildAfterDelete(treePTR);
    colorCheckRightChildAfterDelete(treePTR);
}




export void deleteElementAction(Tree*& treePTR, DataType data)
{
    if (treePTR)
    {
        if (treePTR->data == data)
        {
            std::cout << "Found delete: ";
            treeElementDataOutput(treePTR);
            if (!treePTR->left && !treePTR->right)
            {
                deleteElementWithoutChildren(treePTR);
            }
            else {
                if (treePTR->left && treePTR->right) {
                    deleteElementWithTwoChildren(treePTR);
                    nodeOuput(treePTR);
                    if (!treePTR->red)
                        fixElementDelete(treePTR);
                }
                else
                {
                    deleteElementWithOneChildren(treePTR);
                    nodeOuput(treePTR);
                    if (!treePTR->red)
                        fixElementDelete(treePTR);
                }
            }
            
        }
        else
        {
            if (treePTR->data > data)
                deleteElementAction(treePTR->left, data);
            else
                deleteElementAction(treePTR->right, data);
            if (!treePTR->red)
                fixElementDelete(treePTR);
        }
    }
}


export void deleteElement(Tree*& treePTR, DataType data)
{
    deleteElementAction(treePTR, data);
    treePTR->red = false;
    nodeOuput(treePTR);
}

void addInTreeAction(Tree*& treePTR, DataType newData)
{
    if (treePTR == nullptr)
        treePTR = new Tree(nullptr, nullptr, newData, true);
    else
    {
        if (treePTR->data > newData)
        {
            addInTreeAction(treePTR->left, newData);
        }
        else
        {
            addInTreeAction(treePTR->right, newData);
        }
        doCheckDadAndUncle(treePTR);
        doLeftRightRedCheck(treePTR);
        doRightLeftRedCheck(treePTR);
        doRightHandRotateCheck(treePTR);
        doLeftHandRotateCheck(treePTR);
    }
}

export void addInTree(Tree*& treePTR, DataType newData)
{
    addInTreeAction(treePTR, newData);
    if(treePTR->red)
        treePTR->red = false;
}


export void treeOutput(Tree*& treePTR)
{
    if (treePTR != nullptr)
    {
        treeOutput(treePTR->left);
        treeElementDataOutput(treePTR);
        treeOutput(treePTR->right);
    }
}

export void treeOutputLeftToRight(Tree*& treePTR)
{
    if (treePTR != nullptr)
    {
        treeOutput(treePTR->left);
        treeOutput(treePTR->right);
        std::cout << treePTR->data << " ";
    }
}

export void treeOutputRightToLeft(Tree*& treePTR)
{
    if (treePTR != nullptr)
    {
        treeOutput(treePTR->right);
        std::cout << treePTR->data << " ";
        treeOutput(treePTR->left);
    }
}