#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> myQueue;
    int a = 10, b = 20;
    
    // Push two elements into the queue.
    myQueue.push(a);
    myQueue.push(b);
    
    cout << "Front element: " << myQueue.front() << endl;  // Should print 10
    cout << "Size: " << myQueue.size() << endl;              // Should print 2
    
    cout << "Popped element: " << myQueue.pop() << endl;     // Should remove and print 10
    cout << "Size after pop: " << myQueue.size() << endl;      // Should print 1
    cout << "Is empty? " << (myQueue.empty() ? "Yes" : "No") << endl;  // Should print "No"
    
    cout << endl;
    cout << "Front element: " << myQueue.front() << endl;    // Should print 20
    cout << "Size: " << myQueue.size() << endl;              // Should print 1
    cout << "Popped element: " << myQueue.pop() << endl;     // Should remove and print 20
    cout << "Size after pop: " << myQueue.size() << endl;      // Should print 0
    cout << "Is empty? " << (myQueue.empty() ? "Yes" : "No") << endl;  // Should print "Yes"
    
    return 0;
}
