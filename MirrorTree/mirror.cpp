#include "MirrorTree.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    BinaryTree<int> tree;
    tree.insert(nums);
    
    // Check if the tree is symmetric (mirrored)
    if (tree.isMirror())
        cout << "The tree is symmetric (mirrored)." << endl;
    else
        cout << "The tree is not symmetric (mirrored)." << endl;
    
    return 0;
}
