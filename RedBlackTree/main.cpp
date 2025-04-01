#include <iostream>
#include "RBTree.h"
#include <cstdlib>  // for atoi
#include <string>
using namespace std;

// Helper function: Read a valid positive integer from input.
int getValidInteger() {
    int value = -1;
    string input;
    while (true) {
        cout << "\nEnter a positive integer: ";
        getline(cin, input);
        value = atoi(input.c_str());
        if (value >= 0)
            return value;
        else
            cout << "Invalid value: " << input << endl;
    }
}

int main() {
    RBTree tree;
    int option = -1;
    string input;
    int item;

    while (true) {
        cout << "\n============== RED-BLACK TREE MENU ==============" << endl;
        cout << "1 - Insert Node" << endl;
        cout << "2 - Clear Tree" << endl;
        cout << "3 - Inorder Traversal" << endl;
        cout << "4 - Preorder Traversal" << endl;
        cout << "5 - Postorder Traversal" << endl;
        cout << "6 - Pretty Print Tree" << endl;
        cout << "7 - Print Number of Elements" << endl;
        cout << "8 - Delete Node" << endl;
        cout << "9 - Exit" << endl;
        cout << "==================================================" << endl;
        cout << "\nEnter your option: ";
        getline(cin, input);
        option = atoi(input.c_str());

        if (option >= 1 && option <= 9) {
            if (option == 1) {
                item = getValidInteger();
                tree.insert(item);
            }
            else if (option == 2) {
                tree.clearTree();
                cout << "Press Enter to continue..." << endl;
                cin.ignore();
            }
            else if (option == 3) {
                tree.inorder();
                cout << "Press Enter to continue..." << endl;
                cin.ignore();
            }
            else if (option == 4) {
                tree.preorder();
                cout << "Press Enter to continue..." << endl;
                cin.ignore();
            }
            else if (option == 5) {
                tree.postorder();
                cout << "Press Enter to continue..." << endl;
                cin.ignore();
            }
            else if (option == 6) {
                tree.prettyPrint();
                cout << "Press Enter to continue..." << endl;
                cin.ignore();
            }
            else if (option == 7) {
                cout << "Number of elements: " << tree.getSize() << endl;
                cout << "Press Enter to continue..." << endl;
                cin.ignore();
            }
            else if (option == 8) {
                cout << "Enter the node value to delete: ";
                item = getValidInteger();
                tree.deleteNode(item);
            }
            else if (option == 9) {
                break;
            }
        } else {
            cout << "\nInvalid option: " << input << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore();
        }
    }
    return 0;
}
