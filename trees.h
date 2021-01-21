#ifndef TREES_H_
#define TREES_H_

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left_ptr;
    node *right_ptr;
};

class trees
{
    node *root;

public:
    trees();
    void insert(int data);
    node *remove(node *curr, int data);
    void preorder(node *curr);
    void postorder(node *curr);
    void inorder(node *curr);
    void display();
};

#endif