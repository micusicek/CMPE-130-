#include "avlnode.h"

AVLnode::AVLnode(int r, double p, AVLnode *par)
{
    this->rooms = r;
    this->price = p;
    this->balance = 0;
    this->parent = par;
    this->left = nullptr;
    this->right = nullptr;
}

AVLnode::~AVLnode()
{
    delete this->left, this->right;
}


