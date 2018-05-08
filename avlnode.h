#ifndef AVLNODE_H
#define AVLNODE_H


class AVLnode
{
public:
    int rooms;
    double price;
    int balance;
    AVLnode *left, *right, *parent;
public:
    AVLnode(int r, double p, AVLnode *par);
    ~AVLnode();
};

#endif // AVLNODE_H
