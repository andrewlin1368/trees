#include "trees.h"

int main()
{
    trees tree;
    int arr[6] = {10, 20, 33, 34, 29, 26};
    for (int i = 0; i < 6; i++)
    {
        tree.insert(arr[i]);
    }

    tree.display();
    tree.remove(tree.getroot(),34);
    cout<<"\nRemoved 34\n";
    tree.display();
    cout<<"\nRemove 33\n";
    tree.remove(tree.getroot(),33);
    tree.display();
    return 0;
}