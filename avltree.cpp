#include "avltree.h"

AVLtree::AVLtree()
{

}

AVLtree::~AVLtree()
{
    delete root;
}

bool AVLtree::insert(int r, int price)
{
    if (root == NULL) {
            root = new AVLnode(r, price, NULL);
        }

    else{
        AVLnode *n = root, *parent;

        while (true) {
            if (n->price == price)
                return false;

            parent = n;

            bool goLeft = n->price > price;
            n = goLeft ? n->left : n->right;

            if (n == NULL) {
                if (goLeft) {
                    parent->left = new AVLnode(r, price, parent);
                }
                else {
                    parent->right = new AVLnode(r, price, parent);
                }

                reBalance(parent);
                break;
            }
        }
    }

    return true;
}

bool AVLtree::deleteKey(const int price)
{
    if (root == NULL)
            return false;

        AVLnode
            *n       = root,
            *parent  = root,
            *delNode = NULL,
            *child   = root;

        while (child != NULL) {
            parent = n;
            n = child;
            child = price >= n->price ? n->right : n->left;
            if (price == n->price)
                delNode = n;
        }

        if (delNode != NULL) {
            delNode->price = n->price;

            child = n->left != NULL ? n->left : n->right;

            if (root->price == price) {
                root = child;
            }
            else {
                if (parent->left == n) {
                    parent->left = child;
                }
                else {
                    parent->right = child;
                }

                reBalance(parent);
            }
        }
       return true;
}




void AVLtree::createDatabase(int rooms)
{
    this->AVL_size = rooms;
    this->root = nullptr;

    for(int i=0; i<rooms; i++){

        this->insert(i+1, bell_curve_generator());
    }

}

bool search_helper(AVLnode *n, int price){

    if(n->price == price){

        return true;
    }
    else if(n == nullptr){
        return false;
    }
    else if(price > n->price){
        search_helper(n->right, price);
    }
    else{
        search_helper(n->left, price);
    }


}
bool AVLtree::search(int price)
{
    if(this->root == nullptr){
        return false;
    }
    else{
        return search_helper(this->root, price);
    }
}



AVLnode *AVLtree::rotateLeft(AVLnode *a)
{
        AVLnode *b = a->right;
        b->parent = a->parent;
        a->right = b->left;

        if (a->right != NULL)
            a->right->parent = a;

        b->left = a;
        a->parent = b;

        if (b->parent != NULL) {
            if (b->parent->right == a) {
                b->parent->right = b;
            }
            else {
                b->parent->left = b;
            }
        }

        setBalance(a);
        setBalance(b);
        return b;
}

AVLnode *AVLtree::rotateRight(AVLnode *a)
{
        AVLnode *b = a->left;
        b->parent = a->parent;
        a->left = b->right;

        if (a->left != NULL)
            a->left->parent = a;

        b->right = a;
        a->parent = b;

        if (b->parent != NULL) {
            if (b->parent->right == a) {
                b->parent->right = b;
            }
            else {
                b->parent->left = b;
            }
        }

        setBalance(a);
        setBalance(b);
        return b;
}

AVLnode *AVLtree::rotateLeftThenRight(AVLnode *n)
{
         n->left = rotateLeft(n->left);
        return rotateRight(n);

}

AVLnode *AVLtree::rotateRightThenLeft(AVLnode *n)
{
         n->right = rotateRight(n->right);
        return rotateLeft(n);
}

void AVLtree::reBalance(AVLnode *n)
{
        setBalance(n);

        if (n->balance == -2) {
            if (height(n->left->left) >= height(n->left->right))
                n = rotateRight(n);
            else
                n = rotateLeftThenRight(n);
        }
        else if (n->balance == 2) {
            if (height(n->right->right) >= height(n->right->left))
                n = rotateLeft(n);
            else
                n = rotateRightThenLeft(n);
        }

        if (n->parent != NULL) {
            reBalance(n->parent);
        }
        else {
            root = n;
        }
}

int AVLtree::height(AVLnode *n)
{
    if (n == NULL)
            return -1;
    return 1 + std::max(height(n->left), height(n->right));
}

void AVLtree::setBalance(AVLnode *n)
{
    n->balance = height(n->right) - height(n->left);
}

void AVLtree::printBalance(AVLnode *n)
{
    if (n != NULL) {
            printBalance(n->left);
            std::cout << n->balance << " ";
            printBalance(n->right);
    }
}

int AVLtree::bell_curve_generator()
{
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::normal_distribution<double> distrN(350.0, 12.0);
        int ran_num = distrN(e);
        return ran_num;
}


