#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
    BinaryTree<int> tree;

    // Insert values into the tree.
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    
    cout << "Size: " << tree.size() << endl;
    
    // Remove a value.
    tree.erase(2);
    cout << "Size after erasing 2: " << tree.size() << endl;
    
    // Clear the tree.
    tree.clear();
    cout << "Size after clearing: " << tree.size() << endl;
    
    // Insert new values to test traversals.
    tree.insert(10);
    tree.insert(6);
    tree.insert(15);
    tree.insert(4);
    tree.insert(8);
    
    cout << "Preorder: ";
    tree.preorder();
    cout << "\nInorder: ";
    tree.inorder();
    cout << "\nPostorder: ";
    tree.postorder();
    cout << endl;
    
    return 0;
}
