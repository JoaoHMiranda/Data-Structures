
#include "bbtree.h"

int main()
{
    bbtree<int> a;

    a.insert(5);
    a.insert(2);
    a.insert(7);
    cout << a.size()<< endl;
    a.erase(2);
    cout << a.size()<< endl;
    a.clear();
    cout << a.size()<< endl;
    //~ cout << a.preorder(a.root) << "\n" << a.inorder(a.root) << "\n" << a.posorder(a.root);
    a.Preorder();
    cout  << "\n";
    a.Inorder();
     cout  << "\n";
    a.Posorder();
}
