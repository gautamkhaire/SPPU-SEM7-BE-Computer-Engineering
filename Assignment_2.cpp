/*
    Problem Statement: Write a program to implement Huffman Encoding using a greedy strategy.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Huffman Coding Complexity Analysis :-

    Time Complexity: O(nlogn)
        O(nlogn) where n is the number of unique characters. If there are n nodes, extractMin() is called 2*(n – 1) times.
        extractMin() takes O(logn) time as it calls minHeapify(). So, the overall complexity is O(nlogn).
        If the input array is sorted, there exists a linear time algorithm.

    Space Complexity: O(n)

    Huffman Coding Applications :-
    1. Huffman coding is used in conventional compression formats like GZIP, BZIP2, PKZIP, etc.
    2. For text and fax transmissions.
*/

// A Huffman TreeNode
struct TreeNode
{
    char data;              // One of the input character
    int frequency;          // Frequency of the character
    TreeNode *left, *right; // Left and right child

    TreeNode(char data, int frequency)
    {
        this->data = data;
        this->frequency = frequency;
        left = right = NULL;
    }
};

// Prints huffman codes from the root of Huffman Tree. (Simple DFS Traversal of tree)
void printCodes(TreeNode *root, string path)
{
    if (root == NULL)
        return;

    if (root->data != '$') // Leaf Node
        cout << "      " << root->data << "       :       " << path << "  " << endl;

    printCodes(root->left, path + '0');
    printCodes(root->right, path + '1');
}

// For comparsion of two heap nodes (needed in minHeap)
struct compare
{
    bool operator()(TreeNode *l, TreeNode *r)
    {
        return (l->frequency > r->frequency);
    }
};

void HuffmanCodes(unordered_map<char, int> &frequencyMap)
{
    // Create a min heap & inserts all characters
    priority_queue<TreeNode *, vector<TreeNode *>, compare> minHeap;

    for (auto &itr : frequencyMap)
    {
        char data = itr.first;
        int frequency = itr.second;

        minHeap.push(new TreeNode(data, frequency));
    }

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum frequency items from min heap
        TreeNode *left = minHeap.top();
        minHeap.pop();

        TreeNode *right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes frequencies.
        // Make the two extracted node as left and right children of this new node.
        // Add this node to the min heap '$' is a special value for internal nodes, not used in message string (assumption)
        TreeNode *newNode = new TreeNode('$', (left->frequency + right->frequency));
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    // Print Huffman codes using the Huffman tree built above
    cout << "Encoded codes for each character are as follows:- " << endl;
    cout << "  character       code-word  " << endl;
    printCodes(minHeap.top(), "");
}

int main()
{
    try
    {
        string message = "";
        cout << "Enter the message you want to encode using the Huffman Coding: ";
        cin >> message;

        unordered_map<char, int> frequencyMap; // { character,frequency }
        for (char &ch : message)
            frequencyMap[ch] += 1;

        for (auto &itr : frequencyMap)
            cout << itr.first << " -> " << itr.second << endl;
        cout << endl;

        HuffmanCodes(frequencyMap);
    }
    catch (string errorMessage)
    {
        cout << errorMessage << endl;
    }

    return 0;
}