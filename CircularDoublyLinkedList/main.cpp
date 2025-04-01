#include <iostream>
#include "CircularDoublyLinkedList.h"
using namespace std;

int main() {
    CircularDoublyLinkedList<int> list;
    int a, b, removed;
    
    cin >> a;
    list.insert(a);
    cin >> b;
    list.insert(b);
    
    cout << "Size: " << list.size() << endl;
    
    // Search for element 'a' and erase it.
    if (list.search(a)) {
        removed = list.erase();
        cout << "Erased: " << removed << endl;
    }
    cout << "Size: " << list.size() << endl;
    
    // Search for element 'b' and erase it.
    if (list.search(b)) {
        removed = list.erase();
        cout << "Erased: " << removed << endl;
    }
    cout << "Size: " << list.size() << endl;
    
    // Insert again.
    list.insert(b);
    list.insert(a);
    cout << "Size: " << list.size() << endl;
    
    list.clear();
    cout << "Size after clear: " << list.size() << endl;
    
    if (list.search(b))
        cout << "Found b" << endl;
    else
        cout << "Did not find b" << endl;
    
    if (list.search(a))
        cout << "Found a" << endl;
    else
        cout << "Did not find a" << endl;
    
    list.insert(a);
    if (list.search(a))
        cout << "Found a" << endl;
    else
        cout << "Did not find a" << endl;
    
    return 0;
}
