#include "ExpressionTree.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    ExpressionTree<char> tree;
    string prefixExpression;
    
    cout << "Enter a Prefix Expression (without spaces):" << endl << endl;
    cin >> prefixExpression;
    
    // Insert each character of the prefix expression into the tree.
    for (char ch : prefixExpression) {
        tree.insert(ch);
    }
    
    cout << endl << "Infix Expression:" << endl << endl;
    tree.inorderTraversal();
    cout << endl;
    
    return 0;
}
