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
    {
        root = temp;
        return;
    }
    else
    {
        node *curr = root;
        node *curr1 = nullptr;
        while (curr != nullptr)
        {
            curr1 = curr;
            if (curr->data < data)
            {
                curr = curr->right_ptr;
            }
            else
            {
                curr = curr->left_ptr;
            }
        }
        if (curr1->data < data)
        {
            curr1->right_ptr = temp;
        }
        else
        {
            curr1->left_ptr = temp;
        }
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

node *trees::remove(node *curr, int data)
{
    if (curr == nullptr)
    {
        return curr;
    }
    else
    {
        if (curr->data > data)
        {
            curr->left_ptr = remove(curr->left_ptr, data);
        }
        else if (curr->data < data)
        {
            curr->right_ptr = remove(curr->right_ptr, data);
        }
        else
        {
            if (curr->left_ptr == nullptr && curr->right_ptr == nullptr)
            {
                curr = nullptr;
                delete curr;
            }
            else if (curr->left_ptr != nullptr && curr->right_ptr == nullptr)
            {
                node *temp = curr;
                curr = curr->left_ptr;
                delete temp;
            }
            else if (curr->right_ptr != nullptr && curr->left_ptr == nullptr)
            {
                node *temp = curr;
                curr = curr->right_ptr;
                delete temp;
            }
            else
            {
                node *temp = curr->right_ptr;
                if (temp->left_ptr == nullptr && temp->right_ptr == nullptr)
                {
                    curr->data = temp->data;
                    curr->right_ptr = remove(temp, temp->data);
                }
                else
                {
                    while (temp->left_ptr != nullptr)
                        temp = temp->left_ptr;
                    curr->data = temp->data;
                    curr->right_ptr = remove(temp, temp->data);
                }
            }
        }
    }
    return curr;
}

node *trees::getroot()
{
    return root;
}