#include "trees.h"

int main()
{
    trees tree;
    int arr[6] = {10, 20, 33, 34, 29, 20};
    for (int i = 0; i < 6; i++)
    {
        tree.insert(arr[i]);
    }

    tree.display();

    return 0;
}