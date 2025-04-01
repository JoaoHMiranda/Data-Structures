#include "AVLTree.h"
#include <iostream>
using namespace std;

int main() {
    AVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    
    int removedValue = -1;
    
    cout << "Preorder:" << endl;
    tree.preorder();
    cout << "\n\nInorder:" << endl;
    tree.inorder();
    cout << "\n\nPostorder:" << endl;
    tree.postorder();
    cout << "\n\n";
    
    if (tree.remove(30, &removedValue)) {
        cout << "Removed: " << removedValue << endl;
    } else {
        cout << "Failed to remove: " << removedValue << endl;
    }
    
    cout << "\n";
    if (tree.search(removedValue)) {
        cout << "Found: " << removedValue << endl;
    } else {
        cout << "Not found: " << removedValue << endl;
    }
    
    cout << "\nTree height: " << tree.height() << endl;
    
    return 0;
}
