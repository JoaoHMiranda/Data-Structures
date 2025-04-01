#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<string> s;
    string a = "aasd", b = "bgdggg";
    
    // Push two strings onto the stack.
    s.push(a);
    s.push(b);
    
    cout << "Top element: " << s.peek() << endl;    // Expected: "bgdggg"
    cout << "Size: " << s.size() << endl;             // Expected: 2
    
    cout << "Popped: " << s.pop() << endl;             // Expected: "bgdggg"
    cout << "Size after pop: " << s.size() << endl;    // Expected: 1
    cout << "Empty? " << (s.empty() ? "Yes" : "No") << endl; // Expected: "No"
    
    cout << endl;
    
    cout << "Top element: " << s.peek() << endl;       // Expected: "aasd"
    cout << "Size: " << s.size() << endl;              // Expected: 1
    cout << "Popped: " << s.pop() << endl;             // Expected: "aasd"
    cout << "Size after pop: " << s.size() << endl;    // Expected: 0
    cout << "Empty? " << (s.empty() ? "Yes" : "No") << endl; // Expected: "Yes"
    
    return 0;
}
