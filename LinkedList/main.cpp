
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<string> myList;
    string firstValue = "aasd", secondValue = "bgdggg";
    
    // Insert two strings.
    myList.insert(firstValue);
    myList.insert(secondValue);
    
    cout << "Front element: " << myList.front() << endl;
    cout << "Size: " << myList.size() << endl;
    
    // Erase an element.
    cout << "Erased: " << myList.erase("aasd") << endl;
    cout << "Size after erase: " << myList.size() << endl;
    cout << "Is empty? " << (myList.empty() ? "Yes" : "No") << endl;
    
    cout << endl;
    string found = "a";
    cout << "Before search, value: " << found << endl;
    if (myList.search("bgdggg", &found))
        cout << "After search, found: " << found << endl;
    else
        cout << "Value not found." << endl;
    
    cout << endl;
    cout << "Front element: " << myList.front() << endl;
    cout << "Size: " << myList.size() << endl;
    cout << "Erased: " << myList.erase("bgdggg") << endl;
    cout << "Size after erase: " << myList.size() << endl;
    cout << "Is empty? " << (myList.empty() ? "Yes" : "No") << endl;
    
    return 0;
}
