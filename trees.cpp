#include "trees.h"

trees::trees()
{
    root = nullptr;
}

void trees::insert(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left_ptr = temp->right_ptr = nullptr;
    if (root == nullptr)
        root = temp;
    else
    {
        node *curr = root;
        while (curr != nullptr)
        {
            if (curr->data < temp->data)
                curr = curr->left_ptr;
            else
            {
                curr = curr->right_ptr;
            }
        }
        curr = temp;
    }
}

void trees::preorder(node *curr)
{
    if (curr == nullptr)
        return;
    cout << curr->data << " ";
    preorder(curr->left_ptr);
    preorder(curr->right_ptr);
}

void trees::postorder(node *curr)
{
    if (curr == nullptr)
        return;
    postorder(curr->left_ptr);
    postorder(curr->right_ptr);
    cout << curr->data << " ";
}

void trees::inorder(node *curr)
{
    if (curr == nullptr)
        return;
    inorder(curr->left_ptr);
    cout << curr->data << " ";
    inorder(curr->right_ptr);
}

void trees::display()
{
    node *curr = root;
    cout << "Preorder: ";
    preorder(curr);
    cout << "\nPostorder: ";
    postorder(curr);
    cout << "\nInorder: ";
    inorder(curr);
}