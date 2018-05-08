#ifndef AVLTREE_H
#define AVLTREE_H
#include<string>
#include<avlnode.h>
#include<iostream>
#include<chrono>
#include<random>
#include<utility>


class AVLtree
{
public:
    AVLtree();
    ~AVLtree();
    bool insert(int r, int price);
    bool deleteKey(const int room);
    void printBalance();
    void createDatabase(int rooms);
    int AVL_size;
    bool search(int price);
    int bell_curve_generator();

private:
    AVLnode *root = nullptr;

    AVLnode* rotateLeft(AVLnode *a);
    AVLnode* rotateRight(AVLnode *a);
    AVLnode* rotateLeftThenRight(AVLnode *n);
    AVLnode* rotateRightThenLeft(AVLnode *n);
    void reBalance(AVLnode *n);
    int height(AVLnode *n);
    void setBalance(AVLnode *n);
    void printBalance(AVLnode *n);
    void clearNode(AVLnode *n);

};

#endif // AVLTREE_H
