#include "bbtree2.h"
#include <bits/stdc++.h>
using namespace std;

// Priority queue item type:
//   first  -> frequency (weight)
//   second.first  -> pointer to the tree node
//   second.second -> index of the first occurrence in the text
typedef pair<int, pair<Tnode<char>*, int>> PriorityTreeItem;

map<char, string> encodingMap;
map<string, char> decodingMap;

// Comparison function for sorting the priority queue items.
bool compareItems(const PriorityTreeItem& a, const PriorityTreeItem& b) {
    if (a.second.first->weight < b.second.first->weight)
        return true;
    if (a.second.first->weight > b.second.first->weight)
        return false;
    if (a.second.first->data == '-')
        return true;
    if (b.second.first->data == '-')
        return true;
    if (a.second.second >= b.second.second)
        return true;
    return false;
}

// Recursive function to generate Huffman codes from the tree.
void generateCodes(Tnode<char>* root, string codeStr = "") {
    if (root->right != nullptr)
        generateCodes(root->right, codeStr + '1');
    if (root->left != nullptr)
        generateCodes(root->left, codeStr + '0');
    if (root->data != '_') {
        if (codeStr == "")
            codeStr = "1";
        encodingMap[root->data] = codeStr;
        decodingMap[codeStr] = root->data;
    }
}

int main() {
    // Use "input.txt" for reading and "output.txt" for writing.
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string line, text = "";
    list<PriorityTreeItem> priorityQueue;
    vector<string> encodedSequence;
    
    // Read the entire input text.
    while (getline(cin, line)) {
        text += line + '\n';
    }
    
    // Frequency count for ASCII characters from 32 to 126.
    vector<pair<char, pair<int, int>>> frequency(100);
    for (int ascii = 32; ascii <= 126; ascii++) {
        frequency[ascii - 32].first = static_cast<char>(ascii);
        frequency[ascii - 32].second.first = 0;
        frequency[ascii - 32].second.second = 0;
    }
    
    // Count occurrences and record the index of the first occurrence for each character.
    for (int j = 0; j < int(text.size()); j++) {
        for (int ascii = 32; ascii <= 126; ascii++) {
            if (frequency[ascii - 32].first == text[j]) {
                frequency[ascii - 32].second.first++;
                if (frequency[ascii - 32].second.second == 0)
                    frequency[ascii - 32].second.second = j;
                break;
            }
        }
    }
    
    // For each character that appears in the text, create a node and add it to the priority queue.
    for (int ascii = 32; ascii <= 126; ascii++) {
        if (frequency[ascii - 32].second.first != 0) {
            BinaryTree<char> tree;
            tree.insert(frequency[ascii - 32].first, frequency[ascii - 32].second.first);
            Tnode<char>* node = tree.getRoot();
            priorityQueue.push_back({ frequency[ascii - 32].second.first,
                                       { node, frequency[ascii - 32].second.second } });
        }
    }
    
    // Sort the priority queue according to the comparison function.
    priorityQueue.sort(compareItems);
    
    // Build the Huffman tree by combining nodes until only one remains.
    while (priorityQueue.size() != 1) {
        PriorityTreeItem leftItem = priorityQueue.front();
        priorityQueue.pop_front();
        PriorityTreeItem rightItem = priorityQueue.front();
        priorityQueue.pop_front();
        
        BinaryTree<char> combinedTree(leftItem.second.first, rightItem.second.first);
        int combinedWeight = leftItem.first + rightItem.first;
        int combinedOccurrence = leftItem.second.second + rightItem.second.second;
        priorityQueue.push_back({ combinedWeight, { combinedTree.getRoot(), combinedOccurrence } });
        priorityQueue.sort(compareItems);
    }
    
    // Generate Huffman codes from the final tree.
    generateCodes(priorityQueue.front().second.first);
    
    // Print the original text.
    cout << "Text:" << endl << endl;
    for (char ch : text) {
        if (ch != '*')
            cout << ch;
        else
            cout << endl;
    }
    cout << endl << endl;
    
    // Print the dictionary (encoding map).
    cout << "Dictionary:" << endl << endl;
    for (auto &item : encodingMap) {
        if (item.first == '-')
            cout << " " << " " << item.second << endl;
        else
            cout << item.first << " " << item.second << endl;
    }
    cout << endl;
    
    // Print the encoded text.
    cout << "Encoded Text:" << endl << endl;
    for (char ch : text) {
        if (ch == '\n') {
            cout << endl;
        } else {
            if (ch == ' ') {
                cout << encodingMap['-'] << " ";
                encodedSequence.push_back(encodingMap['-']);
            } else {
                cout << encodingMap[ch] << " ";
                encodedSequence.push_back(encodingMap[ch]);
            }
        }
    }
    cout << endl;
    
    return 0;
}
