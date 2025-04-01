#include "dist.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    BinaryTree<int> tree;
    tree.buildFromVector(numbers);
    cout << "Max distance " << tree.maxDistance() << endl;
    return 0;
}
