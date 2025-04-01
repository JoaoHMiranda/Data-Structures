#include "Burn.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, b;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    BinaryTree<int> tree;
    tree.buildFromVector(nums);
    
    cin >> b;
    TreeNode<int>* target = tree.find(b);
    tree.burn(target);
    
    return 0;
}
